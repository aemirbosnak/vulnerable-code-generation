//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11
#define LEFT_MARGIN 2
#define RIGHT_MARGIN 2
#define TOP_MARGIN 1
#define BOTTOM_MARGIN 1

void print_pattern(int x, int y, char pattern[HEIGHT][WIDTH]);
void print_spaces(int num_spaces);
void print_line(int x, int y, char pattern[HEIGHT][WIDTH], int line_num);
void print_triangle(int x, int y, char pattern[HEIGHT][WIDTH]);

int main() {
    srand(time(NULL));

    char pattern[HEIGHT][WIDTH];
    int i, j;

    // Initialize pattern with random values
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pattern[i][j] = rand() % 2 + '0';
        }
    }

    printf("\033[1;1H"); // Move the cursor to the home position
    print_pattern(LEFT_MARGIN, TOP_MARGIN, pattern);

    return 0;
}

void print_pattern(int x, int y, char pattern[HEIGHT][WIDTH]) {
    print_spaces(x);
    print_line(x, y, pattern, 0);

    for (int i = 1; i < HEIGHT; i++) {
        print_triangle(x, y + i, pattern);
        print_line(x, y + i, pattern, 1);
    }

    print_spaces(x + WIDTH + RIGHT_MARGIN);
}

void print_spaces(int num_spaces) {
    for (int i = 0; i < num_spaces; i++) {
        putchar(' ');
    }
}

void print_line(int x, int y, char pattern[HEIGHT][WIDTH], int is_last_line) {
    putchar('\033[F'); // Move the cursor up one line

    for (int i = 0; i < WIDTH; i++) {
        putchar(is_last_line ? '\033[1m' : '\033[0m'); // Set text color to red for last line
        putchar(pattern[y][i]);
    }

    putchar('\n');

    for (int i = 0; i < RIGHT_MARGIN; i++) {
        putchar(' ');
    }
}

void print_triangle(int x, int y, char pattern[HEIGHT][WIDTH]) {
    if (y < HEIGHT - 1) {
        print_line(x, y, pattern, 0);
        print_line(x + 1, y + 1, pattern, 0);
    }

    putchar('\n');

    for (int i = 0; i < x; i++) {
        putchar(' ');
    }

    putchar('\\');
    putchar('\n');
}