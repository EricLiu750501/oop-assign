


#ifndef _GRASS_H
#define _GRASS_H

#include "Creature.h"
class Goat;

const int InitialGrass = 10;
const int MaxGrassAge = 6; // Died if > 6
const int minGGage = 3;
const int maxGGage = 5;

class Grass : public Creature {
    public:
        // Constructor
        Grass();
        Grass(int posx, int posy);

        // Destructor
        virtual ~Grass();

        /* inheritance Creatures virtual function */
        bool Died();
        void Print();
        Grass* Generate(Creature *C);
        bool ifGenerate();  
        bool ifMove();
        Creature* Eat(Creature *C);
        void Pass();
    

    private:
};


#endif