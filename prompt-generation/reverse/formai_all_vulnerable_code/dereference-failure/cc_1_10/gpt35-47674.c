//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILE_SIZE 102400

typedef struct {
    char* metadata;
    int size;
} Metadata;

// Async function for extracting metadata
void* extract_metadata_async(void* arg) {
    FILE* file = fopen((char*) arg, "r");
    if(file == NULL) {
        perror("ERROR: File could not be opened.");
        pthread_exit(NULL);
    }

    char* metadata_start = strstr(arg, "<meta");
    if(metadata_start == NULL) {
        perror("ERROR: Metadata not found.");
        pthread_exit(NULL);
    }

    char* metadata_end = strstr(metadata_start, ">");
    if(metadata_end == NULL) {
        perror("ERROR: Invalid metadata.");
        pthread_exit(NULL);
    }

    int metadata_length = metadata_end - metadata_start + 1;
    if(metadata_length >= MAX_FILE_SIZE) {
        perror("ERROR: Metadata too large.");
        pthread_exit(NULL);
    }

    char* buffer = malloc(sizeof(char) * MAX_FILE_SIZE);
    if(buffer == NULL) {
        perror("ERROR: Memory allocation failed.");
        pthread_exit(NULL);
    }

    fseek(file, 0, SEEK_SET);
    fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->metadata = malloc(sizeof(char) * metadata_length);
    memcpy(metadata->metadata, metadata_start, metadata_length);

    metadata->size = metadata_length;

    return metadata;
}

int main() {
    char* file_path = "example.html";

    pthread_t thread;
    pthread_create(&thread, NULL, extract_metadata_async, (void*) file_path);

    Metadata* metadata;
    pthread_join(thread, (void**) &metadata);

    printf("Metadata: %s\n", metadata->metadata);
    printf("Size: %d\n", metadata->size);

    free(metadata->metadata);
    free(metadata);

    return 0;
}