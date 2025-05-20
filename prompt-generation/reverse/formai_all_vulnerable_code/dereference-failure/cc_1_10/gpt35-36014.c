//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(int**, int);
void shuffle(int**, int);
void displayBoard(int**, int);
void playGame(int**, int);

int main() {
    int** board = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        board[i] = (int*)malloc(COLS * sizeof(int));
    }

    initializeBoard(board, ROWS * COLS / 2);
    shuffle(board, ROWS * COLS);
    displayBoard(board, ROWS);

    playGame(board, ROWS);

    //free the memory
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}

void initializeBoard(int** board, int numPairs) {
    int nums[numPairs];
    for (int i = 0; i < numPairs; i++) {
        nums[i] = i + 1;
    }
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int index = rand() % numPairs;
            board[i][j] = nums[index];
            nums[index] = nums[numPairs - 1];
            numPairs--;
        }
    }
}

void shuffle(int** board, int numMoves) {
    srand(time(0));
    for (int m = 0; m < numMoves; m++) {
        int i1 = rand() % ROWS;
        int j1 = rand() % COLS;
        int i2 = rand() % ROWS;
        int j2 = rand() % COLS;
        int temp = board[i1][j1];
        board[i1][j1] = board[i2][j2];
        board[i2][j2] = temp;
    }
}

void displayBoard(int** board, int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int** board, int numRows) {
    int* paired[numRows * COLS]; //array to keep track of paired tiles
    int numPaired = 0;
    int numAttempts = 0;
    while (numPaired < numRows * COLS) {
        int i1, j1, i2, j2;
        do { //get valid input
            printf("Enter the row and column of two tiles separated by a space: ");
            scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
            printf("\n");
        } while ((i1 < 0 || i1 >= numRows || j1 < 0 || j1 >= COLS ||
                 i2 < 0 || i2 >= numRows || j2 < 0 || j2 >= COLS ||
                 (i1 == i2 && j1 == j2)) ||
                 paired[i1 * COLS + j1] != NULL || paired[i2 * COLS + j2] != NULL);
        numAttempts++;
        printf("Tile 1: %d\nTile 2: %d\n", board[i1][j1], board[i2][j2]);
        if (board[i1][j1] == board[i2][j2]) {
            paired[i1 * COLS + j1] = &board[i1][j1];
            paired[i2 * COLS + j2] = &board[i2][j2];
            numPaired += 2;
            printf("It's a match!\n");
        } else {
            printf("Sorry, try again.\n");
        }
    }
    printf("Congratulations, you won in %d attempts!\n", numAttempts);
}