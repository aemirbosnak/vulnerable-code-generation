//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char *filename;
} MetadataRequest;

void extract_metadata(const char *filename) {
    // Simulate metadata extraction
    printf("Extracting metadata from file: %s\n", filename);
    sleep(1); // Simulate time delay for extraction
    printf("Metadata extracted for file: %s\n", filename);
}

void *async_extract(void *arg) {
    MetadataRequest *request = (MetadataRequest *)arg;
    extract_metadata(request->filename);
    free(request->filename);
    free(request);
    return NULL;
}

void start_async_metadata_extraction(const char *filename) {
    pthread_t thread;
    MetadataRequest *request = malloc(sizeof(MetadataRequest));
    request->filename = strdup(filename); // Allocate memory for filename
    
    if (pthread_create(&thread, NULL, async_extract, request) != 0) {
        perror("Failed to create thread");
        free(request->filename);
        free(request);
        exit(EXIT_FAILURE);
    }

    // Detach thread so it can run independently
    pthread_detach(thread);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting asynchronous metadata extraction...\n");

    for (int i = 1; i < argc; i++) {
        start_async_metadata_extraction(argv[i]);
    }

    // Main thread continues to run while extraction happens in the background
    while (1) {
        printf("Main thread is doing other work...\n");
        sleep(2); // Simulate doing other work
    }

    return EXIT_SUCCESS;
}