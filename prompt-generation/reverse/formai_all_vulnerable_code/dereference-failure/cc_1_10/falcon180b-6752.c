//Falcon-180B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define INIT_SIZE 10

typedef struct {
    char **strings;
    size_t size;
    size_t capacity;
} StringArray;

StringArray *create_array(void) {
    StringArray *array = (StringArray *) malloc(sizeof(StringArray));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->strings = (char **) calloc(INIT_SIZE, sizeof(char *));
    if (array->strings == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->size = 0;
    array->capacity = INIT_SIZE;
    return array;
}

void destroy_array(StringArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free(array->strings[i]);
    }
    free(array->strings);
    free(array);
}

void add_string(StringArray *array, const char *str) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->strings = (char **) realloc(array->strings, array->capacity * sizeof(char *));
        if (array->strings == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
    }
    array->strings[array->size] = strdup(str);
    array->size++;
}

void print_array(const StringArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        printf("%s\n", array->strings[i]);
    }
}

int main(void) {
    StringArray *array = create_array();
    add_string(array, "Hello");
    add_string(array, "World");
    print_array(array);
    destroy_array(array);
    return 0;
}