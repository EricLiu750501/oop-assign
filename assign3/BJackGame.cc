/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackGame.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackGame.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer &bjp, BJackDealer &bjd)
 : menu(sizeof(menuItems)/sizeof(char *),menuItems), bjplayer(bjp), bjdealer(bjd) {
  bjdealer.start();
  bjplayer.start();
  bjdealer.shuffle(rand());
  bjdealer.shuffle();

  isGaming = false;
  playerCredits = initCredit;
  dealerCredits = initCredit;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
BJackGame::oneRun() {
  menu.print();
  int ans = menu.getAnswer();


  if (ans == o_quit) {
    return false;
  }
  else if (ans == o_more) {
    this->moreCard();    
  }
  else if (ans == o_enough) {
    bjdealer.openFirstCard();
    this->enough();
  }
  else if (ans == o_restart) {
    this->restart();
  } 

  bjplayer.openFirstCard();
  bjplayer.showCards();
  bjdealer.showCards();
  return true;
}

// give the player one more card
// check if we can do that first
void 
BJackGame::moreCard() {
  //check
  if ( isGaming == false ) {
    cout << "Game Over\n";
    return ;
  }
  if (bjplayer.totalPoints() > 21) {
    cout << "You are over 21 already\n";
    return ;
  }
  newCard.setID(bjdealer.giveCard());
  bjplayer.addCard( newCard );
  isGaming = true;

}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void 
BJackGame::enough() {
  if ( isGaming == false ) {
    cout << "Game Over\n";
    return;
  }

  // dealer add
  int playerPoint = bjplayer.totalPoints();
  if (playerPoint > 21) {
    // dealer at least 17
    bjdealer.addCards( 17 );
  }
  else if (playerPoint == 21) {
    bjdealer.addCards(21);
  }
  else {
    // add until dealer win
    bjdealer.addCards( playerPoint + 1 );
  }
  isGaming = false;
  if (isGaming == false) {
      result R = bjdealer.judge(bjplayer.totalPoints());
      if (R == tie) {
        // Tie
        cout << "It's a Tie.";
      }
      else if (R == win) {
        // Dealer Win
        playerCredits -= betCredit;
        dealerCredits += betCredit;
        cout << "I win. Try again.";
      }
      else if (R == lose) {
        // Dealer Lose
        cout << "You win. Good job.";
        playerCredits += betCredit;
        dealerCredits -= betCredit;

      }
      printf("(You have %d Credits, I have %d Credits.)\n", playerCredits, dealerCredits);
 
  
    }
  
  

}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void 
BJackGame::restart() {
  if (playerCredits<=0 || dealerCredits<=0) {
    cout << "Sorry. Game over. No loan here.\n";
    return;
  }
  if ( isGaming == true) {
    cout << "Game is not over yet. Choose 'enough' to end a game\n";
    return;
  }
  bjdealer.start();
  bjplayer.start();
  
  newCard.setID(bjdealer.giveCard());
  bjplayer.addCard( newCard );

  newCard.setID(bjdealer.giveCard());
  bjdealer.addCard(  );
  
  newCard.setID(bjdealer.giveCard());
  bjplayer.addCard( newCard );

  newCard.setID(bjdealer.giveCard());
  bjdealer.addCard(  );
  
  isGaming = true;
}




