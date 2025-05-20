//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rows = 3;
int cols = 3;

void print_maze(int** maze) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void create_maze(int** maze, int** visited, bool** wall, int start_x, int start_y) {
    // Create the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == start_x && j == start_y) {
                maze[i][j] = 'S';
            } else if (wall[i][j] == false) {
                maze[i][j] = 'W';
            } else {
                maze[i][j] = '.';
            }
        }
    }

    // Set the start and end positions
    visited[start_x][start_y] = true;
    wall[start_x][start_y] = true;

    // Create the route
    create_maze(maze, visited, wall, start_x - 1, start_y);
    create_maze(maze, visited, wall, start_x, start_y - 1);
    create_maze(maze, visited, wall, start_x + 1, start_y);
    create_maze(maze, visited, wall, start_x, start_y + 1);
}

int main() {
    int** maze = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze[i] = malloc(cols * sizeof(int));
    }

    int** visited = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        visited[i] = malloc(cols * sizeof(int));
    }

    int** wall = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        wall[i] = malloc(cols * sizeof(int));
    }

    int start_x = 1;
    int start_y = 1;

    create_maze(maze, visited, wall, start_x, start_y);

    print_maze(maze);
    printf("Route: %d %d\n", start_x, start_y);
    printf("-------------------------\n");

    free(maze);
    free(visited);
    free(wall);

    return 0;
}