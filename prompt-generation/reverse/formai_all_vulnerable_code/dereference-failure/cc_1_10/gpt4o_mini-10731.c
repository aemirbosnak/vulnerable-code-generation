//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 256

typedef struct {
    char fileName[FILE_NAME_LENGTH];
    off_t fileSize;
    time_t lastModified;
} Metadata;

typedef struct {
    char *filePath;
    Metadata *metadata;
} ThreadData;

void *extract_metadata(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    struct stat fileStat;

    if (stat(data->filePath, &fileStat) == 0) {
        data->metadata->fileSize = fileStat.st_size;
        data->metadata->lastModified = fileStat.st_mtime;
    } else {
        perror("Failed to get file status");
        data->metadata->fileSize = -1;
        data->metadata->lastModified = -1;
    }

    return NULL;
}

void print_metadata(Metadata *metadata) {
    printf("File: %s\n", metadata->fileName);
    printf("Size: %ld bytes\n", metadata->fileSize);
    printf("Last Modified: %s", ctime(&metadata->lastModified));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fileCount = argc - 1;
    if (fileCount > MAX_FILES) {
        fprintf(stderr, "Exceeded maximum allowed files (%d)\n", MAX_FILES);
        return EXIT_FAILURE;
    }

    Metadata metadataArray[MAX_FILES];
    pthread_t threads[MAX_FILES];
    ThreadData threadData[MAX_FILES];

    for (int i = 0; i < fileCount; i++) {
        strncpy(metadataArray[i].fileName, argv[i + 1], FILE_NAME_LENGTH);
        threadData[i].filePath = argv[i + 1];
        threadData[i].metadata = &metadataArray[i];

        if (pthread_create(&threads[i], NULL, extract_metadata, (void *)&threadData[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < fileCount; i++) {
        pthread_join(threads[i], NULL);
        print_metadata(&metadataArray[i]);
    }

    return EXIT_SUCCESS;
}