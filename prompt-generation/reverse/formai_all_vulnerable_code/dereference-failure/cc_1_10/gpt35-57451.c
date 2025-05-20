//FormAI DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random numbers
int *generateArray(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;
    return arr;
}

// Function to print an array
void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble Sort Algorithm
void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
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

// Function to measure time taken by a function
double timeTaken(void (*func)(int *, int), int *arr, int n)
{
    clock_t start, end;
    start = clock();
    (*func)(arr, n);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main()
{
    int n = 10000;
    int *arr = generateArray(n);

    // Benchmarking the bubble sort algorithm
    double time_spent = timeTaken(bubbleSort, arr, n);
    
    printf("Before sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("After sorting: ");
    printArray(arr, n);

    printf("Time taken for bubble sort: %lf seconds\n", time_spent);

    free(arr);
    return 0;
}