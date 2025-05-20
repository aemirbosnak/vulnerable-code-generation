//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generateMaze(int maze[HEIGHT][WIDTH]) {
    // Set all values to 1
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    // Randomly set some walls
    srand(time(NULL));
    for (int i = 1; i < HEIGHT; i += 2) {
        for (int j = 1; j < WIDTH; j += 2) {
            if (rand() % 2 == 0) {
                maze[i][j-1] = 0;
                maze[i][j+1] = 0;
            } else {
                maze[i-1][j] = 0;
                maze[i+1][j] = 0;
            }
        }
    }
}

void printMaze(int maze[HEIGHT][WIDTH]) {
    printf(" ");
    for (int j = 0; j < WIDTH-1; j++) {
        printf("_ ");
    }
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf(" |");
            } else {
                printf("_|");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}