//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define BOARD_SIZE 25
#define BLOCK_SIZE (BOARD_SIZE * BOARD_SIZE)
#define CHUNK_SIZE (BLOCK_SIZE / 16)

typedef struct {
    unsigned char data[CHUNK_SIZE];
    unsigned int open_sites;
} chunk_t;

bool is_valid(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

void print_board(chunk_t *board) {
    int x, y;

    printf("Percolation Status:\n");
    for (y = 0; y < BOARD_SIZE; ++y) {
        for (x = 0; x < BOARD_SIZE; ++x) {
            int idx = y * BOARD_SIZE + x;
            if (x > 0) printf(" ");
            printf("%c", board[idx].data[x % 16] & (1 << (7 - (y % 16))) ? '#' : '.');
        }
        printf("\n");
    }
}

void open_site(chunk_t *board, int x, int y) {
    int idx = y * BOARD_SIZE + x;

    if (!is_valid(x, y)) return;

    board[idx].data[x % 16] ^= (1 << (7 - (y % 16)));
    board[idx].open_sites++;

    if (y > 0) {
        if (board[idx - BOARD_SIZE].data[x % 16] & (1 << 7)) {
            open_site(board, x, y - 1);
        }
    }

    if (y < BOARD_SIZE - 1) {
        if (board[idx + BOARD_SIZE].data[x % 16] & (1 << 0)) {
            open_site(board, x, y + 1);
        }
    }

    if (x > 0) {
        if (board[idx - 1].data[(y % 16) % 16] & (1 << 7)) {
            open_site(board, x - 1, y);
        }
    }

    if (x < BOARD_SIZE - 1) {
        if (board[idx + 1].data[(y % 16) % 16] & (1 << 0)) {
            open_site(board, x + 1, y);
        }
    }
}

int main() {
    int i;
    chunk_t *board;

    srand(time(NULL));

    board = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    for (i = 0; i < BLOCK_SIZE; i += CHUNK_SIZE) {
        memset(board + i / CHUNK_SIZE, 0xFF, CHUNK_SIZE);
    }

    int x, y;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; ++i) {
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (board[y * BOARD_SIZE + x].open_sites > 0);

        open_site(board, x, y);
    }

    print_board(board);

    munmap(board, BLOCK_SIZE);

    return 0;
}