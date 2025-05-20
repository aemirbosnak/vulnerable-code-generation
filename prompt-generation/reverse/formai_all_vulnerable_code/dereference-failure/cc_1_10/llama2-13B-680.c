//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_ARRAY_SIZE 10

// Structure to hold a string and its length
typedef struct {
    char *str;
    size_t len;
} str_t;

// Function to allocate memory for a string
str_t *str_alloc(const char *s) {
    size_t len = strlen(s) + 1;
    str_t *str = (str_t *)malloc(sizeof(str_t) + len);
    str->str = (char *)(str + 1);
    str->len = len;
    return str;
}

// Function to deallocate memory for a string
void str_free(str_t *str) {
    free(str);
}

// Function to allocate memory for an array of strings
str_t **array_alloc(size_t num_elems) {
    size_t total_size = num_elems * sizeof(str_t *);
    str_t **array = (str_t **)malloc(total_size);
    for (size_t i = 0; i < num_elems; i++) {
        array[i] = str_alloc(NULL);
    }
    return array;
}

// Function to deallocate memory for an array of strings
void array_free(str_t **array, size_t num_elems) {
    for (size_t i = 0; i < num_elems; i++) {
        str_free(array[i]);
    }
    free(array);
}

int main() {
    // Allocate memory for an array of strings
    str_t **array = array_alloc(MAX_ARRAY_SIZE);

    // Initialize each element of the array with a string
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = str_alloc("Hello, world!");
    }

    // Print out the contents of the array
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%s\n", array[i]->str);
    }

    // Deallocate memory for the array
    array_free(array, MAX_ARRAY_SIZE);

    return 0;
}