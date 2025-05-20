//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

// Cell states
#define CELL_EMPTY 0
#define CELL_WALL 1
#define CELL_VISITED 2

// Directions
#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3

// Maze data structure
struct Maze {
    int cells[MAZE_WIDTH][MAZE_HEIGHT];
    int visitedCells;
};

// Function to create a new maze
struct Maze* createMaze() {
    struct Maze* maze = (struct Maze*)malloc(sizeof(struct Maze));

    // Initialize all cells to walls
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            maze->cells[i][j] = CELL_WALL;
        }
    }

    // Set the starting cell to empty
    maze->cells[0][0] = CELL_EMPTY;
    maze->visitedCells = 1;

    return maze;
}

// Function to delete a maze
void deleteMaze(struct Maze* maze) {
    free(maze);
}

// Function to print a maze
void printMaze(struct Maze* maze) {
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            if (maze->cells[i][j] == CELL_WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a maze using depth-first search
void generateMaze(struct Maze* maze) {
    // Initialize the stack
    int stack[MAZE_WIDTH * MAZE_HEIGHT];
    int stackTop = 0;

    // Push the starting cell onto the stack
    stack[stackTop++] = 0;

    // While the stack is not empty
    while (stackTop > 0) {
        // Pop the top cell from the stack
        int cell = stack[--stackTop];

        // If the cell has not been visited
        if (maze->cells[cell / MAZE_WIDTH][cell % MAZE_HEIGHT] == CELL_WALL) {
            // Mark the cell as visited
            maze->cells[cell / MAZE_WIDTH][cell % MAZE_HEIGHT] = CELL_VISITED;
            maze->visitedCells++;

            // Get the neighboring cells
            int neighbors[4];
            int numNeighbors = 0;
            if (cell / MAZE_WIDTH > 0) {
                neighbors[numNeighbors++] = cell - MAZE_WIDTH;
            }
            if (cell % MAZE_HEIGHT < MAZE_WIDTH - 1) {
                neighbors[numNeighbors++] = cell + 1;
            }
            if (cell / MAZE_WIDTH < MAZE_HEIGHT - 1) {
                neighbors[numNeighbors++] = cell + MAZE_WIDTH;
            }
            if (cell % MAZE_HEIGHT > 0) {
                neighbors[numNeighbors++] = cell - 1;
            }

            // Shuffle the neighbors
            for (int i = 0; i < numNeighbors; i++) {
                int j = rand() % (numNeighbors - i) + i;
                int temp = neighbors[i];
                neighbors[i] = neighbors[j];
                neighbors[j] = temp;
            }

            // For each neighboring cell
            for (int i = 0; i < numNeighbors; i++) {
                // If the neighboring cell has not been visited
                if (maze->cells[neighbors[i] / MAZE_WIDTH][neighbors[i] % MAZE_HEIGHT] == CELL_WALL) {
                    // Push the neighboring cell onto the stack
                    stack[stackTop++] = neighbors[i];

                    // Remove the wall between the current cell and the neighboring cell
                    int wallCell;
                    if (cell / MAZE_WIDTH == neighbors[i] / MAZE_WIDTH) {
                        wallCell = (cell + neighbors[i]) / 2;
                    } else {
                        wallCell = (cell + neighbors[i]) / 2;
                        wallCell += MAZE_WIDTH / 2;
                    }
                    maze->cells[wallCell / MAZE_WIDTH][wallCell % MAZE_HEIGHT] = CELL_EMPTY;
                }
            }
        }
    }
}

// Function to play the maze game
void playMaze(struct Maze* maze) {
    int x = 0, y = 0;
    char c;

    // While the player has not reached the exit
    while (x != MAZE_WIDTH - 1 || y != MAZE_HEIGHT - 1) {
        // Print the maze
        printMaze(maze);

        // Get the player's input
        c = getchar();

        // Move the player
        switch (c) {
            case 'w':
                if (y > 0 && maze->cells[y - 1][x] != CELL_WALL) {
                    y--;
                }
                break;
            case 'a':
                if (x > 0 && maze->cells[y][x - 1] != CELL_WALL) {
                    x--;
                }
                break;
            case 's':
                if (y < MAZE_HEIGHT - 1 && maze->cells[y + 1][x] != CELL_WALL) {
                    y++;
                }
                break;
            case 'd':
                if (x < MAZE_WIDTH - 1 && maze->cells[y][x + 1] != CELL_WALL) {
                    x++;
                }
                break;
        }
    }

    // Print the maze
    printMaze(maze);

    // Congratulate the player
    printf("You win!\n");
}

// Main function
int main() {
    // Create a new maze
    struct Maze* maze = createMaze();

    // Generate the maze
    generateMaze(maze);

    // Print the maze
    printMaze(maze);

    // Play the maze game
    playMaze(maze);

    // Delete the maze
    deleteMaze(maze);

    return 0;
}