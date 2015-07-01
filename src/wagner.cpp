// Copyright (c) 2015 by Sean Downey
// Authors: Sean Downey (sean@codexdata.com) and Guowei Sun (gwsun@umd.edu)
// This software is distributed under GPL-3.
// Includes modified C++ code originally developed by Greg Kondrak (c) 2000

// Copyright (c) 2000 by Grzegorz Kondrak
//
// Permission is granted for anyone to copy, use, or modify this program
// for purposes of research or education, provided this copyright notice
// is retained, and note is made of any changes that have been made.
//
// This program is distributed without any warranty, express or implied.
// As this program was written for research purposes only, it has not been
// tested to the degree that would be advisable in any important application.
// All use of this program is entirely at the user's own risk.

// This file contains routines for computing alignment using various
// dynamic programming techniques.

#include "glob.h"
#include "Stack.h"
#include "Word.h"

//#define DEBUG			// debugging mode

// exactly one of the following three names must be defined!
//#define GLOBAL                // global comparison
//#define SEMI_GLOBAL             // semi-global comparison
#define LOCAL                	// local comparison

int max(int a, int b)
{
	if (a > b) { return a; } else { return b; }
}

#define SQUASH	
// If you are interested in scoring similarity, not the alignment,
// it's probably best to turn off "squashing", that is, two-to-one
// alignments (they show up as "<"). Ti turn it off, comment out the
// option SQUASH in the file glob.h.

#define ONE_ONLY		// find only one alignment
                                // (may not be optimal if ScoreMargin < 1.0)
// global variables
int   S[MAXL][MAXL];            // score matrix
int   DpScore;                  // score computed by the DP routine
float AcptScore;		// minimal acceptable score
Stack Trace;                    // trace i.e. unambiguous alignment
Stack Out;                      // alignment found by DP routine
Stack Cost;			// cost of individual operations
bool  FallThru;		        // for ONE_ONLY mode

extern int sigmaSub( Word *wA, short iA, Word *wB, short iB, int vec[12] );
extern int sigmaSkip( Word *w, short i, int skippen);
extern int sigmaExp( Word *wA, short iA, Word *wB, short i1B, short i2B, int vec[12] );

// wrapper function for the score matrix
inline int Score( short i, short j )
{
    return ( ( i >= 0 ) && ( j >= 0 ) ? S[i][j] : NoScore );
}

inline int maxim( int m1, int m2, int m3, int m4, int m5 )
{
    return max( max( max( m1, m2 ), m3 ), max( m4, m5 ) );
}

inline int maxim( int m1, int m2, int m3, int m4, int m5, int m6 )
{
    return max( max( max( m1, m2 ), m3 ), max( max( m4, m5 ), m6 ) );
}

void showScoreMatrix( short lenA, short lenB )
{
    for ( short i = 0; i <= lenA; i++ )
    {
        for ( short j = 0; j <= lenB; j++ )
        {
           // cout << setw(5) << S[i][j];
        }
      //  cout << endl;
    }
}

// display alignment score
int show( int score )
{
    return(deconv(score));   // Modified by G.S.
}

// filtering alignments that violate alternating-skips rule of Covington;
// note that this is a rather expensive solution
bool allowed( Stack* w )
{
    for ( int i = 1; i < w->top; i++ )
    {
        if ( w->stack[0][i] == NUL && w->stack[1][i-1] == NUL )
            return false;
    }
    return true;
}

// algorithm X
int similarity( Word *wA, Word *wB, int vec[12], int skippen )  // Coefficient argument added by G.S.
{
    short lenA = wA->phlen();
    short lenB = wB->phlen();
    int sgmax = 0;			// not meaningful for global case
    int m1, m2, m3, m4 = NoScore, m5 = NoScore, lmax;

    S[0][0] = 0;

    for ( short i = 1; i <= lenA; i++ )
#ifdef GLOBAL
        S[i][0] = S[i-1][0] + sigmaSkip( wA, i, skippen);
#else
        S[i][0] = 0;
#endif

    for ( short j = 1; j <= lenB; j++ )
#ifdef GLOBAL
        S[0][j] = S[0][j-1] + sigmaSkip( wB, j, skippen);
#else
        S[0][j] = 0;
#endif

    for ( short i = 1; i <= lenA; i++ )
    {
        for ( short j = 1; j <= lenB; j++ )
        {
            m1 = Score(i-1,j) + sigmaSkip( wA, i, skippen);
            m2 = Score(i,j-1) + sigmaSkip( wB, j, skippen);
            m3 = Score(i-1,j-1) + sigmaSub( wA, i, wB, j, vec );
#ifdef SQUASH
            m4 = Score(i-1,j-2) + sigmaExp( wA, i, wB, j-1, j, vec );
            m5 = Score(i-2,j-1) + sigmaExp( wB, j, wA, i-1, i, vec );
#endif
#ifdef LOCAL
            lmax = maxim( m1, m2, m3, m4, m5, 0 );
#else
            lmax = maxim( m1, m2, m3, m4, m5 );
#endif
            S[i][j] = lmax;

            if ( lmax > sgmax )
#ifdef SEMI_GLOBAL
                if ( i == lenA || j == lenB )	// border only for semi-global
#endif
                    sgmax = lmax;
        }
    }

    return sgmax;
}

