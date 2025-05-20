//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i, sum;
    clock_t start, end;
    double time_taken;

    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));

    // fill the array with random values
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % 10;
    }

    printf("Starting Benchmarking...\n");

    // test the performance of for loop
    sum = 0;
    start = clock();
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for for loop: %f seconds\n", time_taken);

    // test the performance of while loop
    sum = 0;
    start = clock();
    i = 0;
    while(i < ARRAY_SIZE)
    {
        sum += array[i];
        i++;
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for while loop: %f seconds\n", time_taken);

    // test the performance of do-while loop
    sum = 0;
    start = clock();
    i = 0;
    do
    {
        sum += array[i];
        i++;
    } while(i < ARRAY_SIZE);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for do-while loop: %f seconds\n", time_taken);

    free(array);

    printf("Benchmarking completed.\n");

    return 0;
}