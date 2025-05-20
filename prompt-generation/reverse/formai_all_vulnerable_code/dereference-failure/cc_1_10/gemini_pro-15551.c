//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    WHITE,
    BLACK,
    EMPTY
} Color;

typedef enum {
    PAWN,
    KING
} Piece;

typedef struct {
    Color color;
    Piece piece;
} Square;

typedef struct {
    Square board[8][8];
    Color turn;
} Game;

void init_game(Game *game) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    game->board[i][j].color = BLACK;
                    game->board[i][j].piece = PAWN;
                } else if (i > 4) {
                    game->board[i][j].color = WHITE;
                    game->board[i][j].piece = PAWN;
                } else {
                    game->board[i][j].color = EMPTY;
                }
            } else {
                game->board[i][j].color = EMPTY;
            }
        }
    }
    game->turn = BLACK;
}

void print_board(Game *game) {
    printf("    A B C D E F G H\n");
    printf("  +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            if (game->board[i][j].color == EMPTY) {
                printf(" .");
            } else if (game->board[i][j].color == BLACK) {
                printf(" B");
            } else if (game->board[i][j].color == WHITE) {
                printf(" W");
            }
        }
        printf(" |\n");
    }
    printf("  +-----------------+\n");
}

void get_input(Game *game) {
    char from[3], to[3];
    printf("Enter the from and to coordinates: ");
    scanf("%s %s", from, to);
    int from_row = from[1] - '1';
    int from_col = from[0] - 'A';
    int to_row = to[1] - '1';
    int to_col = to[0] - 'A';
    if (game->board[from_row][from_col].color != game->turn) {
        printf("Invalid move: It is not your turn to move that piece.\n");
        return;
    }
    if (game->board[to_row][to_col].color != EMPTY) {
        printf("Invalid move: The destination square is not empty.\n");
        return;
    }
    if (game->board[from_row][from_col].piece == PAWN) {
        if (game->turn == BLACK) {
            if (to_row - from_row != 1 || abs(to_col - from_col) != 1) {
                printf("Invalid move: Pawns can only move forward one square diagonally.\n");
                return;
            }
        } else {
            if (to_row - from_row != -1 || abs(to_col - from_col) != 1) {
                printf("Invalid move: Pawns can only move forward one square diagonally.\n");
                return;
            }
        }
    } else if (game->board[from_row][from_col].piece == KING) {
        if (abs(to_row - from_row) != abs(to_col - from_col)) {
            printf("Invalid move: Kings can only move diagonally.\n");
            return;
        }
    }
    game->board[from_row][from_col].color = EMPTY;
    game->board[to_row][to_col].color = game->turn;
    if (to_row == 0 || to_row == 7) {
        game->board[to_row][to_col].piece = KING;
    }
    if (game->turn == BLACK) {
        game->turn = WHITE;
    } else {
        game->turn = BLACK;
    }
}

int main() {
    Game game;
    init_game(&game);
    while (1) {
        print_board(&game);
        get_input(&game);
    }
    return 0;
}