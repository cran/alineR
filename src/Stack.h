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

#ifndef STACK_H
#define STACK_H

#include "glob.h"
#include "Word.h"

class Stack
{
public:
    void clear() { top = 0; }
    void push( short i1, short i2 = NUL );
    void pop( short k = 1 ) { top -= k; }
    void show();
    //void showAlign( Word *w, short row);   // Modified by G.S
    void showAlign( Word *w, short row, char aback[50] );

private:
    short stack[2][MAXL];	// trace description
    short top;			// pointer to Stack

    friend short bonus( Stack* );
    friend bool allowed( Stack* );
};

#endif
