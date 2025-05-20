//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_ARR_SIZE 10

typedef struct node {
    char *str;
    int len;
    struct node *next;
} node_t;

typedef struct arr {
    node_t *arr[MAX_ARR_SIZE];
    int size;
} arr_t;

void init_arr(arr_t *arr) {
    int i;
    for (i = 0; i < MAX_ARR_SIZE; i++) {
        arr->arr[i] = NULL;
    }
    arr->size = 0;
}

void add_str(arr_t *arr, char *str) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->str = str;
    new_node->len = strlen(str);
    new_node->next = NULL;

    if (arr->size == MAX_ARR_SIZE) {
        printf("Error: Array is full, cannot add more strings\n");
        return;
    }

    arr->arr[arr->size] = new_node;
    arr->size++;
}

void print_arr(arr_t *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        node_t *cur_node = arr->arr[i];
        printf("%s (len: %d)\n", cur_node->str, cur_node->len);
    }
}

void free_arr(arr_t *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        node_t *cur_node = arr->arr[i];
        free(cur_node->str);
    }
    free(arr->arr);
}

int main() {
    arr_t *arr = (arr_t *)malloc(sizeof(arr_t));
    init_arr(arr);

    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "C";

    add_str(arr, str1);
    add_str(arr, str2);
    add_str(arr, str3);

    print_arr(arr);

    free_arr(arr);

    return 0;
}