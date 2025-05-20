//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024
#define MAX_THREAD 5

typedef struct {
    char *src_file;
    char *dest_file;
} FilePair;

void *backup_file(void *arg) {
    FilePair *filePair = (FilePair *)arg;
    FILE *src = fopen(filePair->src_file, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        pthread_exit(NULL);
    }
    
    FILE *dest = fopen(filePair->dest_file, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Backed up %s to %s\n", filePair->src_file, filePair->dest_file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_file1> <source_file2> ... <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *dest_directory = argv[argc - 1];
    pthread_t threads[MAX_FILES];
    FilePair filePairs[MAX_FILES];
    int thread_count = 0;

    // Create destination directory if it does not exist
    struct stat st = {0};
    if (stat(dest_directory, &st) == -1) {
        mkdir(dest_directory, 0700);
    }

    for (int i = 1; i < argc - 1; i++) {
        char dest_path[256];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_directory, strrchr(argv[i], '/') ? strrchr(argv[i], '/') + 1 : argv[i]);
        
        filePairs[thread_count].src_file = argv[i];
        filePairs[thread_count].dest_file = strdup(dest_path);
        
        if (pthread_create(&threads[thread_count], NULL, backup_file, (void *)&filePairs[thread_count]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }

        thread_count++;

        // Join threads if we've reached the max thread limit
        if (thread_count == MAX_THREAD) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0; // reset for the next batch
        }
    }

    // Join any remaining threads
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    // Free allocated memory for destination paths
    for (int i = 0; i < argc - 2; i++) {
        free(filePairs[i].dest_file);
    }

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}