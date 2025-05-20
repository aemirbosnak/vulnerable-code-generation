//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucket_sort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    for (int i = 0; i < range; i++) {
        if (bucket[i]!= 0) {
            printf("Bucket %d: ", i + min);
            for (int j = 0; j < bucket[i]; j++) {
                printf("%d ", i + min);
            }
            printf("\n");
        }
    }
    free(bucket);
}

// Function to generate an array of random integers
int* generate_array(int n) {
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(1, 100);
    }
    return arr;
}

int main() {
    srand(time(NULL));
    int n = 10;
    int* arr = generate_array(n);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}