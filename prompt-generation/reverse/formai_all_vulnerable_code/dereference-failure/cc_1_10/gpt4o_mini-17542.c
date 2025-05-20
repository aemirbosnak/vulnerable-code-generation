//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_PAIRS (SIZE * SIZE / 2)

void initializeBoard(int board[SIZE][SIZE], int pairs[NUM_PAIRS]);
void displayBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int chooseCell(int player);
int checkMatch(int board[SIZE][SIZE], int choice1, int choice2);
void playGame(void);

int main(void) {
    srand(time(NULL)); // Seed for random number generation
    playGame();
    return 0;
}

void playGame(void) {
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // To track revealed cards
    int pairs[NUM_PAIRS];
    int player1Score = 0, player2Score = 0;
    int playerTurn = 1;
    int attempts = 0;

    initializeBoard(board, pairs);

    while (attempts < NUM_PAIRS) {
        displayBoard(board, revealed);
        printf("Player %d's turn!\n", playerTurn);

        int choice1 = chooseCell(playerTurn);
        revealed[choice1 / SIZE][choice1 % SIZE] = 1;
        displayBoard(board, revealed);
        
        int choice2 = chooseCell(playerTurn);
        revealed[choice2 / SIZE][choice2 % SIZE] = 1;
        displayBoard(board, revealed);

        if (checkMatch(board, choice1, choice2)) {
            printf("Player %d found a match!\n", playerTurn);
            if (playerTurn == 1) player1Score++;
            else player2Score++;
            attempts++;
        } else {
            printf("No match! Next player's turn.\n");
            revealed[choice1 / SIZE][choice1 % SIZE] = 0;
            revealed[choice2 / SIZE][choice2 % SIZE] = 0;
            playerTurn = (playerTurn == 1) ? 2 : 1;
        }

        printf("Scores -> Player 1: %d, Player 2: %d\n\n", player1Score, player2Score);
    }

    printf("Game Over!\n");
    printf("Final Scores -> Player 1: %d, Player 2: %d\n", player1Score, player2Score);
    if (player1Score > player2Score) {
        printf("Player 1 wins!\n");
    } else if (player1Score < player2Score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

void initializeBoard(int board[SIZE][SIZE], int pairs[NUM_PAIRS]) {
    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i] = i + 1; // Fill pairs with numbers 1 through NUM_PAIRS
    }

    // Shuffle the pairs
    for (int i = 0; i < NUM_PAIRS; i++) {
        int j = rand() % NUM_PAIRS;
        int temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

    // Fill the board with pairs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = pairs[(i * SIZE + j) / 2]; // Assign pairs to the board
        }
    }
}

void displayBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("X\t"); // Show X for unrevealed cells
            }
        }
        printf("\n");
    }
}

int chooseCell(int player) {
    int row, col;
    printf("Enter row (0 to %d) and column (0 to %d): ", SIZE-1, SIZE-1);
    scanf("%d %d", &row, &col);
    return row * SIZE + col; // Return cell index
}

int checkMatch(int board[SIZE][SIZE], int choice1, int choice2) {
    return board[choice1 / SIZE][choice1 % SIZE] == board[choice2 / SIZE][choice2 % SIZE];
}