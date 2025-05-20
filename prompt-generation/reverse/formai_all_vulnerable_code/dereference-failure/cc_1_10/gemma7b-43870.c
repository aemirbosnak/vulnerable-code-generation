//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze structure
typedef struct Maze {
    int **grid;
    int width;
    int height;
} Maze;

// Generate a maze
Maze* generate_maze(int w, int h) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = w;
    maze->height = h;
    maze->grid = malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        maze->grid[i] = malloc(sizeof(int) * w);
    }

    // Randomly set walls
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            maze->grid[i][j] = rand() % 2 ? 1 : 0;
        }
    }

    return maze;
}

// Print the maze
void print_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Generate a 10x10 maze
    Maze* maze = generate_maze(10, 10);

    // Print the maze
    print_maze(maze);

    // Free the maze memory
    free(maze->grid);
    free(maze);

    return 0;
}