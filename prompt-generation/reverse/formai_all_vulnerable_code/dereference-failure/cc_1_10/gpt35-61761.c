//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5 // maximum number of elements in the buffer
#define MAX_ALLOC 100 // maximum bytes to allocate

int buffer[BUFFER_SIZE]; // shared buffer
int buffer_top = 0; // index of the top element in the buffer
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex to protect the buffer
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER; // condition variable to signal buffer not full
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER; // condition variable to signal buffer not empty

void* producer(void *arg) {
    int i;
    for(i = 0; i < 10; i++) {
        // allocate memory
        int *p = malloc(rand() % MAX_ALLOC);
        if(p == NULL) {
            perror("malloc");
            exit(1);
        }
        printf("producer: allocated %d bytes\n", (int) sizeof(*p));
        
        // add element to buffer
        pthread_mutex_lock(&mutex);
        while(buffer_top == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_not_full, &mutex);
        }
        buffer[buffer_top++] = (int) p;
        pthread_cond_signal(&buffer_not_empty);
        pthread_mutex_unlock(&mutex);

        // wait
        usleep(rand() % 100000);
    }
    return NULL;
}

void* consumer(void *arg) {
    int i;
    for(i = 0; i < 10; i++) {
        // remove element from buffer
        pthread_mutex_lock(&mutex);
        while(buffer_top == 0) {
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }
        int *p = (int*) buffer[--buffer_top];
        pthread_cond_signal(&buffer_not_full);
        pthread_mutex_unlock(&mutex);
        
        // free memory
        printf("consumer: freeing %d bytes\n", (int) sizeof(*p));
        free(p);
        
        // wait
        usleep(rand() % 100000);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t prod_tid, cons_tid;
    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);
    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);
    return 0;
}