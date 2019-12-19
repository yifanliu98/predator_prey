#include <cstdlib>
#include <iostream>
#include "ant.h"
#include "organism.h"
using namespace std;

Ant::Ant(Point aPoint, World* aWorld, char aType) : Organism(aPoint, aWorld, aType)
{

}

void Ant::move()
{
    if (moved)
	{
		return;
	}
	noBreed++;
	int i;
	i = rand() % 4 + 1;
	// 1. right
	// 2. down
	// 3. left
	// 4. up
	if (i == 1)
	{
	    if (worldPtr -> isEmptyAt(thePoint.X + 1, thePoint.Y))
	    {
	        moveTo(thePoint.X + 1, thePoint.Y);
	    }
	}
	else if (i == 2)
	{
	    if (worldPtr -> isEmptyAt(thePoint.X, thePoint.Y + 1))
	    {
	        moveTo(thePoint.X, thePoint.Y + 1);
	    }
	}
	else if (i == 3)
	{
	    if (worldPtr -> isEmptyAt(thePoint.X - 1, thePoint.Y))
	    {
	        moveTo(thePoint.X - 1, thePoint.Y);
	    }
	}
	else
	{
	    if (worldPtr -> isEmptyAt(thePoint.X, thePoint.Y - 1))
	    {
	        moveTo(thePoint.X, thePoint.Y - 1);
	    }
	}
}

void Ant::breed()
{
    if (noBreed >= 3)
    {
        Point temp;
        temp = breedAt();
        if (thePoint.X == temp.X && thePoint.Y == temp.Y)
        {
            return;
        }
        else 
        {
            noBreed = 0;
            createOrgAt(temp);
        }
    }
}

bool Ant::isDead() const
{
	return false;
}