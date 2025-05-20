//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 20
#define CELL_SIZE 2

typedef struct Cell {
    bool alive;
} Cell;

void print_board(Cell **board) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(board[y][x].alive ? "██" : "  ");
        }
        printf("\n");
    }
}

void update(Cell **board) {
    Cell new_board[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int alive_neighbors = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0)
                        continue;

                    int new_x = x + dx;
                    int new_y = y + dy;

                    if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT) {
                        if (board[new_y][new_x].alive)
                            alive_neighbors++;
                    }
                }
            }

            new_board[y][x].alive = board[y][x].alive
                && (alive_neighbors == 2 || alive_neighbors == 3);
        }
    }

    memcpy(board, new_board, sizeof(new_board));
}

int main() {
    Cell **board = calloc(HEIGHT, sizeof(Cell*) * WIDTH);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y < 2 || y > HEIGHT - 2 || x < 2 || x > WIDTH - 2)
                board[y][x].alive = false;
            else if (rand() % CELL_SIZE)
                board[y][x].alive = true;
        }
    }

    for (int i = 0; i < 10; i++) {
        print_board(board);
        update(board);
        sleep(100);
        system("clear");
    }

    free(board);

    return 0;
}