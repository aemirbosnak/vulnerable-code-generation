//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

typedef struct Cell {
    int state;
    struct Cell* up;
    struct Cell* right;
    struct Cell* down;
    struct Cell* left;
} Cell;

void initialize_percolation(Cell* cell) {
    cell->state = 0;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
}

void simulate_percolation(Cell* cell) {
    if (cell->state == 1) {
        cell->state = 2;
        if (cell->up)
            simulate_percolation(cell->up);
        if (cell->right)
            simulate_percolation(cell->right);
        if (cell->down)
            simulate_percolation(cell->down);
        if (cell->left)
            simulate_percolation(cell->left);
    }
}

int main() {
    srand(time(NULL));

    Cell* board = (Cell*)malloc(MAX_SIZE * MAX_SIZE * sizeof(Cell));
    initialize_percolation(board);

    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
        board[i].state = rand() % 2;
    }

    simulate_percolation(board);

    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
        printf("%d ", board[i].state);
    }

    printf("\n");

    free(board);

    return 0;
}