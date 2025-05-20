//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLS 4

void initBoard(char **board) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            (*(board + i))[j] = '-';
        }
    }
}

void printBoard(char **board) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%c ", (*(board + i))[j]);
        }
        printf("\n");
    }
}

int isMatch(char c1, char c2) {
    return c1 == c2;
}

int main() {
    srand(time(NULL));
    char **board = (char **)malloc(ROWS * sizeof(char *));
    for (int i = 0; i < ROWS; ++i) {
        *(board + i) = (char *)malloc(COLS * sizeof(char));
    }
    initBoard(board);
    int matches = 0;
    int attempts = 0;
    while (matches < ROWS * COLS / 2) {
        int row1, col1, row2, col2;
        row1 = rand() % ROWS;
        col1 = rand() % COLS;
        row2 = rand() % ROWS;
        col2 = rand() % COLS;
        if (isMatch((*(board + row1))[col1], (*(board + row2))[col2])) {
            matches++;
        } else {
            (*(board + row1))[col1] = 'X';
            (*(board + row2))[col2] = 'X';
        }
        attempts++;
        if (attempts == 10) {
            printf("No more matches found.\n");
            break;
        }
        printBoard(board);
    }
    printf("Total matches found: %d\n", matches);
    for (int i = 0; i < ROWS; ++i) {
        free((*(board + i)));
    }
    free(board);
    return 0;
}