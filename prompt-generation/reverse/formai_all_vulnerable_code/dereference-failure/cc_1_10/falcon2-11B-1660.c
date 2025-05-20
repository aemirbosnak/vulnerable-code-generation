//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define WIDTH 20
#define HEIGHT 20
int main() {
    // Initialize the maze matrix
    int maze[HEIGHT][WIDTH] = { 0 };
    
    // Set up walls and open spaces
    maze[0][0] = 1;
    maze[0][1] = 1;
    maze[1][0] = 1;
    maze[1][1] = 1;
    maze[1][WIDTH-1] = 1;
    maze[HEIGHT-1][WIDTH-1] = 1;
    
    // Generate the rest of the maze
    for (int i = 2; i < HEIGHT-1; i++) {
        for (int j = 1; j < WIDTH-1; j++) {
            int r = rand() % 2;
            if (r == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
    
    // Print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Free the memory
    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);
    
    return 0;
}