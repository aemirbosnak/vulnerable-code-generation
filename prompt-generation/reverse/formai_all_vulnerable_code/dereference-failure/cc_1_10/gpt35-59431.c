//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int main()
{
    int i;
    int* arr = (int*)malloc(SIZE * sizeof(int));
    double start, end;

    // Populate array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Measure execution time of linear search
    start = clock();
    for (i = 0; i < SIZE; i++)
    {
        if (arr[i] == 500)
        {
            printf("Found value at index %d\n", i);
        }
    }
    end = clock();
    printf("Linear search time taken: %lf sec\n", (end - start) / CLOCKS_PER_SEC);

    // Measure execution time of binary search
    start = clock();
    int low = 0, high = SIZE - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == 500)
        {
            printf("Found value at index %d\n", mid);
            break;
        }
        else if (arr[mid] < 500)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    end = clock();
    printf("Binary search time taken: %lf sec\n", (end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}