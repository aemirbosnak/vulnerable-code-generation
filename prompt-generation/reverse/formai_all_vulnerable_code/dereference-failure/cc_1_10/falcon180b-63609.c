//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    int buf_size;
    int buf_len;
    pthread_mutex_t mutex;
} buffer_t;

void init_buffer(buffer_t *buffer) {
    buffer->buffer = (char*)malloc(BUFFER_SIZE);
    buffer->buf_size = BUFFER_SIZE;
    buffer->buf_len = 0;
    pthread_mutex_init(&buffer->mutex, NULL);
}

void destroy_buffer(buffer_t *buffer) {
    pthread_mutex_destroy(&buffer->mutex);
    free(buffer->buffer);
}

void *thread_func(void *arg) {
    buffer_t *buffer = (buffer_t*)arg;
    char ch;

    while (1) {
        pthread_mutex_lock(&buffer->mutex);
        if (buffer->buf_len == 0) {
            pthread_mutex_unlock(&buffer->mutex);
            break;
        }
        ch = buffer->buffer[--buffer->buf_len];
        pthread_mutex_unlock(&buffer->mutex);

        printf("%c", ch);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    buffer_t buffer;

    init_buffer(&buffer);

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        pthread_mutex_lock(&buffer.mutex);
        if (buffer.buf_len == buffer.buf_size) {
            printf("Buffer full.\n");
            pthread_mutex_unlock(&buffer.mutex);
            break;
        }
        buffer.buffer[buffer.buf_len++] = ch;
        pthread_mutex_unlock(&buffer.mutex);

        if (num_threads < MAX_THREADS) {
            pthread_create(&threads[num_threads], NULL, thread_func, &buffer);
            num_threads++;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    destroy_buffer(&buffer);

    return 0;
}