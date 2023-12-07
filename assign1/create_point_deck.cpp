#include <iostream>
using namespace std;

const int kNPip=13;
const int kNSuit=4;
const int kNCards=52;
const int kCardWidth=11;
const int kCardHeight=11;

static char deck[kNCards][kNSuit][4] = {
  {
    "1S", "1H", "1D", "1C"
  }, 
  {
    "2S", "2H", "2D", "2C"
  }, 
  {
    "3S", "3H", "3D", "3C"
  }, 
  {
    "4S", "4H", "4D", "4C"
  }, 
  {
    "5S", "5H", "5D", "5C"
  }, 
  {
    "6S", "6H", "6D", "6C"
  }, 
  {
    "7S", "7H", "7D", "7C"
  }, 
  {
    "8S", "8H", "8D", "8C"
  }, 
  {
    "9S", "9H", "9D", "9C"
  }, 
  {
    "10S", "10H", "10D", "10C"
  }, 
  {
    "JS", "JH", "JD", "JC"
  }, 
  {
    "QS", "QH", "QD", "QC"
  }, 
  {
    "KS", "KH", "KD", "KC"
  }, 
};


int main() {
  cout << atoi("12q");
    // cout << "{";
    // for (int i=0;i<kNCards;i++) {
    //     for (int j=0;j<kNSuit;j++) {
    //         cout << "\"" << deck[i][j] << "\"" << ", ";
    //     }
    // }
    
}