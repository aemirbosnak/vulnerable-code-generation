//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE (CELL_SIZE * CELL_SIZE)

typedef struct {
    int alive;
    int neighbors_alive;
} cell_t;

cell_t generate_random_cell(void) {
    int alive = (rand() % 2) == 0;
    int neighbors_alive = 0;

    if (alive) {
        neighbors_alive = (rand() % 4) + 2; // 2-4 neighbors alive
    }

    return (cell_t) {
        .alive = alive,
        .neighbors_alive = neighbors_alive
    };
}

void draw_board(cell_t** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void update_board(cell_t** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cell_t* cell = &board[i][j];

            if (cell->alive) {
                int neighbors_alive = 0;

                // Count alive neighbors
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;
                        }

                        if (board[i + k][j + l].alive) {
                            neighbors_alive++;
                        }
                    }
                }

                // Apply rules
                if (cell->neighbors_alive < 2 || cell->neighbors_alive > 3) {
                    cell->alive = 0; // Death
                } else if (cell->neighbors_alive == 3) {
                    cell->alive = 1; // Survival
                }
            }
        }
    }
}

int main(void) {
    srand(time(NULL)); // Seed random number generator

    cell_t** board = calloc(BOARD_SIZE, sizeof(cell_t*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = calloc(BOARD_SIZE, sizeof(cell_t));
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = generate_random_cell();
        }
    }

    draw_board(board);

    for (int generation = 0; generation < 100; generation++) {
        update_board(board);

        if (generation % 10 == 0) {
            printf("Generation %d\n", generation);
            draw_board(board);
        }
    }

    return 0;
}