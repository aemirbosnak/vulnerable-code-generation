//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char value;
} Cell;

void initializeBoard(Cell **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].row = i;
            board[i][j].col = j;
            board[i][j].value = ' ';
        }
    }
}

void displayBoard(Cell **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].value);
        }
        printf("\n");
    }
}

int checkWin(Cell **board) {
    // Vertical win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i].value == board[1][i].value && board[0][i].value == board[2][i].value) {
            return 1;
        }
    }

    // Horizontal win
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0].value == board[j][1].value && board[j][0].value == board[j][2].value) {
            return 1;
        }
    }

    // Diagonal win
    if (board[0][0].value == board[1][1].value && board[0][0].value == board[2][2].value) {
        return 1;
    }

    // Draw
    if (board[0][0].value != ' ' && board[0][1].value != ' ' && board[0][2].value != ' ' && board[1][0].value != ' ' && board[1][1].value != ' ' && board[1][2].value != ' ' && board[2][0].value != ' ' && board[2][1].value != ' ' && board[2][2].value != ' ') {
        return 2;
    }

    return 0;
}

int main() {
    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    initializeBoard(board);

    // Play the game
    int gameWon = 0;
    char playerTurn = 'X';

    // Loop until someone wins or it's a draw
    while (!gameWon) {
        // Get the player's move
        int row = -1;
        int col = -1;

        // Validate the move
        while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col].value != ' ') {
            printf("Invalid move. Please try again: ");
            scanf("%d %d", &row, &col);
        }

        // Make the move
        board[row][col].value = playerTurn;

        // Check if the player has won
        gameWon = checkWin(board);

        // Switch turns
        playerTurn = (playerTurn == 'X') ? 'O' : 'X';
    }

    // Display the board
    displayBoard(board);

    // Print the winner or draw
    if (gameWon == 1) {
        printf("Congratulations! %c won!", playerTurn);
    } else if (gameWon == 2) {
        printf("It's a draw!");
    }

    // Free the memory
    free(board);

    return 0;
}