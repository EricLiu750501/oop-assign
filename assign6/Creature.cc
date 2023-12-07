#include "Creature.h"
// #include "RandomNum.h"


void Creature::Print() {
    std::cout << " ";
}

Creature::Creature() {
    x = 0;
    y = 0;
    acted = 0;
    age = 0;
}

Creature::Creature(int posx, int posy) {
    x = posx;
    y = posy;
    acted = 0;
    age = 0;
}

Creature::~Creature() {

}

void Creature::setPosition(int newx, int newy) {
    x = newx;
    y = newy;
}
void Creature::getPosition(int &xin, int &yin) {
    xin = this->x;
    yin = this->y;
}

// Creature does not Generate something , so return argument it self
Creature* Creature::Generate(Creature *C) {
    // printf("C:C->C\n");
    return C;
}



bool Creature::ifGenerate() {
    // printf(" ");
    return false;
}

void Creature::Pass() {
    // printf("%d", age);/
    acted = 0;
    age++;
}




bool Creature::Died() {
    return false; // Air doesn't die
}


bool Creature::ifMove() {
    return false;
}

bool Creature::ifActed() {
    //  baby goatsand baby grass do not act during their first day of existence
    if (age == 0) {
        return true;
    }
    return acted;
}

Creature* Creature::Eat(Creature *C) {
    return C;
} 
