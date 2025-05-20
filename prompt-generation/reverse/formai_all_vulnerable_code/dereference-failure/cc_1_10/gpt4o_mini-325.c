//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // Define the size of the game board (4x4)

// Function to initialize the game board with pairs of numbers
void initializeBoard(int board[SIZE][SIZE]) {
    int numbers[SIZE * SIZE / 2]; // Array to hold pairs of numbers
    for (int i = 0; i < (SIZE * SIZE) / 2; i++) {
        numbers[i] = i + 1;  // Fill with numbers 1 to 8
    }

    // Create pairs
    for (int i = 0; i < (SIZE * SIZE) / 2; i++) {
        board[i / SIZE][i % SIZE] = numbers[i];
        board[(i + 8) / SIZE][(i + 8) % SIZE] = numbers[i];
    }

    // Shuffle the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int randRow = rand() % SIZE;
            int randCol = rand() % SIZE;

            // Swap values
            int temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

// Function to display the game board
void displayBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");  // Hide the number with an asterisk
            }
        }
        printf("\n");
    }
}

// Function to check for a match
int checkMatch(int board[SIZE][SIZE], int firstGuess[2], int secondGuess[2]) {
    return board[firstGuess[0]][firstGuess[1]] == board[secondGuess[0]][secondGuess[1]];
}

// Function to update the revealed state of the board
void revealPositions(int revealed[SIZE][SIZE], int guess[2], int value) {
    revealed[guess[0]][guess[1]] = value;
}

// Main function for the game logic
int main() {
    srand(time(NULL)); // Seed random number generator

    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // Keep track of revealed positions
    int pairsFound = 0;
    int totalPairs = (SIZE * SIZE) / 2;

    initializeBoard(board);

    printf("Welcome to the Memory Game!\n");
    
    while (pairsFound < totalPairs) {
        displayBoard(board, revealed);

        int guess1[2], guess2[2];

        // Get the first guess
        printf("Enter coordinates for the first guess (row and column): ");
        scanf("%d %d", &guess1[0], &guess1[1]);

        // Reveal the first guess
        revealPositions(revealed, guess1, 1);
        displayBoard(board, revealed);

        // Get the second guess
        printf("Enter coordinates for the second guess (row and column): ");
        scanf("%d %d", &guess2[0], &guess2[1]);

        // Reveal the second guess
        revealPositions(revealed, guess2, 1);
        displayBoard(board, revealed);

        // Check for a match
        if (checkMatch(board, guess1, guess2)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again!\n");
            // Hide the guesses after a brief display
            sleep(2);
            revealPositions(revealed, guess1, 0);
            revealPositions(revealed, guess2, 0);
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}