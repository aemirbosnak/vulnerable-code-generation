//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze structure
typedef struct maze {
    int **grid;
    int rows;
    int cols;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} maze_t;

// Create a new maze
maze_t *create_maze(int rows, int cols) {
    maze_t *maze = malloc(sizeof(maze_t));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) {
        maze->grid[r] = malloc(cols * sizeof(int));
    }
    return maze;
}

// Traverse the maze
void traverse_maze(maze_t *maze) {
    int x = maze->start_x;
    int y = maze->start_y;
    maze->grid[x][y] = 2;

    // Check if the end goal has been reached
    if (x == maze->end_x && y == maze->end_y) {
        printf("You have reached the end goal!\n");
        return;
    }

    // Move in all four directions
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        // Check if the cell is within the bounds of the maze and if it is not a wall
        if (new_x >= 0 && new_x < maze->cols && new_y >= 0 && new_y < maze->rows && maze->grid[new_x][new_y] != 1) {
            // Move to the new cell
            x = new_x;
            y = new_y;
            maze->grid[x][y] = 2;
            traverse_maze(maze);
        }
    }
}

int main() {
    // Create a maze
    maze_t *maze = create_maze(5, 5);
    maze->grid[2][2] = 2;
    maze->grid[3][2] = 2;
    maze->grid[3][3] = 2;
    maze->start_x = 0;
    maze->start_y = 0;
    maze->end_x = 4;
    maze->end_y = 4;

    // Traverse the maze
    traverse_maze(maze);

    return 0;
}