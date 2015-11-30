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

// This file contains routines for computing similarity between
// individual phonetic segments based on their feature representation.

#include "Word.h"
#include <cstring>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b)))

// feature values
const int FSyl = 0;
	const fval syl = 100;
	const fval nsl = 0;
const int FPlace = 1;
	const fval glo = 10;
//	const fval pha = 30;
//        const fval uvu = 50;
        const fval vel = 60;
        const fval pal = 70;
        const fval pav = 75;
        const fval rfl = 80;
        const fval alv = 85;
        const fval dnt = 90;
        const fval lbd = 95;
	const fval blb = 100;
const int FStop  = 2;
        const fval lvl = 0;
        const fval mvl = 20;
        const fval hvl = 40;
        const fval vwl = hvl;
        const fval apr = 60;
        const fval frc = 80;
        const fval afr = 90;
        const fval stp = 100;
const int FVoice = 3;
	const fval vce = 100;
	const fval vls = 0;
const int FNasal = 4;
	const fval nas = 100;
//	const fval nns = 0;
const int FRetro = 5;
	const fval ret = 100;
//	const fval nrt = 0;
const int FLat  = 6;
	const fval lat = 100;
//	const fval nlt = 0;
const int FAsp  = 7;
	const fval asp = 100;
//	const fval nap = 0;
const int FLong = 8;
	const fval lng = 100;
//	const fval sht = 0;
const int FHigh = 9;
	const fval hgh = 100;
	const fval mid = 50;
	const fval low = 0;
const int FBack = 10;
	const fval frt = 100;
	const fval cnt = 50;
	const fval bak = 0;
const int FRound = 11;
	const fval rnd = 100;
//	const fval nrd = 0;
const int FDouble = 12;

#define FVW syl, pal, vwl, vce, 0, 0, 0, 0, 0
#define BVW syl, vel, vwl, vce, 0, 0, 0, 0, 0
#define FGL nsl, pal, vwl, vce, 0, 0, 0, 0, 0
#define BGL nsl, vel, vwl, vce, 0, 0, 0, 0, 0
#define CNS nsl

FVec Word::FCon[NSEG] = {
    { BVW, low, cnt }, // a
    { CNS, blb, stp, vce }, // b
    { CNS, alv, afr, vls }, // c
    { CNS, alv, stp, vce }, // d
    { FVW, mid, frt }, // e
    { CNS, lbd, frc, vls }, // f
    { CNS, vel, stp, vce }, // g
    { CNS, glo, frc, vls }, // h
    { FVW, hgh, frt }, // i
    { CNS, alv, afr, vce }, // j
    { CNS, vel, stp, vls }, // k
    { CNS, alv, apr, vce, 0, 0, lat }, // l
    { CNS, blb, stp, vce, nas }, // m
    { CNS, alv, stp, vce, nas }, // n
    { BVW, mid, bak, rnd }, // o
    { CNS, blb, stp, vls }, // p
    { CNS, glo, stp, vls }, // q
    { CNS, rfl, apr, vce, 0, ret }, // r
    { CNS, alv, frc, vls }, // s
    { CNS, alv, stp, vls }, // t
    { BVW, hgh, bak, rnd }, // u
    { CNS, lbd, frc, vce }, // v
    { BGL, hgh, bak, rnd, blb }, // w
    { CNS, vel, frc, vls }, // x
    { FGL, hgh, frt }, // y
    { CNS, alv, frc, vce } // z
//  { CNS, vel, stp, vce, nas }, // (ng)
//  { CNS, vel, frc, vce }, // (gamma)
};

// true if segment is a vowel
inline bool vowel( FP p )
{
    return ( p[FStop] <= vwl );
}

// this is to make FCon more transparent
void Word::applyRedundancyRules()
{
    for ( int i = 0; i < NSEG; i++ )
    {
        if ( vowel(FCon[i]) )
        {
                 if ( FCon[i][FHigh] == hgh ) FCon[i][FStop] = hvl;
            else if ( FCon[i][FHigh] == mid ) FCon[i][FStop] = mvl;
            else if ( FCon[i][FHigh] == low ) FCon[i][FStop] = lvl;
            else assert( false );
        }

        if ( !vowel(FCon[i]) )		// harmless
        {
            FCon[i][FHigh] = hgh;
        }
    }
}

