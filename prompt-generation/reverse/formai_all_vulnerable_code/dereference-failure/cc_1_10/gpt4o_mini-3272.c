//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '1'
#define PATH '0'

void generateMaze(char **maze, int width, int height, int x, int y);
void printMaze(char **maze, int width, int height);
void freeMaze(char **maze, int height);

int main() {
    int width, height;

    printf("Enter maze width (odd number): ");
    scanf("%d", &width);
    printf("Enter maze height (odd number): ");
    scanf("%d", &height);

    // Ensuring width and height are odd
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

    // Dynamically allocate memory for the maze
    char **maze = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(width * sizeof(char));
    }

    // Initialize maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = WALL;
        }
    }

    // Seed for randomness
    srand(time(NULL));

    // Generate maze
    generateMaze(maze, width, height, 1, 1);

    // Print maze
    printMaze(maze, width, height);

    // Free allocated memory
    freeMaze(maze, height);

    return 0;
}

void generateMaze(char **maze, int width, int height, int x, int y) {
    // Possible moves: up, down, left, right
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // Shuffle directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp_x = dx[i];
        int temp_y = dy[i];
        dx[i] = dx[j];
        dy[i] = dy[j];
        dx[j] = temp_x;
        dy[j] = temp_y;
    }

    // Recursively carve out paths
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * 2;
        int ny = y + dy[i] * 2;

        if (nx > 0 && nx < width && ny > 0 && ny < height && maze[ny][nx] == WALL) {
            maze[y + dy[i]][x + dx[i]] = PATH; // make a path to it
            maze[ny][nx] = PATH; // carve out a path to the new cell
            generateMaze(maze, width, height, nx, ny); // recursive call
        }
    }
}

void printMaze(char **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void freeMaze(char **maze, int height) {
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
}