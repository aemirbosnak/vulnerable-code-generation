//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 219 // ASCII code for a block
#define PATH 32 // ASCII code for a space

int main() {
    // Seed the random number generator with the current time
    srand((unsigned) time(NULL));
    
    // Define the size of the maze
    int width = 20;
    int height = 10;
    
    // Allocate memory for the maze
    char **maze = (char **) malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        maze[i] = (char *) malloc(sizeof(char) * width);
    }
    
    // Initialize the maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // Generate a random starting point
    int x = rand() % width;
    int y = rand() % height;
    
    // Carve a path through the maze
    while (1) {
        maze[y][x] = PATH;
        
        // Choose a random direction to move
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Up
                if (y > 0 && maze[y-1][x] == WALL) {
                    y--;
                }
                break;
            case 1: // Right
                if (x < width-1 && maze[y][x+1] == WALL) {
                    x++;
                }
                break;
            case 2: // Down
                if (y < height-1 && maze[y+1][x] == WALL) {
                    y++;
                }
                break;
            case 3: // Left
                if (x > 0 && maze[y][x-1] == WALL) {
                    x--;
                }
                break;
        }
        
        // Check if we've reached the end of the maze
        if (x == 0 || x == width-1 || y == 0 || y == height-1) {
            break;
        }
    }
    
    // Print out the maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n"); // Move to the next row
    }
    
    // Free the memory allocated for the maze
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    
    return 0;
}