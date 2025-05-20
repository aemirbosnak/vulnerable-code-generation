//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define CHUNK_SIZE 1024

typedef struct {
    char *filename;
    char *backup_filename;
    int thread_id;
} thread_data_t;

void *backup_thread(void *param) {
    thread_data_t *data = (thread_data_t*) param;

    FILE *file = fopen(data->filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", data->filename);
        exit(1);
    }

    FILE *backup_file = fopen(data->backup_filename, "w");
    if (!backup_file) {
        printf("Error: could not open backup file %s\n", data->backup_filename);
        exit(1);
    }

    char buffer[CHUNK_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Thread %d finished backing up file %s to %s\n", data->thread_id, data->filename, data->backup_filename);
}

int main() {
    char *filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    char *backup_filenames[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        sprintf(backup_filenames[i], "backup_%d.txt", i);
    }

    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].filename = filenames[i % 3];
        data[i].backup_filename = backup_filenames[i];
        data[i].thread_id = i;

        pthread_create(&threads[i], NULL, backup_thread, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}