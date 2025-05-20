//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;
typedef enum { NO_MOVE, MOVE, JUMP } MoveType;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int red_count;
    int black_count;
} GameState;

void initialize_board(GameState *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    game->board[i][j] = RED;
                } else if (i > 4) {
                    game->board[i][j] = BLACK;
                } else {
                    game->board[i][j] = EMPTY;
                }
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
    game->red_count = 12;
    game->black_count = 12;
}

void print_board(const GameState *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY) {
                printf(". ");
            } else if (game->board[i][j] == RED) {
                printf("R ");
            } else {
                printf("B ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(GameState *game, int start_x, int start_y, int end_x, int end_y) {
    if (end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (game->board[end_x][end_y] != EMPTY) {
        return 0; // Destination is not empty
    }
    int dx = end_x - start_x;
    int dy = end_y - start_y;

    if (game->board[start_x][start_y] == RED) {
        return (dx == 1 && (dy == -1 || dy == 1)); // Regular move for RED
    } else if (game->board[start_x][start_y] == BLACK) {
        return (dx == -1 && (dy == -1 || dy == 1)); // Regular move for BLACK
    }
    return 0; // Invalid move
}

void make_move(GameState *game, int start_x, int start_y, int end_x, int end_y) {
    Piece piece = game->board[start_x][start_y];
    game->board[end_x][end_y] = piece;
    game->board[start_x][start_y] = EMPTY;
}

void play_game() {
    GameState game;
    initialize_board(&game);
    print_board(&game);

    int current_player = RED;
    while (game.red_count > 0 && game.black_count > 0) {
        char move[5];
        printf("Player %s, enter your move (e.g., A3 B4): ", current_player == RED ? "RED" : "BLACK");
        fgets(move, sizeof(move), stdin);

        int start_x = move[1] - '1';
        int start_y = move[0] - 'A';
        int end_x = move[4] - '1';
        int end_y = move[3] - 'A';

        if (is_valid_move(&game, start_x, start_y, end_x, end_y)) {
            make_move(&game, start_x, start_y, end_x, end_y);
            print_board(&game);
            current_player = (current_player == RED) ? BLACK : RED;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    if (game.red_count == 0) {
        printf("BLACK wins!\n");
    } else {
        printf("RED wins!\n");
    }
}

int main() {
    play_game();
    return 0;
}