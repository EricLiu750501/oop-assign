/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackDealer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

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
#include "BJackDealer.h"

#include "CardPat.h"
#include <random>
#include <algorithm>

// constructor 
// nDeck is the number of standard decks that the dealer will deal with
BJackDealer::BJackDealer(int nSet) {
  assert(nSet > 0);

  gameCard = new int[nSet * 52];
  gameCardMAX = nSet * 52;
  gameCardRemaining = gameCardMAX - 1;  // 0 ~ nSet*52-1
  nCards = 0;
}

// distribute a card to the player
int
BJackDealer::giveCard() {
  return gameCard[ gameCardRemaining-- ];
}

// give the dealer one card unconditionally
void 
BJackDealer::addCard() {
  myCard[nCards++]= Card(this->giveCard());
  
}

// give the dealer as many cards as necessary to exceed the player 
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

void
BJackDealer::addCards(int oppTotal) {
  // int myT = 0;
  // int myP;
  // int OneS = 0;
  // int myT2 = 0;
  // int OneS2 = 0;
  // for (int i=0;i<nCards;i++) {
  //   myP = myCard[i].getPip()+1;
  //   if (myP == 1) {
  //     OneS++;
  //   }
  //   else if (myP > 10) {
  //     myP = 10;
  //   }
  //   myT += myP;
  // }
  // myT2 = myT;
  // OneS2 = OneS;
  // while (myT <= oppTotal) {
  //   for (int i=0;i<=OneS;i++) {
  //     if (myT + 10 > 21) {
  //       break;
  //     }
  //     else if (myT + 10 > oppTotal) {
  //       myT += 10;
  //       return ;
  //     }
  //   }
  //   this->addCard();
  //   int newCardPoint = myCard[nCards-1].getPip() + 1;
  //   if (newCardPoint == 1) {
  //     OneS++;
  //   }
  //   else if (newCardPoint > 10) {
  //     newCardPoint = 10;
  //   }
  //   myT += newCardPoint;
  //   if (myT > oppTotal) {
  //     return ;
  //   }  
  // }

  while (this->totalPoints() < oppTotal) {
    this->addCard();
  }

}

// Determine who has win the game.
// The total points that the dealer has should be greater than 
// the player at the point this function is called.

result
BJackDealer::judge(int oppTotal) const {
  int dealerP = this->totalPoints();

  if (oppTotal > 21) {
    if (dealerP > 21) {
      return result::tie;
    }else return result::win;
  }
  else {
    if (dealerP > 21) return result::lose;
    if (oppTotal == dealerP) {
      return result::tie;
    }
    else if (oppTotal > dealerP) {
      return result::lose;
    }
    else {
      return result::win;
    }
  }
}

// start a new game
// before starting a new game, check if there are enough cards left for 
// the next game.

void
BJackDealer::start(void) {
  int enough2play = (gameCardRemaining+1) >= (17 * (gameCardMAX / 52));
    
    
  if (!enough2play) {
    this->shuffle(rand());
    this->shuffle();
    cout << "\n=======SHUFFLE=========\n";
    gameCardRemaining = gameCardMAX - 1;
  }
    this->nCards = 0;
    firstCardOpened = false;

}

// shuffle the deck of cards
void 
BJackDealer::shuffle(void) {
  for (int i=0;i<gameCardMAX;i++) {
    gameCard[i] = i % 52;
  }
  std::shuffle(gameCard, gameCard+gameCardMAX, std::default_random_engine(runSeed));

}

// reset the seed before shuffling
void
BJackDealer::shuffle(long seed) {
  this->runSeed = seed;
}

// open the dealer's first card 
void 
BJackDealer::openFirstCard(void) {
  this->firstCardOpened = true;
}

// show the dealer's hand to the screen
void 
BJackDealer::showCards(void) const {
  // cout << "Dealer Card:\n";
  // for (int i=0;i<nCards;i++) {
  //   myCard[i].print();
  // }
  // cout << "\n\n";
  char name[7] = "Dealer"; 
  unsigned char s,p;
  char line[kCardWidth+1];
  int curCard=0, lastCard;
  
  while(curCard < nCards) {
    for(int i=0;i<kCardHeight;i++) {
      
      lastCard = curCard+kNCardPerRow > nCards ?  nCards : curCard+kNCardPerRow;
      if (i < 6) {
	cout << name[i] << " ";
      } else {
	cout << "  ";
      }
      for(int j=curCard;j<lastCard;j++) {
	s=myCard[j].getID()%kNSuit;
	p=myCard[j].getID()/kNSuit;
	if ((j==0)&&(firstCardOpened==false)) 
	    p=13;
	for(int k=0;k<kCardWidth;k++) {
	  line[k]=card[p][i][k];
	  if (line[k]=='x') 
	    line[k]=cardAbbrev[s];
	}
	line[kCardWidth]='\0';
	AnsiPrint(line,cardColor[s],white);
	cout << " ";
      }
      cout << endl;
    }
    curCard=lastCard;
  }
}

int 
BJackDealer::totalPoints() const {
  
    int total=0;
    int point;
    int credit=0;

    for(int i=0; i<nCards; i++) {
	point=myCard[i].getPip()+1;
	if (point==1) {
	    credit++;
	} else if (point>10) 
	    point=10;
	total += point;
    }
    
    // add points depending on how many aces we have
    for(int i=0; i<credit; i++) {
	if (total+10 <=  21) {
	    total += 10;
	} else {
	    break;
	}
    }

    return total;
}
