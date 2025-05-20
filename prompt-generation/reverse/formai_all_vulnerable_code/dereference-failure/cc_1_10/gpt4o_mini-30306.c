//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Dimensions of the grid
#define PAIRS (SIZE * SIZE) / 2

// Function prototypes
void initializeBoard(int board[SIZE][SIZE], int display[SIZE][SIZE]);
void shuffleAndPairNumbers(int board[SIZE][SIZE]);
void displayBoard(int display[SIZE][SIZE]);
bool makeGuess(int board[SIZE][SIZE], int display[SIZE][SIZE], int x1, int y1, int x2, int y2);
bool isBoardCompleted(int display[SIZE][SIZE]);

int main() {
    int board[SIZE][SIZE];
    int display[SIZE][SIZE];
    int guess1[] = {-1, -1}, guess2[] = {-1, -1};
    int tries = 0;

    initializeBoard(board, display);

    printf("Welcome to the Memory Game!\n");
    printf("Try to find all the pairs:\n");

    while (!isBoardCompleted(display)) {
        displayBoard(display);
        printf("Enter coordinates for your first guess (row column): ");
        scanf("%d %d", &guess1[0], &guess1[1]);
        printf("Enter coordinates for your second guess (row column): ");
        scanf("%d %d", &guess2[0], &guess2[1]);

        tries++;
        if (makeGuess(board, display, guess1[0], guess1[1], guess2[0], guess2[1])) {
            printf("Good guess!\n");
        } else {
            printf("Try again.\n");
        }
    }

    printf("Congratulations! You found all pairs in %d tries.\n", tries);
    return 0;
}

// Function to initialize the board and display
void initializeBoard(int board[SIZE][SIZE], int display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display[i][j] = -1; // Use -1 to indicate an unrevealed cell
        }
    }
    shuffleAndPairNumbers(board);
}

// Function to shuffle numbers and create pairs in the board
void shuffleAndPairNumbers(int board[SIZE][SIZE]) {
    int numbers[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        numbers[i] = i + 1; // Fill numbers for the pairs
    }

    // Shuffle the pairs
    srand(time(NULL));
    for (int i = 0; i < PAIRS; i++) {
        int j = rand() % PAIRS;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board with shuffled pairs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
        }
    }
}

// Function to display the current state of the board
void displayBoard(int display[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == -1) {
                printf(" * ");
            } else {
                printf(" %d ", display[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to process a guess
bool makeGuess(int board[SIZE][SIZE], int display[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    if (board[x1][y1] == board[x2][y2]) {
        display[x1][y1] = board[x1][y1];
        display[x2][y2] = board[x2][y2];
        return true; // Correct guess
    }
    return false; // Incorrect guess
}

// Function to check if the game is completed
bool isBoardCompleted(int display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == -1) {
                return false; // There are still unrevealed cells
            }
        }
    }
    return true; // All pairs found
}