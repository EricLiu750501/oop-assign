/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
// #include "CardPat.h"
#include "BJackPlayer.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(const char *player_name) {

    // Card hand[kNhand];   
    // cout << hand[0].getID();
    deck[kNCards] = {};
    hand_count = 0;
    my_name = player_name;
}

// start the black jack game with a new card
void
BJackPlayer::start(void){
    hand_count = 0;
    int rnd = rand() % 52;
    deck[rnd] = 1;
    hand[hand_count].setID(rnd);
    hand_count++;
}

// add a new card to the current hand.
// need to protect the array from overflowing
void 
BJackPlayer::addCard() {
  if (hand_count >= kNhand) return;

  int rnd = rand() % 52;
  while(deck[rnd]) {
    rnd = rand() % 52;
  }
  deck[rnd] = 1;

  hand[hand_count].setID(rnd);
  hand_count++;
 
}

// get the total points of the current hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

int
BJackPlayer::totalPoints(void) const {
  int totalP = 0;
  for (int i=0;i<hand_count;i++) {
    totalP += hand[i].getPoint();
  }
  

  return totalP;


}

// set the status of the first card

void
BJackPlayer::openFirstCard(bool open) {
  showfirst = open;
}

// print the current hand to the screen graphically

void 
BJackPlayer::showCards() const {
  
  char graphical_card[kCardHeight][kCardWidth+1] = {};
  int hand_cnt = hand_count;  

  while (hand_cnt > 0) {
      for (int i=0;i<kCardHeight;i++) {
        for (int c=0;c < min(hand_cnt, kNCardPerRow) ; c++) {
            int cardPip = hand[c].getPip();

            if (c == 0) {
              printf("%c ", player[i]);
              if (!showfirst) {
                if (hand_cnt == hand_count /* the first card */) {
                    cardPip = 13;              
                }
              }
            }

            

            char cardSuit = cardAbbrev[hand[c].getSuit()];
            for (int j=0;j< kCardWidth;j++) {
                graphical_card[i][j] = card[cardPip][i][j] == 'x' ? cardSuit : card[cardPip][i][j];

            }
            AnsiPrint(graphical_card[i], cardColor[hand[c].getSuit()], white);
            printf(" ");
            
           
            
      }
      printf("\n");
    }
    printf("\n");
    hand_cnt -= kNCardPerRow;
  }

  
}

