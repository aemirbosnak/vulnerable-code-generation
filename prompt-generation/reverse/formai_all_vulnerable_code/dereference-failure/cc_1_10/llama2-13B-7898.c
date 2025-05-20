//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 256
#define MAX_ARRAY_SIZE 10

typedef struct {
    char *name;
    size_t len;
} str_t;

typedef struct {
    int num;
    str_t *arr;
} arr_t;

void init_str(str_t *s) {
    s->name = (char *)malloc(MAX_STR_LEN * sizeof(char));
    s->len = 0;
}

void free_str(str_t *s) {
    free(s->name);
}

void init_arr(arr_t *a) {
    a->num = 0;
    a->arr = (str_t *)calloc(MAX_ARRAY_SIZE, sizeof(str_t));
}

void free_arr(arr_t *a) {
    int i;
    for (i = 0; i < a->num; i++) {
        free_str(&a->arr[i]);
    }
    free(a->arr);
}

void print_arr(arr_t *a) {
    int i;
    for (i = 0; i < a->num; i++) {
        printf("%s ", a->arr[i].name);
    }
    printf("\n");
}

int main() {
    arr_t *a;
    str_t s1, s2, s3;

    // Initialize array
    init_arr(&a);

    // Initialize first string
    init_str(&s1);
    s1.name = "Hello";
    s1.len = 5;
    a->arr[0] = s1;
    a->num = 1;

    // Initialize second string
    init_str(&s2);
    s2.name = "World";
    s2.len = 5;
    a->arr[1] = s2;
    a->num = 2;

    // Initialize third string
    init_str(&s3);
    s3.name = "C++";
    s3.len = 5;
    a->arr[2] = s3;
    a->num = 3;

    // Print array
    print_arr(a);

    // Free memory
    free_arr(a);

    return 0;
}