//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define NUM_OF_GENERATIONS 100

int main(int argc, char **argv) {
    srand(time(NULL));

    // Allocate memory for the board
    int *board = (int *) malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        board[i] = 0;
    }

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i * BOARD_SIZE + j] = rand() % 2;
        }
    }

    // Print the initial board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i * BOARD_SIZE + j]);
        }
        printf("\n");
    }

    // Run the Game of Life
    for (int generation = 0; generation < NUM_OF_GENERATIONS; generation++) {
        // Calculate the next generation
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int count = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < BOARD_SIZE && nj >= 0 && nj < BOARD_SIZE) {
                            count += board[ni * BOARD_SIZE + nj];
                        }
                    }
                }
                if (board[i * BOARD_SIZE + j] == 1) {
                    if (count < 2 || count > 3) board[i * BOARD_SIZE + j] = 0;
                } else {
                    if (count == 3) board[i * BOARD_SIZE + j] = 1;
                }
            }
        }

        // Print the next generation
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", board[i * BOARD_SIZE + j]);
            }
            printf("\n");
        }
    }

    free(board);

    return 0;
}