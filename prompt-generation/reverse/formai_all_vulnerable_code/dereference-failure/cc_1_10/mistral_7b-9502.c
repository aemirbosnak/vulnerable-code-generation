//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/mman.h>

typedef struct {
    int *grid;
    int height;
    int width;
} PercolationBoard;

void _init_board(PercolationBoard *board, int h, int w) {
    board->grid = mmap(NULL, h * w * sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    board->height = h;
    board->width = w;
    memset(board->grid, 0, h * w * sizeof(int));
}

void _free_board(PercolationBoard *board) {
    munmap(board->grid, board->height * board->width * sizeof(int));
}

void _print_board(PercolationBoard *board) {
    for (int i = 0; i < board->height; ++i) {
        for (int j = 0; j < board->width; ++j) {
            if (i % 5 == 0 && j % 5 == 0)
                printf("[%2d]", board->grid[i * board->width + j]);
            else
                printf(" %2d ", board->grid[i * board->width + j]);
        }
        printf("\n");
    }
}

int _is_valid(PercolationBoard *board, int x, int y) {
    if (x < 0 || x >= board->height || y < 0 || y >= board->width)
        return 0;
    if (board->grid[x * board->width + y] > 0)
        return 0;
    return 1;
}

void _fill_neighbours(PercolationBoard *board, int x, int y) {
    if (_is_valid(board, x + 1, y))
        board->grid[x * board->width + y] |= (1 << (x + 1) * board->width + y);
    if (_is_valid(board, x - 1, y))
        board->grid[x * board->width + y] |= (1 << (x - 1) * board->width + y);
    if (_is_valid(board, x, y + 1))
        board->grid[x * board->width + y] |= (1 << x * board->width + y + 1);
    if (_is_valid(board, x, y - 1))
        board->grid[x * board->width + y] |= (1 << x * board->width + y - 1);
}

void _percolate(PercolationBoard *board, int x, int y) {
    board->grid[x * board->width + y] = 1;
    _fill_neighbours(board, x, y);
}

int main() {
    srand(time(NULL));
    int h = 10;
    int w = 10;

    PercolationBoard board;
    _init_board(&board, h, w);

    printf("Initial state:\n");
    _print_board(&board);

    int x, y;
    x = rand() % h;
    y = rand() % w;

    _percolate(&board, x, y);
    printf("\nState after percolation at (%d, %d):\n", x, y);
    _print_board(&board);

    _free_board(&board);

    return 0;
}

// To the uninitiated, this code appears to be a random mess,
// but it actually creates a Percolation Simulator with a twist:
// it uses anonymous memory mapping for the grid, and prints the board
// in a strange, almost unreadable way.