//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_RANDOM_NUM 100

// Function to initialize an array with random integers
// between 0 and MAX_RANDOM_NUM
void initArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % MAX_RANDOM_NUM;
    }
}

// Function to print the contents of an array
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort on an array
void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to run the benchmark
void runBenchmark(int size)
{
    int* arr = (int*)malloc(size * sizeof(int));
    initArray(arr, size);
    
    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();

    double timeElapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorting %d integers took %f seconds\n", size, timeElapsed);
    
    // Uncomment to print the sorted array
    // printArray(arr, size);
    
    free(arr);
}

int main()
{
    srand(time(NULL));
    
    // Run the benchmark with different array sizes
    runBenchmark(1000);
    runBenchmark(10000);
    runBenchmark(100000);
    runBenchmark(1000000);
    
    return 0;
}