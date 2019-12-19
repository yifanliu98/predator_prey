
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"

using namespace std;

int main()
{
	srand(time(0));
    World aWorld;
    aWorld.printTheWorld();

       
    char ch;

    while (cin.get(ch) && ch != 'q') 
    {   // q for quit
        aWorld.runTheWorld();
        aWorld.printTheWorld();
    }
	
    return 0;
}