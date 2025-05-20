//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int size;
    struct Sudoku *next;
} Sudoku;

Sudoku *sudoku_insert(Sudoku *head, int size) {
    Sudoku *new_sudoku = malloc(sizeof(Sudoku));
    new_sudoku->board = malloc(size * size * sizeof(int));
    new_sudoku->size = size;
    new_sudoku->next = NULL;

    head = new_sudoku;
    return head;
}

int sudoku_solve(Sudoku *head) {
    if (head == NULL) {
        return 0;
    }

    for (int i = 0; i < head->size; i++) {
        for (int j = 0; j < head->size; j++) {
            if (head->board[i][j] == 0) {
                for (int k = 0; k < head->size; k++) {
                    if (head->board[k][j] != 0 && k != i) {
                        if (head->board[i][k] != 0) {
                            continue;
                        }
                    }
                }

                head->board[i][j] = 1;
                sudoku_solve(head);
                head->board[i][j] = 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *head = sudoku_insert(NULL, 9);
    head->board = malloc(head->size * head->size * sizeof(int));

    head->board[0][0] = 5;
    head->board[0][1] = 3;
    head->board[0][2] = 0;
    head->board[1][0] = 6;
    head->board[1][1] = 0;
    head->board[1][2] = 0;
    head->board[2][0] = 0;
    head->board[2][1] = 0;
    head->board[2][2] = 0;

    sudoku_solve(head);

    for (int i = 0; i < head->size; i++) {
        for (int j = 0; j < head->size; j++) {
            printf("%d ", head->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}