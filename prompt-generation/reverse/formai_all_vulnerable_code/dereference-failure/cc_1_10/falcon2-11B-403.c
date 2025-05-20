//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char grid[9][9];
    int row, col, num;
} State;

void print_grid(State *state) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (state->grid[i][j] == 0)
                printf("_ ");
            else
                printf("%d ", state->grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(State *state, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (state->grid[i][col] == num)
            return false;
        if (state->grid[row][i] == num)
            return false;
        if (state->grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

State *clone_state(State *state) {
    State *new_state = malloc(sizeof(State));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            new_state->grid[i][j] = state->grid[i][j];
        }
    }
    return new_state;
}

bool solve(State *state) {
    if (state->row == 9) {
        print_grid(state);
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(state, state->row, state->col, num)) {
            state->num = num;
            if (solve(clone_state(state))) {
                return true;
            }
            state->num = 0;
        }
    }
    return false;
}

int main() {
    State *state = malloc(sizeof(State));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            state->grid[i][j] = 0;
        }
    }
    solve(state);
    free(state);
    return 0;
}