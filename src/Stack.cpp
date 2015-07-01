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

#include "Stack.h"
#include "Word.h"

void Stack::push( short i1, short i2 )
{
    assert( top >= 0 && top < MAXL );
    stack[0][top] = i1;
    stack[1][top] = i2;
    top++;
}

// Output disabled by G.S.
void Stack::show()
{
    for ( short row = 0; row <= 1; row ++ )
    {
        for ( short ind = 0; ind < top; ind++ )
        {
            //printf( "%4d", stack[row][ind] );
        }
        //printf( "\n");
    }
}


void Stack::showAlign( Word *w, short row, char aback[50] )
//void Stack::showAlign( Word *w, short row)
{
    short len = w->phlen();
    int abackcount=0;

    // Modified by G.S.
    for ( short ind = 0; ind < top; ind++ )
    {
        short i = stack[row][ind];		// pointer to w.ind
        switch (i) {
            case NUL: //printf( "-   " );  
                      aback[abackcount]='-';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      break;
            case LIM: //printf( "|   " );
                      aback[abackcount]='|';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      break;
            case DUB: //printf( "<   " );
                      aback[abackcount]='<';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      aback[abackcount]=' ';abackcount++;
                      break;
            default:  abackcount=(w->flush( len - i, aback, abackcount )); 
          
        }
        aback[abackcount]='\0';
    }
    //printf( "\n");
}

