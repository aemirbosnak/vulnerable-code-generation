//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int *generate_random_numbers(int n) {
    int *numbers = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % n;
    }
    return numbers;
}

// Function to sort the numbers using Bubble Sort
void bubble_sort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// Function to sort the numbers using Quick Sort
void quick_sort(int *numbers, int low, int high) {
    if (low < high) {
        int pivot = numbers[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (numbers[j] < pivot) {
                i++;
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }

        int temp = numbers[i + 1];
        numbers[i + 1] = numbers[high];
        numbers[high] = temp;

        quick_sort(numbers, low, i);
        quick_sort(numbers, i + 2, high);
    }
}

// Function to measure the execution time of a function
double measure_execution_time(void (*function)(int *, int), int *numbers, int n) {
    clock_t start = clock();
    function(numbers, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Main function
int main() {
    int n = 1000000;
    int *numbers = generate_random_numbers(n);

    // Measure the execution time of Bubble Sort
    double bubble_sort_time = measure_execution_time(bubble_sort, numbers, n);

    // Measure the execution time of Quick Sort
    double quick_sort_time = measure_execution_time(quick_sort, numbers, n);

    // Print the execution times
    printf("Bubble Sort execution time: %f seconds\n", bubble_sort_time);
    printf("Quick Sort execution time: %f seconds\n", quick_sort_time);

    return 0;
}