//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeBoard(Cell **board) {
    int i, j;
    *board = (Cell *)malloc(WIDTH * HEIGHT * sizeof(Cell));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 0;
        }
    }
}

void drawBoard(Cell **board) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            switch (board[i][j].state) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("o");
                    break;
                case 2:
                    printf("x");
                    break;
            }
        }
        printf("\n");
    }
}

void updateBoard(Cell **board) {
    int i, j, neighborCount;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            neighborCount = 0;
            if (board[i][j].state == 2) {
                continue;
            }
            if (i > 0) {
                if (board[i - 1][j].state == 1) {
                    neighborCount++;
                }
            }
            if (i < WIDTH - 1) {
                if (board[i + 1][j].state == 1) {
                    neighborCount++;
                }
            }
            if (j > 0) {
                if (board[i][j - 1].state == 1) {
                    neighborCount++;
                }
            }
            if (j < HEIGHT - 1) {
                if (board[i][j + 1].state == 1) {
                    neighborCount++;
                }
            }
            if (neighborCount == 3) {
                board[i][j].state = 1;
            } else if (neighborCount == 2) {
                board[i][j].state = 0;
            }
        }
    }
}

int main() {
    Cell **board;
    initializeBoard(&board);
    drawBoard(board);
    updateBoard(board);
    drawBoard(board);
    return 0;
}