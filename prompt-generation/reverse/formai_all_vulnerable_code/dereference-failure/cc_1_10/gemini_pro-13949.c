//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Cell states
#define UNVISITED 0
#define VISITED 1
#define WALL 2

// Directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Maze data structure
struct Maze {
    int width;
    int height;
    int cells[WIDTH][HEIGHT];
};

// Create a new maze
struct Maze* createMaze(int width, int height) {
    struct Maze* maze = malloc(sizeof(struct Maze));
    maze->width = width;
    maze->height = height;

    // Initialize all cells to UNVISITED
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i][j] = UNVISITED;
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void destroyMaze(struct Maze* maze) {
    free(maze);
}

// Print the maze to the console
void printMaze(struct Maze* maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            switch (maze->cells[i][j]) {
                case UNVISITED:
                    printf(" ");
                    break;
                case VISITED:
                    printf(".");
                    break;
                case WALL:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

// Generate a maze using the Wilson's algorithm
struct Maze* generateWilsonMaze(int width, int height) {
    // Create a new maze
    struct Maze* maze = createMaze(width, height);

    // Set the starting cell to be the center of the maze
    int startX = width / 2;
    int startY = height / 2;

    // Initialize the starting cell as visited
    maze->cells[startX][startY] = VISITED;

    // Create a stack to store the cells that have been visited
    int stack[width * height];
    int stackSize = 0;

    // While there are still unvisited cells
    while (stackSize < width * height) {
        // Choose a random unvisited cell
        int x = rand() % width;
        int y = rand() % height;
        while (maze->cells[x][y] != UNVISITED) {
            x = rand() % width;
            y = rand() % height;
        }

        // Push the cell onto the stack
        stack[stackSize++] = x | (y << 16);

        // While the stack is not empty
        while (stackSize > 0) {
            // Pop the top cell from the stack
            int cell = stack[--stackSize];
            x = cell & 0xFFFF;
            y = cell >> 16;

            // Choose a random direction to walk
            int direction = rand() % 4;

            // Walk in the chosen direction until we hit a wall
            while (1) {
                switch (direction) {
                    case NORTH:
                        if (y > 0 && maze->cells[x][y - 1] == UNVISITED) {
                            y--;
                            maze->cells[x][y] = VISITED;
                            stack[stackSize++] = x | (y << 16);
                        } else {
                            maze->cells[x][y] = WALL;
                            break;
                        }
                        break;
                    case EAST:
                        if (x < width - 1 && maze->cells[x + 1][y] == UNVISITED) {
                            x++;
                            maze->cells[x][y] = VISITED;
                            stack[stackSize++] = x | (y << 16);
                        } else {
                            maze->cells[x][y] = WALL;
                            break;
                        }
                        break;
                    case SOUTH:
                        if (y < height - 1 && maze->cells[x][y + 1] == UNVISITED) {
                            y++;
                            maze->cells[x][y] = VISITED;
                            stack[stackSize++] = x | (y << 16);
                        } else {
                            maze->cells[x][y] = WALL;
                            break;
                        }
                        break;
                    case WEST:
                        if (x > 0 && maze->cells[x - 1][y] == UNVISITED) {
                            x--;
                            maze->cells[x][y] = VISITED;
                            stack[stackSize++] = x | (y << 16);
                        } else {
                            maze->cells[x][y] = WALL;
                            break;
                        }
                        break;
                }
            }
        }
    }

    return maze;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new maze
    struct Maze* maze = generateWilsonMaze(WIDTH, HEIGHT);

    // Print the maze to the console
    printMaze(maze);

    // Free the memory allocated for the maze
    destroyMaze(maze);

    return 0;
}