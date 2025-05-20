//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Function to generate an array of random integers */
void generate_array(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

/* Function to print the contents of an array */
void print_array(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bubble sort */
void bubble_sort(int* arr, int n) {
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    int n = 10000;              // Size of the array
    int* arr = malloc(n * sizeof(int));
    struct timeval start, end;

    // Generate an array of random integers
    generate_array(arr, n);

    // Perform bubble sort and measure the time taken
    gettimeofday(&start, NULL);
    bubble_sort(arr, n);
    gettimeofday(&end, NULL);

    // Print the sorted array
    print_array(arr, n);

    // Calculate the time taken and print it
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("Bubble Sort took %f seconds to execute \n", time_taken);
  
    /* Freeing up memory */
    free(arr);

    return 0;
}