//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create an array of random integers
int* create_array(int size, int min, int max) {
    int* arr = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand_num(min, max);
    }
    return arr;
}

// Function to print an array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the index of the largest element in an array
int find_max(int* arr, int size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// Function to perform bucket sort
void bucket_sort(int* arr, int size, int num_buckets) {
    int* buckets = (int*) malloc(sizeof(int) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_VALUE / num_buckets);
        buckets[bucket_index]++;
    }
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * (MAX_VALUE / num_buckets) + j * (MAX_VALUE / num_buckets / 10);
        }
    }
}

// Function to generate a random array of integers and sort it using bucket sort
void main() {
    srand(time(NULL));
    int size = rand() % (MAX_SIZE - 1) + 1;
    int* arr = create_array(size, 1, MAX_VALUE);
    printf("Original array:\n");
    print_array(arr, size);
    bucket_sort(arr, size, 10);
    printf("Sorted array:\n");
    print_array(arr, size);
}