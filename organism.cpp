#include <iostream>
#include "organism.h"
using namespace std;
#include "ant.h"
#include "doodlebug.h"

Organism::Organism(Point aPoint, World* aWorld, char aType)
{
    thePoint = aPoint;
    noBreed = 0;
    type = aType;
    moved = false;
    worldPtr = aWorld;
    worldPtr -> setValueAt(thePoint.X, thePoint.Y, this);
}

Point Organism::getThePoint() const
{
    return thePoint;
}

int Organism::getNoBreed() const
{
    return noBreed;
}

char Organism::getType() const
{
    return type;
}

bool Organism::getMoved() const
{
    return moved;
}

World* Organism::getWorldPtr() const
{
    return worldPtr;
}

void Organism::setThePoint(Point aPoint)
{
    thePoint = aPoint;
}

void Organism::setMoved(bool flag)
{
    moved = flag;
}
        
void Organism::setNoBreed(int NoB)
{
    noBreed = NoB;
}

void Organism::setWorldPtr(World* aWorld)
{
    worldPtr = aWorld;
}

bool Organism::isInGrid(int x, int y) const
{
    if (x >= 0 && x < 20 && y >= 0 && y < 20)
    {
        return true;
    }
    return false;
}

Point Organism::breedAt()
{
    // right
	if (worldPtr -> isEmptyAt(thePoint.X + 1, thePoint.Y))
	{
		Point temp;
		temp.X = thePoint.X + 1;
		temp.Y = thePoint.Y;
		return temp;
	}
    // down
	else if (worldPtr -> isEmptyAt(thePoint.X, thePoint.Y + 1))
	{
		Point temp;
		temp.X = thePoint.X;
		temp.Y = thePoint.Y + 1;
		return temp;
	}
	// left
	else if (worldPtr -> isEmptyAt(thePoint.X - 1, thePoint.Y))
	{
		Point temp;
		temp.X = thePoint.X - 1;
		temp.Y = thePoint.Y;
		return temp;
	}
    // up
    else if (worldPtr -> isEmptyAt(thePoint.X, thePoint.Y - 1))
	{
		Point temp;
		temp.X = thePoint.X;
		temp.Y = thePoint.Y - 1;
		return temp;
	}
	else
	{
		return thePoint;
	}
}
void Organism::moveTo(int x, int y)
{
    worldPtr -> setValueAt(x, y, worldPtr -> valueAt(thePoint.X, thePoint.Y));
    worldPtr -> setValueAt(thePoint.X, thePoint.Y, NULL);
    thePoint.X = x;
	thePoint.Y = y;
    worldPtr -> valueAt(x, y) -> setMoved(true);
}

void Organism::createOrgAt(Point aPoint)
{
    if (type == 'a')
    {
        Organism* newAnt = new Ant(aPoint, worldPtr, 'a');
        worldPtr -> setValueAt(aPoint.X, aPoint.Y, newAnt);
    }
    else if (type == 'd')
    {
        Organism* newBug = new Doodlebug(aPoint, worldPtr, 'd');
        worldPtr -> setValueAt(aPoint.X, aPoint.Y, newBug);
    }
}

