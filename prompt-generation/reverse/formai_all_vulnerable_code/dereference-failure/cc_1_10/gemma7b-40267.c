//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char value;
} Cell;

void initBoard(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c].row = r;
            board[r][c].col = c;
            board[r][c].value = ' ';
        }
    }
}

void drawBoard(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c].value);
        }
        printf("\n");
    }
}

int isWin(Cell **board, char player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0].value == player && board[r][1].value == player && board[r][2].value == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c].value == player && board[1][c].value == player && board[2][c].value == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0].value == player && board[1][1].value == player && board[2][2].value == player) {
        return 1;
    }

    // If all cells are occupied and no winner, it's a draw
    return 0;
}

int main() {
    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Cell *)malloc(BOARD_SIZE * sizeof(Cell));
    }

    initBoard(board);

    char player = 'X';
    int gameWon = 0;

    // Game loop
    while (!gameWon) {
        // Get the player's move
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (board[row][col].value != ' ' || isWin(board, player) == 1) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][col].value = player;

        // Draw the board
        drawBoard(board);

        // Check if the player has won
        gameWon = isWin(board, player);

        // If the game is not won, switch to the next player
        if (!gameWon) {
            player = 'O';
        }
    }

    // Draw the board
    drawBoard(board);

    // Announce the winner or draw
    if (gameWon) {
        printf("Winner: %c!\n", player);
    } else {
        printf("Draw!\n");
    }

    return 0;
}