//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 1000
#define BUFFER_SIZE 1024

typedef struct {
    char *filePath;
    int fileIndex;
} FileInfo;

void *checkFileIntegrity(void *arg) {
    FileInfo *fileInfo = (FileInfo *)arg;
    FILE *file = fopen(fileInfo->filePath, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", fileInfo->filePath);
        return NULL;
    }

    unsigned long checksum = 0;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Calculate checksum
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    fclose(file);
    printf("File: %s, Checksum: %lu\n", fileInfo->filePath, checksum);
    free(fileInfo);
    return NULL;
}

void recoverFiles(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;
    pthread_t threads[MAX_FILES];
    int threadCount = 0;

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            if (threadCount >= MAX_FILES) {
                fprintf(stderr, "Max file limit reached.\n");
                break;
            }

            // Create the full file path
            char filePath[256];
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);

            // Allocate memory for file info and create thread
            FileInfo *fileInfo = malloc(sizeof(FileInfo));
            if (fileInfo == NULL) {
                perror("Memory allocation failed");
                continue;
            }
            fileInfo->filePath = strdup(filePath); // Duplicate string for thread use
            fileInfo->fileIndex = threadCount;

            pthread_create(&threads[threadCount], NULL, checkFileIntegrity, fileInfo);
            threadCount++;
        }
    }
    closedir(dir);

    // Wait for all threads to finish
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char directory[256];

    printf("Enter the directory to scan for files: ");
    scanf("%255s", directory); // Read input safely

    recoverFiles(directory);

    return 0;
}