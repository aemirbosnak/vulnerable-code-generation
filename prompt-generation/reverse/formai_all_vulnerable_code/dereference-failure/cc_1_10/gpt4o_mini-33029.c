//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_BACKUPS 10

typedef struct {
    char *src_file;
    char *backup_file;
} BackupTask;

void *backup_file(void *task) {
    BackupTask *backupTask = (BackupTask *)task;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    // Open the source file for reading
    int src_fd = open(backupTask->src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        pthread_exit(NULL);
    }

    // Open (or create) the backup file for writing
    int backup_fd = open(backupTask->backup_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd < 0) {
        perror("Error opening backup file");
        close(src_fd);
        pthread_exit(NULL);
    }

    // Read from the source file and write to the backup file
    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(backup_fd, buffer, bytesRead);
        if (bytesWritten <= 0) {
            perror("Error writing to backup file");
            break;
        }
    }

    if (bytesRead < 0) {
        perror("Error reading source file");
    }

    // Clean up file descriptors
    close(src_fd);
    close(backup_fd);

    printf("Backup completed from '%s' to '%s'\n", backupTask->src_file, backupTask->backup_file);
    free(backupTask->src_file);
    free(backupTask->backup_file);
    free(backupTask);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_BACKUPS];
    int thread_count = 0;

    for (int i = 1; i < argc; i++) {
        if (thread_count >= MAX_BACKUPS) {
            fprintf(stderr, "Max concurrent backups reached. Waiting for threads to finish...\n");
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0; // Reset thread count
        }

        BackupTask *task = malloc(sizeof(BackupTask));
        task->src_file = strdup(argv[i]);
        
        // Create backup file name
        int len = strlen(argv[i]);
        task->backup_file = malloc(len + 5); // buffer for ".bak"
        snprintf(task->backup_file, len + 5, "%s.bak", argv[i]);

        // Create a new thread for the backup operation
        if (pthread_create(&threads[thread_count], NULL, backup_file, (void *)task) != 0) {
            perror("Error creating thread");
            free(task->src_file);
            free(task->backup_file);
            free(task);
            continue; // Skip to the next file
        }
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("All backups completed.\n");
    return EXIT_SUCCESS;
}