// the sole constructor
Word::Word( const char *w )
{
    outlen = strlen( w );
    assert( outlen > 0 && outlen < ELEN );
    assert( w[0] >= BASE_LOW );
    strcpy( out, w );
    fconvert();
}

// Display external representation sequence corresponding to
// an individual phoneme.
int Word::flush( short wi, char aback[50], int abackcount )
//void Word::flush( short wi )
{
    assert( wi >= 0 && wi < len );
    short o1 = ind[wi];               // pointers to w.out
    short o2 = ind[wi+1];
    for ( int t = 0; t < TAB; t++ )
    {
        if ( o1 != o2 )
            {
            //printf( "%c", out[o1++] );
            o1++;
            aback[abackcount]=out[o1-1]; abackcount++;
            }             //This palce could easily have some mistakes!
        else
            {
            //printf( " " );
            aback[abackcount]=' '; abackcount++;
            }
    }
    return(abackcount);
}

// Display whole record.
void Word::showAll()
{
    //printf( "    out: |%s|\n", out );
    //printf( " outlen: %d\n", outlen );
    //printf( "         " );
    for ( int i = 0; i <= len; i++ )
    {
        //printf( "%d ", ind[i] );
    }
    //printf( "\n" );
    for ( int i = 0; i < len; i++ )
    {
        //printf( "         " );
        for ( int f = 0; f < FT_LEN; f++ )
        {
            //printf( "%4.1d", phon[i][f] );
        }
        //printf( "\n" );
    }
    //printf( "    len: %d\n", len );
}

// Convert the external string representation into a feature matrix.
void Word::fconvert()
{
    int j = -1;
    for ( int seg = 0; seg < outlen; seg++ )
    {
        char c = out[seg];
        if ( c >= BASE_LOW )
        {
            j++;
            for ( int f = 0; f < FT_LEN; f++ )
            {
                phon[j][f] = FCon[ c - BASE_LOW ][f];
            }
            ind[j] = seg;
        }
        else
        {
            modify( phon[j], c );
        }
    }
    ind[j+1] = outlen;
    len = j+1;
    assert( j+1 < PLEN );
}

// modifies feature matrix
void Word::modify( FP p, char c )
{
    switch ( c )
    {
        case 'A': p[FAsp] = asp;        // "Aspirated"
            break;
        case 'C': p[FBack] = cnt;       // "Central"
            break;
        case 'D': p[FPlace] = dnt;      // "Dental"
            break;
        case 'F': p[FBack] = frt;       // "Front"
            break;
        case 'H': p[FLong] = lng;       // "loHng"
            break;
        case 'L':                       // "Lax" (ignored)
            break;
        case 'N': p[FNasal] = nas;      // "Nasal"
            break;
        case 'P': p[FPlace] = pal;      // "Palatal"
            break;
        case 'S': p[FStop] = frc;       // "Spirant"
            break;
        case 'V': p[FPlace] = pav;      // "palato-alVeolar"
            break;
        case 'X': p[FRetro] = ret;      // "retrofleX" added by SD 8-31-06
            break;
        default:
           // cout << "I don't know " << c << endl;
            assert( false );
    }
}

// deal with double articulations
int places( FP p1, FP p2, int vec[12] )
{
    //for(int test=0;test<12;test++) {printf("%d",coeff[test]);}; printf("\n"); This means the values are also in here!

    int pd = abs( p1[FPlace] - p2[FPlace] );

    if ( p1[FDouble] ) {
    
    	if ( pd > abs( p1[FDouble] - p2[FPlace]) ) {
        	pd = abs( p1[FDouble] - p2[FPlace]);
        }
        
        }

    if ( p2[FDouble] )
//        pd = min( pd,  abs( p1[FPlace] - p2[FDouble] ) );

			if ( pd > abs( p1[FPlace] - p2[FDouble] ) ){
				pd = abs( p1[FPlace] - p2[FDouble] );
			}

    if ( p1[FDouble] && p2[FDouble] )
//        pd = min( pd,  abs( p1[FDouble] - p2[FDouble] ) );
		if ( pd > abs( p1[FDouble] - p2[FDouble] ) ){
				pd = abs( p1[FDouble] - p2[FDouble] );
			}

    //cout<<gP::SalCoef[FPlace]<<endl; //This shows that SalCoef is jsut like a vector
    
    //return pd * gP::SalCoef[FPlace];
    return pd * vec[FPlace];
}

