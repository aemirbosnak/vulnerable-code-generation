//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define INIT_VALUE 0

// Function to generate random numbers
void generateRandom(int arr[], int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand()%MAX_SIZE;
    }
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int size) {
    int n = size;
    int max = arr[0];
    int min = arr[0];

    for(int i=0; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_size = range / n;

    int *bucket[MAX_SIZE];

    for(int i=0; i<n; i++) {
        int bucket_index = (arr[i] - min) / bucket_size;
        if(bucket[bucket_index] == NULL) {
            bucket[bucket_index] = malloc(sizeof(int));
        }
        int *temp = bucket[bucket_index];
        while(*temp!= INIT_VALUE) {
            temp = temp + 1;
        }
        *temp = arr[i];
    }

    int j = 0;
    for(int i=0; i<n; i++) {
        if(bucket[i]!= NULL) {
            int *temp = bucket[i];
            while(*temp!= INIT_VALUE) {
                arr[j] = *temp;
                temp = temp + 1;
                j++;
            }
        }
    }
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generateRandom(arr, size);

    printf("Unsorted array:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("Sorted array:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}