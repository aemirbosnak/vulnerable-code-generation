//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[100];
int sum = 0;
pthread_mutex_t lock;

void *sumThread(void *arg) {
    int start = *((int*) arg);
    int end = start + 10;
    int thread_sum = 0;
    for(int i=start; i<end; i++) {
        thread_sum += arr[i];
    }

    pthread_mutex_lock(&lock);
    sum += thread_sum;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_mutex_init(&lock, NULL);

    for(int i=0; i<100; i++) {
        arr[i] = rand()%10;
    }

    printf("The array is:\n");
    for(int i=0; i<100; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    for(int i=0; i<10; i++) {
        int *arg = (int*)malloc(sizeof(*arg));
        *arg = i*10;
        pthread_create(&threads[i], &attr, sumThread, arg);
    }

    for(int i=0; i<10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nThe sum of all elements in the array is: %d", sum);

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&lock);

    return 0;
}