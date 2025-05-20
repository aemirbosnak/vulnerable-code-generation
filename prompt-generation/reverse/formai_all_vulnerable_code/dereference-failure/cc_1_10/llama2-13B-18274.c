//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define ROW_COUNT 10
#define COLUMN_COUNT 10

typedef struct {
    char symbol;
    int value;
} Cell;

typedef struct {
    Cell cells[ROW_COUNT][COLUMN_COUNT];
} GameBoard;

GameBoard* create_game_board() {
    GameBoard* board = (GameBoard*) calloc(1, sizeof(GameBoard));
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            board->cells[i][j].symbol = '?';
            board->cells[i][j].value = 0;
        }
    }
    return board;
}

void print_game_board(GameBoard* board) {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            printf("%c", board->cells[i][j].symbol);
        }
        printf("\n");
    }
}

int get_cell_value(GameBoard* board, int row, int column) {
    return board->cells[row][column].value;
}

void set_cell_value(GameBoard* board, int row, int column, int value) {
    board->cells[row][column].value = value;
}

void place_cell(GameBoard* board, int row, int column, char symbol) {
    board->cells[row][column].symbol = symbol;
    board->cells[row][column].value = 0;
}

void draw_cell(GameBoard* board, int row, int column) {
    char symbol = board->cells[row][column].symbol;
    if (symbol == 'X') {
        printf("❓");
    } else if (symbol == 'O') {
        printf("⬤");
    } else {
        printf("?");
    }
}

int check_win(GameBoard* board) {
    for (int i = 0; i < ROW_COUNT; i++) {
        if (board->cells[i][0].value == board->cells[i][1].value &&
                board->cells[i][1].value == board->cells[i][2].value) {
            return 1;
        }
    }
    for (int i = 0; i < COLUMN_COUNT; i++) {
        if (board->cells[0][i].value == board->cells[1][i].value &&
                board->cells[1][i].value == board->cells[2][i].value) {
            return 1;
        }
    }
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (board->cells[i][j].value == board->cells[i][j + 1].value &&
                    board->cells[i][j + 1].value == board->cells[i][j + 2].value) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    GameBoard* board = create_game_board();
    char player = 'X';
    int turn = 0;

    while (1) {
        print_game_board(board);
        int row = rand() % ROW_COUNT;
        int column = rand() % COLUMN_COUNT;
        char symbol = player == 'X' ? 'X' : 'O';
        place_cell(board, row, column, symbol);
        draw_cell(board, row, column);
        turn++;

        if (check_win(board)) {
            printf("Game Over! %c wins!\n", player);
            break;
        }

        if (turn % 2 == 0) {
            player = player == 'X' ? 'O' : 'X';
        }
    }

    free(board);
    return 0;
}