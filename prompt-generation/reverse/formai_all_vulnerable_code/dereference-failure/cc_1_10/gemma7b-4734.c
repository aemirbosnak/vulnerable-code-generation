//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

// Define the board structure
typedef struct Board {
    int **cells;
    int current_player;
    int game_status;
} Board;

// Function to initialize the board
void init_board(Board *board) {
    board->cells = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->current_player = PLAYER_X;
    board->game_status = 0;
}

// Function to place a piece on the board
void place_piece(Board *board, int row, int col) {
    if (board->cells[row][col] != 0) {
        return;
    }
    board->cells[row][col] = board->current_player;
    board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

// Function to check if the game is over
int check_game_over(Board *board) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->cells[r][0] == board->cells[r][1] && board->cells[r][0] == board->cells[r][2] && board->cells[r][0] != 0) {
            return board->cells[r][0] * 2;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->cells[0][c] == board->cells[1][c] && board->cells[0][c] == board->cells[2][c] && board->cells[0][c] != 0) {
            return board->cells[0][c] * 2;
        }
    }

    // Check diagonals
    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
        return board->cells[0][0] * 2;
    }

    // If all cells are occupied and there is no winner, the game is a draw
    if (board->game_status == 0) {
        return 3;
    }

    return 0;
}

// Main game loop
int main() {
    Board board;
    init_board(&board);

    // Play until the game is over
    while (!check_game_over(&board)) {
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        place_piece(&board, row, col);
    }

    // Print the winner or draw
    switch (check_game_over(&board)) {
        case PLAYER_X * 2:
            printf("Player X won!\n");
            break;
        case PLAYER_O * 2:
            printf("Player O won!\n");
            break;
        case 3:
            printf("It's a draw!\n");
            break;
    }

    return 0;
}