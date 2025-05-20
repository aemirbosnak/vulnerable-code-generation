//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int alive;
    int num_neighbors;
} Cell;

Cell **create_board(int size) {
    Cell **board = malloc(size * sizeof(Cell *));
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            board[i][j].alive = 0;
            board[i][j].num_neighbors = 0;
        }
    }
    return board;
}

void print_board(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", board[i][j].alive);
        }
        printf("\n");
    }
}

void update_neighbors(Cell **board, int size, int x, int y) {
    Cell *current_cell = &board[x][y];
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int new_x = x + dx;
            int new_y = y + dy;
            if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size) {
                current_cell->num_neighbors++;
                if (board[new_x][new_y].alive == 1) {
                    current_cell->num_neighbors--;
                }
            }
        }
    }
}

void next_generation(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Cell *current_cell = &board[i][j];
            if (current_cell->alive == 1 && (current_cell->num_neighbors < 2 || current_cell->num_neighbors > 3)) {
                current_cell->alive = 0;
            } else if (current_cell->alive == 0 && current_cell->num_neighbors == 3) {
                current_cell->alive = 1;
            }
        }
    }
}

int main() {
    int size = 10;
    Cell **board = create_board(size);
    print_board(board, size);
    for (int i = 0; i < 1000; i++) {
        next_generation(board, size);
        printf("Generation %d:\n", i);
        print_board(board, size);
    }
    free(board[0]);
    for (int i = 1; i < size; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}