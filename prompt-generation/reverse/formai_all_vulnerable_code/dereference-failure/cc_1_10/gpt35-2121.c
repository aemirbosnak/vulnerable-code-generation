//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int size);
void printMaze(int** maze, int size);
void fillMaze(int** maze, int size);
void carvePath(int** maze, int x, int y, int size);

int main()
{
    int size;
    
    printf("Enter a size for the maze: ");
    scanf("%d", &size);
    if (size % 2 == 0) size++;   // Make sure size is odd
    
    generateMaze(size);
    
    return 0;
}

void generateMaze(int size)
{
    int** maze = malloc(size * sizeof(int*));    // Allocate 2D array
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(size * sizeof(int));
    }
    
    srand(time(NULL));  // Seed random generator
    
    fillMaze(maze, size);
    carvePath(maze, 1, 1, size);
    printMaze(maze, size);
    
    // Free memory
    for (int i = 0; i < size; i++) {
        free(maze[i]);
    }
    free(maze);
}

void fillMaze(int** maze, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                maze[i][j] = 1; // Fill border with walls
            } else {
                maze[i][j] = 0; // Fill interior with empty space
            }
        }
    }
}

void carvePath(int** maze, int x, int y, int size)
{
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible directions
    int order[4] = {0, 1, 2, 3};    // Randomize direction order
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
    
    for (int i = 0; i < 4; i++) {   // Try to carve path in each direction
        int dx = directions[order[i]][0];
        int dy = directions[order[i]][1];
        int nx = x + dx*2;
        int ny = y + dy*2;
        if (nx >= 1 && nx < size - 1 && ny >= 1 && ny < size - 1 && maze[nx][ny] == 0) {
            maze[x+dx][y+dy] = 1;   // Carve path
            maze[nx][ny] = 1;
            carvePath(maze, nx, ny, size);  // Recurse
        }
    }
}

void printMaze(int** maze, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}