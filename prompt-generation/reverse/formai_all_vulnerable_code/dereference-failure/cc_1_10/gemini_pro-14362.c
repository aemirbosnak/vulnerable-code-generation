//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimensions
#define WIDTH 20
#define HEIGHT 20

// Define the possible directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the cell types
#define WALL 0
#define PATH 1
#define EXIT 2

// Define the maze data structure
typedef struct {
    int cells[WIDTH][HEIGHT];
    int width;
    int height;
} Maze;

// Create a new maze
Maze *createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));

    maze->width = width;
    maze->height = height;

    // Initialize all cells to walls
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i][j] = WALL;
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze *maze) {
    free(maze);
}

// Display the maze
void displayMaze(Maze *maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            switch (maze->cells[i][j]) {
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf(" ");
                    break;
                case EXIT:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

// Generate a random direction
int randomDirection() {
    return rand() % 4;
}

// Generate a random position within the maze
void randomPosition(Maze *maze, int *x, int *y) {
    *x = rand() % maze->width;
    *y = rand() % maze->height;
}

// Generate a maze using the recursive backtracker algorithm
void generateMaze(Maze *maze) {
    int x, y;
    int directions[4] = {NORTH, EAST, SOUTH, WEST};

    // Start at a random position
    randomPosition(maze, &x, &y);

    // Set the current cell to a path
    maze->cells[x][y] = PATH;

    // While there are still unvisited cells
    while (1) {
        // Get a list of unvisited directions
        int unvisitedDirections[4] = {0, 0, 0, 0};
        int numUnvisitedDirections = 0;
        for (int i = 0; i < 4; i++) {
            int dx = x + (i % 2 == 0 ? (i - 1) : 0);
            int dy = y + (i % 2 == 1 ? (i - 2) : 0);

            if (dx >= 0 && dx < maze->width && dy >= 0 && dy < maze->height && maze->cells[dx][dy] == WALL) {
                unvisitedDirections[numUnvisitedDirections++] = directions[i];
            }
        }

        // If there are no unvisited directions, we're done
        if (numUnvisitedDirections == 0) {
            break;
        }

        // Choose a random unvisited direction
        int direction = unvisitedDirections[rand() % numUnvisitedDirections];

        // Move in the chosen direction
        switch (direction) {
            case NORTH:
                y -= 1;
                break;
            case EAST:
                x += 1;
                break;
            case SOUTH:
                y += 1;
                break;
            case WEST:
                x -= 1;
                break;
        }

        // Set the new cell to a path
        maze->cells[x][y] = PATH;
    }

    // Place the exit at a random position
    randomPosition(maze, &x, &y);
    maze->cells[x][y] = EXIT;
}

// Find the path from the entrance to the exit
int findPath(Maze *maze, int *pathLength, int **path) {
    int x, y;
    int direction;
    int steps = 0;

    // Start at the entrance
    x = 0;
    y = 0;
    direction = EAST;

    // Allocate memory for the path
    *path = malloc(sizeof(int) * (maze->width * maze->height + 1));

    // While we haven't reached the exit
    while (maze->cells[x][y] != EXIT) {
        // Add the current cell to the path
        (*path)[steps++] = maze->cells[x][y];

        // Choose a random direction to move in
        direction = randomDirection();

        // Move in the chosen direction
        switch (direction) {
            case NORTH:
                y -= 1;
                break;
            case EAST:
                x += 1;
                break;
            case SOUTH:
                y += 1;
                break;
            case WEST:
                x -= 1;
                break;
        }
    }

    // Add the exit cell to the path
    (*path)[steps++] = maze->cells[x][y];

    *pathLength = steps;

    return 1;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new maze
    Maze *maze = createMaze(WIDTH, HEIGHT);

    // Generate the maze
    generateMaze(maze);

    // Find the path from the entrance to the exit
    int pathLength;
    int *path;
    if (!findPath(maze, &pathLength, &path)) {
        printf("No path found!\n");
        return 1;
    }

    // Display the maze
    displayMaze(maze);

    // Display the path
    printf("Path: ");
    for (int i = 0; i < pathLength; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    // Free the memory allocated for the maze and the path
    freeMaze(maze);
    free(path);

    return 0;
}