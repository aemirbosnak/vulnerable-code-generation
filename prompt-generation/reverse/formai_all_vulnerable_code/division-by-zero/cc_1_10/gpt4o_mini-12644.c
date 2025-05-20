//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 1024

pthread_mutex_t mutex;
char *json_string;
int string_length;

typedef struct {
    int start;
    int end;
    char *result;
} ThreadData;

void *parse_json(void *data) {
    ThreadData *thread_data = (ThreadData *)data;

    for (int i = thread_data->start; i < thread_data->end; i++) {
        // Skip whitespace
        if (isspace(json_string[i])) continue;

        // Start parsing a JSON object
        if (json_string[i] == '{') {
            thread_data->result = strdup("Parsed an object");
            break;
        }
        // Start parsing a JSON array
        else if (json_string[i] == '[') {
            thread_data->result = strdup("Parsed an array");
            break;
        }
    }

    pthread_exit(NULL);
}

void create_threads(int num_threads, int length) {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int segment = length / num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = i * segment;
        thread_data[i].end = (i == num_threads - 1) ? length : (i + 1) * segment;
        thread_data[i].result = NULL;

        if (pthread_create(&threads[i], NULL, parse_json, (void *)&thread_data[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
        if (thread_data[i].result) {
            pthread_mutex_lock(&mutex);
            printf("Thread %d: %s\n", i, thread_data[i].result);
            free(thread_data[i].result);
            pthread_mutex_unlock(&mutex);
        }
    }
}

char *read_json_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    size_t total_length = 0;
    size_t bytes_read;

    while ((bytes_read = fread(buffer + total_length, 1, BUFFER_SIZE - total_length, file)) > 0) {
        total_length += bytes_read;
        if (total_length >= BUFFER_SIZE) {
            buffer = realloc(buffer, total_length + BUFFER_SIZE);
            if (!buffer) {
                perror("Failed to reallocate memory");
                fclose(file);
                return NULL;
            }
        }
    }
    buffer[total_length] = '\0';
    fclose(file);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <json_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_mutex_init(&mutex, NULL);
    json_string = read_json_file(argv[1]);
    if (!json_string) {
        return EXIT_FAILURE;
    }

    string_length = strlen(json_string);
    int num_threads = (string_length < MAX_THREADS) ? string_length : MAX_THREADS;

    create_threads(num_threads, string_length);

    free(json_string);
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}