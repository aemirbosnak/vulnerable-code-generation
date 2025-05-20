//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the list of integers
typedef struct {
    int* arr;
    int size;
    int capacity;
} list;

// Function to create a new list
list* new_list(int capacity) {
    list* l = (list*) malloc(sizeof(list));
    l->arr = (int*) malloc(capacity * sizeof(int));
    l->size = 0;
    l->capacity = capacity;
    return l;
}

// Function to insert an element into the list
void insert(list* l, int e) {
    if (l->size == l->capacity) {
        // Double the capacity of the list
        int* new_arr = (int*) realloc(l->arr, 2 * l->capacity * sizeof(int));
        if (new_arr == NULL) {
            // Oops, out of memory!
            printf("Error: Out of memory\n");
            return;
        }
        l->arr = new_arr;
        l->capacity *= 2;
    }
    l->arr[l->size++] = e;
}

// Function to search for an element in the list
int search(list* l, int e) {
    int i;
    for (i = 0; i < l->size; i++) {
        if (l->arr[i] == e) {
            return i;
        }
    }
    return -1;
}

int main() {
    list* l = new_list(10);
    insert(l, 5);
    insert(l, 10);
    insert(l, 15);
    insert(l, 20);
    int found = search(l, 15);
    if (found != -1) {
        printf("Found %d at index %d\n", found, found + 1);
    } else {
        printf("Not found\n");
    }
    return 0;
}