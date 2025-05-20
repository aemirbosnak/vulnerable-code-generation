//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

typedef struct {
    Node *array;
    int size;
} Array;

void init(Array *arr) {
    arr->array = (Node *)malloc(MAX_SIZE * sizeof(Node));
    arr->size = 0;
}

void insert(Array *arr, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->index = arr->size;
    arr->array[arr->size++] = *new_node;
    free(new_node);
}

void delete(Array *arr, int index) {
    for (int i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
        arr->array[i + 1].index = i;
    }
    arr->size--;
}

void search(Array *arr, int data) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i].data == data) {
            printf("Found %d at index %d\n", data, arr->array[i].index);
        }
    }
}

void print_array(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i].data);
    }
}

int main() {
    Array arr;
    init(&arr);
    srand(time(0));
    for (int i = 0; i < MAX_SIZE; i++) {
        int data = rand() % 100;
        insert(&arr, data);
    }
    printf("Original array:\n");
    print_array(&arr);
    search(&arr, 42);
    delete(&arr, 42);
    printf("Array after deleting 42:\n");
    print_array(&arr);

    return 0;
}