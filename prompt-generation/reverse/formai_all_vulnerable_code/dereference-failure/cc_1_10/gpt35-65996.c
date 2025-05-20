//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_PLAYERS 4 // Number of players in the game
#define BOARD_SIZE 20 // Size of the game board

// Function prototypes
void initializeBoard(int board[]);
void printBoard(int board[], int currentPlayer);
bool playTurn(int board[], int* currentPlayer);
void applyBitwiseOperation(int* a, int* b, int op);

int main() {
    int board[BOARD_SIZE]; // The game board
    int currentPlayer = 0; // The current player in the game

    initializeBoard(board);

    // Game loop
    while (true) {
        printBoard(board, currentPlayer);

        // Play the turn for the current player
        bool finishedTurn = playTurn(board, &currentPlayer);

        // If the player has won the game, break out of the loop
        if (board[BOARD_SIZE - 1] == currentPlayer + 1) {
            printf("Player %d wins the game!\n", currentPlayer + 1);
            break;
        }

        // Move on to the next player if the current player has finished their turn
        if (finishedTurn) {
            currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
        }
    }

    return 0;
}

// Initializes the game board with random values
void initializeBoard(int board[]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = rand() % 256;
    }
}

// Prints the game board and highlights the current player's position
void printBoard(int board[], int currentPlayer) {
    printf("Current board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == 0) {
            printf("  * ");
        }
        else {
            printf("%3d ", board[i]);
        }
    }
    printf("\n");

    // Print the current player's position
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i == currentPlayer) {
            printf("  ^ ");
        }
        else {
            printf("    ");
        }
    }
    printf("\n\n");
}

// Plays the turn for the current player
bool playTurn(int board[], int* currentPlayer) {
    int move;

    // Get the move from the user
    printf("Player %d, enter the number of positions to move (1-6): ", *currentPlayer + 1);
    scanf("%d", &move);
    printf("\n");

    // Apply the bitwise operation to the current position and the move value
    applyBitwiseOperation(&board[*currentPlayer], &move, *currentPlayer % 3);

    // Calculate the new position of the player on the board
    int newPosition = (*currentPlayer + move) % BOARD_SIZE;

    // Move the player on the board
    board[*currentPlayer] = 0;
    board[newPosition] = *currentPlayer + 1;

    // Check if the player has landed on a zero value
    if (board[newPosition] == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Applies the specified bitwise operation to the two integers
void applyBitwiseOperation(int* a, int* b, int op) {
    switch (op) {
        case 0: // AND
            *a &= *b;
            break;
        case 1: // OR
            *a |= *b;
            break;
        case 2: // XOR
            *a ^= *b;
            break;
    }
}