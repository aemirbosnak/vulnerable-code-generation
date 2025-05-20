//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Function to print the maze
void printMaze(int **maze, int maze_size) {
    for (int i = 0; i < maze_size; i++) {
        for (int j = 0; j < maze_size; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}


// Recursive function to find the exit point of the maze
bool findExit(int **maze, int maze_size, int x, int y) {

    if (x < 0 || x >= maze_size || y < 0 || y >= maze_size) {
        // Out of bounds
        return false;
    }

    if (maze[x][y] == 2) {
        // Exit point found
        return true;
    }

    if (maze[x][y] != 1) {
        // Already visited
        return false;
    }

    maze[x][y] = 3; // Mark as visited 

    // Recursively explore in all four directions
    if (findExit(maze, maze_size, x + 1, y)) {
        return true;
    }

    if (findExit(maze, maze_size, x - 1, y)) {
        return true;
    }

    if (findExit(maze, maze_size, x, y + 1)) {
        return true;
    }

    if (findExit(maze, maze_size, x, y - 1)) {
        return true;
    }

    // If no path leads to the exit, mark as dead end
    maze[x][y] = 4; 

    return false;
}


// Main function
int main() {
    int maze_size = 7;

    // Initialize the maze
    int **maze = (int **) malloc(maze_size * sizeof(int *));
    for (int i = 0; i < maze_size; i++) {
        maze[i] = (int *) malloc(maze_size * sizeof(int));
    }

    // Set the maze
    maze[0][0] = 1;
    maze[0][1] = 0;
    maze[0][2] = 1;
    maze[0][3] = 1;
    maze[0][4] = 1;
    maze[0][5] = 1;
    maze[0][6] = 1;

    maze[1][0] = 1;
    maze[1][1] = 0;
    maze[1][2] = 1;
    maze[1][3] = 0;
    maze[1][4] = 0;
    maze[1][5] = 0;
    maze[1][6] = 1;

    maze[2][0] = 1;
    maze[2][1] = 0;
    maze[2][2] = 1;
    maze[2][3] = 0;
    maze[2][4] = 1;
    maze[2][5] = 0;
    maze[2][6] = 1;

    maze[3][0] = 1;
    maze[3][1] = 0;
    maze[3][2] = 1;
    maze[3][3] = 1;
    maze[3][4] = 1;
    maze[3][5] = 0;
    maze[3][6] = 1;

    maze[4][0] = 1;
    maze[4][1] = 0;
    maze[4][2] = 0;
    maze[4][3] = 0;
    maze[4][4] = 1;
    maze[4][5] = 0;
    maze[4][6] = 1;

    maze[5][0] = 1;
    maze[5][1] = 1;
    maze[5][2] = 1;
    maze[5][3] = 0;
    maze[5][4] = 1;
    maze[5][5] = 0;
    maze[5][6] = 1;

    maze[6][0] = 0;
    maze[6][1] = 0;
    maze[6][2] = 1;
    maze[6][3] = 0;
    maze[6][4] = 1;
    maze[6][5] = 0;
    maze[6][6] = 1;

    printf("Initial maze:\n");
    printMaze(maze, maze_size);

    // Find the exit
    bool exit_found = findExit(maze, maze_size, 0, 0);

    if (exit_found) {
        printf("\nExit found!\n");
        printMaze(maze, maze_size);
    } else {
        printf("\nNo exit found!\n");
    }

    // Free the memory
    for (int i = 0; i < maze_size; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}