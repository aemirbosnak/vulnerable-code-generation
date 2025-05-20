//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void DrawBoard(int **board, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%c ", board[r][c] ? 'O' : '.');
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

    board[2][2] = board[1][2] = board[1][1] = 1;
    board[2][1] = board[3][2] = board[3][1] = 1;

    DrawBoard(board, size);

    int generation = 0;
    while (1) {
        DrawBoard(board, size);
        printf("Generation: %d\n", generation++);

        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                int neighbors = 0;
                if (board[r - 1][c] == 1) neighbors++;
                if (board[r + 1][c] == 1) neighbors++;
                if (board[r][c - 1] == 1) neighbors++;
                if (board[r][c + 1] == 1) neighbors++;

                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        if (board[0][0] == 0) break;
    }

    DrawBoard(board, size);
    printf("Final Board:\n");

    free(board);

    return 0;
}