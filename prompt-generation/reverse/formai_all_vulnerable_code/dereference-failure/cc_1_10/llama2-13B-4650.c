//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_ROWS 8
#define BOARD_COLS 8
#define PIECE_TYPES 4
#define SQUARE_SIZE 32

typedef struct {
    char name[32];
    int row, col;
} piece_t;

typedef struct {
    piece_t pieces[BOARD_ROWS][BOARD_COLS];
    int player;
} board_t;

void init_board(board_t *board);
void print_board(board_t *board);
void make_move(board_t *board, int row, int col);
void check_win(board_t *board, int player);

int main() {
    srand(time(NULL));

    board_t *board = malloc(sizeof(board_t));
    init_board(board);

    while (1) {
        print_board(board);
        int move = getchar();
        make_move(board, move - 'a', move - '0');
        check_win(board, board->player);
    }

    return 0;
}

void init_board(board_t *board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board->pieces[i][j].row = i;
            board->pieces[i][j].col = j;
            board->pieces[i][j].name[0] = ' ';
        }
    }
    board->player = 1;
}

void print_board(board_t *board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            printf("%c", board->pieces[i][j].name[0]);
        }
        printf("\n");
    }
}

void make_move(board_t *board, int row, int col) {
    if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS) {
        printf("Invalid move\n");
        return;
    }

    piece_t *piece = &board->pieces[row][col];
    if (piece->name[0] == 'X') {
        board->player = 2 - board->player;
    }

    piece->row = row;
    piece->col = col;
    piece->name[0] = board->player == 1 ? 'X' : 'O';
}

void check_win(board_t *board, int player) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            if (board->pieces[i][j].name[0] == player == 'X' ? 'X' : 'O') {
                continue;
            }
            if (i == j || board->pieces[i][j].row == i || board->pieces[i][j].col == j) {
                continue;
            }
            if (board->pieces[i][j].row + board->pieces[i][j].col == player) {
                printf("Win! Congratulations, %c player\n", player == 'X' ? 'X' : 'O');
                return;
            }
        }
    }
}