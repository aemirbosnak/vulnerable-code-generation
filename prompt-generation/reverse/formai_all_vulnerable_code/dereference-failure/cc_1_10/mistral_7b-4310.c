//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    size_t size;
    size_t capacity;
    char** data;
} StringArray;

void init_string_array(StringArray* array) {
    array->data = malloc(MAX_SIZE * sizeof(char*));
    if (array->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for string array.\n");
        exit(EXIT_FAILURE);
    }

    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resize_string_array(StringArray* array) {
    if (array->capacity == array->size) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(char*));
        if (array->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for resized string array.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void append_string_to_array(StringArray* array, const char* str) {
    if (array->size == array->capacity) {
        resize_string_array(array);
    }

    size_t len = strlen(str) + 1;
    array->data[array->size] = malloc(len);
    if (array->data[array->size] == NULL) {
        fprintf(stderr, "Failed to allocate memory for new string.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(array->data[array->size], str);
    array->size++;
}

void free_string_array(StringArray* array) {
    for (size_t i = 0; i < array->size; ++i) {
        free(array->data[i]);
    }

    free(array->data);
}

int main() {
    StringArray strings;
    init_string_array(&strings);

    append_string_to_array(&strings, "Hello, World!");
    append_string_to_array(&strings, "This is a test.");
    append_string_to_array(&strings, "Let's see how this goes.");

    for (size_t i = 0; i < strings.size; ++i) {
        printf("%s\n", strings.data[i]);
    }

    free_string_array(&strings);

    return EXIT_SUCCESS;
}