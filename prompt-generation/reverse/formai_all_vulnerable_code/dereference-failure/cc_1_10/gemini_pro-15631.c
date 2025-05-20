//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int** createBoard(int rows, int cols);
void printBoard(int** board, int rows, int cols);
int checkPair(int** board, int firstRow, int firstCol, int secondRow, int secondCol);
int playGame(int** board, int rows, int cols);

int main() {
    // Welcome the player
    printf("Welcome to the C Memory Game!\n");
    printf("Your goal is to match pairs of hidden numbers on a board.\n");

    // Set up the game parameters
    int rows = 4;
    int cols = 4;
    int** board = createBoard(rows, cols);

    // Print the initial board
    printBoard(board, rows, cols);

    // Start the game
    int win = playGame(board, rows, cols);

    // Declare the winner
    if (win) {
        printf("Congratulations! You found all the pairs!\n");
    } else {
        printf("Game over. Better luck next time!\n");
    }

    // Free the board
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

// Function to create the game board
int** createBoard(int rows, int cols) {
    // Allocate memory for the board
    int** board = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }

    // Initialize the board with random numbers
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 10 + 1;
        }
    }

    return board;
}

// Function to print the game board
void printBoard(int** board, int rows, int cols) {
    // Print the board header
    printf("   ");
    for (int i = 0; i < cols; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    // Print the board rows
    for (int i = 0; i < rows; i++) {
        printf("%d  ", i);
        for (int j = 0; j < cols; j++) {
            printf("%2c ", '*');
        }
        printf("\n");
    }
}

// Function to check if a pair of numbers match
int checkPair(int** board, int firstRow, int firstCol, int secondRow, int secondCol) {
    // Check if the numbers match
    if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
        return 1;
    } else {
        return 0;
    }
}

// Function to play the game
int playGame(int** board, int rows, int cols) {
    int firstRow = -1, firstCol = -1, secondRow = -1, secondCol = -1;
    int pairsFound = 0;

    // Continue until all pairs are found
    while (pairsFound < rows * cols / 2) {
        // Get the first card selection
        printf("Enter the coordinates of the first card (row, col): ");
        scanf("%d %d", &firstRow, &firstCol);

        // Check if the coordinates are valid
        if (firstRow < 0 || firstRow >= rows || firstCol < 0 || firstCol >= cols) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        // Get the second card selection
        printf("Enter the coordinates of the second card (row, col): ");
        scanf("%d %d", &secondRow, &secondCol);

        // Check if the coordinates are valid
        if (secondRow < 0 || secondRow >= rows || secondCol < 0 || secondCol >= cols) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        // Check if the cards match
        if (checkPair(board, firstRow, firstCol, secondRow, secondCol)) {
            // The cards match. Reveal them and increment the number of pairs found.
            board[firstRow][firstCol] = '*';
            board[secondRow][secondCol] = '*';
            pairsFound++;
            printBoard(board, rows, cols);
            printf("Match found!\n");
        } else {
            // The cards do not match. Hide them again.
            printBoard(board, rows, cols);
            printf("No match. Try again.\n");
        }
    }

    // Return 1 if all pairs were found, 0 otherwise
    if (pairsFound == rows * cols / 2) {
        return 1;
    } else {
        return 0;
    }
}