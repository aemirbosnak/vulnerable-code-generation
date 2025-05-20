//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_PATH 256
#define BUFFER_SIZE 1024

typedef struct {
    char source[MAX_FILE_PATH];
    char destination[MAX_FILE_PATH];
    int thread_id;
} FILE_SYNC_DATA;

static FILE_SYNC_DATA file_sync_data[MAX_THREADS];

void *file_sync_thread(void *arg) {
    FILE_SYNC_DATA *data = (FILE_SYNC_DATA *) arg;
    FILE *source_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    source_file = fopen(data->source, "rb");
    if (source_file == NULL) {
        fprintf(stderr, "Error opening source file %s: %s\n", data->source, strerror(errno));
        exit(1);
    }

    dest_file = fopen(data->destination, "wb");
    if (dest_file == NULL) {
        fprintf(stderr, "Error opening destination file %s: %s\n", data->destination, strerror(errno));
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to destination file %s: %s\n", data->destination, strerror(errno));
            exit(1);
        }
    }

    fclose(source_file);
    fclose(dest_file);

    printf("File synchronization completed for thread %d\n", data->thread_id);
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_file destination_file [num_threads]\n", argv[0]);
        exit(1);
    }

    strcpy(file_sync_data[0].source, argv[1]);
    strcpy(file_sync_data[0].destination, argv[2]);
    num_threads = (argc > 3)? atoi(argv[3]) : 1;

    for (i = 1; i < num_threads; i++) {
        sprintf(file_sync_data[i].source, "%s", argv[1]);
        sprintf(file_sync_data[i].destination, "%s_%d", argv[2], i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, file_sync_thread, (void *) &file_sync_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}