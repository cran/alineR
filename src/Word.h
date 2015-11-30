// Copyright (c) 2015 by Sean Downey
// Authors: Sean Downey (sean@codexdata.com) and Guowei Sun (gwsun@umd.edu)
// This software is distributed under GPL-3.
// Includes modified C++ code originally developed by Greg Kondrak (c) 2000

// Copyright (c) 2000 by Grzegorz Kondrak
//
// Permission is granted for anyone to copy, use, or modify this program
// for purposes of research or education, provided this copyright notice
// is retained, and note is made of any changes that have been made.
// This program is distributed without any warranty, express or implied.
// As this program was written for research purposes only, it has not been
// tested to the degree that would be advisable in any important application.
// All use of this program is entirely at the user's own risk.

#ifndef WORD_H
#define WORD_H  

#include "glob.h"
#include <stdlib.h>

const int NoScore = -99999;

const int FT_LEN = 13;          // number of features in the feature table
typedef short fval;             // feature value
typedef fval FVec[FT_LEN];      // feature vector
typedef fval *FP;               // new

// global parameters
class gP
{
public:
    static float ScoreMargin;		// margin of tolerance
    static int MaxScore;		// maximal substitution score
    static int MaxCmpScore;		// maximal compression score
    static int SkipCost;		// penalty for insertion/deletion
    static int VwlDecr;			// vowel handicap
    static int SalCoef[FT_LEN];		// salience coeficients
};

class Word
{
    friend int sigmaSub( Word *wA, short iA, Word *wB, short iB, int vec[12] );
    friend int sigmaSkip( Word *w, short i, int skippen);
    friend int sigmaExp( Word *wA, short iA, Word *wB, short i1B, short i2B, int vec[12]);
    friend int sigmaIdent( Word *wA, short iA, Word *wB, short iB );

public:
    Word( const char *w );
    short phlen()       { return len; }
    void showCode()     { printf( "%s ", out ); }

    //void flush( short i );     // flushes out code corresponding to segment i
    int flush( short i, char aback[50], int abackcount ); 
    void showAll();            // display all fields

    static void applyRedundancyRules(); // operates on FCon

private:
    static FVec FCon[NSEG];    // feature assignments for individual segments

    char out[ELEN];     // external (mixed) representation
    short outlen;       // external length
    short ind[PLEN];    // pointers to external representation
    FVec phon[PLEN];    // feature matrix
    short len;          // internal (phonemic) length

    void fconvert();                 // converts segments into feature matrix
    void modify( FP p, char c );  // modify a feature vector
};

const int FACTOR = 100;             // for emulation of floats by ints
inline int conv( float f ) { return (int) f * FACTOR; }
inline float deconv( int k ) { return (float) k / FACTOR; }

#endif
