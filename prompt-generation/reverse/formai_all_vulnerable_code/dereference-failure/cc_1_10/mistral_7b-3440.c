//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define MIN_SIZE 5
#define MAX_SIZE 21

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_diamond(int size) {
    char symbol = 'A' + (size > 10 ? size - 10 : 0);
    int half_size = size / 2;

    if (size < MIN_SIZE || size > MAX_SIZE) {
        fprintf(stderr, "Invalid size: must be between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        die("Exiting...");
    }

    int row, col;
    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            if ((row < half_size && col < half_size) ||
                (row > half_size - 1 && col >= half_size - size)) {
                printf("%c ", symbol);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        die("Exiting...");
    }

    int size = atoi(argv[1]);

    if (isdigit(argv[1][0]) && size >= MIN_SIZE && size <= MAX_SIZE) {
        print_diamond(size);
    } else {
        fprintf(stderr, "Invalid argument: %s. Must be a positive integer between %d and %d.\n", argv[1], MIN_SIZE, MAX_SIZE);
        die("Exiting...");
    }

    return EXIT_SUCCESS;
}