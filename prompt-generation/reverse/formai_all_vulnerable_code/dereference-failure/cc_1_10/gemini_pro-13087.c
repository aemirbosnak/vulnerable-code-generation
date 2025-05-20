//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int8_t matrix[9][9];
    int8_t used[9];
} board;

static void
print_board(board *b)
{
    for (int8_t y = 0; y < 9; y++) {
        for (int8_t x = 0; x < 9; x++) {
            printf("%d ", b->matrix[y][x]);
        }
        printf("\n");
    }
}

static void
copy_board(board *dst, board *src)
{
    memcpy(dst->matrix, src->matrix, sizeof(src->matrix));
    memcpy(dst->used, src->used, sizeof(src->used));
}

static int8_t
is_valid_move(board *b, int8_t x, int8_t y, int8_t val)
{
    for (int8_t i = 0; i < 9; i++) {
        if (b->matrix[y][i] == val || b->matrix[i][x] == val) {
            return 0;
        }
    }

    for (int8_t i = y % 3 * 3; i < y % 3 * 3 + 3; i++) {
        for (int8_t j = x % 3 * 3; j < x % 3 * 3 + 3; j++) {
            if (b->matrix[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

static void
solve(board *b, int8_t x, int8_t y)
{
    if (x == 9) {
        x = 0;
        y++;
    }

    if (y == 9) {
        print_board(b);
        exit(0);
    }

    if (b->matrix[y][x] == 0) {
        for (int8_t i = 1; i <= 9; i++) {
            if (is_valid_move(b, x, y, i)) {
                board b2;
                copy_board(&b2, b);
                b2.matrix[y][x] = i;
                b2.used[i - 1] = 1;
                solve(&b2, x + 1, y);
            }
        }
    } else {
        solve(b, x + 1, y);
    }
}

int
main(int argc, char **argv)
{
    if (argc != 10) {
        printf("usage: %s <row1> <row2> <row3> <row4> <row5> <row6> <row7> <row8> <row9>\n", argv[0]);
        exit(1);
    }

    board b;
    for (int8_t y = 0; y < 9; y++) {
        for (int8_t x = 0; x < 9; x++) {
            b.matrix[y][x] = atoi(argv[y + 1][x]);
            if (b.matrix[y][x] != 0) {
                b.used[b.matrix[y][x] - 1] = 1;
            }
        }
    }

    solve(&b, 0, 0);
    return 0;
}