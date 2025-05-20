//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define PATTERN_LENGTH 5

typedef struct {
    int row;
    int col;
} Position;

void print_binary(int num, int length) {
    int i;
    for (i = length - 1; i >= 0; i--) {
        putchar(num & 1 ? '1' : '0');
        num >>= 1;
    }
    putchar('\n');
}

void hide_pattern(int** grid, int pattern[PATTERN_LENGTH], Position p) {
    int i, j, b;
    for (i = 0; i < PATTERN_LENGTH; i++) {
        b = pattern[i] % 2;
        grid[p.row + (i + 1) % ROWS][p.col + (i + 1) % COLS] = b;
    }
}

int check_pattern(int** grid, int pattern[PATTERN_LENGTH], Position p) {
    int i, j, b;
    for (i = 0; i < PATTERN_LENGTH; i++) {
        j = p.row + (i + 1) % ROWS;
        j = (j < 0) ? j + ROWS : j;
        j = (j >= ROWS) ? j - ROWS : j;
        b = grid[j][p.col + (i + 1) % COLS];
        if (b != pattern[i] % 2) {
            return 0;
        }
    }
    return 1;
}

void reveal_pattern(int** grid, Position p) {
    int i, j;
    printf("The pattern at position (%d, %d) is:\n", p.row, p.col);
    for (i = 0; i < PATTERN_LENGTH; i++) {
        j = p.row + (i + 1) % ROWS;
        j = (j < 0) ? j + ROWS : j;
        j = (j >= ROWS) ? j - ROWS : j;
        print_binary(grid[j][p.col + (i + 1) % COLS], 1);
    }
}

int main() {
    int i, j, k, l, m, n, o, p, q, r, s;
    int pattern[PATTERN_LENGTH];
    int** grid;
    Position position;

    srand(time(NULL));

    grid = malloc(ROWS * sizeof(int*));
    for (i = 0; i < ROWS; i++) {
        grid[i] = calloc(COLS, sizeof(int));
    }

    printf("Generating random pattern...\n");
    for (i = 0; i < PATTERN_LENGTH; i++) {
        pattern[i] = rand() % 2;
    }

    hide_pattern(grid, pattern, (Position) {rand() % ROWS, rand() % COLS});

    printf("Your turn! Remember the pattern and enter the position where you think it is hidden:\n");
    scanf("%d%d", &i, &j);

    position.row = i;
    position.col = j;

    if (check_pattern(grid, pattern, position)) {
        printf("Congratulations! You found the pattern.\n");
        reveal_pattern(grid, position);
    } else {
        printf("Sorry, try again!\n");
    }

    for (i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}