//LLAMA2-13B DATASET v1.0 Category: Digital signal processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} buffer_t;

void *process_buffer(void *arg) {
    buffer_t *buf = arg;
    for (int i = 0; i < buf->size; i++) {
        float sample = buf->data[i];
        // do some signal processing here
        sample = sample * 0.5;
        buf->data[i] = sample;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    buffer_t buffer;

    buffer.data = malloc(BUFFER_SIZE * sizeof(float));
    buffer.size = BUFFER_SIZE;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer.data[i] = i / 10.0;
    }

    pthread_create(&thread1, NULL, process_buffer, &buffer);
    pthread_create(&thread2, NULL, process_buffer, &buffer);

    sleep(2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%.2f ", buffer.data[i]);
    }
    printf("\n");

    free(buffer.data);

    return 0;
}