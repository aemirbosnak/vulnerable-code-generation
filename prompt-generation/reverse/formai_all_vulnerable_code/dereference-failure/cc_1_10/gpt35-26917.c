//FormAI DATASET v1.0 Category: Chess engine ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int type;
    Position position;
    bool moved;
} Piece;

typedef struct {
    Piece **board;
    int white_captured;
    int black_captured;
    Position white_king;
    Position black_king;
    char *history;
    int move_count;
    bool white_turn;
} Game;

Piece *create_piece(int type, int x, int y) {
    Piece *piece = malloc(sizeof(Piece));
    piece->type = type;
    piece->position.x = x;
    piece->position.y = y;
    piece->moved = false;
    return piece;
}

void initialize_board(Game *game) {
    game->board = malloc(sizeof(Piece*) * BOARD_SIZE);
    for(int i=0; i < BOARD_SIZE; i++) {
        game->board[i] = malloc(sizeof(Piece) * BOARD_SIZE);
    }

    // set up pawns
    for(int i=0; i < BOARD_SIZE; i++) {
        game->board[1][i] = *create_piece(1, i, 1); // black pawn
        game->board[6][i] = *create_piece(-1, i, 6); // white pawn
    }
    // set up rooks
    game->board[0][0] = *create_piece(2, 0, 0); // black rook
    game->board[0][7] = *create_piece(2, 7, 0); // black rook
    game->board[7][0] = *create_piece(-2, 0, 7); // white rook
    game->board[7][7] = *create_piece(-2, 7, 7); // white rook
    // set up knights
    game->board[0][1] = *create_piece(3, 1, 0); // black knight
    game->board[0][6] = *create_piece(3, 6, 0); // black knight
    game->board[7][1] = *create_piece(-3, 1, 7); // white knight
    game->board[7][6] = *create_piece(-3, 6, 7); // white knight
    // set up bishops
    game->board[0][2] = *create_piece(4, 2, 0); // black bishop
    game->board[0][5] = *create_piece(4, 5, 0); // black bishop
    game->board[7][2] = *create_piece(-4, 2, 7); // white bishop
    game->board[7][5] = *create_piece(-4, 5, 7); // white bishop
    // set up kings
    game->board[0][4] = *create_piece(6, 4, 0); // black king
    game->board[7][4] = *create_piece(-6, 4, 7); // white king
    game->black_king = (Position) {4, 0};
    game->white_king = (Position) {4, 7};
    // set up queens
    game->board[0][3] = *create_piece(5, 3, 0); // black queen
    game->board[7][3] = *create_piece(-5, 3, 7); // white queen

    game->white_captured = 0;
    game->black_captured = 0;
    game->history = malloc(sizeof(char) * BOARD_SIZE * BOARD_SIZE * 5); // assuming max 5 chars per move
    game->move_count = 1;
    game->white_turn = true;
}

void print_board(Game *game) {
    for(int i=0; i < BOARD_SIZE; i++) {
        for(int j=0; j < BOARD_SIZE; j++) {
            if(game->board[i][j].type != 0) {
                printf("%d ", game->board[i][j].type);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Game game;
    initialize_board(&game);
    print_board(&game);
    return 0;
}