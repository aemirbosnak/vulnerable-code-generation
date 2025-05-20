//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

typedef struct {
    int *array;
    size_t size;
} BenchmarkData;

void fill_array(BenchmarkData *data) {
    for (size_t i = 0; i < data->size; i++) {
        data->array[i] = rand() % 1000; // Fill with random numbers
    }
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
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

        int partIndex = i + 1;

        quicksort(array, low, partIndex - 1);
        quicksort(array, partIndex + 1, high);
    }
}

void benchmark_sorting(void) {
    BenchmarkData data;
    data.size = ARRAY_SIZE;
    data.array = (int *)malloc(data.size * sizeof(int));

    // Fill array with random numbers
    fill_array(&data);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    // Perform quicksort on the array
    quicksort(data.array, 0, data.size - 1);
    
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorting completed in %f seconds.\n", cpu_time_used);
    
    // Clean up
    free(data.array);
}

void benchmark_linear_search(void) {
    BenchmarkData data;
    data.size = ARRAY_SIZE;
    data.array = (int *)malloc(data.size * sizeof(int));

    // Fill array with random numbers
    fill_array(&data);
    
    clock_t start, end;
    double cpu_time_used;

    int target = data.array[rand() % data.size]; // Pick a random target

    start = clock();
    
    // Perform linear search for the target
    int found = 0;
    for (size_t i = 0; i < data.size; i++) {
        if (data.array[i] == target) {
            found = 1;
            break;
        }
    }
    
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found) {
        printf("Found the target %d in %f seconds.\n", target, cpu_time_used);
    } else {
        printf("Target %d not found in %f seconds.\n", target, cpu_time_used);
    }

    // Clean up
    free(data.array);
}

int main(void) {
    srand(time(NULL));

    printf("Benchmarking Sorting Algorithm...\n");
    benchmark_sorting();

    printf("Benchmarking Linear Search Algorithm...\n");
    benchmark_linear_search();

    return 0;
}