//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[10];

// A function to print an array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Thread function to multiply given number with each element of the array
void *multiply(void *arg)
{
    int num = *(int *)arg;
    sleep(1);
    int *res = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        res[i] = arr[i] * num;
    printf("Thread with ID %ld: Array after multiplication\n", pthread_self());
    printArray(res, 10);
    return (void *)res;
}

int main()
{
    pthread_t t1, t2;
    int num1 = 2, num2 = 3;

    // Initialize the array
    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;

    // Create two threads
    pthread_create(&t1, NULL, multiply, (void *)&num1);
    pthread_create(&t2, NULL, multiply, (void *)&num2);

    // Wait for the threads to finish
    void *res1, *res2;
    pthread_join(t1, &res1);
    pthread_join(t2, &res2);

    // Print the final arrays
    printf("Thread with ID %ld: Final array 1\n", t1);
    printArray((int *)res1, 10);
    printf("Thread with ID %ld: Final array 2\n", t2);
    printArray((int *)res2, 10);

    // Free the memory allocated to the arrays
    free((int *)res1);
    free((int *)res2);

    return 0;
}