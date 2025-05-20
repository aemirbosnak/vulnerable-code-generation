//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int thread_id;
} ThreadData;

void *extract_metadata(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    FILE *file = fopen(data->filename, "r");
    
    if (!file) {
        fprintf(stderr, "Thread %d: Error opening file %s\n", data->thread_id, data->filename);
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    int line_count = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        line_count++;
        if (line_count <= 10) { // Extract first 10 lines as metadata
            printf("Thread %d processing %s: %s", data->thread_id, data->filename, buffer);
        }
    }

    fclose(file);
    pthread_exit(NULL);
}

void list_files_in_directory(const char *path, char files[][BUFFER_SIZE], int *count) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            snprintf(files[*count], BUFFER_SIZE, "%s/%s", path, entry->d_name);
            (*count)++;
            if (*count >= MAX_THREADS) break; // Limit to MAX_THREADS
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char files[MAX_THREADS][BUFFER_SIZE];
    int file_count = 0;

    list_files_in_directory(argv[1], files, &file_count);

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    for (int i = 0; i < file_count; i++) {
        thread_data[i].filename = files[i];
        thread_data[i].thread_id = i;

        if (pthread_create(&threads[i], NULL, extract_metadata, &thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread for file: %s\n", files[i]);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed processing files in directory: %s\n", argv[1]);
    return EXIT_SUCCESS;
}