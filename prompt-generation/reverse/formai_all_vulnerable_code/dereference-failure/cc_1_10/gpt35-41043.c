//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void randomize_array(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
}

void bubble_sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        int j_min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[j_min])
            {
                j_min = j;
            }
        }
        if (j_min != i)
        {
            temp = arr[i];
            arr[i] = arr[j_min];
            arr[j_min] = temp;
        }
    }
}

void insertion_sort(int *arr, int size)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int *array = malloc(sizeof(int) * ARRAY_SIZE);

    randomize_array(array, ARRAY_SIZE);

    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    start = clock();

    bubble_sort(array, ARRAY_SIZE);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort took %f seconds\n", cpu_time_used);

    randomize_array(array, ARRAY_SIZE);

    // Selection Sort
    start = clock();

    selection_sort(array, ARRAY_SIZE);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Selection Sort took %f seconds\n", cpu_time_used);

    randomize_array(array, ARRAY_SIZE);

    // Insertion Sort
    start = clock();

    insertion_sort(array, ARRAY_SIZE);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Insertion Sort took %f seconds\n", cpu_time_used);

    free(array);

    return 0;
}