// difference between segments for a given feature
#define diff(f)		( ( d = p1[f] - p2[f] ) > 0 ? d : -d )

// compute difference wrt specific feature
//#define Consider(f)	dist += diff(f) * gP::SalCoef[f]

//reproduce a function would be too complicated, let's put the code back in the functinos. OK!?

// compute distance between two feature vectors
int ladDist( FP p1, FP p2, int vec[12] )
{
    //for(int test=0;test<12;test++) {printf("%d",coeff[test]);}; printf("\n"); This means the value is also in here!
    
    int dist = 0;
    fval d;

    if ( vowel(p1) && vowel(p2) )
    {
        //Consider(FSyl);
        dist += diff(FSyl) * vec[FSyl];
        //Consider(FNasal);
        dist += diff(FNasal) * vec[FNasal];
        //Consider(FRetro);
        dist += diff(FRetro) * vec[FRetro];
        //Consider(FHigh);
        dist += diff(FHigh) * vec[FHigh];
        //Consider(FBack);
        dist += diff(FBack) * vec[FBack];
        //Consider(FRound);
        dist += diff(FRound) * vec[FRound];
        //Consider(FLong);
        dist += diff(FLong) * vec[FLong];
    }
    else
    {
        //Consider(FSyl);
        dist += diff(FSyl) * vec[FSyl];
        //Consider(FStop);
        dist += diff(FStop) * vec[FStop];
        //Consider(FVoice);
        dist += diff(FVoice) * vec[FVoice];
        //Consider(FNasal);
        dist += diff(FNasal) * vec[FNasal];
        //Consider(FRetro);
        dist += diff(FRetro) * vec[FRetro];
        //Consider(FLat);
        dist += diff(FLat) * vec[FLat];
        //Consider(FAsp);
        dist += diff(FAsp) * vec[FAsp];
        dist += places( p1, p2, vec );		// was: Consider(FPlace);
    }

    return dist;
}

// compute score for substitution
int sigmaSub( Word *wA, short iA, Word *wB, short iB, int vec[12] )
{
    if(iA==0 || iB==0) return NoScore; //bug fix
    FP pA = wA->phon[wA->len-iA];
    FP pB = wB->phon[wB->len-iB];
    
    int score = gP::MaxScore - ladDist( pA, pB, vec );

    if ( vowel(pA) )
        score -= gP::VwlDecr;
    if ( vowel(pB) )
        score -= gP::VwlDecr;
    
    return score;
}

// compute score for expansion/compresion
int sigmaExp( Word *wA, short iA, Word *wB, short i1B, short i2B, int vec[12] )
{
    // bug fix 
    
    //for(int test=0;test<12;test++) {printf("%d",coeff[test]);}; printf("\n");
    if(iA==0 || i2B==0) return NoScore; //bug fix
    
    if ( i1B == 0 )
        return NoScore;

    FP pA  = wA->phon[wA->len-iA];
    FP p1B = wB->phon[wB->len-i1B];
    FP p2B = wB->phon[wB->len-i2B];

    int d1 = ladDist( p1B, pA, vec );
    int d2 = ladDist( p2B, pA, vec );

    if ( ( d1 == 0 ) || ( d2 == 0 ) )
        return NoScore;

    int score = gP::MaxCmpScore - (d1 + d2);

    if ( vowel(p1B) || vowel(p2B) )
        score -= gP::VwlDecr;
    if ( vowel(pA) )
        score -= gP::VwlDecr;
    return score;
}

// compute score for insertion/deletion
int sigmaSkip( Word *w, short i , int skippen)
{
   // FP p = w->phon[w->len-i];

    //return -gP::SkipCost;
    return skippen;
}

// check if they are identical
int sigmaIdent(  Word *wA, short iA, Word *wB, short iB )
{
    FP pA = wA->phon[wA->len-iA];
    FP pB = wB->phon[wB->len-iB];

    for ( int f = 0; f < FT_LEN; f++ )
    {
        if ( pA[f] != pB[f] )
            return 0;
    }

    return 1;
}

