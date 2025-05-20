//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_MOVES 128

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn; // 0 for white, 1 for black
} ChessGame;

void initialize_game(ChessGame *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    game->turn = 0;

    // Setting up pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = PAWN; // White pawns
        game->board[6][i] = PAWN; // Black pawns
    }

    // Setting up other pieces
    game->board[0][0] = game->board[0][7] = ROOK;
    game->board[0][1] = game->board[0][6] = KNIGHT;
    game->board[0][2] = game->board[0][5] = BISHOP;
    game->board[0][3] = QUEEN;
    game->board[0][4] = KING;

    game->board[7][0] = game->board[7][7] = ROOK;
    game->board[7][1] = game->board[7][6] = KNIGHT;
    game->board[7][2] = game->board[7][5] = BISHOP;
    game->board[7][3] = QUEEN;
    game->board[7][4] = KING;
}

void print_board(ChessGame *game) {
    const char *piece_symbols[] = {" ", "P", "N", "B", "R", "Q", "K"};
    
    for (int r = BOARD_SIZE - 1; r >= 0; r--) {
        printf("%d | ", r + 1);
        for (int c = 0; c < BOARD_SIZE; c++) {
            Piece piece = game->board[r][c];
            printf("%s ", piece_symbols[piece]);
        }
        printf("|\n");
    }
    printf("   +-----------------\n");
    printf("     a b c d e f g h\n");
}

int is_move_valid(ChessGame *game, int sr, int sc, int dr, int dc) {
    // Dummy validation, add proper movement rules for each piece later
    if (dr < 0 || dr >= BOARD_SIZE || dc < 0 || dc >= BOARD_SIZE) return 0;
    if (game->board[dr][dc] != EMPTY && game->turn == 0 && game->board[dr][dc] != EMPTY) return 0; // cannot capture own piece
    return 1;
}

void move_piece(ChessGame *game, int sr, int sc, int dr, int dc) {
    if (is_move_valid(game, sr, sc, dr, dc)) {
        game->board[dr][dc] = game->board[sr][sc];
        game->board[sr][sc] = EMPTY;
        game->turn = 1 - game->turn; // Switch turns
    } else {
        printf("Invalid move!\n");
    }
}

void play_game() {
    ChessGame game;
    initialize_game(&game);

    while (1) {
        print_board(&game);
        printf("%s's turn (enter move: e.g. e2 e4): ", game.turn == 0 ? "White" : "Black");

        char input[20];
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) break;

        int sr = input[1] - '1';
        int sc = input[0] - 'a';
        int dr = input[4] - '1';
        int dc = input[3] - 'a';

        move_piece(&game, sr, sc, dr, dc);
    }
}

int main() {
    printf("Welcome to the C Chess Engine in Puzzling Style!\n");
    printf("Type 'exit' to end the game.\n");
    play_game();
    return 0;
}