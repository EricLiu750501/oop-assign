#include "RandomNum.h"
#include <iostream>

using namespace std;

RandomNum::RandomNum(int seed) {

    srand(seed);

}


/* [low, high]*/
int
RandomNum::getRandomNum(int low, int high) const {

    int k;
    double d;

    d = (double) rand()/((double)RAND_MAX+1);
    k = (int)(d*(high-low+1));
    return low+k;

}


RandomNum& f() {
    RandomNum R;
    return R;
}


int main() {
     
   RandomNum R;

   

}