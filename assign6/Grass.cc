#include "Grass.h"


Grass::Grass() : Creature() {
    age = 0;
}

Grass::Grass(int posx, int posy) : Creature(posx, posy) {
    age = 0;
}

bool Grass::Died() {
    return this->age > MaxGrassAge;
}


void Grass::Print() {
    AnsiPrint("I", GRASS_COLOR);
}

Grass::~Grass() {
}



Grass* Grass::Generate(Creature *C) {
    
    int tarX, tarY;
    C->getPosition(tarX, tarY);
    delete C;
    // printf("Grass Gen%d %d -> %d %d\n", x, y, tarX, tarY);
    return new Grass(tarX, tarY);
}

bool Grass::ifGenerate() {
    // printf("W%d_%d", this->age >= minGGage && this->age <= maxGGage, age);
    return ((this->age >= minGGage) && (this->age <= maxGGage) && !(acted) );
    
}

bool Grass::ifMove() {
    // Grass cannot move
    return false;
}

Creature* Grass::Eat(Creature *C) {
    // Grass cannot Eat
    return C;
}


void Grass::Pass() {
    acted = 0;
    age++;
}

