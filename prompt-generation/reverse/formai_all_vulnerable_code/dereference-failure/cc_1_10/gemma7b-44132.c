//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku_board {
    int **board;
    int size;
    int **visited;
} Sudoku_board;

Sudoku_board *sudoku_board_init(int size) {
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    board->visited = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        board->board[i] = 0;
        board->visited[i] = 0;
    }
    return board;
}

void sudoku_board_solve(Sudoku_board *board) {
    for (int i = 0; i < board->size * board->size; i++) {
        if (board->board[i] == 0 && board->visited[i] == 0) {
            for (int j = 0; j < board->size * board->size; j++) {
                if (board->board[j] != 0 && board->visited[j] == 0) {
                    if (board->board[j] == board->board[i] && board->visited[j] == 0) {
                        board->visited[j] = 1;
                        board->board[i] = board->board[j];
                        sudoku_board_solve(board);
                        board->board[i] = 0;
                        board->visited[j] = 0;
                    }
                }
            }
        }
    }
    if (board->board[0] != 0) {
        printf("Solution:\n");
        for (int i = 0; i < board->size; i++) {
            for (int j = 0; j < board->size; j++) {
                printf("%d ", board->board[i * board->size + j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int main() {
    Sudoku_board *board = sudoku_board_init(MAX_SIZE);
    board->board[0] = 5;
    board->board[3] = 3;
    board->board[6] = 4;
    board->board[8] = 2;
    sudoku_board_solve(board);
    return 0;
}