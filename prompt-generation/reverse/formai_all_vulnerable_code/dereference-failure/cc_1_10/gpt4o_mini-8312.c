//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Function to generate a random array of integers
void generate_random_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000; // Random number between 0 and 9999
    }
}

// Bubble Sort function
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Quick Sort function
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Function to display an array
void display_array(const int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int *array_bubble = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array_quick = (int *)malloc(ARRAY_SIZE * sizeof(int));

    generate_random_array(array_bubble, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array_quick[i] = array_bubble[i]; // Copy for quick sort
    }

    printf("Welcome to the Sorting Benchmark Program!\n");
    printf("Generating an array of %d random integers...\n", ARRAY_SIZE);

    // Time Bubble Sort
    clock_t start_bubble = clock();
    bubble_sort(array_bubble, ARRAY_SIZE);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    printf("Bubble Sort completed in: %.6f seconds\n", time_bubble);

    // Time Quick Sort
    clock_t start_quick = clock();
    quick_sort(array_quick, 0, ARRAY_SIZE - 1);
    clock_t end_quick = clock();
    double time_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

    printf("Quick Sort completed in: %.6f seconds\n", time_quick);

    // Comment on performance
    if (time_bubble < time_quick) {
        printf("Bubble Sort was faster, which is surprising!\n");
    } else {
        printf("Quick Sort was faster, as expected!\n");
    }

    // Display the sorted array (optional, can comment out for large arrays)
    // printf("Sorted Array (Bubble Sort): ");
    // display_array(array_bubble, ARRAY_SIZE);
    // printf("Sorted Array (Quick Sort): ");
    // display_array(array_quick, ARRAY_SIZE);

    free(array_bubble);
    free(array_quick);
    printf("Thanks for using the Sorting Benchmark Program! Have a great day!\n");

    return 0;
}