//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int* board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i*cols + j]);
        }
        printf("\n");
    }
}

void generateRandomBoard(int* board, int rows, int cols) {
    for (int i = 0; i < rows*cols; i++) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (rand() % 2 == 0) {
            board[i] = 1;
        } else {
            board[i] = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    int rows = 10;
    int cols = 10;
    int* board = (int*)malloc(rows*cols*sizeof(int));

    generateRandomBoard(board, rows, cols);
    printf("Initial Board:\n");
    printBoard(board, rows, cols);

    int* nextBoard = (int*)malloc(rows*cols*sizeof(int));
    int numIterations = 1000;

    for (int i = 0; i < numIterations; i++) {
        for (int j = 0; j < rows*cols; j++) {
            int r = j / cols;
            int c = j % cols;
            int liveNeighbors = 0;

            if (r > 0 && c > 0 && r < rows - 1 && c < cols - 1) {
                liveNeighbors += board[(r - 1)*cols + c + 1] +
                               board[(r + 1)*cols + c + 1] +
                               board[(r + 1)*cols + c - 1] +
                               board[(r - 1)*cols + c - 1] +
                               board[(r + 1)*cols + c - cols + 1] +
                               board[(r - 1)*cols + c - cols + 1] +
                               board[(r + 1)*cols + c + cols - 1] +
                               board[(r - 1)*cols + c + cols - 1];
            } else if (r > 0 && c > 0) {
                liveNeighbors += board[(r - 1)*cols + c + 1];
            } else if (r > 0) {
                liveNeighbors += board[(r - 1)*cols + c + cols - 1];
            } else if (c > 0) {
                liveNeighbors += board[(r + 1)*cols + c - 1];
            } else {
                liveNeighbors += board[(r + 1)*cols + c - cols + 1];
            }

            if (board[j] == 1 && liveNeighbors < 2 || board[j] == 0 && liveNeighbors == 3) {
                nextBoard[j] = 1 - board[j];
            } else {
                nextBoard[j] = board[j];
            }
        }
    }

    printBoard(nextBoard, rows, cols);

    free(board);
    free(nextBoard);

    return 0;
}