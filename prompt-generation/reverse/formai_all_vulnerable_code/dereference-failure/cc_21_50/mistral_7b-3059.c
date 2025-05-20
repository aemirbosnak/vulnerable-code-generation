//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#define H 5
#define W 11

char *msg = ".-\\+-—/|\\|\\|\\|\\|";

int main() {
    int i, j, len;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                putchar('*');
            } else {
                len = (H * W) / 2 + 1;
                putchar(msg[(i * W + j) % len]);
            }
        }
        putchar('\n');
    }
    putchar('\n');
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2]);
    }
    putchar(' ');
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2 + 5]);
    }
    putchar(':\n');
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                putchar('*');
            } else {
                len = (H * W) / 2 + 1;
                putchar(msg[(i * W + j) % len]);
            }
        }
        putchar('\n');
    }
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2]);
    }
    putchar(' ');
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2 + 5]);
    }
    putchar(':\n');
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                putchar('*');
            } else {
                len = (H * W) / 2 + 1;
                putchar(msg[(i * W + j) % len]);
            }
        }
        putchar('\n');
    }
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2]);
    }
    putchar(' ');
    for (i = 0; i < 6; i++) {
        putchar(msg[(i * W) / 2 + 5]);
    }
    putchar(':\n');

    return 0;
}