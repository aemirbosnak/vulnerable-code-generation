//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 1024

// Structure to hold file information and results
typedef struct {
    char *filename;
    int thread_id;
} FileJob;

const char *malware_signatures[] = {
    "malware1",
    "malware2",
    "threatX",
    "virusA"
};

void *scan_file(void *job) {
    FileJob *fileJob = (FileJob *)job;
    FILE *file = fopen(fileJob->filename, "r");
    char buffer[BUFFER_SIZE];
    int found = 0;

    if (file == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        for (int i = 0; i < sizeof(malware_signatures) / sizeof(malware_signatures[0]); i++) {
            if (strstr(buffer, malware_signatures[i]) != NULL) {
                printf("Thread %d: Malware signature '%s' found in file: %s\n", fileJob->thread_id, malware_signatures[i], fileJob->filename);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("Thread %d: No malware found in file: %s\n", fileJob->thread_id, fileJob->filename);
    }

    fclose(file);
    free(fileJob->filename);
    free(fileJob);
    pthread_exit(NULL);
}

void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && thread_count < MAX_THREADS) { // Only regular files
            FileJob *fileJob = (FileJob *)malloc(sizeof(FileJob));
            fileJob->filename = malloc(strlen(directory) + strlen(entry->d_name) + 2);
            sprintf(fileJob->filename, "%s/%s", directory, entry->d_name);
            fileJob->thread_id = thread_count;

            if (pthread_create(&threads[thread_count], NULL, scan_file, (void *)fileJob) != 0) {
                perror("Failed to create thread");
                free(fileJob->filename);
                free(fileJob);
                continue;
            }

            thread_count++;
        }

        if (thread_count == MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for future threads
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}