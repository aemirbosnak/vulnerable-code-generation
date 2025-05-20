//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 10

typedef struct {
    char *filename;
    int id;
    int allocated_memory;
} FileData;

pthread_t threads[NUM_THREADS];
FileData *files;
int num_files;

void *monitor_memory(void *arg) {
    FileData *file_data = (FileData *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int file_size = 0;

    FILE *fp = fopen(file_data->filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_data->filename);
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        file_size += bytes_read;
    }

    fclose(fp);

    if (file_size > file_data->allocated_memory) {
        printf("File %s has exceeded its allocated memory (%d bytes)\n", file_data->filename, file_data->allocated_memory);
    }
}

int main() {
    int i;
    char line[256];
    char *filename;
    char *delimiter = ",";
    char *token;
    FileData *file_data;

    printf("Enter filenames and allocated memory (in bytes) separated by commas:\n");
    fgets(line, 256, stdin);

    files = (FileData *) malloc(sizeof(FileData));
    num_files = 1;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, monitor_memory, files);
    }

    while (fgets(line, 256, stdin)!= NULL) {
        token = strtok(line, delimiter);
        while (token!= NULL) {
            filename = strtok(NULL, delimiter);
            file_data = (FileData *) malloc(sizeof(FileData));

            file_data->filename = strdup(filename);
            file_data->id = num_files;
            file_data->allocated_memory = atoi(token);

            files = (FileData *) realloc(files, sizeof(FileData) * (num_files + 1));
            files[num_files - 1] = *file_data;
            num_files++;

            token = strtok(NULL, delimiter);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(files);

    return 0;
}