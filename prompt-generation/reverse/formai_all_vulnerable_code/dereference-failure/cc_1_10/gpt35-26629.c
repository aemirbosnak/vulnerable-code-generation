//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_THREADS 4

char input_file_name[MAX_BUFFER_SIZE];
char output_file_name[MAX_BUFFER_SIZE];

pthread_mutex_t lock;

typedef struct _ThreadData {
    int thread_id;
    char* buffer;
    int buffer_size;
} ThreadData;

void* readFile(ThreadData* data) {
    int start = data->thread_id * (data->buffer_size / MAX_THREADS);
    int end = start + (data->buffer_size / MAX_THREADS);

    pthread_mutex_lock(&lock);

    FILE* input_file = fopen(input_file_name, "rb");
    if (!input_file) {
        perror("Failed to open input file\n");
        exit(1);
    }

    fseek(input_file, start, SEEK_SET);
    fread(data->buffer, data->buffer_size, 1, input_file);

    fclose(input_file);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void writeToFile(char* buffer, int buffer_size) {
    pthread_mutex_lock(&lock);

    FILE* output_file = fopen(output_file_name, "ab");
    if (!output_file) {
        perror("Failed to open output file\n");
        exit(1);
    }

    fwrite(buffer, buffer_size, 1, output_file);

    fclose(output_file);

    pthread_mutex_unlock(&lock);
}

void recoverData() {
    char buffer[MAX_BUFFER_SIZE * MAX_THREADS];
    int buffer_size = 0;

    int i;
    ThreadData threads[MAX_THREADS];
    pthread_t thread_ids[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; ++i) {
        threads[i].thread_id = i;
        threads[i].buffer = buffer + i * MAX_BUFFER_SIZE;
        threads[i].buffer_size = MAX_BUFFER_SIZE;

        int rc = pthread_create(&thread_ids[i], NULL, (void*)readFile, &threads[i]);
        if (rc) {
            perror("Could not create thread\n");
            exit(1);
        }
    }

    for (i = 0; i < MAX_THREADS; ++i) {
        pthread_join(thread_ids[i], NULL);

        buffer_size += threads[i].buffer_size;
    }

    writeToFile(buffer, buffer_size);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    strcpy(input_file_name, argv[1]);
    strcpy(output_file_name, argv[2]);

    recoverData();

    return 0;
}