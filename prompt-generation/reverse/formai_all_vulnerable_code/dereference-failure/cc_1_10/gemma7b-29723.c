//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20

void drawBoard(int **board) {
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            printf("%c ", board[r][c] == 0 ? '.' : '*');
        }
        printf("\n");
    }
}

int main() {
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++) {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initial game board
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Game loop
    int generation = 0;
    while (1) {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        int **nextBoard = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (int r = 0; r < MAX_SIZE; r++) {
            nextBoard[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for (int r = 0; r < MAX_SIZE; r++) {
            for (int c = 0; c < MAX_SIZE; c++) {
                nextBoard[r][c] = calculateCell(board, r, c);
            }
        }

        // Free previous board and update current board
        for (int r = 0; r < MAX_SIZE; r++) {
            for (int c = 0; c < MAX_SIZE; c++) {
                free(board[r][c]);
            }
            free(board[r]);
        }

        board = nextBoard;
        generation++;

        // Check if game is over
        if (board[0][0] == 0 && board[MAX_SIZE - 1][MAX_SIZE - 1] == 0) {
            break;
        }
    }

    drawBoard(board);
    printf("Game over!\n");

    // Free memory
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            free(board[r][c]);
        }
        free(board[r]);
    }
    free(board);

    return 0;
}

int calculateCell(int **board, int r, int c) {
    int neighbors = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] == 1) {
                neighbors++;
            }
        }
    }

    if (board[r][c] == 1 && neighbors < 2) {
        return 0;
    } else if (board[r][c] == 0 && neighbors == 3) {
        return 1;
    } else {
        return board[r][c];
    }
}