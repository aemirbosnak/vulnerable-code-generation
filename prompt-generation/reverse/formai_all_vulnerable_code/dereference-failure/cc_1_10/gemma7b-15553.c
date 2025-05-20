//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }

    board->current_player = 1;
    board->game_status = 0;
}

int place_piece(Board *board, int row, int column) {
    if (board->board[row][column] != 0) {
        return -1;
    }

    board->board[row][column] = board->current_player;
    return 0;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // If all cells are filled and there is no winner, it's a draw
    return 3;
}

int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    while (!board.game_status) {
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        if (place_piece(&board, row, column) == -1) {
            printf("Error: Invalid move.\n");
        } else {
            board.current_player = (board.current_player == 1) ? 2 : 1;
        }
    }

    // Show the winner or draw
    switch (check_win(&board)) {
        case 1:
            printf("Player 1 won!\n");
            break;
        case 2:
            printf("Player 2 won!\n");
            break;
        case 3:
            printf("It's a draw.\n");
            break;
    }

    return 0;
}