//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define CHUNK_SIZE 1000

typedef struct {
    char *buffer;
    int start;
    int end;
} thread_data_t;

void *beautify_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char *buffer = data->buffer;
    int start = data->start;
    int end = data->end;

    for (int i = start; i < end; i++) {
        if (buffer[i] == '<') {
            int j = i + 1;
            while (buffer[j]!= '>' && j < end) {
                j++;
            }
            if (j < end) {
                memmove(buffer + j + 1, buffer + i + 1, end - j);
                memcpy(buffer + i, " ", 1);
                i++;
            }
        }
    }

    return NULL;
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    rewind(input_file);

    char *buffer = (char *) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory\n");
        fclose(input_file);
        return 1;
    }

    fread(buffer, file_size, 1, input_file);
    fclose(input_file);

    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    int chunk_size = CHUNK_SIZE;
    int num_threads = 1;

    for (int i = 0; i < num_threads; i++) {
        data[i].buffer = buffer;
        data[i].start = i * chunk_size;
        data[i].end = (i == num_threads - 1)? file_size : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, beautify_thread, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Beautified HTML:\n%s\n", buffer);

    free(buffer);

    return 0;
}