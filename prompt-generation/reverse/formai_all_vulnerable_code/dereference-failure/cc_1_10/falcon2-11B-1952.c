//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_ROW 30

typedef struct maze {
    int rows;
    int columns;
    int start;
    int end;
    int** matrix;
} maze_t;

maze_t* create_maze(int rows, int columns) {
    maze_t* maze = (maze_t*) malloc(sizeof(maze_t));
    maze->rows = rows;
    maze->columns = columns;
    maze->start = 0;
    maze->end = 0;
    maze->matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze->matrix[i] = (int*) malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            maze->matrix[i][j] = 0;
        }
    }
    return maze;
}

void free_maze(maze_t* maze) {
    free(maze->matrix);
    free(maze);
}

void display_maze(maze_t* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->columns; j++) {
            printf("%d ", maze->matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(maze_t* maze) {
    maze->start = rand() % maze->rows;
    maze->end = rand() % maze->rows;
    int start_x = maze->start % maze->columns;
    int start_y = maze->start / maze->columns;
    int end_x = maze->end % maze->columns;
    int end_y = maze->end / maze->columns;
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->columns; j++) {
            if (i == start_y && j == start_x) {
                maze->matrix[i][j] = 1;
            }
            if (i == end_y && j == end_x) {
                maze->matrix[i][j] = 2;
            }
            if (i == start_y || i == end_y || j == start_x || j == end_x) {
                maze->matrix[i][j] = 3;
            }
        }
    }
}

bool check_path(maze_t* maze, int x, int y) {
    if (x < 0 || y < 0 || x >= maze->rows || y >= maze->columns) {
        return false;
    }
    return maze->matrix[x][y]!= 1;
}

int main() {
    int rows = 10;
    int columns = 10;
    maze_t* maze = create_maze(rows, columns);
    generate_maze(maze);
    display_maze(maze);
    int start_x = maze->start % maze->columns;
    int start_y = maze->start / maze->columns;
    int end_x = maze->end % maze->columns;
    int end_y = maze->end / maze->columns;
    int x = start_x;
    int y = start_y;
    bool found_path = false;
    int path[MAX_SIZE];
    int path_length = 0;
    int current_x = x;
    int current_y = y;
    while (!found_path && path_length < MAX_SIZE) {
        path[path_length] = current_x;
        path[path_length + 1] = current_y;
        path_length += 2;
        int current_neighbor_x = current_x + 1;
        int current_neighbor_y = current_y;
        if (current_neighbor_x < maze->columns && check_path(maze, current_neighbor_x, current_neighbor_y)) {
            current_x = current_neighbor_x;
            current_y = current_neighbor_y;
        } else {
            current_neighbor_x = current_x - 1;
            current_neighbor_y = current_y;
            if (current_neighbor_x >= 0 && check_path(maze, current_neighbor_x, current_neighbor_y)) {
                current_x = current_neighbor_x;
                current_y = current_neighbor_y;
            } else {
                current_neighbor_x = current_x;
                current_neighbor_y = current_y - 1;
                if (current_neighbor_x >= 0 && current_neighbor_y >= 0 && current_neighbor_y < maze->rows && check_path(maze, current_neighbor_x, current_neighbor_y)) {
                    current_x = current_neighbor_x;
                    current_y = current_neighbor_y;
                } else {
                    current_neighbor_x = current_x;
                    current_neighbor_y = current_y + 1;
                    if (current_neighbor_x >= 0 && current_neighbor_y < maze->rows && current_neighbor_y >= 0 && check_path(maze, current_neighbor_x, current_neighbor_y)) {
                        current_x = current_neighbor_x;
                        current_y = current_neighbor_y;
                    } else {
                        current_neighbor_x = current_x;
                        current_neighbor_y = current_y;
                        if (current_neighbor_x >= 0 && check_path(maze, current_neighbor_x, current_neighbor_y)) {
                            current_x = current_neighbor_x;
                            current_y = current_neighbor_y;
                        } else {
                            found_path = true;
                        }
                    }
                }
            }
        }
    }
    if (found_path) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }
    display_maze(maze);
    free_maze(maze);
    return 0;
}