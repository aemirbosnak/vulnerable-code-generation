//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 1024

typedef struct {
    char *name;
    size_t length;
} string_t;

typedef struct {
    int *array;
    size_t size;
} array_t;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

string_t *create_string(const char *str) {
    size_t len = strlen(str) + 1;
    string_t *s = (string_t *)my_malloc(sizeof(string_t) + len);
    s->name = (char *)(s + 1);
    strcpy(s->name, str);
    s->length = len;
    return s;
}

array_t *create_array(int size) {
    array_t *a = (array_t *)my_malloc(sizeof(array_t) + size * sizeof(int));
    a->array = (int *)(a + 1);
    for (size_t i = 0; i < size; i++) {
        a->array[i] = i + 1;
    }
    a->size = size;
    return a;
}

void print_string(string_t *s) {
    printf("%s\n", s->name);
}

void print_array(array_t *a) {
    for (size_t i = 0; i < a->size; i++) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

int main() {
    string_t *s1 = create_string("Hello");
    string_t *s2 = create_string("World");
    array_t *a1 = create_array(5);
    array_t *a2 = create_array(10);

    print_string(s1);
    print_array(a1);

    s1->length = 20;
    my_free(s1->name);
    s1->name = my_malloc(20);
    strcpy(s1->name, "This is a longer string");

    a1->size = 10;
    my_free(a1->array);
    a1->array = my_malloc(10 * sizeof(int));
    for (size_t i = 0; i < 10; i++) {
        a1->array[i] = i + 1;
    }

    print_string(s1);
    print_array(a1);

    return 0;
}