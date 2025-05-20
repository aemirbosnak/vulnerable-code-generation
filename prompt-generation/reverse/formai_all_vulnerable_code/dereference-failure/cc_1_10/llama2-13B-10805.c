//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a cell in the game of life
typedef struct cell {
    int x;
    int y;
    int state; // 0 for dead, 1 for alive
} cell_t;

// Function to draw the game board
void draw_board(cell_t *board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (board[i * width + j].state == 1) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to update the game board based on the current state
void update_board(cell_t *board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check the neighbors of the current cell
            int count_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (board[i * width + j + k].state == 1 && board[i * width + j + l].state == 1) {
                        count_alive++;
                    }
                }
            }
            // Update the current cell's state based on the number of alive neighbors
            if (count_alive < 2 && board[i * width + j].state == 1) {
                board[i * width + j].state = 0;
            } else if (count_alive >= 2 && board[i * width + j].state == 0) {
                board[i * width + j].state = 1;
            }
        }
    }
}

// Function to initialize the game board
void init_board(cell_t *board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            board[i * width + j].state = rand() % 2;
        }
    }
}

int main() {
    srand(time(NULL));
    cell_t *board = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    init_board(board, WIDTH, HEIGHT);

    while (1) {
        update_board(board, WIDTH, HEIGHT);
        draw_board(board, WIDTH, HEIGHT);
        printf("Press any key to continue...\n");
        getchar();
    }

    free(board);
    return 0;
}