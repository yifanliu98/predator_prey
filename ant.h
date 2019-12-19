#ifndef ANT_H
#define ANT_H
#include <iostream>
#include "organism.h"
using namespace std;

class Ant : public Organism
{
    public:
        Ant(Point aPoint, World* aWorld, char aType);
        void move();
        void breed();
		bool isDead() const;

};

#endif