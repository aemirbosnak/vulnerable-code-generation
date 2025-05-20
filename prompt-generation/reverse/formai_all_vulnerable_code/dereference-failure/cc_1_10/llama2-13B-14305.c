//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to store the list of integers
struct IntList {
    int *arr;
    int size;
    int capacity;
};

// Function to initialize the list
void initList(struct IntList *list) {
    list->arr = malloc(10 * sizeof(int));
    list->size = 0;
    list->capacity = 10;
}

// Function to search an element in the list
int search(struct IntList *list, int target) {
    int i = 0;
    for (i = 0; i < list->size; i++) {
        if (list->arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to insert an element in the list
void insert(struct IntList *list, int element) {
    if (list->size == list->capacity) {
        // Double the capacity of the list
        list->capacity *= 2;
        int *newArr = realloc(list->arr, list->capacity * sizeof(int));
        if (newArr == NULL) {
            printf("Error: Memory allocation failed\n");
            return;
        }
        list->arr = newArr;
    }
    list->arr[list->size] = element;
    list->size++;
}

// Example program
int main() {
    struct IntList list;
    initList(&list);

    insert(&list, 5);
    insert(&list, 10);
    insert(&list, 20);

    // Search for the element 15
    int index = search(&list, 15);
    if (index != -1) {
        printf("Element 15 found at index %d\n", index);
    } else {
        printf("Element 15 not found\n");
    }

    return 0;
}