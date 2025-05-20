//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    int len;
} Buffer;

void *hash_thread(void *arg) {
    Buffer *buffer = arg;
    char hash[32];
    int i, j;
    for (i = 0; i < strlen(buffer->data); i++) {
        hash[i % 32] ^= buffer->data[i];
    }
    for (i = 0; i < 32; i++) {
        hash[i] = toupper(hash[i]);
    }
    printf("Thread %d calculated hash: %s\n", pthread_self(), hash);
    return NULL;
}

int main() {
    FILE *file;
    char ch;
    int len = 0;
    char *data = malloc(BUFFER_SIZE);
    pthread_t threads[NUM_THREADS];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        data[len] = ch;
        len++;
        if (len == BUFFER_SIZE) {
            break;
        }
    }

    fclose(file);

    int buffer_size = len / NUM_THREADS;
    Buffer buffers[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        buffers[i].data = data + i * buffer_size;
        buffers[i].len = buffer_size;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, hash_thread, &buffers[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(data);
    return 0;
}