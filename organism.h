#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
using namespace std;
class Organism;


struct Point
{
    int X;
    int Y;
};

class World
{
    public:
        World();
        // Initialized a 20X20 grid, with 100 ants and 5 doodlebugs
        // by the random position
        
        ~World();
        // Destructor
        // Delete the 2D array
        
        Organism* valueAt(int x, int y) const;
        // Precondition: x and y are in the grid
        // Return the value at point (x,y)
        
        void setValueAt(int x, int y, Organism* newOrg);
        // Precondition: x, y are in the grid
        // Set the new value at point (x,y)
        
        Point randomPoint() const;
        // Return a random position in the grid
        
        bool isEmptyAt(int x, int y) const;
        
        void printTheWorld() const;
        // Present the world by char
        
        void runTheWorld();
        // Make organisms move, breed, strave and die.
        
    private:
        Organism* grid[20][20];
        void makeUnmoved();
        void moveBugs();
        void moveAnts();
        void straveBugs();
        void breedOrg();
};



class Organism
{
    public:
        Organism(Point aPoint, World* aWorld, char aType);
        
        virtual void move() = 0;
        virtual void breed() = 0;
		virtual bool isDead() const = 0;
        
        // getter functions 
        Point getThePoint() const;
        bool getMoved() const;
        int getNoBreed() const;
        char getType() const;
        World* getWorldPtr() const;

        // setter functions
        void setThePoint(Point aPoint);
        void setMoved(bool flag);
        void setNoBreed(int NoB);
        void setWorldPtr(World* aWorld);
        
        // member functions
        bool isInGrid(int x, int y) const;
        
    protected:
        Point thePoint; // location in the grid
        bool moved; // if moved, true. False otherwise.
        int noBreed; // Number of steps after breed
        char type; // 'a' means an Ant, 'd' is a Doodlebug
        World* worldPtr; 

        void moveTo(int x, int y);
        Point breedAt();
        void createOrgAt(Point aPoint);
        
};

#endif