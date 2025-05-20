//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define MAX_STRING_LENGTH 100

void print_array(char **array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
}

void resize_array(char ***array, int *capacity) {
    *capacity *= 2;
    *array = realloc(*array, (*capacity) * sizeof(char *));
    if (*array == NULL) {
        perror("Failed to resize array");
        exit(EXIT_FAILURE);
    }
}

void sort_array(char **array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    char **array = malloc(INITIAL_CAPACITY * sizeof(char *));
    if (array == NULL) {
        perror("Failed to allocate initial array");
        return EXIT_FAILURE;
    }

    int capacity = INITIAL_CAPACITY;
    int size = 0;
    char input[MAX_STRING_LENGTH];

    printf("Enter strings to sort (type 'END' to finish):\n");
    while (1) {
        printf("Input string: ");
        fgets(input, sizeof(input), stdin);
        // Remove newline character from the input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "END") == 0) {
            break;
        }

        if (size >= capacity) {
            resize_array(&array, &capacity);
        }

        array[size] = malloc((strlen(input) + 1) * sizeof(char));
        if (array[size] == NULL) {
            perror("Failed to allocate memory for string");
            return EXIT_FAILURE;
        }
        strcpy(array[size], input);
        size++;
    }

    printf("\nYou entered:\n");
    print_array(array, size);

    sort_array(array, size);
    printf("\nSorted strings:\n");
    print_array(array, size);

    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}