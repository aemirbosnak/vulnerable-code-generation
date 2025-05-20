//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

// Function prototypes
char** createMaze();
void displayMaze(char** maze);
void freeMaze(char** maze);
void navigateMaze(char** maze, int x, int y);

// Main function
int main() {
    srand(time(NULL));
    char** maze = createMaze();
    displayMaze(maze);

    printf("\nStarting Navigation!\n");
    navigateMaze(maze, 0, 0); // Start navigation from (0, 0)

    freeMaze(maze);
    return 0;
}

// Function to create a random maze
char** createMaze() {
    char** maze = (char**)malloc(MAZE_SIZE * sizeof(char*));
    for (int i = 0; i < MAZE_SIZE; i++) {
        maze[i] = (char*)malloc(MAZE_SIZE * sizeof(char));
        for (int j = 0; j < MAZE_SIZE; j++) {
            // Randomly assign walls and paths
            if (i == 0 && j == 0) {
                maze[i][j] = START; // Start point
            } else if (i == MAZE_SIZE - 1 && j == MAZE_SIZE - 1) {
                maze[i][j] = END; // End point
            } else {
                maze[i][j] = (rand() % 4 == 0) ? WALL : PATH; // 25% chance of being a wall
            }
        }
    }

    // Ensuring that start and end are accessible
    maze[0][1] = PATH;
    maze[1][0] = PATH;
    maze[MAZE_SIZE - 1][MAZE_SIZE - 2] = PATH;
    maze[MAZE_SIZE - 2][MAZE_SIZE - 1] = PATH;

    return maze;
}

// Function to display the maze layout
void displayMaze(char** maze) {
    printf("Maze Layout:\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to free allocated maze memory
void freeMaze(char** maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        free(maze[i]);
    }
    free(maze);
}

// Function to navigate the maze recursively
void navigateMaze(char** maze, int x, int y) {
    // Base cases for navigation 
    if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE || maze[x][y] == WALL) {
        return; // Out of bounds or hit a wall
    }
    
    if (maze[x][y] == END) {
        printf("Reached the END at (%d, %d)!\n", x, y);
        return; // Successfully reached the end
    }

    // Marking the current position as part of the path
    maze[x][y] = '*'; // Mark as visited
    displayMaze(maze);
    
    // Recursive step in all four directions
    navigateMaze(maze, x + 1, y); // Down
    navigateMaze(maze, x - 1, y); // Up
    navigateMaze(maze, x, y + 1); // Right
    navigateMaze(maze, x, y - 1); // Left

    // Unmark the path after exploring one route fully (backtrack)
    maze[x][y] = PATH; // Mark as unvisited for exploration flexibility
}