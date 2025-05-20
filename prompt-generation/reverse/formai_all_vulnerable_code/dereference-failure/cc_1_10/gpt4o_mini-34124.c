//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_PATH 512

typedef struct {
    char *filename;
    char *metadata;
} FileMetadata;

void *extract_metadata(void *arg) {
    FileMetadata *fileMeta = (FileMetadata *)arg;

    // Simulate metadata extraction
    // Normally, you'd parse file based on its type
    // Here, we just create a dummy metadata string
    fileMeta->metadata = (char *)malloc(256);
    snprintf(fileMeta->metadata, 256, "Metadata for %s: Size, Type, and other info.", fileMeta->filename);
    
    printf("Extracted metadata for file: %s\n", fileMeta->filename);

    return NULL;
}

void process_files(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    pthread_t threads[MAX_FILES];
    FileMetadata fileMetas[MAX_FILES];
    int count = 0;

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL && count < MAX_FILES) {
        if (entry->d_type == DT_REG) {  // Only regular files
            char *filename = (char *)malloc(MAX_PATH);
            snprintf(filename, MAX_PATH, "%s/%s", directory, entry->d_name);

            fileMetas[count].filename = filename;

            // Create a thread for extracting metadata
            if (pthread_create(&threads[count], NULL, extract_metadata, &fileMetas[count]) != 0) {
                perror("pthread_create");
                free(filename);
            } else {
                count++;
            }
        }
    }

    closedir(dp);

    // Wait for all threads to complete
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
        printf("Metadata for file '%s': %s\n", fileMetas[i].filename, fileMetas[i].metadata);
        free(fileMetas[i].filename);
        free(fileMetas[i].metadata);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_files(argv[1]);

    return EXIT_SUCCESS;
}