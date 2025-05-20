//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 50

void print_square(char pattern, int size, int row, int col) {
    if (row > size) {
        return;
    }

    for (int i = 0; i < size; i++) {
        if (i == 0 || i == size - 1 || col == size) {
            printf("%c", pattern);
        } else {
            printf(" ");
        }
    }

    printf("\n");

    if (col < size) {
        print_square(pattern, size, row, col + 1);
    }
}

int main(int argc, char *argv[]) {
    char pattern;
    int size;

    if (argc != 3) {
        printf("Usage: %s <character> <size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pattern = argv[1][0];
    size = atoi(argv[2]);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Error: Size should be a positive number less than or equal to %d\n", MAX_SIZE);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    printf("Generated Pattern using character '%c' and size %d:\n", pattern, size);

    print_square(pattern, size, 1, 1);

    return EXIT_SUCCESS;
}