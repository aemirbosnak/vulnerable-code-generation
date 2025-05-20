//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    char *input_buffer;
    char *output_buffer;
    int buffer_size;
    pthread_t thread_id;
} ThreadData;

void *translate(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    char *input_buffer = thread_data->input_buffer;
    char *output_buffer = thread_data->output_buffer;
    int buffer_size = thread_data->buffer_size;

    for (int i = 0; i < buffer_size; i++) {
        if (isalpha(input_buffer[i])) {
            if (isupper(input_buffer[i])) {
                output_buffer[i] = tolower(input_buffer[i]);
            } else {
                output_buffer[i] = toupper(input_buffer[i]);
            }
        } else {
            output_buffer[i] = input_buffer[i];
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    char input_buffer[MAX_BUFFER_SIZE];
    printf("Enter input string: ");
    fgets(input_buffer, MAX_BUFFER_SIZE, stdin);

    int buffer_size = strlen(input_buffer);

    for (int i = 0; i < NUM_THREADS; i++) {
        int chunk_size = buffer_size / NUM_THREADS;
        if (i == NUM_THREADS - 1) {
            chunk_size = buffer_size % NUM_THREADS;
        }

        thread_data[i].input_buffer = input_buffer + i * chunk_size;
        thread_data[i].output_buffer = malloc(chunk_size + 1);
        thread_data[i].buffer_size = chunk_size;

        pthread_create(&threads[i], NULL, translate, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Output string: %s\n", input_buffer);

    return 0;
}