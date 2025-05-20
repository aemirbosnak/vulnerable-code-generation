//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main()
{
    int i;
    double elapsed_time;
    clock_t start, end;
    int *array = (int*)malloc(ARRAY_SIZE*sizeof(int)); // allocate memory for array

    // fill array with random numbers
    srand(time(NULL));
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand() % 256;
    }

    // calculate total sum of array using for loop
    start = clock();
    int sum = 0;
    for(i=0; i<ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate elapsed time in seconds
    printf("Total sum using for loop: %d\n", sum);
    printf("Elapsed time using for loop: %f seconds\n\n", elapsed_time);

    // calculate total sum of array using recursion
    start = clock();
    sum = 0;
    int index = 0;
    int* ptr = &index;
    void* array_void = array; // cast int array to void pointer
    int* array_recursion = (int*)array_void; // cast void pointer to int pointer
    sum = calculate_sum(array_recursion, ARRAY_SIZE, ptr);
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate elapsed time in seconds
    printf("Total sum using recursion: %d\n", sum);
    printf("Elapsed time using recursion: %f seconds\n\n", elapsed_time);

    free(array); // free allocated memory for array

    return 0;
}

int calculate_sum(int* array, int size, int* index)
{
    if(*index < size) {
        int sum = array[*index] + calculate_sum(array, size, index + 1);
        return sum;
    }
    else {
        return 0;
    }
}