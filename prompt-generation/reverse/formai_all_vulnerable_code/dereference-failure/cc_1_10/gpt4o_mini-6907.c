//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 2
#define GROWTH_FACTOR 2

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} StringArray;

StringArray* create_string_array() {
    StringArray *arr = (StringArray *)malloc(sizeof(StringArray));
    if (!arr) {
        perror("Failed to create array");
        exit(EXIT_FAILURE);
    }
    arr->data = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (!arr->data) {
        perror("Failed to allocate memory for data");
        free(arr);
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    return arr;
}

void free_string_array(StringArray *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr->data);
    free(arr);
}

void append_to_string_array(StringArray *arr, const char *str) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= GROWTH_FACTOR;
        arr->data = (char **)realloc(arr->data, arr->capacity * sizeof(char *));
        if (!arr->data) {
            perror("Failed to resize array");
            free_string_array(arr);
            exit(EXIT_FAILURE);
        }
    }
    arr->data[arr->size] = (char *)malloc(strlen(str) + 1);
    if (!arr->data[arr->size]) {
        perror("Failed to allocate memory for string");
        free_string_array(arr);
        exit(EXIT_FAILURE);
    }
    strcpy(arr->data[arr->size], str);
    arr->size++;
}

void print_string_array(const StringArray *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printf("[%lu]: %s\n", i, arr->data[i]);
    }
}

void sort_string_array(StringArray *arr) {
    for (size_t i = 0; i < arr->size - 1; i++) {
        for (size_t j = 0; j < arr->size - i - 1; j++) {
            if (strcmp(arr->data[j], arr->data[j + 1]) > 0) {
                char *temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    StringArray *myStrings = create_string_array();
    char buffer[256];

    printf("Enter strings (type 'exit' to finish):\n");
    
    while (1) {
        printf("String %zu: ", myStrings->size + 1);
        fgets(buffer, sizeof(buffer), stdin);
        
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        append_to_string_array(myStrings, buffer);
    }

    printf("\nYou entered:\n");
    print_string_array(myStrings);

    sort_string_array(myStrings);
    printf("\nSorted strings:\n");
    print_string_array(myStrings);

    free_string_array(myStrings);
    return EXIT_SUCCESS;
}