//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char get_free_space(char **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == ' ') {
                return board[r][c];
            }
        }
    }
    return 'N';
}

int check_win(char **board) {
    // Horizontal win
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != ' ') {
            return 1;
        }
    }

    // Vertical win
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != ' ') {
            return 1;
        }
    }

    // Diagonal win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    // No win
    return 0;
}

void ai_move(char **board) {
    char move = get_free_space(board);

    // Make the move
    board[move - '1'][move - '1'] = 'O';
}

int main() {
    ai_move(board);
    printf("%c", board[0][0]);
    return 0;
}