//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initialize_game(Cell **cells);
void print_cells(Cell **cells);
void update_cells(Cell **cells);

int main() {
    Cell **cells = NULL;
    initialize_game(&cells);
    print_cells(cells);
    update_cells(cells);
    print_cells(cells);

    return 0;
}

void initialize_game(Cell **cells) {
    *cells = (Cell *)malloc(MAX_CELLS * sizeof(Cell));
    for (int i = 0; i < MAX_CELLS; i++) {
        (*cells)[i].x = -1;
        (*cells)[i].y = -1;
        (*cells)[i].state = 0;
    }
}

void print_cells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        printf("(%d, %d): %d ", cells[i]->x, cells[i]->y, cells[i]->state);
    }
    printf("\n");
}

void update_cells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (cells[i]->x + x >= 0 && cells[i]->x + x < MAX_CELLS && cells[i]->y + y >= 0 && cells[i]->y + y < MAX_CELLS) {
                    if (cells[i]->state == 1 && cells[i]->x + x == cells[i]->x && cells[i]->y + y == cells[i]->y) {
                        neighbors++;
                    }
                }
            }
        }
        if (cells[i]->state == 0 && neighbors == 3) {
            cells[i]->state = 1;
        } else if (cells[i]->state == 1 && (neighbors < 2 || neighbors > 3)) {
            cells[i]->state = 0;
        }
    }
}