//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <fcntl.h>
#define WIDTH 81
#define HEIGHT 31
#define SIZE (WIDTH * HEIGHT)
typedef struct {
    bool open;
    int site;
} Cell;
Cell *board;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
void init_board() {
    int i;
    board = mmap(NULL, SIZE * sizeof(Cell), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    for (i = 0; i < SIZE; i++) {
        board[i].open = false;
    }
}
bool is_valid(int r, int c) {
    if (r < 0 || r >= HEIGHT || c < 0 || c >= WIDTH) {
        return false;
    }
    return true;
}
bool open_site(int r, int c) {
    if (!is_valid(r, c) || board[r * WIDTH + c].open) {
        return false;
    }
    board[r * WIDTH + c].open = true;
    int i;
    for (i = 0; i < 4; i++) {
        if (open_site(r + dr[i], c + dc[i])) {
            return true;
        }
    }
    return false;
}
bool percolation() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        if (!board[i * WIDTH].open) {
            for (j = 0; j < WIDTH; j++) {
                if (board[i * WIDTH + j].open) {
                    if (open_site(i + 1, j)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    int i, j;
    srand(time(NULL));
    init_board();
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 10 < 50) {
                open_site(j, i);
            }
        }
    }
    if (percolation()) {
        printf("Percolation occurred!\n");
    } else {
        printf("Percolation did not occur.\n");
    }
    munmap(board, SIZE * sizeof(Cell));
    return 0;
}