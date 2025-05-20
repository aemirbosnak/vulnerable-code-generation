//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_STRINGS 10
#define STRING_SIZE 50

typedef struct string_array {
    char **strings;
    size_t size;
    size_t capacity;
} StringArray;

void init_string_array(StringArray *string_array) {
    string_array->strings = malloc(MAX_NUM_STRINGS * sizeof(char *));
    if (!string_array->strings) {
        fprintf(stderr, "Failed to allocate memory for string array\n");
        exit(EXIT_FAILURE);
    }

    string_array->size = 0;
    string_array->capacity = MAX_NUM_STRINGS;
}

void resize_string_array(StringArray *string_array) {
    if (string_array->size == string_array->capacity) {
        string_array->capacity *= 2;
        string_array->strings = realloc(string_array->strings, string_array->capacity * sizeof(char *));
        if (!string_array->strings) {
            fprintf(stderr, "Failed to allocate memory for expanded string array\n");
            exit(EXIT_FAILURE);
        }
    }
}

void append_string_to_array(StringArray *string_array, const char *str) {
    if (string_array->size == string_array->capacity) {
        resize_string_array(string_array);
    }

    size_t len = strlen(str) + 1;
    string_array->strings[string_array->size] = malloc(len);
    if (!string_array->strings[string_array->size]) {
        fprintf(stderr, "Failed to allocate memory for string %ld\n", string_array->size);
        exit(EXIT_FAILURE);
    }

    strcpy(string_array->strings[string_array->size], str);
    string_array->size++;
}

void print_string_array(const StringArray *string_array) {
    for (size_t i = 0; i < string_array->size; ++i) {
        printf("%s\n", string_array->strings[i]);
    }
}

void deinit_string_array(StringArray *string_array) {
    for (size_t i = 0; i < string_array->size; ++i) {
        free(string_array->strings[i]);
    }

    free(string_array->strings);
}

int main() {
    StringArray string_array;
    init_string_array(&string_array);

    append_string_to_array(&string_array, "Hello");
    append_string_to_array(&string_array, "World");
    append_string_to_array(&string_array, "C Programming");

    print_string_array(&string_array);

    deinit_string_array(&string_array);

    return 0;
}