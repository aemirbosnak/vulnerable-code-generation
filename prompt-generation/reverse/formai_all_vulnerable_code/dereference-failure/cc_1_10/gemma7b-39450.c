//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_WATER 10

typedef struct Cell {
    int water;
    struct Cell* up, *right, *down, *left;
} Cell;

Cell** createMap() {
    Cell** map = (Cell**)malloc(MAP_SIZE * sizeof(Cell*));
    for (int r = 0; r < MAP_SIZE; r++) {
        map[r] = (Cell*)malloc(MAP_SIZE * sizeof(Cell));
        for (int c = 0; c < MAP_SIZE; c++) {
            map[r][c].water = 0;
            map[r][c].up = NULL;
            map[r][c].right = NULL;
            map[r][c].down = NULL;
            map[r][c].left = NULL;
        }
    }
    return map;
}

void fillRandom(Cell** map, int water) {
    srand(time(NULL));
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            if (rand() % MAX_WATER == 0) {
                map[r][c].water = water;
            }
        }
    }
}

void simulatePercolation(Cell** map) {
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            if (map[r][c].water > 0) {
                // Check if cell is at the top of the map or if water can flow from above
                if (r == 0 || map[r - 1][c].water == 0) {
                    // Flow water down
                    map[r][c].water--;
                    map[r + 1][c].water++;
                }
                // Check if cell is at the right of the map or if water can flow from right
                if (c == MAP_SIZE - 1 || map[r][c + 1].water == 0) {
                    // Flow water right
                    map[r][c].water--;
                    map[r][c + 1].water++;
                }
            }
        }
    }
}

int main() {
    Cell** map = createMap();
    fillRandom(map, MAX_WATER);
    simulatePercolation(map);

    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            printf("%d ", map[r][c].water);
        }
        printf("\n");
    }

    return 0;
}