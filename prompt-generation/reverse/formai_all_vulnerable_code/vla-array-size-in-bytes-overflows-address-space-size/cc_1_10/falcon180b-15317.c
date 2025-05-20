//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

/* Function to swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to calculate the range of an array */
int calculateRange(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];

    for(int i=1; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max - min + 1;
}

/* Function to create an array of random integers */
void createArray(int arr[], int n) {
    srand(time(NULL));

    for(int i=0; i<n; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

/* Function to perform bucket sort */
void bucketSort(int arr[], int n) {
    /* Calculate the range of the array */
    int range = calculateRange(arr, n);

    /* Create an array of empty buckets */
    int buckets[MAX_SIZE] = {0};

    /* Place each element in its respective bucket */
    for(int i=0; i<n; i++) {
        int bucketIndex = arr[i] / (MAX_RANGE / range);
        buckets[bucketIndex]++;
    }

    /* Place the elements back into the array */
    int j = 0;
    for(int i=0; i<range; i++) {
        for(int k=0; k<buckets[i]; k++) {
            arr[j++] = i * MAX_RANGE / range + k * MAX_RANGE / range;
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Main function */
int main() {
    int n;

    /* Get the number of elements from the user */
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    /* Create an array of the specified size */
    int arr[n];

    /* Initialize the array with random integers */
    createArray(arr, n);

    /* Print the unsorted array */
    printf("Unsorted array:\n");
    printArray(arr, n);

    /* Sort the array using bucket sort */
    bucketSort(arr, n);

    /* Print the sorted array */
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}