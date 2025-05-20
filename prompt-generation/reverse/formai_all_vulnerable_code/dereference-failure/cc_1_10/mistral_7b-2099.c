//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 10

bool **board;
int openSites;

void printBoard(void) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isFull(int row, int col) {
    return (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col]);
}

void addSite(int row, int col) {
    if (!isFull(row, col)) {
        board[row][col] = 1;
        openSites++;
    }
}

void connect(int row, int col) {
    int i, j;

    addSite(row - 1, col);
    addSite(row + 1, col);
    addSite(row, col - 1);
    addSite(row, col + 1);

    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i != row || j != col) {
                connect(i, j);
            }
        }
    }
}

int main() {
    int i, j;
    srand(time(NULL));

    board = calloc(SIZE, sizeof(bool *));
    for (i = 0; i < SIZE; i++) {
        board[i] = calloc(SIZE, sizeof(bool));
    }

    addSite(rand() % SIZE, rand() % SIZE);
    connect(rand() % SIZE, rand() % SIZE);

    printf("Initial Board:\n");
    printBoard();
    printf("Number of Open Sites: %d\n", openSites);

    for (i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}