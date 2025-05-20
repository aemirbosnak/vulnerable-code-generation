//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// A struct to hold a key-value pair
typedef struct {
    int key;
    int value;
} KeyValuePair;

// A function to perform binary search on an array of KeyValuePair structs
int binarySearch(KeyValuePair *arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid].key == x) {
            return mid;
        } else if (arr[mid].key < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    // Populate an array of KeyValuePair structs
    int n = 10;
    KeyValuePair *arr = (KeyValuePair *) malloc(n * sizeof(KeyValuePair));
    for (int i = 0; i < n; i++) {
        arr[i].key = i;
        arr[i].value = i * i;
    }

    // Call binary search with various keys to find
    int keysToFind[] = {1, 5, 9, 10, 15};
    int numKeysToFind = sizeof(keysToFind) / sizeof(int);

    for (int i = 0; i < numKeysToFind; i++) {
        int resultIndex = binarySearch(arr, n, keysToFind[i]);

        if (resultIndex == -1) {
            printf("The key %d was not found.\n", keysToFind[i]);
        } else {
            printf("Key %d found at index %d with value %d.\n", keysToFind[i], resultIndex, arr[resultIndex].value);
        }
    }

    free(arr);
    return 0;
}