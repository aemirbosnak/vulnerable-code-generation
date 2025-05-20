//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100
#define GENERATIONS 100

typedef struct {
    int x;
    int y;
} cell_t;

typedef struct {
    cell_t cells[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j].x = i % 2 == 0 ? 1 : 0;
            board->cells[i][j].y = j % 2 == 0 ? 1 : 0;
        }
    }
}

void update_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int alive_neighbors = 0;

            if (i - 1 >= 0 && board->cells[i - 1][j].x == 1) alive_neighbors++;
            if (i + 1 < BOARD_SIZE && board->cells[i + 1][j].x == 1) alive_neighbors++;
            if (j - 1 >= 0 && board->cells[i][j - 1].x == 1) alive_neighbors++;
            if (j + 1 < BOARD_SIZE && board->cells[i][j + 1].x == 1) alive_neighbors++;

            board->cells[i][j].x = (board->cells[i][j].x == 1 && alive_neighbors < 2) ||
                                    (board->cells[i][j].x == 0 && alive_neighbors >= 3);
        }
    }
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->cells[i][j].x);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    board_t *board = malloc(sizeof(board_t));
    init_board(board);

    for (int generation = 0; generation < GENERATIONS; generation++) {
        update_board(board);
        print_board(board);
        printf("Generation %d\n", generation + 1);
        sleep(1);
    }

    free(board);

    return 0;
}