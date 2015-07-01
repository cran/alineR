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

#ifndef GLOB_H
#define GLOB_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include <iostream>
//#include <iomanip>
//#include <fstream>

#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>

const int MAXL = 40;        // max length of an input word
const int LINELEN = 800;    // max input line length
const int MAXS = 2400;      // max input size (in lines)
const int BASE_UPP = 65;    // = ord('A')
const int BASE_LOW = 97;    // = ord('a')
const int OFFSET = 32;      // = ord('a') - ord('A')
const int NUL = -1;         // empty alignment
const int LIM = -2;         // border character (for local comparison)
const int DUB = -3;         // double linking (for compression)
const int TAB = 4;          // output space for one phoneme
const int PLEN = 42;        // max word phonemic length (+2)
const int ELEN = 30;        // max word representation length
const int NSEG = 26;        // number of recognized segments

#endif
