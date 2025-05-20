//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Board structure
typedef struct Board {
    char **board;
    char current_player;
    int game_status;
} Board;

// Initialize a new board
Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(char));
    board->current_player = PLAYER_X;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }

    return board;
}

// Place a piece on the board
void place_piece(Board *board, int x, int y) {
    if (board->board[x][y] != ' ') {
        return;
    }

    board->board[x][y] = board->current_player;
}

// Check if the game is over
int check_game_over(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
        return 1;
    }

    // If all cells are filled and there is no winner, it's a draw
    return 2;
}

// Play a game of Tic Tac Toe
int main() {
    Board *board = init_board();

    // Game loop
    while (!check_game_over(board)) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Place the piece
        place_piece(board, x, y);

        // Switch players
        board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    switch (check_game_over(board)) {
        case 1:
            printf("Winner: %c!\n", board->current_player);
            break;
        case 2:
            printf("It's a draw!\n");
            break;
    }

    return 0;
}