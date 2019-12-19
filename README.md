# predator_prey
This is a simple two-dimensional predator-prey simulation using C++.

In this simulation the prey are ants and the predators are doodlebugs. These critters live in a world composed of a 20x20 grid of cells. Only one critter may occupy a cell at a time. The grid is enclosed, so a critter is not allowed to move off the edges of the world. Time is simulated in time steps. Each critter performs some action every time step. Doodlebugs eat Ants.

# The ants behave according to the following model:

1. Move: Every time step, randomly try to move up, down, left, or right. (hints: you can use a random number generator to generate integer from 1 to 4, 1 = right, 2 = down, 3 = left, and 4 = up). If the neighboring cell in the selected direction is occupied or would             move the ant off the grid, then the ant stays in the current cell.

2. Breed: If an ant survives for three time steps, then at the end of the time step (that is; after moving) the ant will breed. This is simulated by creating a new ant in an adjacent (up, down, left, or right) cell that is empty. If there is no empty cell available, then no breeding occurs. Once an offspring is produced, an ant cannot produce an offspring until three more time steps have elapsed.

# The doodlebugs behave according to the following model:

1. Move: Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug will move to that cell and eat the ant. Otherwise, the doodlebug moves according to the same rules as the ant. Note that a doodlebug cannot eat other doodlebugs.

2. Breed: If a doodlebug survives for eight time steps, then at the end of the time step it will spawn off a new doodlebug in the same manner as the ant.

3. Starve: If a doodlebug has not eaten an ant within the last three time steps, then at the end of the third time step it will starve and die. The doodlebug should then be removed from the grid of cells. During one turn, all the doodlebugs should move before the ants do.
