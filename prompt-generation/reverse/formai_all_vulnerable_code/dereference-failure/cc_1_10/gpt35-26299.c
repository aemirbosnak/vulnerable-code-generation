//FormAI DATASET v1.0 Category: Chess AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

// Board structure
struct board {
    int squares[BOARD_WIDTH][BOARD_HEIGHT];
};

// Initializes the board
void init_board(struct board *game_board) {
    int i, j;

    // Setting up the initial board positions
    game_board->squares[0][0] = game_board->squares[0][7] = 1;
    game_board->squares[7][0] = game_board->squares[7][7] = 8;

    // Setting up the pawns positions
    for (i = 1; i < BOARD_WIDTH - 1; i++) {
        game_board->squares[i][1] = 2;
        game_board->squares[i][6] = 7;
    }

    // Filling in the remaining squares with zeroes
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 2; j < 6; j++) {
            game_board->squares[i][j] = 0;
        }
    }
}

// Prints the board
void print_board(struct board *game_board) {
    int i, j;

    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            printf("%d ", game_board->squares[j][i]);
        }
        printf("\n");
    }
}

int main() {
    struct board *game_board = (struct board *)malloc(sizeof(struct board));
    init_board(game_board);
    print_board(game_board);

    return 0;
}