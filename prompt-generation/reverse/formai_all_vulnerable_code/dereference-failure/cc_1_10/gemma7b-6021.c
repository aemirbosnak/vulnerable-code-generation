//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

#define LIVING 1
#define DEAD 0

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initialize_board(Cell **board) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[x][y].x = x;
            board[x][y].y = y;
            board[x][y].state = DEAD;
        }
    }
}

void draw_board(Cell **board) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (board[x][y].state == LIVING) {
                printf("%c ", '*');
            } else {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell **board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));

    initialize_board(board);

    for (int t = 0; t < 200; t++) {
        draw_board(board);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int neighbors = 0;

                if (board[x][y].state == LIVING) {
                    neighbors++;
                }

                if (board[x][y].state == DEAD && neighbors == 3) {
                    board[x][y].state = LIVING;
                } else if (board[x][y].state == LIVING && neighbors < 2) {
                    board[x][y].state = DEAD;
                }
            }
        }

        printf("\n");
    }

    free(board);

    return 0;
}