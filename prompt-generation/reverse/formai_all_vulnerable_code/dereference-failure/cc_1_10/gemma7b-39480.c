//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **cells;
    int current_player;
} Board;

void initialize_board(Board *board) {
    board->cells = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j] = 0;
        }
    }
    board->current_player = 1;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0) {
            return board->cells[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0) {
            return board->cells[j][0];
        }
    }

    // Check diagonals
    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
        return board->cells[0][0];
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

void make_move(Board *board, int x, int y) {
    if (board->cells[x][y] != 0) {
        return;
    }
    board->cells[x][y] = board->current_player;
    board->current_player *= -1;
}

int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    int game_over = 0;
    while (!game_over) {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Make the move
        make_move(&board, move_x, move_y);

        // Check if the game is over
        game_over = check_win(&board);

        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", board.cells[i][j]);
            }
            printf("\n");
        }

        // Print the game result
        if (game_over) {
            printf("Game Over! The winner is: %d\n", board.cells[move_x][move_y]);
        }
    }

    return 0;
}