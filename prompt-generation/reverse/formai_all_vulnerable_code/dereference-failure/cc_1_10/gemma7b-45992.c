//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 20

typedef struct Cell {
    int x;
    int y;
    char state;
} Cell;

void initialize_board(Cell **board) {
    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            board[y][x].x = x;
            board[y][x].y = y;
            board[y][x].state = 'N';
        }
    }
}

void draw_board(Cell **board) {
    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            switch (board[y][x].state) {
                case 'O':
                    printf("O ");
                    break;
                case 'X':
                    printf("X ");
                    break;
                default:
                    printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell **board = (Cell **)malloc(MAX_HEIGHT * sizeof(Cell *));
    for (int y = 0; y < MAX_HEIGHT; y++) {
        board[y] = (Cell *)malloc(MAX_WIDTH * sizeof(Cell));
    }

    initialize_board(board);

    draw_board(board);

    return 0;
}