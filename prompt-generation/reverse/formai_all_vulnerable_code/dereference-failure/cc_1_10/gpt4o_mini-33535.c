//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_THREADS 4

typedef struct {
    const char *source_dir;
    const char *dest_dir;
    const char *file_name;
} FileSyncTask;

void *sync_file(void *arg) {
    FileSyncTask *task = (FileSyncTask *)arg;
    char source_path[PATH_MAX];
    char dest_path[PATH_MAX];
    
    // Create full paths for source and destination
    snprintf(source_path, sizeof(source_path), "%s/%s", task->source_dir, task->file_name);
    snprintf(dest_path, sizeof(dest_path), "%s/%s", task->dest_dir, task->file_name);

    // Open source file
    int src_fd = open(source_path, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return NULL;
    }

    // Open (or create) destination file
    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return NULL;
    }

    // Buffer to hold file data for copying
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Copy file data from source to destination
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination file");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
    }

    // Clean up
    close(src_fd);
    close(dest_fd);
    printf("Synchronized: %s to %s\n", source_path, dest_path);
    return NULL;
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        // Skip the . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Prepare synchronization task
        FileSyncTask *task = malloc(sizeof(FileSyncTask));
        task->source_dir = source_dir;
        task->dest_dir = dest_dir;
        task->file_name = entry->d_name;

        // Create a thread to sync the file
        pthread_create(&threads[thread_count], NULL, sync_file, task);
        thread_count++;

        // Wait for current thread if maximum thread limit reached
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
                thread_count--;
            }
            thread_count = 0;
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_directory(source_dir, dest_dir);

    return EXIT_SUCCESS;
}