//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeBoard(Cell **board) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            board[x][y].x = x;
            board[x][y].y = y;
            board[x][y].state = 0;
        }
    }
}

void simulate(Cell **board) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (board[x + dx][y + dy].state == 1) {
                        neighbors++;
                    }
                }
            }

            if (board[x][y].state == 0 && neighbors == 3) {
                board[x][y].state = 1;
            } else if (board[x][y].state == 1 && (neighbors < 2 || neighbors > 3)) {
                board[x][y].state = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Cell **board = (Cell **)malloc(WIDTH * sizeof(Cell *) + HEIGHT * sizeof(Cell));
    initializeBoard(board);

    for (int t = 0; t < 10; t++) {
        simulate(board);
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            printf("%d ", board[x][y].state);
        }
        printf("\n");
    }

    free(board);

    return 0;
}