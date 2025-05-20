//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random number between 0 and max
int rand_num(int max) {
    return rand() % max;
}

// Function to create an array of random numbers
int* create_array(int size) {
    int* arr = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand_num(MAX_SIZE);
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

// Function to perform bucket sort
void bucket_sort(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucket_size = max / size;
    int* buckets = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index]++;
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucket_size + j * bucket_size;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int* arr = create_array(size);
    printf("Unsorted array:\n");
    print_array(arr, size);
    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}