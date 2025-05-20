//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Create a 2D array to store the game board
    int **board = NULL;
    board = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++) {
        board[i] = malloc(5 * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }

    // Place the survivors
    board[2][2] = 1;
    board[3][2] = 1;
    board[2][3] = 1;

    // Simulate the post-apocalyptic environment
    int generation = 0;
    while (board[2][2] || board[3][2] || board[2][3]) {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int neighbors = 0;
                if (board[i - 1][j] == 1) neighbors++;
                if (board[i + 1][j] == 1) neighbors++;
                if (board[i][j - 1] == 1) neighbors++;
                if (board[i][j + 1] == 1) neighbors++;
                board[i][j] = neighbors;
            }
        }

        // Apply the Game of Life rules
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0 && board[i][j] == 3) board[i][j] = 1;
                else if (board[i][j] == 1 && board[i][j] < 2) board[i][j] = 0;
            }
        }

        // Increment the generation
        generation++;

        // Print the game board
        printf("Generation %d:\n", generation);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < 5; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}