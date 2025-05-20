//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    int* maze;
} Maze;

void generateMaze(Maze* maze, int width, int height) {
    maze->width = width;
    maze->height = height;
    maze->maze = (int*)malloc(width * height * sizeof(int));

    // Initialize maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->maze[i * width + j] = 1;
        }
    }

    // Generate maze using Prim's algorithm
    int* frontier = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            frontier[i * width + j] = 0;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze->maze[i * width + j] == 0) {
                int current = -1;
                int neighborCount = 0;
                int minNeighbor = 1;
                int minNeighborIndex = -1;

                for (int k = 0; k < 4; k++) {
                    int neighborIndex = (i + 1) * width + (j + k) % width;
                    if (neighborIndex >= 0 && neighborIndex < width * height) {
                        if (frontier[neighborIndex] == 0) {
                            neighborCount++;
                            if (minNeighbor > maze->maze[neighborIndex]) {
                                minNeighbor = maze->maze[neighborIndex];
                                minNeighborIndex = neighborIndex;
                            }
                        }
                    }
                }

                if (minNeighborIndex!= -1) {
                    maze->maze[minNeighborIndex] = 0;
                    frontier[minNeighborIndex] = 1;
                    current = minNeighborIndex;
                }

                if (current!= -1) {
                    for (int k = 0; k < 4; k++) {
                        int neighborIndex = (i + 1) * width + (j + k) % width;
                        if (neighborIndex >= 0 && neighborIndex < width * height) {
                            if (frontier[neighborIndex] == 0) {
                                frontier[neighborIndex] = current;
                            }
                        }
                    }
                }
            }
        }
    }

    // Free memory
    free(frontier);
}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->maze[i * maze->width + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int width = 10;
    int height = 10;
    Maze maze = {.width = width,.height = height,.maze = NULL };
    generateMaze(&maze, width, height);
    printMaze(&maze);
    return 0;
}