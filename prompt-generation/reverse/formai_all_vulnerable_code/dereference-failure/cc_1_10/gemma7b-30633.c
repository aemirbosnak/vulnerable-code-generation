//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define LIVING_CELL 1
#define DEAD_CELL 0

typedef struct Cell {
    int x, y;
    int state;
} Cell;

Cell **board;

void initialize_board() {
    board = malloc(WIDTH * HEIGHT * sizeof(Cell));
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            board[x][y].x = x;
            board[x][y].y = y;
            board[x][y].state = DEAD_CELL;
        }
    }
}

void simulate_life() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int num_living_neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int neighbor_x = board[x][y].x + dx;
                    int neighbor_y = board[x][y].y + dy;
                    if (neighbor_x >= 0 && neighbor_x < WIDTH && neighbor_y >= 0 && neighbor_y < HEIGHT && board[neighbor_x][neighbor_y].state == LIVING_CELL) {
                        num_living_neighbors++;
                    }
                }
            }
            if (board[x][y].state == LIVING_CELL && num_living_neighbors < 2) {
                board[x][y].state = DEAD_CELL;
            } else if (board[x][y].state == DEAD_CELL && num_living_neighbors == 3) {
                board[x][y].state = LIVING_CELL;
            }
        }
    }
}

int main() {
    initialize_board();
    simulate_life();

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (board[x][y].state == LIVING_CELL) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }

    return 0;
}