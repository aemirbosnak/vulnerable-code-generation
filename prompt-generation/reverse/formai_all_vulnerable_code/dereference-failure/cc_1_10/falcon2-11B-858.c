//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random maze
void generateMaze(int width, int height) {
    int i, j;
    int* maze = (int*)malloc(width * height * sizeof(int));

    // Initialize the maze with walls
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            maze[i * height + j] = 1;
        }
    }

    // Create a path from the top left to the bottom right
    maze[0 * height + height - 1] = 0;
    for (i = 1; i < height - 1; i++) {
        maze[i * height + height - 1] = 0;
    }
    maze[width - 1 * height + height - 1] = 0;

    // Fill in the rest of the maze
    for (i = 1; i < width - 1; i++) {
        for (j = 1; j < height - 1; j++) {
            if (maze[i * height + j - 1] == 0 && maze[i * height + j + 1] == 0 &&
                maze[i * height + j - 1 + width] == 0 && maze[i * height + j + 1 - width] == 0) {
                maze[i * height + j] = 0;
            }
        }
    }

    // Print the maze
    printf("Maze: \n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (maze[i * height + j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Free the memory
    free(maze);
}

int main() {
    // Set the width and height of the maze
    int width = 20;
    int height = 20;

    // Generate the maze
    generateMaze(width, height);

    return 0;
}