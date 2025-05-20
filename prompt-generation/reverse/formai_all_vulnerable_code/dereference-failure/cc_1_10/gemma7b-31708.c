//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%c ", board[r][c] + 48);
        }
        printf("\n");
    }
}

int main() {
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++) {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            board[r][c] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while (1) {
        draw_board(board, size);

        // Calculate the next generation
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                int neighbors = 0;
                if (r - 1 >= 0) neighbors++;
                if (r + 1 < size) neighbors++;
                if (c - 1 >= 0) neighbors++;
                if (c + 1 < size) neighbors++;
                board[r][c] = neighbors > 3 ? 1 : 0;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation > 10) break;
    }

    draw_board(board, size);

    // Free the memory
    for (int r = 0; r < size; r++) {
        free(board[r]);
    }
    free(board);

    return 0;
}