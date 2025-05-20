//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Pos;

typedef struct {
    char type;
    Pos pos;
} Piece;

typedef struct {
    Piece pieces[16];
} Board;

typedef struct {
    int color;
    int in_check;
    int checkmate;
} Player;

typedef struct {
    Board board;
    Player players[2];
} Game;

void init_game(Game *game) {
    for (int i = 0; i < 8; i++) {
        game->board.pieces[i] = (Piece){'P', {i, 1}};
        game->board.pieces[i + 8] = (Piece){'p', {i, 6}};
    }
    game->board.pieces[0] = (Piece){'R', {0, 0}};
    game->board.pieces[1] = (Piece){'N', {1, 0}};
    game->board.pieces[2] = (Piece){'B', {2, 0}};
    game->board.pieces[3] = (Piece){'Q', {3, 0}};
    game->board.pieces[4] = (Piece){'K', {4, 0}};
    game->board.pieces[5] = (Piece){'B', {5, 0}};
    game->board.pieces[6] = (Piece){'N', {6, 0}};
    game->board.pieces[7] = (Piece){'R', {7, 0}};
    game->players[0].color = 0;
    game->players[1].color = 1;
    game->players[0].in_check = 0;
    game->players[1].in_check = 0;
    game->players[0].checkmate = 0;
    game->players[1].checkmate = 0;
}

void print_board(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            if (piece.type == 0) {
                printf("  ");
            } else {
                printf("%c ", piece.type);
            }
        }
        printf("\n");
    }
}

int main() {
    Game game;
    init_game(&game);
    print_board(&game.board);
    return 0;
}