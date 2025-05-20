//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROWS 8
#define NUM_COLS 8
#define WHITE 1
#define BLACK -1

typedef struct {
    char board[NUM_ROWS][NUM_COLS];
    int currentPlayer;
    int whiteTurn;
} chess_board;

void print_board(chess_board* board) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(chess_board* board, int row, int col) {
    return (board->board[row][col] == '.');
}

void make_move(chess_board* board, int row, int col) {
    if (board->board[row][col]!= '.') {
        return;
    }
    board->board[row][col] = board->currentPlayer + 1;
    board->currentPlayer = board->whiteTurn? BLACK : WHITE;
    board->whiteTurn =!board->whiteTurn;
}

int main() {
    chess_board board;
    board.board[0][0] = 'P';
    board.board[0][1] = 'N';
    board.board[0][2] = 'B';
    board.board[0][3] = 'R';
    board.board[0][4] = 'Q';
    board.board[0][5] = 'K';
    board.board[0][6] = 'B';
    board.board[0][7] = 'N';
    board.board[1][0] = 'P';
    board.board[1][1] = 'P';
    board.board[1][2] = 'P';
    board.board[1][3] = 'R';
    board.board[1][4] = 'B';
    board.board[1][5] = 'Q';
    board.board[1][6] = 'K';
    board.board[1][7] = 'B';
    board.currentPlayer = WHITE;
    board.whiteTurn = 0;
    print_board(&board);

    int row, col;
    printf("Enter a move (row, col): ");
    scanf("%d%d", &row, &col);

    if (is_valid_move(&board, row, col)) {
        make_move(&board, row, col);
        print_board(&board);
    }

    return 0;
}