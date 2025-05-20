//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random maze
void generate_maze(int width, int height) {
    int **maze = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        maze[i] = (int *)malloc(width * sizeof(int));
    }

    // Initialize maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }

    // Randomly remove walls to create paths
    srand(time(NULL));
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            int random = rand() % 10;
            if (random < 5) {
                maze[i][j] = 0;
                maze[i][j + 1] = 0;
                maze[i + 1][j] = 0;
                maze[i + 1][j + 1] = 0;
            }
        }
    }

    // Print the maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width = 10;
    int height = 10;

    printf("Welcome to the C Maze Route Finder!\n");

    generate_maze(width, height);

    return 0;
}