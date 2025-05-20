//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

// Define the board structure
typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

// Function to initialize the board
void initialize_board(Board *board) {
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->current_player = PLAYER_X;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

// Function to place a piece on the board
void place_piece(Board *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return;
    }

    board->board[x][y] = board->current_player;

    if (board->current_player == PLAYER_X) {
        board->current_player = PLAYER_O;
    } else {
        board->current_player = PLAYER_X;
    }
}

// Function to check if the game is over
int check_game_over(Board *board) {
    // Check if the current player has won
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check if the player has won in a row
        if (board->board[i][0] == board->board[i][1] && board->board[i][0] == board->board[i][2] && board->board[i][0] != 0) {
            return 1;
        }

        // Check if the player has won in a column
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return 1;
        }
    }

    // Check if the board is full
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }

    // If there are no winners and the board is full, the game is a draw
    return 2;
}

// Main game loop
int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    while (!check_game_over(&board)) {
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);
        place_piece(&board, x, y);
    }

    // Check if the game is over
    switch (check_game_over(&board)) {
        case 1:
            printf("You won!");
            break;
        case 2:
            printf("It's a draw!");
            break;
        default:
            printf("Error!");
            break;
    }

    return 0;
}