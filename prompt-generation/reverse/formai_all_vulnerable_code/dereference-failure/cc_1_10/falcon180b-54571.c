//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_NUM_THREADS 10
#define BUFFER_SIZE 100

typedef struct {
    char input_buffer[BUFFER_SIZE];
    int input_index;
    char output_buffer[BUFFER_SIZE];
    int output_index;
    pthread_mutex_t lock;
} thread_data_t;

void *convert_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;

    pthread_mutex_lock(&data->lock);
    while (data->input_index < BUFFER_SIZE && data->output_index < BUFFER_SIZE) {
        char c = data->input_buffer[data->input_index++];
        if (c >= '0' && c <= '9') {
            char hex_digit = (c - '0') & 0x0f;
            if (hex_digit < 10) {
                data->output_buffer[data->output_index++] = (hex_digit + '0');
            } else {
                data->output_buffer[data->output_index++] = (hex_digit + 'A' - 10);
            }
        } else if (c >= 'A' && c <= 'F') {
            char hex_digit = (c - 'A') & 0x0f;
            data->output_buffer[data->output_index++] = (hex_digit + 'A');
        } else if (c >= 'a' && c <= 'f') {
            char hex_digit = (c - 'a') & 0x0f;
            data->output_buffer[data->output_index++] = (hex_digit + 'A');
        }
    }
    pthread_mutex_unlock(&data->lock);

    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads;
    pthread_t threads[MAX_NUM_THREADS];
    thread_data_t thread_data[MAX_NUM_THREADS];

    if (argc < 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        exit(1);
    }

    num_threads = atoi(argv[1]);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, convert_thread, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}