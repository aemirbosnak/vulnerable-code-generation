//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initialize_game(Cell **cells);
void print_board(Cell **cells);
void update_cells(Cell **cells);

int main() {
    Cell **cells = (Cell **)malloc(MAX_CELLS * sizeof(Cell));
    initialize_game(cells);
    print_board(cells);
    update_cells(cells);
    print_board(cells);

    free(cells);
    return 0;
}

void initialize_game(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = (Cell *)malloc(sizeof(Cell));
        cells[i]->x = i % 10;
        cells[i]->y = i / 10;
        cells[i]->state = 0;
    }
}

void print_board(Cell **cells) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            printf("%d ", cells[x + 10 * y]->state);
        }
        printf("\n");
    }
}

void update_cells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        if (cells[i]->x > 0) neighbors++;
        if (cells[i]->x < 9) neighbors++;
        if (cells[i]->y > 0) neighbors++;
        if (cells[i]->y < 9) neighbors++;

        if (neighbors == 3) cells[i]->state = 1;
        else cells[i]->state = 0;
    }
}