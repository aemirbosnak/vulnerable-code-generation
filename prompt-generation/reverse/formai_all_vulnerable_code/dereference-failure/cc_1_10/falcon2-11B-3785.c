//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[][2], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void randomize_board(int board[][2], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int r = rand() % 2;
            if (r == 0)
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
}

int main() {
    int board[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int size = 3;
    int turn = 0;

    while (1) {
        print_board(board, size);
        printf("Turn %d\n", turn);
        int row, col;
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= size || col < 0 || col >= size) {
            printf("Invalid move\n");
            continue;
        }

        if (board[row][col]!= 0) {
            printf("That tile is already revealed\n");
            continue;
        }

        board[row][col] = turn;

        if (turn == 0)
            turn = 1;
        else
            turn = 0;

        randomize_board(board, size);

        if (turn == 1) {
            printf("Player 1 wins!\n");
            break;
        }

        printf("Turn %d\n", turn);
    }

    return 0;
}