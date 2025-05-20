//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 1024

typedef struct {
    char *name;
    size_t length;
} string_t;

typedef struct {
    int *data;
    size_t size;
} array_t;

void *malloc_with_name(size_t size, const char *name) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Failed to allocate memory for %s\n", name);
        return NULL;
    }
    printf("Allocated %zu bytes for %s\n", size, name);
    return ptr;
}

void free_with_name(void *ptr, const char *name) {
    if (ptr == NULL) {
        printf("Trying to free null pointer for %s\n", name);
        return;
    }
    printf("Freed %zu bytes for %s\n", ptr, name);
    free(ptr);
}

string_t *create_string(const char *str) {
    size_t len = strlen(str);
    string_t *s = malloc(sizeof(string_t));
    s->name = str;
    s->length = len;
    return s;
}

array_t *create_array(size_t size) {
    array_t *a = malloc(sizeof(array_t));
    a->data = malloc(size * sizeof(int));
    a->size = size;
    return a;
}

int main() {
    // Create a string
    string_t *s = create_string("Hello, world!");
    if (s == NULL) {
        printf("Failed to create string\n");
        return 1;
    }

    // Create an array
    array_t *a = create_array(10);
    if (a == NULL) {
        printf("Failed to create array\n");
        return 2;
    }

    // Malloc some memory with a name
    void *ptr = malloc_with_name(100, "my_memory");
    if (ptr == NULL) {
        printf("Failed to allocate memory for my_memory\n");
        return 3;
    }

    // Free some memory with a name
    free_with_name(ptr, "my_memory");

    // Print the string and array
    printf("String: %s\n", s->name);
    printf("Array: ");
    for (size_t i = 0; i < a->size; i++) {
        printf("%d ", a->data[i]);
    }
    printf("\n");

    // Delete the string and array
    free(s);
    free(a);

    return 0;
}