//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of each element in the array
typedef struct {
    int data;
    int index;
} element;

// Define the structure of the array
typedef struct {
    element *arr;
    int size;
} array;

// Initialize the array with the given size
void init(array *a, int size) {
    a->arr = (element *)malloc(sizeof(element) * size);
    a->size = size;
}

// Free the memory allocated to the array
void destroy(array *a) {
    free(a->arr);
}

// Insert an element into the array
void insert(array *a, int data) {
    if (a->size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    element e;
    e.data = data;
    e.index = rand() % MAX_SIZE;
    for (int i = 0; i < a->size; i++) {
        if (a->arr[i].index == e.index) {
            printf("Element already exists.\n");
            return;
        }
    }
    a->arr[a->size] = e;
    a->size++;
}

// Search for an element in the array
element* search(array *a, int data) {
    for (int i = 0; i < a->size; i++) {
        if (a->arr[i].data == data) {
            return &a->arr[i];
        }
    }
    return NULL;
}

// Print the elements of the array
void print(array *a) {
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i].data);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));
    array a;
    init(&a, 10);
    for (int i = 0; i < 20; i++) {
        int data = rand() % 100;
        insert(&a, data);
    }
    print(&a);
    element *e = search(&a, 50);
    if (e!= NULL) {
        printf("Found element with data %d and index %d.\n", e->data, e->index);
    } else {
        printf("Element not found.\n");
    }
    destroy(&a);
    return 0;
}