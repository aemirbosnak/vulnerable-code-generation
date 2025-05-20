//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define INITIAL_NUM_LINES 10

typedef struct {
    char **strings;
    int num_lines;
    int capacity;
} array_t;

void init_array(array_t *array) {
    array->strings = malloc(INITIAL_NUM_LINES * sizeof(char *));
    array->num_lines = 0;
    array->capacity = INITIAL_NUM_LINES;
}

void resize_array(array_t *array) {
    array->capacity *= 2;
    array->strings = realloc(array->strings, array->capacity * sizeof(char *));
}

void add_string_to_array(array_t *array, const char *str) {
    if (array->num_lines == array->capacity) {
        resize_array(array);
    }
    array->strings[array->num_lines] = strdup(str);
    array->num_lines++;
}

void print_array(const array_t *array) {
    for (int i = 0; i < array->num_lines; i++) {
        printf("%s\n", array->strings[i]);
    }
}

void free_array(array_t *array) {
    for (int i = 0; i < array->num_lines; i++) {
        free(array->strings[i]);
    }
    free(array->strings);
    array->strings = NULL;
}

int main() {
    array_t strings_array;
    init_array(&strings_array);

    char line1[MAX_LINE_LENGTH] = "Hello, World!";
    char line2[MAX_LINE_LENGTH] = "This is a test.";

    add_string_to_array(&strings_array, line1);
    add_string_to_array(&strings_array, line2);

    print_array(&strings_array);

    char line3[MAX_LINE_LENGTH] = "Another line to add.";
    add_string_to_array(&strings_array, line3);

    print_array(&strings_array);

    free_array(&strings_array);

    return 0;
}