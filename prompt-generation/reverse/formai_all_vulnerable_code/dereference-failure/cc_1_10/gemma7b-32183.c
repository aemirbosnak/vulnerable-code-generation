//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initialize_cells(Cell **cells) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            cells[x][y].x = x;
            cells[x][y].y = y;
            cells[x][y].state = 0;
        }
    }
}

void simulate_life(Cell **cells) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int neighbor_x = x + dx;
                    int neighbor_y = y + dy;
                    if (neighbor_x >= 0 && neighbor_x < WIDTH && neighbor_y >= 0 && neighbor_y < HEIGHT && cells[neighbor_x][neighbor_y].state == 1) {
                        neighbors++;
                    }
                }
            }
            if (cells[x][y].state == 1) {
                if (neighbors < 2) cells[x][y].state = 0;
            } else if (neighbors == 3) cells[x][y].state = 1;
        }
    }
}

int main() {
    srand(time(NULL));

    Cell **cells = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
    initialize_cells(cells);

    for (int t = 0; t < 10; t++) {
        simulate_life(cells);
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            printf("%d ", cells[x][y].state);
        }
        printf("\n");
    }

    free(cells);

    return 0;
}