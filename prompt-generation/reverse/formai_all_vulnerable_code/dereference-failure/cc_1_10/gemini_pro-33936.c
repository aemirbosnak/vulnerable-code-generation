//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Define the maze structure
typedef struct Maze {
    int width;
    int height;
    int** cells;
} Maze;

// Create a new maze
Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(int) * width);
    }

    // Initialize the maze cells to 0 (unvisited)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->cells[i][j] = 0;
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Get a random direction
enum Direction getRandomDirection() {
    return rand() % 4;
}

// Check if a given cell is valid (within the maze and unvisited)
int isValidCell(Maze* maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->cells[y][x] == 0;
}

// Find a path through the maze using a recursive depth-first search
int findPath(Maze* maze, int x, int y) {
    // Mark the current cell as visited
    maze->cells[y][x] = 1;

    // Check if the current cell is the goal
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // Try all possible directions
    for (enum Direction direction = NORTH; direction <= WEST; direction++) {
        int nextX, nextY;

        // Get the next cell in the given direction
        switch (direction) {
            case NORTH:
                nextX = x;
                nextY = y - 1;
                break;
            case EAST:
                nextX = x + 1;
                nextY = y;
                break;
            case SOUTH:
                nextX = x;
                nextY = y + 1;
                break;
            case WEST:
                nextX = x - 1;
                nextY = y;
                break;
        }

        // If the next cell is valid, recursively search for a path from that cell
        if (isValidCell(maze, nextX, nextY)) {
            if (findPath(maze, nextX, nextY)) {
                return 1;
            }
        }
    }

    // No path found from the current cell
    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new maze
    Maze* maze = createMaze(MAZE_WIDTH, MAZE_HEIGHT);

    // Find a path through the maze
    if (findPath(maze, 0, 0)) {
        printf("Path found!\n");
        printMaze(maze);
    } else {
        printf("No path found.\n");
    }

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}