// algorithm Y
// made recursive in order to find all maximal solutions (not just one)
void alignment( Word *wA, Word *wB, short i, short j, int T, int *getscore, char aback1[50], char aback2[50], int vec[12], int skippen )  // Modified by G.S.
{
    //short lenA = wA->phlen();
    //short lenB = wB->phlen();

#ifdef ONE_ONLY
    if ( FallThru ) return;
#endif

    if ( i == 0 && j == 0 )
    {
display:
        assert( Score(i,j) == 0 );
        if ( allowed( &Out ) && !FallThru )
        {
            Out.push( LIM, LIM );
            // padding the remaining string
            for ( short i1 = i; i1 > 0; i1-- )
                Out.push( i1, NUL );
            for ( short j1 = j; j1 > 0; j1-- )
                Out.push( NUL, j1 );
//#ifdef DEBUG
            Cost.show();
            Trace.show();
            Out.show();
//#endif

            Out.showAlign( wA, 0, aback1 ); 
            
            Out.showAlign( wB, 1, aback2);
            
            Out.pop(i+j+1);

#ifdef GLOBAL // patchy
            int score = T + (i+j)*sigmaSkip( wA, 0, skippen);
#else
            int score = T;
#endif
            *getscore=show( score ); 
#ifdef ONE_ONLY
            FallThru = true;
#endif
        }
    }
    else
    {
        int subSc = sigmaSub( wA, i, wB, j, vec );
        if ( Score(i-1,j-1) + subSc + T >= AcptScore )
        {
            Cost.push( subSc );
            Out.push( i, j );
            Trace.push( i, j );
            alignment( wA, wB, i-1, j-1, T + subSc, getscore, aback1, aback2, vec, skippen );
            Trace.pop();
            Out.pop();
            Cost.pop();
        }

#ifndef GLOBAL
        if ( i == 0 ) goto display; // shortcut
#endif

        int insSc = sigmaSkip( wB, j, skippen);
        if ( ( i == 0 ) || ( Score(i,j-1) + insSc + T >= AcptScore ) )
        {
            Cost.push( insSc );
            Out.push( NUL, j );
            alignment( wA, wB, i, j-1, T + insSc, getscore, aback1, aback2, vec, skippen);
            Out.pop();
            Cost.pop();
        }
#ifdef SQUASH
        int expSc = sigmaExp( wA, i, wB, j-1, j, vec );
        if ( Score(i-1,j-2) + expSc + T >= AcptScore )
        {
            Cost.push( expSc );
            Cost.push( NUL );
            Out.push( i, j );
            Out.push( DUB, j-1 );
            Trace.push( i, j );
            Trace.push( i, j-1 );
            alignment( wA, wB, i-1, j-2, T + expSc, getscore, aback1, aback2, vec, skippen);
            Trace.pop(2);
            Out.pop(2);
            Cost.pop(2);
        }
#endif

#ifndef GLOBAL
        if ( j == 0 ) goto display;  // shortcut
#endif

        int delSc = sigmaSkip( wA, j, skippen);
        if ( ( j == 0 ) || ( Score(i-1,j) + delSc + T >= AcptScore ) )
        {
            Cost.push( delSc );
            Out.push( i, NUL );
            alignment( wA, wB, i-1, j, T + delSc, getscore, aback1, aback2, vec, skippen);
            Out.pop();
            Cost.pop();
        }
#ifdef SQUASH
        int cmpSc = sigmaExp( wB, j, wA, i-1, i, vec );
        if ( Score(i-2,j-1) + cmpSc + T >= AcptScore )
        {
            Cost.push( cmpSc );
            Cost.push( NUL );
            Out.push( i, j );
            Out.push( i-1, DUB );
            Trace.push( i, j );
            Trace.push( i-1, j );
            alignment( wA, wB, i-2, j-1, T + cmpSc, getscore, aback1, aback2, vec, skippen);
            Trace.pop(2);
            Out.pop(2);
            Cost.pop(2);
        }
#endif

#ifdef LOCAL
        if ( Score(i,j) == 0 ) goto display; // shortcut
#endif
    }
}

// find all optimal alignments
void align( Word *wA, Word *wB, int *getscore, char aback1[50], char aback2[50], int vec[12] , int skippen)
{
    //for(int test=0;test<12;test++) {printf("%d",coeff[test]);}; printf("\n"); This is for test!
    
    short lenA = wA->phlen();
    short lenB = wB->phlen();

    Cost.clear();
    Trace.clear();
    Out.clear();
    FallThru = false;

    int sgmax = similarity( wA, wB, vec, skippen );
#ifdef DEBUG
    showScoreMatrix( lenA, lenB );
#endif

#ifdef GLOBAL
    DpScore = Score( lenA, lenB );	// sgmax is ignored in global case
#else
    DpScore = sgmax;
#endif
    AcptScore = DpScore * gP::ScoreMargin;

    for ( short i = 0; i <= lenA; i++ )
    {
        for ( short j = 0; j <= lenB; j++ )
        {
#ifdef GLOBAL
            if ( i < lenA || j < lenB )		// corner start point only
                continue;
#endif
#ifdef SEMI_GLOBAL
            if ( i < lenA && j < lenB )		// border start points only
                continue;
#endif
            if ( S[i][j] >= AcptScore ) 
            {
                for ( short j1 = lenB; j1 > j; j1-- )
                    Out.push( NUL, j1 );
                for ( short i1 = lenA; i1 > i; i1-- )
                    Out.push( i1, NUL );
                Out.push( LIM, LIM );
                alignment( wA, wB, i, j, 0, getscore, aback1, aback2, vec, skippen);
                Out.pop(lenA-i+lenB-j+1);
     //           S[i][j] = NoScore;	// potential bug
                if ( FallThru ) return;
            }
        }
    }
}

