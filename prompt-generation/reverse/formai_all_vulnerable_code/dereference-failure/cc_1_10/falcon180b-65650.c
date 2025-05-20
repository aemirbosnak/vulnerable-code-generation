//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000

typedef struct {
    int id;
    char ip[16];
    char request[100];
} Request;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *worker(void *arg) {
    Request *request = (Request *) arg;

    printf("Thread %d received request from %s: %s\n", request->id, request->ip, request->request);

    pthread_mutex_lock(&mutex);
    printf("Thread %d is waiting to process request...\n", request->id);
    pthread_cond_wait(&cond, &mutex);
    printf("Thread %d is processing request...\n", request->id);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
        thread_count++;
    }

    for (int i = 0; i < MAX_REQUESTS; i++) {
        Request request;
        sprintf(request.ip, "192.168.%d.%d", rand() % 256, rand() % 256);
        sprintf(request.request, "GET / HTTP/1.1");

        pthread_mutex_lock(&mutex);
        while (thread_count >= MAX_THREADS) {
            printf("No available threads, request from %s is blocked...\n", request.ip);
            pthread_cond_wait(&cond, &mutex);
        }
        thread_count++;
        pthread_mutex_unlock(&mutex);

        printf("Request from %s is assigned to thread %d\n", request.ip, thread_count - 1);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}