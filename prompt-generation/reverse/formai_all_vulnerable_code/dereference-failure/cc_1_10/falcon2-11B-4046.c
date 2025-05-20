//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int x, y;
    bool alive;
} Cell;

void initialize_board(Cell** board, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        board[i] = (Cell*) malloc(width * sizeof(Cell));
        for (j = 0; j < width; j++) {
            board[i][j].x = j;
            board[i][j].y = i;
            board[i][j].alive = false;
        }
    }
}

void print_board(Cell** board, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (board[i][j].alive) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void step(Cell** board, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int alive_neighbors = 0;
            int x_offset = j - 1;
            int y_offset = i - 1;
            if (x_offset >= 0 && y_offset >= 0) {
                alive_neighbors += board[i][x_offset].alive && board[y_offset][j].alive;
            }
            x_offset = j - 1;
            if (x_offset < 0 || y_offset >= height) {
                continue;
            }
            alive_neighbors += board[i][x_offset].alive && board[y_offset][j].alive;
            x_offset = j + 1;
            if (x_offset >= width || y_offset >= height) {
                continue;
            }
            alive_neighbors += board[i][x_offset].alive && board[y_offset][j].alive;
            y_offset = i - 1;
            if (y_offset < 0 || x_offset >= width) {
                continue;
            }
            alive_neighbors += board[i][x_offset].alive && board[y_offset][j].alive;
            y_offset = i + 1;
            if (y_offset >= height || x_offset >= width) {
                continue;
            }
            alive_neighbors += board[i][x_offset].alive && board[y_offset][j].alive;
            if (board[i][j].alive) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    board[i][j].alive = false;
                }
            } else {
                if (alive_neighbors == 3) {
                    board[i][j].alive = true;
                }
            }
        }
    }
}

int main() {
    int width = 10, height = 10;
    Cell** board = (Cell**) malloc(height * sizeof(Cell*));
    initialize_board(board, width, height);
    print_board(board, width, height);
    for (int i = 0; i < 100; i++) {
        step(board, width, height);
        print_board(board, width, height);
    }
    free(board);
    return 0;
}