//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_ARRAY_SIZE 100
#define STRING_SIZE 256

void check_memory_allocation(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void read_integers(int *array, size_t size) {
    printf("Enter %zu integers:\n", size);
    for (size_t i = 0; i < size; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading integer. Invalid input detected.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void write_to_file(const char *filename, const int *array, size_t size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s' for writing: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; ++i) {
        if (fprintf(file, "%d\n", array[i]) < 0) {
            fprintf(stderr, "Error writing to file '%s': %s\n", filename, strerror(errno));
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing the file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Data successfully written to '%s'.\n", filename);
}

void read_from_file(const char *filename, int *array, size_t *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s' for reading: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (*size < MAX_ARRAY_SIZE && fscanf(file, "%d", &array[*size]) == 1) {
        (*size)++;
    }

    if (!feof(file)) {
        fprintf(stderr, "Error reading from file '%s': Expecting format mismatch or file is too large.\n", filename);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing the file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Data successfully read from '%s'. Total numbers read: %zu\n", filename, *size);
}

void print_array(const int *array, size_t size) {
    printf("Array contents:\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *numbers = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));
    check_memory_allocation(numbers);

    size_t size = 0;

    char input_file[STRING_SIZE];
    char output_file[STRING_SIZE];

    printf("Enter the input file name for reading integers: ");
    scanf("%s", input_file);
    read_from_file(input_file, numbers, &size);
    print_array(numbers, size);

    printf("Enter the output file name for saving integers: ");
    scanf("%s", output_file);
    write_to_file(output_file, numbers, size);

    free(numbers);
    return 0;
}