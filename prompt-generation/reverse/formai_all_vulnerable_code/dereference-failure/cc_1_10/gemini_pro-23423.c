//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// This structure will be passed to the thread function
typedef struct
{
    int *array;
    int size;
    int sum;
} sum_args_t;

// This is the thread function that will be executed by each thread
void *sum_array(void *args)
{
    sum_args_t *arguments = (sum_args_t *)args;

    // Calculate the sum of the array
    for (int i = 0; i < arguments->size; i++)
    {
        arguments->sum += arguments->array[i];
    }

    // Return the sum
    return NULL;
}

int main(int argc, char *argv[])
{
    // Check if the user provided the size of the array
    if (argc < 2)
    {
        printf("Usage: %s <size_of_array>\n", argv[0]);
        return 1;
    }

    // Get the size of the array from the user
    int size = atoi(argv[1]);

    // Create an array of the specified size
    int *array = (int *)malloc(sizeof(int) * size);

    // Initialize the array with random numbers
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }

    // Create a thread for each element in the array
    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * size);

    // Create the arguments for each thread
    sum_args_t *args = (sum_args_t *)malloc(sizeof(sum_args_t) * size);

    for (int i = 0; i < size; i++)
    {
        args[i].array = array;
        args[i].size = size;
        args[i].sum = 0;
    }

    // Create the threads
    for (int i = 0; i < size; i++)
    {
        pthread_create(&threads[i], NULL, sum_array, &args[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < size; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Calculate the total sum of the array
    int total_sum = 0;
    for (int i = 0; i < size; i++)
    {
        total_sum += args[i].sum;
    }

    // Print the total sum of the array
    printf("The total sum of the array is: %d\n", total_sum);

    // Clean up
    free(array);
    free(threads);
    free(args);

    return 0;
}