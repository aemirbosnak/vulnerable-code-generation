//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 10

typedef struct {
    char *name;
    size_t length;
} string_t;

typedef struct {
    int *arr;
    size_t size;
} array_t;

bool is_valid_input(const char *str) {
    size_t i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i] != '-') {
            return false;
        }
    }
    return true;
}

string_t *create_string(const char *str) {
    size_t len = strlen(str);
    string_t *s = malloc(sizeof(string_t));
    s->name = malloc(len + 1);
    strcpy(s->name, str);
    s->length = len;
    return s;
}

array_t *create_array(size_t size) {
    array_t *a = malloc(sizeof(array_t));
    a->arr = malloc(size * sizeof(int));
    a->size = size;
    return a;
}

void print_string(string_t *s) {
    printf("%s\n", s->name);
}

void print_array(array_t *a) {
    size_t i;
    for (i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

void free_string(string_t *s) {
    free(s->name);
    free(s);
}

void free_array(array_t *a) {
    free(a->arr);
    free(a);
}

int main() {
    string_t *s1 = create_string("hello");
    string_t *s2 = create_string("world");
    array_t *a = create_array(5);
    a->arr[0] = 1;
    a->arr[1] = 2;
    a->arr[2] = 3;
    a->arr[3] = 4;
    a->arr[4] = 5;

    print_string(s1);
    print_array(a);

    string_t *s3 = create_string("foo");
    if (!is_valid_input(s3->name)) {
        printf("Invalid input\n");
        return 1;
    }

    free_string(s1);
    free_array(a);

    s1 = create_string("bar");
    print_string(s1);

    array_t *a2 = create_array(10);
    for (size_t i = 0; i < 10; i++) {
        a2->arr[i] = i * 2;
    }
    print_array(a2);

    free_string(s2);
    free_array(a2);

    return 0;
}