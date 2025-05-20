//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_PAIRS (SIZE * SIZE) / 2

void initializeBoard(int board[SIZE][SIZE]);
void shuffleBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int checkMatch(int guess1[2], int guess2[2], int board[SIZE][SIZE]);
int allMatched(int revealed[SIZE][SIZE]);

int main() {
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 = hidden, 1 = revealed
    int guess1[2], guess2[2];
    int pairsFound = 0, turns = 0;

    srand(time(NULL)); // Seed the random number generator
    initializeBoard(board);
    shuffleBoard(board);

    printf("Welcome to the Memory Game!\n");
    printf("Try to find all pairs in the least number of turns.\n");

    while (pairsFound < NUM_PAIRS) {
        printBoard(board, revealed);
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &guess1[0], &guess1[1]);
        guess1[0]--; guess1[1]--; // Adjusting for 0 index

        if (revealed[guess1[0]][guess1[1]] == 1) {
            printf("Card is already revealed! Try again.\n");
            continue;
        }

        revealed[guess1[0]][guess1[1]] = 1;
        printBoard(board, revealed);

        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &guess2[0], &guess2[1]);
        guess2[0]--; guess2[1]--; // Adjusting for 0 index

        if (revealed[guess2[0]][guess2[1]] == 1) {
            printf("Card is already revealed! Try again.\n");
            revealed[guess1[0]][guess1[1]] = 0; // Hide first guess
            continue;
        }

        revealed[guess2[0]][guess2[1]] = 1;
        printBoard(board, revealed);
        turns++;

        if (checkMatch(guess1, guess2, board)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            revealed[guess1[0]][guess1[1]] = 0; // Hide first guess
            revealed[guess2[0]][guess2[1]] = 0; // Hide second guess
        }
    }

    printBoard(board, revealed);
    printf("You've found all pairs in %d turns!\n", turns);
    
    return 0;
}

void initializeBoard(int board[SIZE][SIZE]) {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i * SIZE + j < NUM_PAIRS) {
                board[i][j] = num;
                if (num == NUM_PAIRS) num = 1; // Cycle the numbers
                else num++;
            } else {
                board[i][j] = 0; // Fill remaining cells with zeros
            }
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int randRow = rand() % SIZE;
            int randCol = rand() % SIZE;
            int temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

void printBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
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
}

int checkMatch(int guess1[2], int guess2[2], int board[SIZE][SIZE]) {
    return board[guess1[0]][guess1[1]] == board[guess2[0]][guess2[1]];
}

int allMatched(int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 0) {
                return 0; // There's at least one card that is not revealed
            }
        }
    }
    return 1; // All cards are revealed
}