#include "World.h"
#include <iostream>
#include <unistd.h>
#include "Goat.h"
#include "Grass.h"
#include "Creature.h"


using std::cout;
World::World(int innp, int s) :rnd(s) {
    numPasses = innp;
    int setx=0, sety=0;
    
    for (int i=0;i<WORLD_LENGTH;i++) {
        for (int j=0;j<WORLD_WIDTH;j++) {
            theWorld[i][j] = new Creature(i, j);
        }
    } 
    // 隨機 Goat 位置 替換 theWorld
    for (int i=0;i<InitialGoat;i++) {
        setx = rnd.getRandomNum(0, WORLD_WIDTH-1);
        sety = rnd.getRandomNum(0, WORLD_LENGTH-1);
        delete theWorld[sety][setx];
        theWorld[sety][setx] = new Goat(setx, sety);
    }
    // 隨機Grass 位置 替換 theWorld
    for (int i=0;i<InitialGrass;i++) {
        setx = rnd.getRandomNum(0, WORLD_WIDTH-1);
        sety = rnd.getRandomNum(0, WORLD_LENGTH-1); 
        delete theWorld[sety][setx];
        theWorld[sety][setx] = new Grass(setx, sety);
    }
    
}


void World::mainLoop(int displayinterval) {
    for (int i=0;i<numPasses;i++) {
        Fresh();
        if (i % displayinterval == 0) {
            system("clear");
            cout << "[\t" << i << "]" << "\n";
            showFrame();
            usleep(sleepT);
            
       }
       for (int i=0;i<WORLD_LENGTH;i++) {
            for (int j=0;j<WORLD_WIDTH;j++) {
                theWorld[i][j]->Pass();
            }
        }
    }
}

void World::showFrame() {
    cout << " ";
    for (int i=0;i<WORLD_WIDTH;i++) {
        cout << " " << i%10;
    }
    cout << "\n";
    
    for (int i=0;i<WORLD_LENGTH;i++) {
        cout << i%10 << " ";
        for (int j=0;j<WORLD_WIDTH;j++) {
            theWorld[i][j]->Print();
            cout << " ";
        }
        cout << "\n";
    }

    for (int i=0;i<WORLD_WIDTH*2+2;i++) {
        cout << "-";
    }
    cout << "\n";
}

void World::Fresh() {
    int dx, dy;// Random 位移量

    // 先判斷死了沒
    for (int i=0;i<WORLD_LENGTH;i++) {
        for (int j=0;j<WORLD_WIDTH;j++) {
            if(theWorld[i][j]->Died()) {
                delete theWorld[i][j];
                theWorld[i][j] = new Creature(i, j);
            }
        }
    }

    // 生小孩
    for (int i=0;i<WORLD_LENGTH;i++) {
        for (int j=0;j<WORLD_WIDTH;j++) {
            if (theWorld[i][j]->ifActed()) {
                continue;
            }
            if (theWorld[i][j]->ifGenerate()) {
                rndPos(dx, dy);
                if (BoundaryTest(i+dx, j+dy)) {
                    if(typeid(*theWorld[i+dx][j+dy]) == typeid(Grass)) {
                        theWorld[i+dx][j+dy] = theWorld[i][j]->Eat(theWorld[i+dx][j+dy]);
                    }
                    if(typeid(*theWorld[i+dx][j+dy]) == typeid(Creature)) {
                        theWorld[i+dx][j+dy] = theWorld[i][j]->Generate(theWorld[i+dx][j+dy]);
                    }
                    
                }
            }
        }
    }
    
    // 吃草
    for (int i=0;i<WORLD_LENGTH;i++) {
        for (int j=0;j<WORLD_WIDTH;j++) {
            if (theWorld[i][j]->ifActed()) {
                continue;
            }
            if (theWorld[i][j]->ifMove()) {
                rndPos(dx, dy);
                if (BoundaryTest(i+dx, j+dy)) {
                    if(typeid(*theWorld[i+dx][j+dy]) == typeid(Grass)) {
                        theWorld[i+dx][j+dy] = theWorld[i][j]->Eat(theWorld[i+dx][j+dy]);
                    }
                    if(typeid(*theWorld[i+dx][j+dy]) == typeid(Creature)) {
                        theWorld[i][j]->setPosition(i+dx, j+dy);
                        theWorld[i+dx][j+dy]->setPosition(i, j);
                        std::swap(theWorld[i][j], theWorld[i+dx][j+dy]);
                        
                    }

                }

            }
        }
    }


    
}

bool World::BoundaryTest(int tarX, int tarY) {
   
    // cout << tarX << " " << tarY << "\n";
    if (tarX < 0) return 0;
    if (tarX >= WORLD_LENGTH) return 0;
    if (tarY < 0) return 0;
    if (tarY >= WORLD_WIDTH) return 0;
    return 1;
}


void World::rndPos(int &dx, int &dy) {
    int dir = rnd.getRandomNum(0, 3);
    if (dir == direction::east) {
        dx=1;dy=0;
    }
    else if (dir == direction::south) {
        dy=1;dx=0;
    }
    else if (dir == direction::west) {
        dx=-1;dy=0;
    }
    else if (dir == direction::north) {
        dy=-1;dx=0;
    } 
}

