//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

typedef struct {
    int alive;
    int next;
} cell_t;

cell_t *board;

void init_board(void) {
    board = (cell_t *)calloc(BOARD_SIZE, sizeof(cell_t));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].alive = (i % 2 == 0) ? 1 : 0;
        board[i].next = (i + 1) % BOARD_SIZE;
    }
}

void apply_rules(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        cell_t current = board[i];
        if (current.alive) {
            if (current.next == i) {
                // alive cell has two alive neighbors, leave it alive
                current.alive = 1;
            } else if (current.next == (i + 1) % BOARD_SIZE) {
                // alive cell has one alive neighbor, leave it alive
                current.alive = 1;
            } else {
                // alive cell has no alive neighbors, die
                current.alive = 0;
            }
        } else {
            // dead cell has one alive neighbor, come to life
            current.alive = 1;
        }
        board[i] = current;
    }
}

void print_board(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i].alive) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main(void) {
    init_board();
    for (int generation = 0; generation < 10; generation++) {
        apply_rules();
        print_board();
    }
    return 0;
}