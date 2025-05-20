//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_ARR_SIZE 10

typedef struct {
    char *str;
    int len;
} str_t;

typedef struct {
    int arr[MAX_ARR_SIZE];
    int size;
} arr_t;

void init_str(str_t *s) {
    s->str = (char *)malloc(MAX_STR_LEN * sizeof(char));
    s->len = 0;
}

void free_str(str_t *s) {
    free(s->str);
    s->str = NULL;
    s->len = 0;
}

void init_arr(arr_t *a) {
    int i;
    for (i = 0; i < MAX_ARR_SIZE; i++) {
        a->arr[i] = 0;
    }
    a->size = 0;
}

void free_arr(arr_t *a) {
    int i;
    for (i = 0; i < MAX_ARR_SIZE; i++) {
        free(a->arr[i]);
    }
    a->arr[0] = NULL;
    a->size = 0;
}

void print_str(str_t *s) {
    printf("%s\n", s->str);
}

void print_arr(arr_t *a) {
    int i;
    for (i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

int main() {
    str_t str = {"Hello, World!"};
    arr_t arr = {{1, 2, 3, 4, 5}, 5};

    init_str(&str);
    init_arr(&arr);

    print_str(&str);
    print_arr(&arr);

    // dynamically allocate memory for str
    char *new_str = (char *)malloc(str.len + 10);
    strcpy(new_str, str.str);
    new_str[str.len + 9] = '\0';
    str.str = new_str;
    str.len += 10;

    // dynamically allocate memory for arr
    int *new_arr = (int *)malloc(arr.size * sizeof(int));
    for (int i = 0; i < arr.size; i++) {
        new_arr[i] = arr.arr[i] * 2;
    }
    arr.arr[0] = new_arr;
    arr.size *= 2;

    print_str(&str);
    print_arr(&arr);

    // free memory for str
    free_str(&str);

    // free memory for arr
    free_arr(&arr);

    return 0;
}