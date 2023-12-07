#include "Goat.h"

void Goat::Print() {
    AnsiPrint("X", GOAT_COLOR);
}

Goat::Goat() : Creature() {
    foodPoints = InitialFood; 
}

Goat::~Goat() {

}

Goat::Goat(int posx, int posy) : Creature(posx, posy) {
    foodPoints = InitialFood;
}

bool Goat::Died() {
    if (this->age > MaxGoatAge) {
        return true;
    } 
    if (this->foodPoints < 0) {
        return true;
    }
    return false;
}



Goat* Goat::Generate(Creature *C) {
    acted = 1;
    int tarX, tarY;
    C->getPosition(tarX, tarY);
    delete C;
    return new Goat(tarX, tarY);
    
}

bool Goat::ifGenerate() {
    // printf("Y%d_%d", this->age >= minGage && this->age <= maxGage, age);
    return ((this->age >= minGage) && (this->age <= maxGage) && (!acted));
}

bool Goat::ifMove() {
    return ( (age!=0) && (!acted) ); // baby goat don't act,  acted don't act.
}

Creature* Goat::Eat(Creature *C) {
    int xx, yy;
    C->getPosition(xx, yy);
    delete C;
    foodPoints += 5;
    return new Creature(xx, yy);
}


void Goat::Pass() {
    acted = 0;
    age++;
    foodPoints--;
}

