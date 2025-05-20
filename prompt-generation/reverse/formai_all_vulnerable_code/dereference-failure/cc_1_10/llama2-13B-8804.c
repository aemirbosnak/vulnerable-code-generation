//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10
#define PUZZLE_WIDTH 10
#define PUZZLE_HEIGHT 10

typedef struct {
    char letter;
    int x, y;
} PuzzleCell;

typedef struct {
    PuzzleCell cells[TABLE_SIZE][PUZZLE_WIDTH][PUZZLE_HEIGHT];
    int current_cell;
} PuzzleGrid;

void init_puzzle(PuzzleGrid *grid) {
    int i, j, k;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < PUZZLE_WIDTH; j++) {
            for (k = 0; k < PUZZLE_HEIGHT; k++) {
                grid->cells[i][j][k].letter = '?';
                grid->cells[i][j][k].x = j * 10;
                grid->cells[i][j][k].y = k * 10;
            }
        }
    }
}

void print_puzzle(PuzzleGrid *grid) {
    int i, j, k;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < PUZZLE_WIDTH; j++) {
            for (k = 0; k < PUZZLE_HEIGHT; k++) {
                printf("%c", grid->cells[i][j][k].letter);
                printf(" %d, %d", grid->cells[i][j][k].x, grid->cells[i][j][k].y);
                printf("\n");
            }
        }
    }
}

void move_cell(PuzzleGrid *grid, int dx, int dy) {
    int i, j, k;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < PUZZLE_WIDTH; j++) {
            for (k = 0; k < PUZZLE_HEIGHT; k++) {
                if (grid->cells[i][j][k].letter == '?' || grid->cells[i][j][k].letter == 'X') {
                    if (dx == 0 && dy == 0) {
                        grid->cells[i][j][k].x += 10;
                    } else if (dx == 1 && dy == 0) {
                        grid->cells[i][j][k].x += 20;
                    } else if (dx == 0 && dy == 1) {
                        grid->cells[i][j][k].y += 10;
                    } else {
                        grid->cells[i][j][k].x += 20;
                        grid->cells[i][j][k].y += 10;
                    }
                    break;
                }
            }
        }
    }
}

void solve_puzzle(PuzzleGrid *grid) {
    int i, j, k;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < PUZZLE_WIDTH; j++) {
            for (k = 0; k < PUZZLE_HEIGHT; k++) {
                if (grid->cells[i][j][k].letter == '?') {
                    int x = grid->cells[i][j][k].x / 10;
                    int y = grid->cells[i][j][k].y / 10;
                    if (x < PUZZLE_WIDTH && x >= 0 && y < PUZZLE_HEIGHT && y >= 0) {
                        grid->cells[i][j][k].letter = grid->cells[x][y][0].letter;
                    }
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    PuzzleGrid *grid = malloc(sizeof(PuzzleGrid));
    init_puzzle(grid);
    int move_count = 0;
    while (1) {
        move_cell(grid, rand() % 3 - 1, rand() % 3 - 1);
        move_count++;
        solve_puzzle(grid);
        printf("Move %d: ", move_count);
        print_puzzle(grid);
        if (grid->cells[0][0][0].letter == 'X') {
            break;
        }
    }
    free(grid);
    return 0;
}