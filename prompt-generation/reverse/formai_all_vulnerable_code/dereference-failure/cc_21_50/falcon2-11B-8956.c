//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width = 10, height = 10, generation = 0;
    int **board;

    srand(time(NULL));

    board = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        board[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            board[i][j] = (rand() % 2) == 0? 1 : 0;
        }
    }

    while (1) {
        printf("Generation %d\n", generation++);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int neighbors = 0;
                if (i > 0 && j > 0 && i < height - 1 && j < width - 1) {
                    neighbors += board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] +
                                    board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] +
                                    board[i + 1][j + 1];
                } else if (i > 0 && j > 0) {
                    neighbors += board[i - 1][j - 1] + board[i - 1][j];
                } else if (i > 0) {
                    neighbors += board[i - 1][j];
                } else if (j > 0) {
                    neighbors += board[i][j - 1];
                }
                if (board[i][j] == 1 && neighbors < 2 || board[i][j] == 0 && neighbors > 3) {
                    board[i][j] =!board[i][j];
                }
            }
        }
    }

    free(board);
    return 0;
}