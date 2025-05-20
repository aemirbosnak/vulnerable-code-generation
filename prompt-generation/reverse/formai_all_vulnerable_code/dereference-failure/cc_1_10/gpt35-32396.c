//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define ROWS 20
#define COLS 50

int count_neighbors(int **arr, int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += arr[i][j];
            }
        }
    }
    return count;
}

void print_board(int **arr) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j]) {
                putchar('X');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

void update_board(int **arr) {
    int new[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(arr, i, j);
            if (neighbors == 3 || (arr[i][j] && neighbors == 2)) {
                new[i][j] = 1;
            } else {
                new[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = new[i][j];
        }
    }
}

int main() {
    srand(time(0));
    int **board = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        board[i] = malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    while (1) {
        system("clear");
        print_board(board);
        update_board(board);
        usleep(50000);
    }
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}