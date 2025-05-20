//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 21

typedef struct {
    int x, y, len, depth;
} Point;

char *symbols = "  _____\n /_____/\n/  ___/\n\\/__\\/__\\n\\/  \\/  \\n";

void print_symbol(int len, int depth) {
    char *p = symbols + (len * (3 * depth + 2) - (depth * 3) - 1);
    printf("%s", p);
    fflush(stdout);
    usleep(100000);
}

void generate_square(int x, int y, int len, int depth) {
    if (len <= 0 || depth <= 0)
        return;

    Point p = {x, y, len, depth - 1};
    generate_square(x + len, y, len, depth - 1);
    generate_square(x, y + len, len, depth - 1);
    generate_square(x + len, y + len, len, depth - 1);
    generate_square(x, y, len, depth - 1);
    print_symbol(len, depth);
}

void generate_triangle(int x, int y, int len, int depth) {
    if (len <= 0 || depth <= 0)
        return;

    Point p1 = {x, y, len, depth - 1};
    Point p2 = {x + len, y, len, depth - 1};
    Point p3 = {x + len, y + len, len, depth - 1};

    generate_triangle(x, y, len, depth - 1);
    generate_triangle(p1.x, p1.y, len / 2, depth - 1);
    generate_triangle(p2.x, p2.y, len / 2, depth - 1);
    generate_triangle(p3.x, p3.y, len / 2, depth - 1);

    print_symbol(len, depth);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s shape size\n", argv[0]);
        return 1;
    }

    char shape = argv[1][0];
    int size = atoi(argv[2]);

    if (size > SIZE || size < 1 || shape != 's' && shape != 't') {
        printf("Error: Invalid shape or size.\n");
        return 1;
    }

    if (shape == 's') {
        generate_square(SIZE / 2, SIZE / 2, size, size / 2);
    } else {
        generate_triangle(SIZE / 2, SIZE / 2, size, size / 2);
    }

    return 0;
}