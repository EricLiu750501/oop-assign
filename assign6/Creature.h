#ifndef _CREATURE_H
#define _CREATURE_H

#include <iostream>
#include "AnsiPrint.h"
// #include "Goat.h"
// #include "Grass.h"

// 避免循環include
class Goat;
class Grass;


const color GOAT_COLOR = color::red;
const color GRASS_COLOR = color::green;

class Creature {
    public:
        // Constructor
        Creature();
        Creature(int posx, int posy);

        // Destructor
        virtual ~Creature(void);
        
        // get & set x, y
        void setPosition(int newx, int newy);
        void getPosition(int &xin, int &yin);

        // return weather it's died
        virtual bool Died(); 

        // Generate Baby
        virtual Creature* Generate(Creature *C);

        // if this can Generate
        virtual bool ifGenerate();

        // if this can Move
        virtual bool ifMove();

        // if this previously act
        bool ifActed();

        // Eat other Creature
        virtual Creature* Eat(Creature *C);

        // update Creature's situation per Pass
        virtual void Pass();
        
        // Display Creature on Screen
        virtual void Print();
        
        
       
    // Protected let Goat and Grass inheritance
    protected: 
        int x;
        int y;
        int age;
        bool acted;
        
};

#endif 
