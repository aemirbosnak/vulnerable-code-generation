//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} ChessGame;

void initialize_board(ChessGame *game) {
    game->turn = WHITE;
    memset(game->board, EMPTY, sizeof(game->board));

    // Set pieces for the initial position
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = WHITE; // White pawns
        game->board[6][i] = BLACK; // Black pawns
    }

    game->board[0][0] = WHITE; game->board[0][7] = WHITE; // White rooks
    game->board[0][1] = WHITE; game->board[0][6] = WHITE; // White knights
    game->board[0][2] = WHITE; game->board[0][5] = WHITE; // White bishops
    game->board[0][3] = WHITE; // White queen
    game->board[0][4] = WHITE; // White king

    game->board[7][0] = BLACK; game->board[7][7] = BLACK; // Black rooks
    game->board[7][1] = BLACK; game->board[7][6] = BLACK; // Black knights
    game->board[7][2] = BLACK; game->board[7][5] = BLACK; // Black bishops
    game->board[7][3] = BLACK; // Black queen
    game->board[7][4] = BLACK; // Black king
}

void print_board(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char piece, int start_row, int start_col, int end_row, int end_col) {
    // Simple validation based on piece type (pawns only)
    if (piece == WHITE) {
        return start_row == end_row + 1 && start_col == end_col; // Moving forward
    } else if (piece == BLACK) {
        return start_row == end_row - 1 && start_col == end_col;
    }
    return 0; // Invalid for other pieces
}

void make_move(ChessGame *game, int start_row, int start_col, int end_row, int end_col) {
    char piece = game->board[start_row][start_col];
    if (is_valid_move(piece, start_row, start_col, end_row, end_col)) {
        game->board[end_row][end_col] = piece;
        game->board[start_row][start_col] = EMPTY;
        game->turn = (game->turn == WHITE) ? BLACK : WHITE; // Switch turn
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    ChessGame game;
    initialize_board(&game);

    char input[100];
    while (1) {
        print_board(&game);
        printf("%c's turn. Enter move (e.g., e2 e4): ", game.turn);
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        char start[3], end[3];
        sscanf(input, "%s %s", start, end);
        int start_row = BOARD_SIZE - (start[1] - '0');
        int start_col = start[0] - 'a';
        int end_row = BOARD_SIZE - (end[1] - '0');
        int end_col = end[0] - 'a';

        make_move(&game, start_row, start_col, end_row, end_col);
    }

    printf("Game ended.\n");
    return 0;
}