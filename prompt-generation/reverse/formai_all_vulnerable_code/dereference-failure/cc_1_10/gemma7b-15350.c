//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeGame(Cell **cells);
void updateCells(Cell **cells);
void displayCells(Cell **cells);

int main() {
    Cell **cells = (Cell **)malloc(MAX_CELLS * sizeof(Cell));
    initializeGame(cells);
    updateCells(cells);
    displayCells(cells);

    return 0;
}

void initializeGame(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = (Cell *)malloc(sizeof(Cell));
        cells[i]->x = i % MAX_CELLS;
        cells[i]->y = i / MAX_CELLS;
        cells[i]->state = 0;
    }
}

void updateCells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) continue;
                int neighborX = cells[i]->x + x;
                int neighborY = cells[i]->y + y;
                if (neighborX >= 0 && neighborX < MAX_CELLS && neighborY >= 0 && neighborY < MAX_CELLS) {
                    neighbors++;
                }
            }
        }

        if (neighbors < 2) cells[i]->state = 0;
        else if (neighbors == 2) cells[i]->state = 1;
        else if (neighbors == 3) cells[i]->state = 2;
    }
}

void displayCells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        switch (cells[i]->state) {
            case 0:
                printf("O ");
                break;
            case 1:
                printf("A ");
                break;
            case 2:
                printf("V ");
                break;
        }
    }
    printf("\n");
}