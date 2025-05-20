//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print elements in a bucket
void printBucket(char **bucket, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", bucket[i]);
    }
    printf("\n");
}

// Function to create a new bucket and return a pointer to it
char **createBucket(int size) {
    char **bucket = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        bucket[i] = (char *)malloc(100 * sizeof(char));
    }
    return bucket;
}

// Function to sort strings using Bucket Sort algorithm
void bucketSort(char *arr[], int n) {
    // Create an array of pointers to store the bucket addresses
    char **bucket = createBucket(26);

    // Insert each string into the corresponding bucket
    for (int i = 0; i < n; i++) {
        int ascii = arr[i][0] - 'A';
        bucket[ascii][i] = arr[i];
    }

    // Merge the buckets into a single sorted array
    for (int i = 0; i < 26; i++) {
        char **temp = bucket[i];
        for (int j = 0; j < 26; j++) {
            if (bucket[j]!= NULL && bucket[j][0]!= NULL) {
                for (int k = 0; k < 26; k++) {
                    if (bucket[j][k]!= NULL) {
                        for (int l = 0; l < 26; l++) {
                            if (temp[l] == NULL || temp[l][0] == NULL) {
                                temp[l] = bucket[j][k];
                                bucket[j][k] = NULL;
                            }
                        }
                    }
                }
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"C", "B", "A", "D", "E", "F"};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    return 0;
}