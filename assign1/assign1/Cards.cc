/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.cc
   NOTE
     You are asked to design this module.
     You need to draw the given number of cards and print them out.
     Assume that you are given a deck of 52 cards. The cards do not reappear.
     That is, you do not put a card back into the deck after it is drawn.
***************************************************************************/
#include "Cards.h"
#include <cstring>
#include <iostream>
using namespace std;
#include "AnsiPrint.h"


void show_card_in_row(int card_quantity, int *card_in_a_row) {
  int point;
  char suit;

  char new_cards[5][kCardHeight][kCardWidth+1] = {};
  // for (int c=0;c<card_quantity;c++) {
  //   point = card_in_a_row[c]/4 + 1;
  //   char suit_box[5] = "SHDC";
  //   suit = suit_box[card_in_a_row[c] % 4];
  //   for (int i=0;i<kCardHeight;i++) {
  //     for (int j=0;j<kCardWidth;j++) {
  //       new_cards[c][i][j] = card[point-1][i][j]=='x' ? suit : card[point-1][i][j];

  //     }
  //   }
  // }
  
  // for (int i=0;i<kCardHeight;i++) {
  //     for (int c=0;c<card_quantity;c++) {
  //       AnsiPrint(new_cards[c][i], card_in_a_row[c] % 4 == 0 || card_in_a_row[c] % 4 == 3 ? black : red, white);
  //       cout << " ";
  //     }
  //   cout << endl;
  // }
  for (int i=0;i<kCardHeight;i++) {
      for (int c=0;c<card_quantity;c++) {
            point = card_in_a_row[c]/4 + 1;
    char suit_box[5] = "SHDC";
    suit = suit_box[card_in_a_row[c] % 4];
        for (int j=0;j<kCardWidth;j++) {
          new_cards[c][i][j] = card[point-1][i][j]=='x' ? suit : card[point-1][i][j];

        }
        AnsiPrint(new_cards[c][i], card_in_a_row[c] % 4 == 0 || card_in_a_row[c] % 4 == 3 ? black : red, white);
        cout << " ";
      }
    cout << endl;
  }
   
  
   
  delete[] card_in_a_row;
}


// NOT_USED
void show_card(int point, char type) {
  char new_card[kCardHeight][kCardWidth*5+5] = {};
  for (int i=0;i<kCardHeight;i++) {
    for (int j=0;j<kCardWidth;j++) {
      new_card[i][j] = card[point-1][i][j]=='x' ? type : card[point-1][i][j];

    }
  }

  // for (int i=0;i<kCardHeight;i++) {
  //   for (int j=0;j<kCardWidth;j++) {
  //     cout << new_card[i][j];
  //   }
  //   cout << endl;
  // }


  for (int i=0;i<kCardWidth;i++) {
    AnsiPrint(new_card[i], (type == 'D'|| type == 'H') ? red : black, white, false, false);     
    if (i != kCardWidth-1)cout <<endl;
  }
  

}

int *record_picked = new int[52]();

int *pick_card(int card_quantity) {
  int *card_row = new int[card_quantity];
   for (int i=0;i<card_quantity;i++) {
    card_row[i] = rand() % 52;
    while(record_picked[card_row[i]] == 1) {
          card_row[i] = rand() % 52;
    }
    record_picked[card_row[i]] = 1;
  }
  return card_row;

  // return card_num % 4 == 0 ? deck[card_num/4 - 1][3] : deck[card_num/4][card_num % 4 - 1]; 
}
