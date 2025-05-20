//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to compare two strings
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to perform bucket sort
void bucketSort(char **arr, int n) {
    char **bucket = (char **)malloc(MAX_SIZE * sizeof(char *));
    int i, j, k = 0;

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Place each element into its respective bucket
    for (i = 0; i < n; i++) {
        k = strlen(arr[i]) % MAX_SIZE;
        bucket[k] = realloc(bucket[k], (strlen(arr[i]) + 1) * sizeof(char));
        strcat(bucket[k], arr[i]);
    }

    // Sort each bucket using quicksort
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            qsort(bucket[i], strlen(bucket[i]) / sizeof(char), sizeof(char), compare);
        }
    }

    // Merge the sorted buckets back into the original array
    i = j = 0;
    while (i < n && j < MAX_SIZE) {
        if (bucket[j]!= NULL) {
            strcpy(arr[i], bucket[j]);
            i++;
            j++;
        } else {
            j++;
        }
    }

    free(bucket);
}

int main() {
    char **arr = (char **)malloc(10 * sizeof(char *));
    int n = 0;

    // Read input strings and store them in an array
    while (n < 10) {
        char input[100];
        printf("Enter a string: ");
        scanf("%s", input);
        arr[n] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        strcpy(arr[n], input);
        n++;
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}