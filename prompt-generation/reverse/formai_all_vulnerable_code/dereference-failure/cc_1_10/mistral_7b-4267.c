//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_PAIRS 4

// Function to initialize the board with random numbers
void init_board(int board[ROWS][COLS]) {
    int numbers[NUM_PAIRS];
    int i, j;

    // Initialize an array with unique numbers to be shuffled and placed on the board
    for (i = 0; i < NUM_PAIRS; i++) {
        numbers[i] = i * 2 + 1;
    }

    // Shuffle the numbers using Fisher-Yates shuffle algorithm
    for (i = NUM_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Place the numbers on the board
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = numbers[i * COLS + j];
        }
    }
}

// Function to check if two numbers are matching
bool is_matching(int board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    return (board[row1][col1] == board[row2][col2]);
}

// Function to print the board
void print_board(int board[ROWS][COLS]) {
    int i, j;

    printf("     ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to handle the player's guess
void handle_guess(int board[ROWS][COLS], int* turns, int* score) {
    int row1, col1, row2, col2;

    printf("Enter the row and column of the first number: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter the row and column of the second number: ");
    scanf("%d%d", &row2, &col2);

    if (row1 == row2 && col1 == col2) {
        // Matching numbers, mark them as matched and increment the score
        board[row1][col1] = board[row2][col2] = -1;
        (*score)++;
    } else {
        // Incorrect guess, lose a turn
        printf("Incorrect guess. You lose a turn.\n");
        (*turns)--;
    }
}

int main() {
    int board[ROWS][COLS], turns = ROWS * COLS, score = 0;

    // Initialize the board with random numbers
    init_board(board);

    // Game loop
    while (turns > 0) {
        print_board(board);
        handle_guess(board, &turns, &score);
    }

    // Print the final score
    printf("\nGame Over! Your score is: %d\n", score);

    return 0;
}