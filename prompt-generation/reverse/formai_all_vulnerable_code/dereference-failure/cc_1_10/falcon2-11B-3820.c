//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_maze(int width, int height) {
    int** maze = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze[i] = (int*)malloc(width * sizeof(int));
    }

    int start_row = rand() % height;
    int start_col = rand() % width;

    maze[start_row][start_col] = 1;

    int current_row = start_row;
    int current_col = start_col;

    for (int i = 0; i < height * width; i++) {
        if (maze[current_row][current_col] == 0) {
            maze[current_row][current_col] = 1;
            int next_row = current_row;
            int next_col = current_col;

            while (next_row!= start_row && next_col!= start_col) {
                srand(time(NULL));
                next_row = (rand() % height) + 1;
                next_col = (rand() % width) + 1;
            }

            maze[next_row][next_col] = 1;
            current_row = next_row;
            current_col = next_col;
        }

        if (current_row == start_row && current_col == start_col) {
            break;
        }
    }

    printf("Maze generated:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);
}

int main() {
    int width = 10;
    int height = 10;
    generate_maze(width, height);

    return 0;
}