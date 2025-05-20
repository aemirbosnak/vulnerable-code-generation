//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define BOARD_WIDTH 40

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    int state;
} Cell;

Cell cells[SIZE * SIZE];
Coord origin = {0, 0};

void initialize(Cell *cells, int size) {
    int i;
    for (i = 0; i < size; i++) {
        cells[i].state = 0;
    }
}

void print_board(Cell *cells, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d", cells[i * size + j].state);
        }
        printf("\n");
    }
}

void update_cell(Cell *cells, int x, int y) {
    int i, j;
    int count = 0;
    Cell cell = cells[x + y * SIZE];
    for (i = -1; i < 2; i++) {
        for (j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;
            if (x + i >= 0 && x + i < SIZE && y + j >= 0 && y + j < SIZE) {
                count++;
            }
        }
    }
    if (cell.state == 1 && count < 2 || cell.state == 0 && count == 3) {
        cell.state = 0;
    } else {
        cell.state = 1;
    }
}

int main() {
    Cell *cells = malloc(SIZE * SIZE * sizeof(Cell));
    initialize(cells, SIZE);
    int i, j;
    Coord pos = {0, 0};
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1) {
                cells[i * SIZE + j].state = 1;
            } else {
                cells[i * SIZE + j].state = 0;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            update_cell(cells, i + origin.x, j + origin.y);
        }
    }
    printf("Initial board:\n");
    print_board(cells, SIZE);
    printf("\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < SIZE; j++) {
            update_cell(cells, j + origin.x, i + origin.y);
        }
        printf("Generation %d:\n", i + 1);
        print_board(cells, SIZE);
        printf("\n");
    }
    free(cells);
    return 0;
}