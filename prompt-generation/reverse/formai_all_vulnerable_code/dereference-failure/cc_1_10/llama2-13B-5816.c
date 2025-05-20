//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 100

// Structure to hold a single element in the heap
struct romantic_heap_element {
    int key;
    char *message;
};

// Function to sort the elements in the heap
void romantic_sort(struct romantic_heap_element arr[], int n) {
    int i, j, min_index;
    char temp_message[100];

    // Build a minimum heap
    for (i = (n - 2) / 2; i >= 0; i--) {
        // Find the smallest element in the bottom half of the heap
        min_index = i;
        for (j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j < n && arr[j].key < arr[min_index].key) {
                min_index = j;
            }
        }
        // If the smallest element is not at the root, swap it with the root
        if (min_index != i) {
            temp_message[0] = arr[i].message;
            arr[i].message = arr[min_index].message;
            arr[min_index].message = temp_message;
        }
    }
}

int main() {
    int n = 10; // Size of the heap
    struct romantic_heap_element arr[n];

    // Initialize the elements in the heap with random keys and messages
    for (int i = 0; i < n; i++) {
        arr[i].key = rand() % 100;
        strcpy(arr[i].message, "I love you more than pizza!");
    }

    // Sort the elements in the heap
    romantic_sort(arr, n);

    // Print the sorted elements in the heap
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", arr[i].key, arr[i].message);
    }

    return 0;
}