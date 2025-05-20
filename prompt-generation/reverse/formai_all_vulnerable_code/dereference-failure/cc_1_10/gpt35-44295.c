//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum Piece {
    EMPTY,
    WHITE,
    RED
};

struct Checker_Players {
    enum Piece player_one;
    enum Piece player_two;
};

struct Checker_Board {
    enum Piece** pieces;
    struct Checker_Players players;
};

struct Checker_Move {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
};

void init_board(struct Checker_Board* board) {
    int i, j;
    
    board->pieces = malloc(sizeof(enum Piece*) * BOARD_SIZE);
    for (i = 0; i < BOARD_SIZE; i++) {
        board->pieces[i] = malloc(sizeof(enum Piece) * BOARD_SIZE);
        for (j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j] = EMPTY;
        }
    }

    board->players.player_one = WHITE;
    board->players.player_two = RED;
}

void print_board(struct Checker_Board* board) {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board->pieces[i][j]) {
                case EMPTY:
                    printf("- ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
                case RED:
                    printf("R ");
                    break;
            }
        }
        printf("\n");
    }
}

int is_valid_move(struct Checker_Board* board, struct Checker_Move move) {
    enum Piece player_piece, other_piece;
    int direction, diff_row, diff_col, abs_diff_row, abs_diff_col;
    int jump_row, jump_col;

    player_piece = board->pieces[move.from_row][move.from_col];

    if (player_piece != board->players.player_one && player_piece != board->players.player_two) {
        return 0;
    }

    if (player_piece == board->players.player_one) {
        other_piece = board->players.player_two;
        direction = 1;
    } else {
        other_piece = board->players.player_one;
        direction = -1;
    }

    diff_row = move.to_row - move.from_row;
    diff_col = move.to_col - move.from_col;
    abs_diff_row = abs(diff_row);
    abs_diff_col = abs(diff_col);

    if (abs_diff_row != abs_diff_col) {
        return 0;
    }

    if (abs_diff_row == 1) {
        if (board->pieces[move.to_row][move.to_col] != EMPTY) {
            return 0;
        }

        if (!diff_col) {
            return 1;
        }

        return 0;
    }

    if (abs_diff_row == 2) {
        jump_row = move.from_row + direction;
        jump_col = move.from_col + (diff_col / abs_diff_col);

        if (board->pieces[jump_row][jump_col] != other_piece) {
            return 0;
        }

        if (board->pieces[move.to_row][move.to_col] != EMPTY) {
            return 0;
        }

        return 1;
    }

    return 0;
}

void make_move(struct Checker_Board* board, struct Checker_Move move) {
    enum Piece** pieces;
    enum Piece player_piece;
    int direction, diff_row, diff_col, abs_diff_row, abs_diff_col;
    int jump_row, jump_col;

    pieces = board->pieces;
    player_piece = pieces[move.from_row][move.from_col];

    pieces[move.to_row][move.to_col] = player_piece;
    pieces[move.from_row][move.from_col] = EMPTY;

    if (player_piece == board->players.player_one) {
        direction = 1;
    } else {
        direction = -1;
    }

    diff_row = move.to_row - move.from_row;
    diff_col = move.to_col - move.from_col;
    abs_diff_row = abs(diff_row);
    abs_diff_col = abs(diff_col);

    if (abs_diff_row == 2) {
        jump_row = move.from_row + direction;
        jump_col = move.from_col + (diff_col / abs_diff_col);

        pieces[jump_row][jump_col] = EMPTY;
    }
}

int main(void) {
    struct Checker_Board board;
    struct Checker_Move move;
    int valid_move;

    init_board(&board);

    while (1) {
        print_board(&board);

        printf("Enter move (from_row from_col to_row to_col): ");
        if (scanf("%d %d %d %d", &move.from_row, &move.from_col, &move.to_row, &move.to_col) != 4) {
            printf("Invalid move!\n");
            continue;
        }

        valid_move = is_valid_move(&board, move);
        if (!valid_move) {
            printf("Invalid move!\n");
            continue;
        }

        make_move(&board, move);
    }

    return 0;
}