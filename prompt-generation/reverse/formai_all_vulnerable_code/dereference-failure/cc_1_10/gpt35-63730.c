//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SUCCESS = 0,
    FILE_ERROR,
    MEMORY_ERROR,
    INPUT_ERROR,
    OUTPUT_ERROR
} ErrorCode;

void handle_error(ErrorCode error_code) {
    switch (error_code) {
        case FILE_ERROR:
            fprintf(stderr, "Error: Could not open file!\n");
            exit(FILE_ERROR);
        case MEMORY_ERROR:
            fprintf(stderr, "Error: Could not allocate memory!\n");
            exit(MEMORY_ERROR);
        case INPUT_ERROR:
            fprintf(stderr, "Error: Invalid input detected!\n");
            exit(INPUT_ERROR);
        case OUTPUT_ERROR:
            fprintf(stderr, "Error: Could not write to output file!\n");
            exit(OUTPUT_ERROR);
        default:
            fprintf(stderr, "Unknown error occurred!\n");
            exit(EXIT_FAILURE);
    }
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        handle_error(FILE_ERROR);
    }

    int size;
    if (fscanf(fp, "%d", &size) != 1) {
        handle_error(INPUT_ERROR);
    }

    int *arr = malloc(sizeof(int) * size);
    if (!arr) {
        handle_error(MEMORY_ERROR);
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            handle_error(INPUT_ERROR);
        }
    }

    fclose(fp);

    fp = fopen("output.txt", "w");
    if (!fp) {
        handle_error(OUTPUT_ERROR);
    }

    for (int i = 0; i < size; i++) {
        if (fprintf(fp, "%d\n", arr[i] * 2) < 0) {
            handle_error(OUTPUT_ERROR);
        }
    }

    fclose(fp);
    free(arr);
    return SUCCESS;
}