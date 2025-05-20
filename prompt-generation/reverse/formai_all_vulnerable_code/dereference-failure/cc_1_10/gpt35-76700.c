//FormAI DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_NUM_BACKUPS 10

volatile int num_backups = 0;

void* backup(void* filename) {
    char* original_file = (char*)filename;
    char* backup_file = (char*)malloc(strlen(original_file) + 10);
    sprintf(backup_file, "%s.bak%d", original_file, num_backups++ % MAX_NUM_BACKUPS);

    // Open files
    int orig_fd = open(original_file, O_RDONLY);
    if (orig_fd == -1) {
        printf("Error opening original file: %s\n", strerror(errno));
        free(backup_file);
        return NULL;
    }
    int backup_fd = open(backup_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (backup_fd == -1) {
        printf("Error opening backup file: %s\n", strerror(errno));
        close(orig_fd);
        free(backup_file);
        return NULL;
    }

    // Create buffer for data transfer
    char buffer[BUFFER_SIZE];

    // Transfer data
    ssize_t bytes_read;
    while ((bytes_read = read(orig_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytes_written = write(backup_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("Error writing to backup file: %s\n", strerror(errno));
            close(orig_fd);
            close(backup_fd);
            free(backup_file);
            return NULL;
        }
    }

    // Check for reading errors
    if (bytes_read == -1) {
        printf("Error reading from original file: %s\n", strerror(errno));
        close(orig_fd);
        close(backup_fd);
        free(backup_file);
        return NULL;
    }

    // Close files
    close(orig_fd);
    close(backup_fd);
    free(backup_file);

    return NULL;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename(s)>\n", argv[0]);
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Create threads for each file
    pthread_t* threads = (pthread_t*)malloc((argc - 1) * sizeof(pthread_t));
    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, backup, (void*)argv[i]);
    }

    // Wait for threads to finish
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
    }

    printf("Backup complete.\n");

    free(threads);

    return 0;
}