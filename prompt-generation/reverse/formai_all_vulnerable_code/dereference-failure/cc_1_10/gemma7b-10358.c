//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze structure
typedef struct Maze {
    int rows;
    int cols;
    char **grid;
} Maze;

// Function to create a maze
Maze *createMaze(int rows, int cols) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = (char **)malloc(rows * sizeof(char *));
    for (int r = 0; r < rows; r++) {
        maze->grid[r] = (char *)malloc(cols * sizeof(char));
    }
    return maze;
}

// Function to print the maze
void printMaze(Maze *maze) {
    for (int r = 0; r < maze->rows; r++) {
        for (int c = 0; c < maze->cols; c++) {
            printf("%c ", maze->grid[r][c]);
        }
        printf("\n");
    }
}

// Function to find the shortest path in a maze
int findPath(Maze *maze, int x, int y) {
    // If the cell is the goal, return 0
    if (maze->grid[x][y] == 'G') {
        return 0;
    }

    // If the cell is a wall, return -1
    if (maze->grid[x][y] == '#') {
        return -1;
    }

    // Mark the cell as visited
    maze->grid[x][y] = 'V';

    // Search for the shortest path in the four directions
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        // If the cell is within the bounds of the maze and has not been visited, and the path is not blocked, search for the shortest path recursively
        if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols && maze->grid[new_x][new_y] != 'V' && maze->grid[new_x][new_y] != '#') {
            int path_length = findPath(maze, new_x, new_y);

            // If the path length is less than the current path length, update the current path length
            if (path_length < 0) {
                return path_length;
            }
        }
    }

    // If no path is found, return -1
    return -1;
}

int main() {
    // Create a maze
    Maze *maze = createMaze(5, 5);

    // Print the maze
    printMaze(maze);

    // Find the shortest path in the maze
    int path_length = findPath(maze, 0, 0);

    // Print the path length
    printf("Path length: %d\n", path_length);

    return 0;
}