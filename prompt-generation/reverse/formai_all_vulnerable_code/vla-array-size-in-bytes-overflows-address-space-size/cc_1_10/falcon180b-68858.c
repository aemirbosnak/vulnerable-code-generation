//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Ada Lovelace style function declarations
void* lovelace_thread(void* arg);
void print_lovelace_message(char* message);

int main() {
    int num_threads;
    printf("Enter the number of threads to create: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int rc;
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, lovelace_thread, (void*)i);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");
    return 0;
}

void* lovelace_thread(void* arg) {
    int thread_num = (int)arg;
    printf("Thread %d starting...\n", thread_num);

    // Ada Lovelace style sleep
    for (int i = 0; i < 100; i++) {
        printf(".");
        sleep(1);
    }

    print_lovelace_message("Hello, world!");

    printf("Thread %d ending.\n", thread_num);
    return NULL;
}

void print_lovelace_message(char* message) {
    printf("Ada Lovelace says: %s\n", message);
}