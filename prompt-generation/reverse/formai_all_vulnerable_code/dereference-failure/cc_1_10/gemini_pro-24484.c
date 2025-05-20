//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[16];
    int num_pieces;
} Board;

typedef struct {
    Board board;
    int player_turn;
} Game;

void init_board(Board *board) {
    board->num_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = {0, {i, j}};
            board->pieces[board->num_pieces++] = piece;
        }
    }
}

void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board->pieces[i * BOARD_SIZE + j];
            printf("%c ", piece.type);
        }
        printf("\n");
    }
}

int main() {
    Game game;
    init_board(&game.board);
    game.player_turn = 1;

    while (1) {
        print_board(&game.board);

        // Get player input
        Position from, to;
        printf("Enter move from (x, y): ");
        scanf("%d %d", &from.x, &from.y);
        printf("Enter move to (x, y): ");
        scanf("%d %d", &to.x, &to.y);

        // Validate move
        if (from.x < 0 || from.x >= BOARD_SIZE || from.y < 0 || from.y >= BOARD_SIZE) {
            printf("Invalid move: From position is out of bounds.\n");
            continue;
        }
        if (to.x < 0 || to.x >= BOARD_SIZE || to.y < 0 || to.y >= BOARD_SIZE) {
            printf("Invalid move: To position is out of bounds.\n");
            continue;
        }
        Piece from_piece = game.board.pieces[from.x * BOARD_SIZE + from.y];
        if (from_piece.type == 0) {
            printf("Invalid move: No piece at from position.\n");
            continue;
        }
        if (from_piece.type != game.board.pieces[to.x * BOARD_SIZE + to.y].type) {
            printf("Invalid move: Cannot capture own piece.\n");
            continue;
        }

        // Make move
        game.board.pieces[to.x * BOARD_SIZE + to.y] = from_piece;
        game.board.pieces[from.x * BOARD_SIZE + from.y].type = 0;

        // Switch player turn
        game.player_turn = game.player_turn == 1 ? 2 : 1;
    }

    return 0;
}