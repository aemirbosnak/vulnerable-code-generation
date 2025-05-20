//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define HASH_LEN 64
#define NUM_THREADS 4

typedef struct {
    char *input;
    char *hash;
} thread_data_t;

void *hash_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char *input = data->input;
    char *hash = data->hash;

    hash = malloc(HASH_LEN * sizeof(char));
    if (hash == NULL) {
        printf("Error: Failed to allocate memory for hash.\n");
        exit(1);
    }

    int len = strlen(input);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        hash[j++] = input[i];
        if (j == HASH_LEN) {
            j = 0;
        }
    }

    for (i = 0; i < HASH_LEN; i++) {
        hash[i] = toupper(hash[i]);
    }

    printf("Thread %d has computed hash: %s\n", pthread_self(), hash);

    return NULL;
}

int main() {
    char input[100] = "Hello, world!";
    char *hash = malloc(HASH_LEN * sizeof(char));
    if (hash == NULL) {
        printf("Error: Failed to allocate memory for hash.\n");
        exit(1);
    }

    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].input = input;
        data[i].hash = hash;
        pthread_create(&threads[i], NULL, hash_thread, (void *) &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final hash: %s\n", hash);

    return 0;
}