//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE]);
void shuffleBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool checkMatch(int board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol);
bool isGameWon(bool revealed[SIZE][SIZE]);
void clearBuffer();

int main() {
    srand(time(0)); // Seed for randomness
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    int moves = 0, firstRow, firstCol, secondRow, secondCol;

    // Step 1: Initialize and shuffle the game board
    initializeBoard(board);
    shuffleBoard(board);

    // Step 2: Game loop
    while (!isGameWon(revealed)) {
        printBoard(board, revealed);
        
        // Player picks the first card
        printf("Enter the coordinates of the first card (row col, 0-3): ");
        scanf("%d %d", &firstRow, &firstCol);
        clearBuffer();

        // Player picks the second card
        printf("Enter the coordinates of the second card (row col, 0-3): ");
        scanf("%d %d", &secondRow, &secondCol);
        clearBuffer();
        
        moves++;

        // Step 3: Check for a match
        if (checkMatch(board, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n\n");
            revealed[firstRow][firstCol] = true;
            revealed[secondRow][secondCol] = true;
        } else {
            printf("Not a match. Try again.\n\n");
        }
    }

    printf("Congratulations! You've won the game in %d moves!\n", moves);
    return 0;
}

void initializeBoard(int board[SIZE][SIZE]) {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num;
            if (num < (SIZE * SIZE) / 2) {
                num++;
            } else {
                num = 1;
            }
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            int rand_i = rand() % (i + 1);
            int rand_j = rand() % (j + 1);
            // Swap the elements
            int temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }
}

void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool checkMatch(int board[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
        return true;
    }
    return false;
}

bool isGameWon(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}