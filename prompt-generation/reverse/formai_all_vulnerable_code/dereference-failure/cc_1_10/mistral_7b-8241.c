//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BOARD_SIZE 10
#define CELL_SIZE 1
#define MEM_SIZE (BOARD_SIZE * CELL_SIZE * BOARD_SIZE * CELL_SIZE)

typedef unsigned char byte;
typedef struct {
    int width, height;
    byte **cells;
} Board;

Board *newBoard(int width, int height) {
    Board *b = calloc(1, sizeof(Board) + (width * height) * sizeof(byte *));
    b->width = width;
    b->height = height;
    b->cells = (byte **) (b + 1);
    for (int y = 0; y < height; y++) {
        b->cells[y] = (byte *) (b + 1 + width * height + y * width);
    }
    return b;
}

void freeBoard(Board *b) {
    free(b->cells[0]);
    free(b->cells);
    free(b);
}

void setCell(Board *b, int x, int y, byte value) {
    b->cells[y][x] = value;
}

byte getCell(Board *b, int x, int y) {
    return b->cells[y][x];
}

void drawBoard(Board *b) {
    for (int y = 0; y < b->height; y++) {
        for (int x = 0; x < b->width; x++) {
            putchar(getCell(b, x, y) + '0');
        }
        putchar('\n');
    }
}

void nextGeneration(Board *b) {
    int x, y, n;
    byte cell;
    for (y = 0; y < b->height; y++) {
        for (x = 0; x < b->width; x++) {
            cell = getCell(b, x, y);
            n = neighbors(b, x, y);
            if (cell && (n < 2 || n > 3)) setCell(b, x, y, 0);
            else if (!cell && (n == 3)) setCell(b, x, y, 1);
        }
    }
}

int neighbors(Board *b, int x, int y) {
    int n = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                int xx = x + dx, yy = y + dy;
                if (xx >= 0 && xx < b->width && yy >= 0 && yy < b->height) {
                    n += getCell(b, xx, yy);
                }
            }
        }
    }
    return n;
}

int main() {
    int i;
    Board *b;

    b = newBoard(5, 5);

    for (i = 0; i < 5 * 5; i++) {
        setCell(b, i % 5, i / 5, i % 2 == 0);
    }

    while (1) {
        drawBoard(b);
        nextGeneration(b);
        sleep(1);
    }

    freeBoard(b);
    return 0;
}