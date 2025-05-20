//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure for passing data to threads
struct v {
    int *a;
    int n;
};

// Function to be executed by each thread
void *sum_array(void *arg) {
    struct v *data = (struct v *) arg;
    int i, sum = 0;

    // Calculate sum of elements in the array
    for(i=0; i<data->n; i++) {
        sum += data->a[i];
    }

    // Return the sum as result of the thread
    return (void *)sum;
}

int main() {
    pthread_t threads[5];
    int i, sum=0, n=10, *a=(int *)malloc(n*sizeof(int));

    // Initialize the array with random numbers
    for(i=0; i<n; i++) {
        a[i] = rand() % 100;
    }

    // Create 5 threads, each calculating sum of a portion of the array
    struct v v[5];
    int portion = n/5;
    for(i=0; i<5; i++) {
        v[i].a = a+i*portion;
        v[i].n = portion;
        pthread_create(&threads[i], NULL, sum_array, (void *)&v[i]);
    }

    // Join all threads and add up their results
    for(i=0; i<5; i++) {
        pthread_join(threads[i], (void **)&sum);
        sum += *(int *)sum;
    }

    // Print the final sum
    printf("Sum of array elements: %d\n", sum);

    return 0;
}