//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RANDOM_MAX 1000000 // Maximum value for random numbers

/* Function to generate a random number between min and max */
int rand_int(int min, int max) {
    return (int) (rand() % (max - min + 1)) + min;
}

/* Function to generate an array of random integers */
int* generate_array(int size, int min, int max) {
    int *arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(min, max);
    }
    return arr;
}

/* Function to print an array of integers */
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to swap two elements in an array */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to implement bucket sort */
void bucket_sort(int *arr, int size) {
    int num_buckets = 10; // Number of buckets
    int *buckets = (int*) malloc(num_buckets * sizeof(int)); // Array of buckets
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }

    // Place elements into buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (RANDOM_MAX / num_buckets);
        buckets[bucket_index]++;
    }

    // Sort elements within each bucket
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            int index = i * (RANDOM_MAX / num_buckets) + j * (RANDOM_MAX / num_buckets);
            arr[index] = rand_int(0, RANDOM_MAX); // Generate a new random number for each element
        }
    }
}

/* Main function */
int main() {
    int size = 10; // Size of array
    int min = 0; // Minimum value for random numbers
    int max = RANDOM_MAX; // Maximum value for random numbers

    srand(time(NULL)); // Seed the random number generator with the current time

    int *arr = generate_array(size, min, max); // Generate an array of random integers
    print_array(arr, size); // Print the unsorted array

    bucket_sort(arr, size); // Sort the array using bucket sort
    print_array(arr, size); // Print the sorted array

    free(arr); // Free the memory used by the array
    return 0;
}