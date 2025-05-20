//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define ELEMENT_SIZE 256

typedef struct {
    int count;
    void *elements;
} Array;

void array_init(Array *arr) {
    arr->elements = malloc(MAX_ELEMENTS * ELEMENT_SIZE);
    if (arr->elements == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for array.\n");
        exit(EXIT_FAILURE);
    }
    arr->count = 0;
}

void array_deinit(Array *arr) {
    free(arr->elements);
}

void array_push(Array *arr, const void *element) {
    if (arr->count == MAX_ELEMENTS) {
        arr->elements = realloc(arr->elements, (MAX_ELEMENTS + 1) * ELEMENT_SIZE);
        if (arr->elements == NULL) {
            fprintf(stderr, "Error: Failed to reallocate memory for array.\n");
            exit(EXIT_FAILURE);
        }
    }
    memcpy((char *)arr->elements + arr->count * ELEMENT_SIZE, element, ELEMENT_SIZE);
    arr->count++;
}

int main(int argc, char **argv) {
    Array int_arr;
    Array str_arr;

    array_init(&int_arr);
    array_init(&str_arr);

    for (int i = 0; i < 15; i++) {
        int num = i * i;
        array_push(&int_arr, &num);
    }

    for (int i = 0; i < 10; i++) {
        char str[32];
        snprintf(str, sizeof(str), "String %d", i);
        array_push(&str_arr, str);
    }

    printf("Integer array:\n");
    for (int i = 0; i < int_arr.count; i++) {
        int *num_ptr = (int *)((char *)int_arr.elements + i * ELEMENT_SIZE);
        printf("%d ", *num_ptr);
    }
    printf("\n");

    printf("String array:\n");
    for (int i = 0; i < str_arr.count; i++) {
        char *str_ptr = (char *)int_arr.elements + i * ELEMENT_SIZE;
        size_t len = strlen(str_ptr) + 1;
        char *str = malloc(len);
        strncpy(str, str_ptr, len);
        printf("%s ", str);
        free(str);
    }
    printf("\n");

    array_deinit(&int_arr);
    array_deinit(&str_arr);

    return EXIT_SUCCESS;
}