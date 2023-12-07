/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"
#include <algorithm>
#include <random>
using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str,yellow,red, true, true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}





/**
 * Main Function Call
 */
int
main(int argc, char **argv) {

  int ncards=0;  // number of cards to draw 
  if (argc==3) {
    long seed=atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  } else if (argc==2) {
    ncards=atoi(argv[1]);
  } else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  

  // You are asked to fill in a few missing statements here
  if (ncards > 52 ) {  // exceed cards
    cout << "Sorry, number of cards can not be greater than 52." << endl;
    exit(-1);
  }


  while(ncards >= 5) {
    show_card_in_row(5, pick_card(5));
    ncards -= 5;
  }
  if (ncards) show_card_in_row(ncards, pick_card(ncards));
//  show_card(10, 'D');


  // Print my id at the end of the program
  PrintMyID("111703044");

  return 0;

}
