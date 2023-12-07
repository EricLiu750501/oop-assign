/*
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
0                                         I                            
1                       I                                              
2                                                                      
3                                                                      
4                                                 I                    
5                                                                      
6   I                                                                  
7     I                                                                
8                                               X         X            
9                                                                      
0                                                                      
1                                                                      
2                                                                      
3                                                                      
4                                       I         I                    
5                     I                                                
6                                                               X      
7                         I                                            
8                 X                                                 X  
9                   I                                                  
------------------------------------------------------------------------

---35---
|       |
2       |
0       |
|-------

*/

#ifndef _WORLD_H
#define _WORLD_H

#include "AnsiPrint.h"
#include "Creature.h"
#include "RandomNum.h"

const int WORLD_WIDTH = 35;
const int WORLD_LENGTH = 20;
const int sleepT = 50000 * 1; // stop time per display
enum direction {east, south, west, north};

class World {
    public:
        // Constructor
        World(int innp, int s);
        
        // Loop the ALife game
        void mainLoop(int displayinterval);
        
    private:
        int numPasses;
        RandomNum rnd;
        Creature *theWorld[WORLD_LENGTH][WORLD_WIDTH];

        // display
        void showFrame();
        
        // update per Pass
        void Fresh();

        // Test if x, y out of the world
        bool BoundaryTest(int x, int y);

        // Reference dx, dy: (1, 0), (0, 1), (-1, 0), (0, -1)
        void rndPos(int &dx, int &dy);

};













#endif