//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ARRAY_SIZE 100
#define MIN_VALUE -2147483648
#define MAX_VALUE 2147483647

typedef struct {
    int array[MAX_ARRAY_SIZE];
    size_t size;
} Array;

void check_input(const char *msg, int value, const char *input) {
    if (value < MIN_VALUE || value > MAX_VALUE) {
        fprintf(stderr, "Error: %s - Input value out of range\n", msg);
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(input);

    for (size_t i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            fprintf(stderr, "Error: %s - Input must be a valid integer\n", msg);
            exit(EXIT_FAILURE);
        }
    }
}

bool c_search(const Array *array, int value) {
    if (array == NULL) {
        fprintf(stderr, "Error: Array is null\n");
        exit(EXIT_FAILURE);
    }

    if (array->size > MAX_ARRAY_SIZE) {
        fprintf(stderr, "Error: Array size exceeds maximum allowed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < array->size; i++) {
        if (array->array[i] == value) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <array_size> <value>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Array array;
    check_input("Array size", atoi(argv[1]), argv[1]);

    array.size = atoi(argv[1]);

    for (size_t i = 0; i < array.size; i++) {
        check_input("Array element", (int) rand() % (MAX_VALUE + 1), "Random");
        array.array[i] = rand() % (MAX_VALUE + 1);
    }

    check_input("Value to search", atoi(argv[2]), argv[2]);

    if (!c_search(&array, atoi(argv[2]))) {
        fprintf(stderr, "Error: Value not found in array\n");
        exit(EXIT_FAILURE);
    }

    printf("Value %d found in array.\n", atoi(argv[2]));

    free(array.array);

    return EXIT_SUCCESS;
}