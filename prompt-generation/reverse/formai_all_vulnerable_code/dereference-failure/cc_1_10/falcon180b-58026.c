//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Function to initialize the game board
void initializeBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = -1; // Initialize all elements to -1 (indicating empty)
        }
    }
}

// Function to print the game board
void printBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == -1) {
                printf(" %d ", -1);
            } else {
                printf(" %d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if two cards match
int matchCards(int card1, int card2) {
    return (card1 == card2);
}

// Function to play the game
void playGame(int board[MAX_ROWS][MAX_COLS]) {
    int i, j, k, numCards = 0, matches = 0;
    int card1, card2;
    srand(time(NULL)); // Seed the random number generator

    // Initialize the game board with random numbers
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 10 + 1; // Random number between 1 and 10
            numCards++;
        }
    }

    // Shuffle the game board
    for (i = 0; i < numCards; i++) {
        int row = rand() % MAX_ROWS;
        int col = rand() % MAX_COLS;
        int temp = board[row][col];
        board[row][col] = board[i][0];
        board[i][0] = temp;
    }

    // Print the game board
    printf("Game Board:\n");
    printBoard(board);

    // Play the game
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j]!= -1) {
                card1 = board[i][j];
                for (k = 0; k < MAX_COLS; k++) {
                    if (board[i][k] == card1) {
                        board[i][k] = -1; // Remove the matching card
                        matches++;
                        break;
                    }
                }
            }
        }
    }

    // Print the final game board
    printf("\nFinal Game Board:\n");
    printBoard(board);

    // Print the number of matches
    printf("\nNumber of matches: %d\n", matches);
}

int main() {
    int board[MAX_ROWS][MAX_COLS];

    // Initialize the game board
    initializeBoard(board);

    // Play the game
    playGame(board);

    return 0;
}