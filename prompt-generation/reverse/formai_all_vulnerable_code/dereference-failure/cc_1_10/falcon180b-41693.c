//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to sort the strings using bucket sort
void bucketSort(char **array, int size) {
    char **buckets = (char **)malloc(size * sizeof(char *));
    memset(buckets, 0, size * sizeof(char *));

    // Fill the buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = strlen(array[i]) % size;
        buckets[bucketIndex] = realloc(buckets[bucketIndex], (strlen(array[i]) + 1) * sizeof(char));
        strcat(buckets[bucketIndex], array[i]);
    }

    // Sort the buckets
    qsort(buckets, size, sizeof(char *), compare);

    // Concatenate the sorted buckets
    char *result = (char *)malloc((size * strlen(array[0]) + 1) * sizeof(char));
    memset(result, 0, size * strlen(array[0]) + 1);

    int index = 0;
    for (int i = 0; i < size; i++) {
        strcat(result, buckets[i]);
        free(buckets[i]);
    }

    free(buckets);
    strcpy(array[0], result);
    free(result);
}

int main() {
    char **array = (char **)malloc(10 * sizeof(char *));
    memset(array, 0, 10 * sizeof(char *));

    array[0] = "apple";
    array[1] = "banana";
    array[2] = "cherry";
    array[3] = "date";
    array[4] = "elderberry";
    array[5] = "fig";
    array[6] = "grape";
    array[7] = "honeydew";
    array[8] = "kiwi";
    array[9] = "lemon";

    bucketSort(array, 10);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", array[i]);
    }

    free(array);
    return 0;
}