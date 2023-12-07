
#ifndef _GOAT_H
#define _GOAT_H
#include "Creature.h"
class Grass;

const int InitialGoat = 5;
const int InitialFood = 20;
const int MaxGoatAge = 70;
const int minGage = 50;
const int maxGage = 55;


class Goat : public Creature {
    public:
        // Constructor
        Goat();
        Goat(int posx, int posy);

        // Destructor
        virtual ~Goat();


        /* inheritance Creatures virtual function */
        void Print();
        bool Died();
        Goat* Generate(Creature *C);
        bool ifGenerate();
        bool ifMove();
        Creature* Eat(Creature *C); 
        void Pass();

    private:
        int foodPoints;
};


#endif