//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void init_board(Cell **board) {
    for (int x = 0; x < MAX_WIDTH; x++) {
        for (int y = 0; y < MAX_HEIGHT; y++) {
            board[x][y].x = x;
            board[x][y].y = y;
            board[x][y].state = 0;
        }
    }
}

void draw_board(Cell **board) {
    for (int x = 0; x < MAX_WIDTH; x++) {
        for (int y = 0; y < MAX_HEIGHT; y++) {
            switch (board[x][y].state) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("X");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell **board = (Cell **)malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(Cell));
    init_board(board);

    draw_board(board);

    return 0;
}