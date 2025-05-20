//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVES 9

typedef struct Board {
    char **board;
    int moves;
    char winner;
} Board;

void initializeBoard(Board *board) {
    board->board = (char **)malloc(MAX_MOVES * sizeof(char *));
    for (int i = 0; i < MAX_MOVES; i++) {
        board->board[i] = (char *)malloc(MAX_MOVES * sizeof(char));
    }

    board->moves = 0;
    board->winner = '\0';
}

void placeMove(Board *board, int row, int col, char player) {
    if (board->moves >= MAX_MOVES || board->winner != '\0') {
        return;
    }

    board->board[row][col] = player;
    board->moves++;
}

char checkWinner(Board *board, char player) {
    // Check rows
    for (int r = 0; r < MAX_MOVES; r++) {
        if (board->board[r][0] == player && board->board[r][1] == player && board->board[r][2] == player) {
            return player;
        }
    }

    // Check columns
    for (int c = 0; c < MAX_MOVES; c++) {
        if (board->board[0][c] == player && board->board[1][c] == player && board->board[2][c] == player) {
            return player;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return player;
    }

    // If all moves have been made and there is no winner, it's a draw
    if (board->moves == MAX_MOVES) {
        return 'D';
    }

    // No winner, so return '\0'
    return '\0';
}

int main() {
    Board board;
    initializeBoard(&board);

    // Play the game
    placeMove(&board, 0, 0, 'X');
    placeMove(&board, 1, 1, 'O');
    placeMove(&board, 0, 2, 'X');
    placeMove(&board, 2, 0, 'O');
    placeMove(&board, 1, 0, 'X');

    // Check if there is a winner or a draw
    char winner = checkWinner(&board, 'X');

    // Print the winner or draw
    if (winner == 'X') {
        printf("X won!");
    } else if (winner == 'O') {
        printf("O won!");
    } else if (winner == 'D') {
        printf("It's a draw!");
    }

    return 0;
}