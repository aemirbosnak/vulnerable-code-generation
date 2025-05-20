//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_board(int **board) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial seeds
    board[5][5] = 1;
    board[3][3] = 1;
    board[2][2] = 1;

    // Simulate the game of life
    for (int t = 0; t < 10; t++) {
        draw_board(board);
        printf("Generation %d:\n", t + 1);

        // Calculate the next generation
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                int neighbors = 0;
                if (board[i - 1][j] == 1) neighbors++;
                if (board[i + 1][j] == 1) neighbors++;
                if (board[i][j - 1] == 1) neighbors++;
                if (board[i][j + 1] == 1) neighbors++;

                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }
    }

    draw_board(board);
    printf("Final Generation:\n");

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}