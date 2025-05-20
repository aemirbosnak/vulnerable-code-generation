//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK 2
#define EMPTY 0

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

void initialize_board(GameState *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    game->board[0][0] = game->board[0][7] = BLACK; // Rooks
    game->board[0][1] = game->board[0][6] = BLACK; // Knights
    game->board[0][2] = game->board[0][5] = BLACK; // Bishops
    game->board[0][3] = BLACK; // Queen
    game->board[0][4] = BLACK; // King
    for (int i = 0; i < BOARD_SIZE; i++) game->board[1][i] = BLACK; // Pawns

    game->board[7][0] = game->board[7][7] = WHITE; 
    game->board[7][1] = game->board[7][6] = WHITE; 
    game->board[7][2] = game->board[7][5] = WHITE; 
    game->board[7][3] = WHITE; 
    game->board[7][4] = WHITE;
    for (int i = 0; i < BOARD_SIZE; i++) game->board[6][i] = WHITE;

    game->turn = WHITE;
}

void print_board(GameState *game) {
    printf("Current Board State:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board[i][j]) {
                case WHITE: printf("W "); break;
                case BLACK: printf("B "); break;
                case EMPTY: printf(". "); break;
            }
        }
        printf("\n");
    }
    printf("Turn: %s\n", game->turn == WHITE ? "White" : "Black");
}

bool is_valid_move(int piece, int start_row, int start_col, int end_row, int end_col) {
    // Simplistic move validation logic
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) return false;
    return (piece == WHITE && (end_row > start_row)) || (piece == BLACK && (end_row < start_row));
}

void make_move(GameState *game, int start_row, int start_col, int end_row, int end_col) {
    if (is_valid_move(game->board[start_row][start_col], start_row, start_col, end_row, end_col)) {
        game->board[end_row][end_col] = game->board[start_row][start_col];
        game->board[start_row][start_col] = EMPTY;
        game->turn = (game->turn == WHITE) ? BLACK : WHITE;
    } else {
        printf("Invalid Move!\n");
    }
}

bool is_game_over(GameState *game) {
    // Simplistic check for game over
    int white_king = 0, black_king = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == WHITE && (i == 7 && j == 4)) white_king++;
            if (game->board[i][j] == BLACK && (i == 0 && j == 4)) black_king++;
        }
    }
    return (white_king == 0 || black_king == 0);
}

int main() {
    GameState game;
    initialize_board(&game);
    
    while (!is_game_over(&game)) {
        print_board(&game);
        int start_row, start_col, end_row, end_col;
        printf("Enter your move (start_row start_col end_row end_col): ");
        if (scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col) != 4) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            return EXIT_FAILURE;
        }
        make_move(&game, start_row, start_col, end_row, end_col);
    }

    printf("Game over! Thank you for playing.\n");
    return EXIT_SUCCESS;
}