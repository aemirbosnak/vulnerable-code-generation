//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search for a string in an array of strings using linear search
int linear_search(char** arr, int size, char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to search for a string in an array of strings using binary search
int binary_search(char** arr, int size, char* target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (strcmp(arr[mid], target) == 0) {
            return mid;
        } else if (strcmp(arr[mid], target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to search for a string in an array of strings using interpolation search
int interpolation_search(char** arr, int size, char* target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int pos = low + (((high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (strcmp(arr[pos], target) == 0) {
            return pos;
        } else if (strcmp(arr[pos], target) < 0) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    // Initialize an array of strings
    char** arr = malloc(sizeof(char*) * 10);
    arr[0] = "Alice";
    arr[1] = "Bob";
    arr[2] = "Carol";
    arr[3] = "Dave";
    arr[4] = "Eve";
    arr[5] = "Frank";
    arr[6] = "George";
    arr[7] = "Helen";
    arr[8] = "Ian";
    arr[9] = "Jack";

    // Search for a string using linear search
    int index = linear_search(arr, 10, "Carol");
    if (index == -1) {
        printf("String not found using linear search\n");
    } else {
        printf("String found at index %d using linear search\n", index);
    }

    // Search for a string using binary search
    index = binary_search(arr, 10, "Carol");
    if (index == -1) {
        printf("String not found using binary search\n");
    } else {
        printf("String found at index %d using binary search\n", index);
    }

    // Search for a string using interpolation search
    index = interpolation_search(arr, 10, "Carol");
    if (index == -1) {
        printf("String not found using interpolation search\n");
    } else {
        printf("String found at index %d using interpolation search\n", index);
    }

    return 0;
}