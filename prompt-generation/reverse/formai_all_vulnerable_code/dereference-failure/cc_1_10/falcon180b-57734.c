//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to perform binary search on a sorted array of strings
int binarySearch(char **arr, int low, int high, char *target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    char **arr;
    int n;

    // Read input from user
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    // Sort the array of strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Perform binary search on the sorted array
    char target[MAX_SIZE];
    printf("Enter the target string: ");
    scanf("%s", target);
    int index = binarySearch(arr, 0, n - 1, target);

    // Print the result
    if (index == -1)
        printf("Target string not found.\n");
    else
        printf("Target string found at index %d.\n", index + 1);

    // Free memory
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}