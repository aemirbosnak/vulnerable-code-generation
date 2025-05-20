//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_COUNT 5
#define COL_COUNT 10
#define MIN_NUMBER 1
#define MAX_NUMBER 10

typedef struct {
    int row;
    int col;
    int value;
} cell_t;

cell_t *board;

void init_board(void) {
    board = (cell_t *)calloc(ROW_COUNT, sizeof(cell_t));
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COL_COUNT; j++) {
            board[i * COL_COUNT + j].row = i;
            board[i * COL_COUNT + j].col = j;
            board[i * COL_COUNT + j].value = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
        }
    }
}

void print_board(void) {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COL_COUNT; j++) {
            printf("%d ", board[i * COL_COUNT + j].value);
        }
        printf("\n");
    }
}

void make_move(int row, int col) {
    if (row < 0 || row >= ROW_COUNT || col < 0 || col >= COL_COUNT) {
        printf("Invalid move!\n");
        return;
    }
    int temp = board[row * COL_COUNT + col].value;
    board[row * COL_COUNT + col].value = board[row * COL_COUNT + (col + 1) % COL_COUNT].value;
    board[row * COL_COUNT + (col + 1) % COL_COUNT].value = temp;
    print_board();
}

int main(void) {
    init_board();
    print_board();
    int move = 0;
    while (1) {
        printf("Enter row and col to make a move (e.g. 1 2): ");
        scanf("%d%d", &move, &move);
        make_move(move, move);
    }
    return 0;
}