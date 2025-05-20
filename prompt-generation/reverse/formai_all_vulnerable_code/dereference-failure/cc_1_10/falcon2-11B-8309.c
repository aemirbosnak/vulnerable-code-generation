//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int alive;
} Cell;

void printBoard(Cell *board, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", board[i * width + j].alive);
        }
        printf("\n");
    }
    printf("\n");
}

void updateBoard(Cell *board, int width, int height) {
    Cell *newBoard = (Cell *)malloc(sizeof(Cell) * width * height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < height && l >= 0 && l < width) {
                        neighbors++;
                    }
                }
            }
            if (board[i * width + j].alive) {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[i * width + j].alive = 0;
                } else {
                    newBoard[i * width + j].alive = 1;
                }
            } else {
                if (neighbors == 3) {
                    newBoard[i * width + j].alive = 1;
                }
            }
        }
    }

    free(board);
    board = newBoard;
}

int main() {
    int width = 20, height = 20;
    Cell *board = (Cell *)malloc(sizeof(Cell) * width * height);

    srand(time(0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i * width + j].x = j;
            board[i * width + j].y = i;
            board[i * width + j].alive = rand() % 2 == 0;
        }
    }

    printBoard(board, width, height);

    for (int i = 0; i < 1000; i++) {
        updateBoard(board, width, height);
        printBoard(board, width, height);
    }

    return 0;
}