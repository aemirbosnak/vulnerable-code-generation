//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg);
void *thread2(void *arg);

int main() {
    pthread_t tid1, tid2;
    int err1, err2;

    // Create thread1
    if ((err1 = pthread_create(&tid1, NULL, &thread1, NULL)) != 0) {
        printf("Error creating thread1: %s\n", strerror(err1));
        exit(1);
    }

    // Create thread2
    if ((err2 = pthread_create(&tid2, NULL, &thread2, NULL)) != 0) {
        printf("Error creating thread2: %s\n", strerror(err2));
        exit(1);
    }

    // Wait for both threads to finish
    if ((err1 = pthread_join(tid1, NULL)) != 0) {
        printf("Error joining thread1: %s\n", strerror(err1));
        exit(1);
    }
    if ((err2 = pthread_join(tid2, NULL)) != 0) {
        printf("Error joining thread2: %s\n", strerror(err2));
        exit(1);
    }

    printf("Program complete.\n");
    return 0;
}

void *thread1(void *arg) {
    printf("Thread1 starting...\n");

    // Simulate an error
    int *ptr = NULL;
    *ptr = 5;

    printf("Thread1 complete.\n");
    pthread_exit(NULL);
}

void *thread2(void *arg) {
    printf("Thread2 starting...\n");
    printf("Thread2 complete.\n");
    pthread_exit(NULL);
}