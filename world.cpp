#include <iostream>
#include <cstdlib>
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
using namespace std;

World::World()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        Point aPoint;
        do
        {
            aPoint = randomPoint();
            
        } while(!isEmptyAt(aPoint.X, aPoint.Y));
        Organism* aDoodlebug = new Doodlebug(aPoint, this, 'd');
        grid[aPoint.X][aPoint.Y] = aDoodlebug; 
    }

    for (int i = 0; i < 100; i++)
    {
        Point aPoint;
        do
        {
            aPoint = randomPoint();
            
        } while(!isEmptyAt(aPoint.X, aPoint.Y));
        Organism* aAnt = new Ant(aPoint, this, 'a');
        grid[aPoint.X][aPoint.Y] = aAnt; 
    }
}

World::~World()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
			if (grid[i][j] != NULL)
			{
				delete grid[i][j];
			}
        }
    }
}

Organism* World::valueAt(int x, int y) const
{
    return grid[x][y];
}

void World::setValueAt(int x, int y, Organism* newOrg)
{
	delete grid[x][y];
    grid[x][y] = newOrg;
}

Point World::randomPoint() const
{
    Point aPoint;
    aPoint.X = rand() % 20;
    aPoint.Y = rand() % 20;
    return aPoint;
}

bool World::isEmptyAt(int x, int y) const
{
    if (x < 0 || x >= 20 || y < 0 || y >= 20)
    {
        return false;
    }
    if (grid[x][y] == NULL)
    {
        return true;
    }
    return false;
}

void World::printTheWorld() const
{
    int numAnt;
    numAnt = 0;
    int numDBug;
    numDBug = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (grid[i][j] == NULL)
            {
                cout << ".";
            }
            else if (grid[i][j] -> getType() == 'a')
            {
                cout << "A";
                numAnt++;
            }
            else
            {
               	cout << "D";
                numDBug++;
            }
        }
        cout << endl;
    }
    cout << endl << "Ants: " << numAnt;
    cout << "    Doodlebugs: " << numDBug << endl;
}

void World::makeUnmoved()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (grid[i][j] != NULL)
            {
                grid[i][j] -> setMoved (false); 
            }
        }
    }
}

void World::moveBugs()
{
    for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(grid[i][j] != NULL && grid[i][j] -> getType() == 'd')
			{
			    grid[i][j] -> move();
			}
		}
	}
}

void World::moveAnts()
{
    for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(grid[i][j] != NULL && grid[i][j] -> getType() == 'a')
			{
			    grid[i][j] -> move();
			}
		}
	}
}

void World::straveBugs()
{
    for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(grid[i][j] != NULL && grid[i][j] -> getType() == 'd')
			{
				if (grid[i][j] -> isDead() )
				{
					delete grid[i][j];
					grid[i][j] = NULL;
				}
			}
		}
	}
}

void World::breedOrg()
{
    for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(grid[i][j] != NULL)
			{
				grid[i][j] -> breed();
			}
		}
	}
}

void World::runTheWorld()
{
    //makeUnmoved();
    moveBugs();
   // moveAnts();
    //straveBugs();
    //breedOrg();
}