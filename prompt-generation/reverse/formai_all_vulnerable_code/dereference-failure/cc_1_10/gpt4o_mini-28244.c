//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define VISITED '.'

// Function prototypes
void generateMaze(int width, int height);
void printMaze(int width, int height);
void carvePath(int x, int y);
int isValidMove(int x, int y);

// Global variables
char **maze;
int width, height;

int main() {
    // Set maze dimensions
    printf("Enter maze width (odd number): ");
    scanf("%d", &width);
    printf("Enter maze height (odd number): ");
    scanf("%d", &height);

    // Ensure dimensions are odd for proper maze generation
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

    // Allocate memory for maze
    maze = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze[i] = (char *)malloc(width * sizeof(char));
    }

    // Initialize the maze with walls
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maze[y][x] = WALL;
        }
    }

    // Generate the maze
    srand(time(NULL));
    carvePath(1, 1);

    // Print the completed maze
    printMaze(width, height);

    // Free allocated memory
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}

void printMaze(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(maze[y][x]);
        }
        putchar('\n');
    }
}

void carvePath(int x, int y) {
    // Marks the current position as visited
    maze[y][x] = PATH;

    // Directions to move in the maze (up, down, left, right)
    int directions[4][2] = {
        {0, -2},   // Up
        {0, 2},    // Down
        {-2, 0},   // Left
        {2, 0}     // Right
    };

    // Shuffle the directions array
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp[2] = {directions[i][0], directions[i][1]};
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp[0];
        directions[j][1] = temp[1];
    }

    // Perform recursive carving
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValidMove(newX, newY)) {
            maze[y + directions[i][1] / 2][x + directions[i][0] / 2] = PATH; // carve the wall
            carvePath(newX, newY);
        }
    }
}

int isValidMove(int x, int y) {
    // Check bounds
    if (x < 1 || x >= width || y < 1 || y >= height) {
        return 0;
    }
    // Check if the cell has been visited
    return maze[y][x] == WALL;
}