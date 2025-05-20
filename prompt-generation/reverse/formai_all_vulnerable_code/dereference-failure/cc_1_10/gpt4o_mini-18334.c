//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#define MAX_FILES 5

typedef struct {
    const char *filename;
    int thread_id;
} ThreadData;

void *read_file(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    FILE *file;
    char buffer[256];

    printf("Thread %d: Attempting to read file: %s\n", data->thread_id, data->filename);
    file = fopen(data->filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Thread %d: Error opening file %s: %s\n", data->thread_id, data->filename, strerror(errno));
        pthread_exit(NULL);
    }

    printf("Thread %d: Reading file %s:\n", data->thread_id, data->filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Simulate some processing time
        for (volatile int i = 0; i < 1000000; ++i);
        printf("Thread %d: %s", data->thread_id, buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Thread %d: Error reading file %s: %s\n", data->thread_id, data->filename, strerror(errno));
    }

    fclose(file);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_FILES];
    ThreadData thread_data[MAX_FILES];
    const char *filenames[MAX_FILES] = {
        "file1.txt",
        "file2.txt",
        "nonexistent.txt",
        "file3.txt",
        "protected_file.txt" // assume this file is not readable
    };

    for (int i = 0; i < MAX_FILES; ++i) {
        thread_data[i].filename = filenames[i];
        thread_data[i].thread_id = i;

        if (pthread_create(&threads[i], NULL, read_file, (void *)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread for file %s: %s\n", filenames[i], strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_FILES; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");
    return 0;
}