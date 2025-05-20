//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

// Structure to hold a single element of the array
typedef struct {
    int value;
    char name[20];
} element_t;

// Function to swap two elements
void swap(element_t* a, element_t* b) {
    int temp = a->value;
    strcpy(a->name, b->name);
    strcpy(b->name, temp);
    temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Function to sort the array using bubble sort
void bubble_sort(element_t arr[], int low, int high) {
    int i, j;

    // If the length of the array is 1 or less, return
    if (low >= high) return;

    // Loop through the array
    for (i = low; i <= high; i++) {
        // Loop through the array again, but this time from i+1 to high
        for (j = i + 1; j <= high; j++) {
            // If the current element is less than the next element, swap them
            if (arr[i].value < arr[j].value) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Create an array of elements
    element_t arr[MAX_ARRAY_SIZE];

    // Initialize the array with random values and names
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        arr[i].value = rand() % 100;
        strcpy(arr[i].name, "Element ");
        strcat(arr[i].name, i + 1);
    }

    // Sort the array using bubble sort
    bubble_sort(arr, 0, MAX_ARRAY_SIZE - 1);

    // Print the sorted array
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d: %s\n", arr[i].value, arr[i].name);
    }

    return 0;
}