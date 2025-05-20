//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_ROWS 100
#define MAX_COLS 100

enum {
    VALID,
    INVALID_PATTERN_LENGTH,
    INVALID_ROWS_OR_COLS,
    INVALID_CHARACTER,
    INVALID_ARGUMENTS,
    INVALID_ALLOCATION
};

typedef struct {
    char pattern[MAX_PATTERN_LENGTH];
    int rows;
    int cols;
} Pattern;

int validate_pattern(const char *pattern) {
    int i = 0;
    while (*pattern!= '\0' && i < MAX_PATTERN_LENGTH - 1) {
        if (!isprint(*pattern)) {
            return INVALID_CHARACTER;
        }
        pattern++;
        i++;
    }
    if (i == 0) {
        return INVALID_PATTERN_LENGTH;
    }
    return VALID;
}

int validate_rows_and_cols(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return INVALID_ROWS_OR_COLS;
    }
    return VALID;
}

int validate_arguments(int argc, char **argv) {
    if (argc!= 4) {
        return INVALID_ARGUMENTS;
    }
    if (validate_pattern(argv[1])!= VALID) {
        return INVALID_PATTERN_LENGTH;
    }
    if (validate_rows_and_cols(atoi(argv[2]), atoi(argv[3]))!= VALID) {
        return INVALID_ROWS_OR_COLS;
    }
    return VALID;
}

int main(int argc, char **argv) {
    int rows, cols;
    char *pattern = argv[1];
    if (validate_arguments(argc, argv)!= VALID) {
        printf("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    rows = atoi(argv[2]);
    cols = atoi(argv[3]);
    Pattern p = {
       .pattern = pattern,
       .rows = rows,
       .cols = cols
    };
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", p.pattern[i * cols + j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}