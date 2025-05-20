//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // maximum number of elements in the array
#define BUCKET_SIZE 10 // number of elements in each bucket

// function to generate random numbers within a range
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to find the index of the bucket for a given element
int find_bucket(int* arr, int n, int bucket_size) {
    return (int) (arr[n] / bucket_size);
}

// function to sort the elements in each bucket using insertion sort
void bucket_sort(int* arr, int n, int bucket_size) {
    int i, j;
    for (i = 0; i < n; i++) {
        int index = find_bucket(arr, i, bucket_size);
        if (i!= index) {
            swap(&arr[i], &arr[index]);
        }
    }
    for (i = 0; i < n; i++) {
        int index = find_bucket(arr, i, bucket_size);
        int j = i;
        while (j >= 0 && arr[j] < arr[index]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

// function to print the sorted array
void print_array(int* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function to generate random array, sort it using bucket sort, and print the sorted array
int main() {
    int i, n;
    srand(time(0));
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        arr[i] = rand_int(0, MAX_SIZE);
    }
    printf("Unsorted array:\n");
    print_array(arr, n);
    bucket_sort(arr, n, BUCKET_SIZE);
    printf("Sorted array:\n");
    print_array(arr, n);
    free(arr);
    return 0;
}