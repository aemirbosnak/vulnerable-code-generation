//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function to print the game board
void printBoard(int board[][BOARD_SIZE]) {
    printf("\n********************************\n\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }

        printf("\n");
    }

    printf("\n********************************\n");
}

// Function to shuffle the game board
void shuffleBoard(int board[][BOARD_SIZE]) {
    int row, col, temp;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;

            temp = board[row][col];
            board[row][col] = board[i][j];
            board[i][j] = temp;
        }
    }
}

// Function to get user input
void getUserInput(int *row1, int *col1, int *row2, int *col2) {
    printf("Enter the row and column of first card (separated by space): ");
    scanf("%d %d", row1, col1);

    printf("Enter the row and column of second card (separated by space): ");
    scanf("%d %d", row2, col2);
}

// Function to check if two cards are the same
int isMatch(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 6}, {7, 7, 8, 8}};
    int openCards[2][2];
    int matched[BOARD_SIZE][BOARD_SIZE] = {0};
    int attempts = 0, matchedCount = 0;

    srand(time(NULL)); 
    shuffleBoard(board);

    while (matchedCount < BOARD_SIZE*BOARD_SIZE/2) {
        int row1, col1, row2, col2;

        printBoard(board);
        getUserInput(&row1, &col1, &row2, &col2);

        if (matched[row1][col1] || matched[row2][col2]) {
            printf("One of the cards is already matched!\n");
            continue;
        }

        printf("\n");
        printf("Card 1: %d\n", board[row1][col1]);
        printf("Card 2: %d\n", board[row2][col2]);
        attempts++;

        if (isMatch(board, row1, col1, row2, col2)) {
            printf("Match Found!\n\n");
            matched[row1][col1] = 1;
            matched[row2][col2] = 1;
            matchedCount++;
        } else {
            printf("Cards do not match! Try again.\n\n");
        }
    }

    printf("\nCongratulations! You have won Memory Game in %d attempts.\n", attempts);
    return 0;
}