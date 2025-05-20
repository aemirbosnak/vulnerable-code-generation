//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define MAX_SIZE 1000
#define THREADS_NUM 5

char* data;
char compressed[MAX_SIZE];
int compressed_idx;
pthread_mutex_t lock;

void* compress(void* arg) {
    int chunk_size = MAX_SIZE / THREADS_NUM;
    int idx = *(int*)arg;
    int start_idx = idx * chunk_size;
    int end_idx = start_idx + chunk_size;
    int count = 1;
    
    for (int i = start_idx; i < end_idx; i++) {
        if (data[i] == data[i+1]) {
            count++;
        } else {
            pthread_mutex_lock(&lock);
            compressed[compressed_idx] = data[i];
            compressed[compressed_idx+1] = count + '0';
            compressed_idx += 2;
            pthread_mutex_unlock(&lock);
            count = 1;
        }
    }

    pthread_exit(NULL);
}

int main() {
    data = (char*) malloc(MAX_SIZE * sizeof(char));
    compressed_idx = 0;
    
    // generate random data string
    for (int i = 0; i < MAX_SIZE; i++) {
        data[i] = rand() % 26 + 'a';
    }

    pthread_t threads[THREADS_NUM];
    int thread_ids[THREADS_NUM];

    // initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < THREADS_NUM; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, compress, &thread_ids[i]);
    }

    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Original data: %s\n", data);
    printf("Compressed data: %s\n", compressed);

    pthread_mutex_destroy(&lock);
    free(data);

    return 0;
}