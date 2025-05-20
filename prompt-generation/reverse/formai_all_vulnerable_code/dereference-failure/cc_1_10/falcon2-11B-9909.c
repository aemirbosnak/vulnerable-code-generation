//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Recursive function to generate a maze
void generateMaze(int** maze, int m, int n) {
    // Base case: If we reach the bottom right corner, we're done
    if (maze[m][n] == 0) {
        return;
    }
    
    // Mark the current cell as visited
    maze[m][n] = 0;
    
    // Recursively generate the maze in all four directions
    generateMaze(maze, m+1, n);
    generateMaze(maze, m, n+1);
    generateMaze(maze, m-1, n);
    generateMaze(maze, m, n-1);
}

// Function to print the maze
void printMaze(int** maze, int m, int n) {
    // Print the borders
    for (int i = 0; i < m; i++) {
        printf("+---");
    }
    printf("+---\n");
    
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < m; j++) {
            printf("%d", maze[j][i]);
        }
        printf("|\n");
    }
    
    for (int i = 0; i < m; i++) {
        printf("+---");
    }
    printf("+---\n");
}

int main() {
    // Set the dimensions of the maze
    int m = 10;
    int n = 10;
    
    // Allocate memory for the maze
    int** maze = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        maze[i] = malloc(n * sizeof(int));
    }
    
    // Initialize the maze with all walls
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Generate the maze
    generateMaze(maze, 0, 0);
    
    // Print the maze
    printMaze(maze, m, n);
    
    // Free the memory
    for (int i = 0; i < m; i++) {
        free(maze[i]);
    }
    free(maze);
    
    return 0;
}