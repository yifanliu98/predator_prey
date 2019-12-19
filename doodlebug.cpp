
#include <iostream>
#include <cstdlib>
#include "ant.h"
#include "doodlebug.h"
using namespace std;

Doodlebug::Doodlebug(Point aPoint, World* aWorld, char aType) : Organism(aPoint, aWorld, aType)
{

}

void Doodlebug::move()
{
    if (moved)
	{
		return;
	}
	noBreed++;
	noEat++;
	// check if is an Ant on the right
	if (worldPtr -> valueAt(thePoint.X + 1, thePoint.Y) != NULL)
	{
	    if (worldPtr -> valueAt(thePoint.X + 1, thePoint.Y) -> getType() == 'a')
	    {
	        noEat = 0;
			delete worldPtr -> valueAt(thePoint.X + 1, thePoint.Y);
	        moveTo(thePoint.X + 1, thePoint.Y);
	        return;
	    }
	}
	// check if is an Ant below
    if (worldPtr -> valueAt(thePoint.X, thePoint.Y + 1) != NULL)
	{
	    if (worldPtr -> valueAt(thePoint.X, thePoint.Y + 1) -> getType() == 'a')
	    {
	        noEat = 0;
	        delete worldPtr -> valueAt(thePoint.X, thePoint.Y + 1);
	        moveTo(thePoint.X, thePoint.Y + 1);
	        return;
	    }
	}
	// check if is an Ant on the left
	if (worldPtr -> valueAt(thePoint.X - 1, thePoint.Y) != NULL)
	{
	    if (worldPtr -> valueAt(thePoint.X - 1, thePoint.Y) -> getType() == 'a')
	    {
	        noEat = 0;
	        delete worldPtr -> valueAt(thePoint.X - 1, thePoint.Y);
	        moveTo(thePoint.X - 1, thePoint.Y);
	        return;
	    }
	}
	// check if is an Ant above
    if (worldPtr -> valueAt(thePoint.X, thePoint.Y - 1) != NULL)
	{
	    if (worldPtr -> valueAt(thePoint.X, thePoint.Y - 1) -> getType() == 'a')
	    {
	        noEat = 0;
	        delete worldPtr -> valueAt(thePoint.X, thePoint.Y - 1);
	        moveTo(thePoint.X, thePoint.Y - 1);
	        return;
	    }
	}	
	// There is no ant around the doodlebug.
	// So the doodlebug moves according to the same rules as the ant.
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

void Doodlebug::breed()
{
    if (noBreed >= 8)
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

bool Doodlebug::isDead() const
{
	if (noEat >= 3)
	{
		return true;
	}
	else 
	{
		return false;
	}
}