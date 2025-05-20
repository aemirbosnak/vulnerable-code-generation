//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024
#define THREAD_COUNT 5

typedef struct {
    char *file_path;
    int thread_id;
} ThreadData;

void *scan_file(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    FILE *file = fopen(data->file_path, "r");
    char buffer[BUFFER_SIZE];
    int found = 0;

    if (!file) {
        fprintf(stderr, "Thread %d: Unable to open file %s\n", data->thread_id, data->file_path);
        pthread_exit(NULL);
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Simulated virus patterns
        if (strstr(buffer, "VIRUS") || strstr(buffer, "INFECTED")) {
            printf("Thread %d: WARNING! Virus detected in file %s\n", data->thread_id, data->file_path);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Thread %d: No viruses found in file %s\n", data->thread_id, data->file_path);
    }

    pthread_exit(NULL);
}

void scan_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];
    int thread_count = 0;

    if (dp == NULL) {
        fprintf(stderr, "Could not open directory %s\n", dir_name);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            if (thread_count >= THREAD_COUNT) {
                // Join threads if we reach the limit
                for (int i = 0; i < THREAD_COUNT; i++) {
                    pthread_join(threads[i], NULL);
                }
                thread_count = 0; // Reset for new batch
            }

            char file_path[BUFFER_SIZE];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            thread_data[thread_count].file_path = strdup(file_path);
            thread_data[thread_count].thread_id = thread_count;

            pthread_create(&threads[thread_count], NULL, scan_file, (void *)&thread_data[thread_count]);
            thread_count++;
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}