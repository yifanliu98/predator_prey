
#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include <iostream>
#include "organism.h"

class Doodlebug : public Organism
{
    public:
        Doodlebug(Point aPoint, World* aWorld, char aType);
        
        void move();
        void breed();
		bool isDead() const;
	private:
		int noEat;
};

#endif