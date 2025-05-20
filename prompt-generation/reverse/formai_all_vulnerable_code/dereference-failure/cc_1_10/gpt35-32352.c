//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = '.';
            }
        }
    }
    int current_row = 1;
    int current_col = 1;
    maze[current_row][current_col] = 'S';
    while(1) {
        int direction = rand() % 4;
        if (direction == 0) {
            if (maze[current_row-2][current_col] == '.') {
                maze[current_row-1][current_col] = '.';
                maze[current_row-2][current_col] = '.';
                current_row -= 2;
            }
        }
        else if (direction == 1) {
            if (maze[current_row][current_col+2] == '.') {
                maze[current_row][current_col+1] = '.';
                maze[current_row][current_col+2] = '.';
                current_col += 2;
            }
        }
        else if (direction == 2) {
            if (maze[current_row+2][current_col] == '.') {
                maze[current_row+1][current_col] = '.';
                maze[current_row+2][current_col] = '.';
                current_row += 2;
            }
        }
        else if (direction == 3) {
            if (maze[current_row][current_col-2] == '.') {
                maze[current_row][current_col-1] = '.';
                maze[current_row][current_col-2] = '.';
                current_col -= 2;
            }
        }

        if (current_row == 1 && current_col == 1) {
            maze[current_row][current_col] = 'S';
            break;
        }
    }
    maze[ROWS-2][COLS-2] = 'E';
}

int main() {
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}