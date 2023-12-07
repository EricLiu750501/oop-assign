/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJTest.cc
   PURPOSE
     Homework assignment for simulating card game
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
	 Ming-Te Chi - Oct 1, 2023: revised.
***************************************************************************/

/* $Log: BJTest.cc,v $
 * */

extern "C" {
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackPlayer.h"

/**
 * Print my id 
 */

void
PrintMyID(const char* studId) {

	char* str = new char[sizeof(studId)+5];
	sprintf(str, "ID: %s", studId);
	AnsiPrint(str, yellow, red, true, true);
	cout << endl << endl;
	delete [] str;

}


/**
 * PrintUsage
 */

void
PrintUsage(const char* progName) {

	assert(progName);
	cout << "Usage: " << progName << " [Seed] [ShowFirst(0/1)]" << endl;

}

/**
 * Main Function Call
 */

int
main(int argc, char **argv) {

    bool showFirst = false;
    long seed = 0;

    if (argc==3) {
		showFirst = atoi(argv[2]); // the third argument shows the first card
    	seed=atoi(argv[1]);
	} else if (argc>1) {
		seed=atoi(argv[1]);
    } else {
        PrintUsage(argv[0]);
		exit(-1);
	}

    srand(seed);

    // put your code here
    BJackPlayer bjplayer("BJPlayer");

    Card c = Card(34);
    c.print();    
 
    bjplayer.start();
    bjplayer.openFirstCard(showFirst);
    while (bjplayer.totalPoints() <= 21) {
      bjplayer.addCard();
    }    

    bjplayer.showCards();

    // bjplayer.start();
    // bjplayer.openFirstCard(showFirst);
    // bjplayer.addCard();
    // bjplayer.showCards();
    // string act;
    // while (cin >> act ) {
    //   if (act == "add") {
    //     bjplayer.addCard(); 
    //   }
    //   else if (act == "stop") {
    //     break;
    //   }
    //   bjplayer.showCards();
    //   if (bjplayer.totalPoints() > 21 ) {
    //     cout << "You Lose!";
    //     break;
    //   }
    //   else if(bjplayer.totalPoints() == 21 ) {
    //     cout << "How Lucky!";
    //     break;
    //   }
    // }s
    
    cout << "Total points: " << bjplayer.totalPoints() << "\n";
    PrintMyID("111703044");
    
    return 0;
}

// 如果現在21point pick ace, it will 22 or 32?