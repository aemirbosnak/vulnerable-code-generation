//FormAI DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 8

void shuffle(int *array, int size) {
    srand(time(NULL));
    if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            int j = i + rand() / (RAND_MAX / (size - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

void printBoard(int **board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **board = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        board[i] = malloc(COLS * sizeof(int));
    }
    int values[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++) {
        values[i] = i + 1;
    }
    shuffle(values, MAX_VALUE);
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = values[index % MAX_VALUE];
            index++;
        }
    }
    printBoard(board);
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}