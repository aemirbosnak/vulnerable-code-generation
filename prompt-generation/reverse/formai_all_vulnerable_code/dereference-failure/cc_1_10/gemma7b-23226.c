//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the board structure
typedef struct Board {
    char **board;
    char current_player;
    int game_status;
} Board;

// Initialize a new board
Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(BOARD_SIZE * sizeof(char));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
    board->current_player = PLAYER_X;
    board->game_status = 0;
    return board;
}

// Place a piece on the board
void place_piece(Board *board, int x, int y) {
    if (board->board[x][y] != ' ') {
        return;
    }
    board->board[x][y] = board->current_player;
}

// Check if the player has won
int check_win(Board *board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }
    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Play a game of Tic Tac Toe
void play_game(Board *board) {
    int game_loop = 1;
    char current_player = board->current_player;

    // Loop until the game is over
    while (game_loop) {
        // Get the player's move
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        // Place the piece on the board
        place_piece(board, x, y);

        // Check if the player has won
        if (check_win(board, current_player) == 1) {
            board->game_status = 1;
            game_loop = 0;
        } else if (board->board[x][y] == ' ') {
            board->current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        } else {
            game_loop = 0;
        }
    }

    // Print the winner or draw
    if (board->game_status == 1) {
        printf("The winner is: %c\n", board->current_player);
    } else {
        printf("It's a draw.\n");
    }
}

int main() {
    // Initialize the board
    Board *board = init_board();

    // Play the game
    play_game(board);

    // Free the memory
    free(board->board);
    free(board);

    return 0;
}