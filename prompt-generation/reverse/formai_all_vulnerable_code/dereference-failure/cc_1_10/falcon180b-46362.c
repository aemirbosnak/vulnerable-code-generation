//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int **create_maze(int rows, int cols) {
    int **maze = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 0;
        }
    }
    return maze;
}

void print_maze(int **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(int **maze, int rows, int cols) {
    int start_x = rand() % rows;
    int start_y = rand() % cols;
    maze[start_x][start_y] = 1;

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int current_x = start_x;
    int current_y = start_y;

    while (1) {
        int next_x = current_x + directions[rand() % 4][0];
        int next_y = current_y + directions[rand() % 4][1];

        if (next_x >= 0 && next_x < rows && next_y >= 0 && next_y < cols && maze[next_x][next_y] == 0) {
            maze[current_x][current_y] = 1;
            current_x = next_x;
            current_y = next_y;
        } else {
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    int rows = ROWS;
    int cols = COLS;

    int **maze = create_maze(rows, cols);
    generate_maze(maze, rows, cols);

    print_maze(maze, rows, cols);

    return 0;
}