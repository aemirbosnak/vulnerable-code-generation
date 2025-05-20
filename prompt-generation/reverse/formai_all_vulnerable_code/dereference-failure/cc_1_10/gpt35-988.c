//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 9

// Function to clear the console screen
void clearScreen() {
    printf("\033[2J"); 
    printf("\033[%d;%dH", 0, 0);
}

// Function to print the game board
void printBoard(char board[][COLS], int score) {
    clearScreen();
    printf("Score: %d\n\n", score);
    printf("  1 2 3 4 5 6 7 8 9\n");
    printf(" +-+-+-+-+-+-+-+-+-+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < COLS; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +-+-+-+-+-+-+-+-+-+\n");
    }
}

// Function to update the game board
void updateBoard(char board[][COLS], int *score, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = 'O';
        *score += 10;
    } else {
        board[row][col] = 'X';
        *score -= 5;
    }
}

// Function to check if the game is over
int gameOver(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Initialize the game board and score
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    int score = 0;

    // Set the random seed for the game
    srand(time(NULL));

    // Print the game instructions
    printf("Welcome to the Whack-a-Mole game!\n");
    printf("Instructions:\n");
    printf(" - Moles will randomly appear on the board as 'O'\n");
    printf(" - You must hit the moles by entering the row and column number where they appear\n");
    printf(" - You get 10 points for hitting a mole, but lose 5 points for hitting an already hit mole or missing a mole\n");
    printf(" - The game is over when there are no more moles to hit\n");
    printf(" - Have fun!\n\n");

    // Sleep for 3 seconds to let the user read the instructions
    printf("Starting in 3 seconds...\n");
    sleep(3);

    // Start the game loop
    while (1) {
        // Check if the game is over
        if (gameOver(board)) {
            break;
        }

        // Generate a random mole position
        int row = rand() % ROWS;
        int col = rand() % COLS;

        // Update the game board
        printBoard(board, score);
        printf("Enter row and column number (separated by a space): ");
        int userRow, userCol;
        scanf("%d %d", &userRow, &userCol);
        updateBoard(board, &score, userRow-1, userCol-1);
        printf("\n");

        // Sleep for 1 second to give the user time to see the updated board
        sleep(1);
    }

    // Game over, print the final score
    printBoard(board, score);
    printf("Game over! Final score: %d\n", score);

    return 0;
}