//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Structure to hold the checker piece
typedef struct {
    int color; // 0 - white; 1 - black
} checker;

// Structure to hold the cell on the board
typedef struct {
    checker* piece; // pointer to the checker piece
    int color; // 0 - black; 1 - white
    int state; // 0 - empty; 1 - occupied
} cell;

// Structure to hold the game board
typedef struct {
    cell** cells; // 2D array of cells
} board;

// Function to initialize the board
board* create_board() {
    board* game_board = (board*) malloc(sizeof(board));

    game_board->cells = (cell**) malloc(BOARD_SIZE * sizeof(cell*));

    for (int i = 0; i < BOARD_SIZE; i++) {
        game_board->cells[i] = (cell*) malloc(BOARD_SIZE * sizeof(cell));
        for (int j = 0; j < BOARD_SIZE; j++) {
            game_board->cells[i][j].state = 0;
            game_board->cells[i][j].color = (i+j)%2;
            if (i < 3) {
                checker* piece = (checker*) malloc(sizeof(checker));
                piece->color = 1;
                game_board->cells[i][j].piece = piece;
                game_board->cells[i][j].state = 1;
            }
            if (i > 4) {
                checker* piece = (checker*) malloc(sizeof(checker));
                piece->color = 0;
                game_board->cells[i][j].piece = piece;
                game_board->cells[i][j].state = 1;
            }
        }
    }

    return game_board;
}

// Function to print the board
void print_board(board* game_board) {
    printf("\n\n");
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_board->cells[i][j].state == 1) {
                if (game_board->cells[i][j].piece->color == 0) {
                    printf(" B ");
                }
                else {
                    printf(" W ");
                }
            }
            else {
                printf("   ");
            }
            printf("|");
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

int main() {
    board* game_board = create_board();
    print_board(game_board);
    return 0;
}