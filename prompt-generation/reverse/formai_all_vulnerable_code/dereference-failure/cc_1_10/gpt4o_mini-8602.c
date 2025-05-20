//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SOURCE_DIR "source"
#define DEST_DIR "backup"
#define MAX_THREADS 4

typedef struct {
    char *filename;
    int thread_id;
} FileData;

void *backup_file(void *arg) {
    FileData *data = (FileData *)arg;
    char src_path[256], dest_path[256];
    int bytes;
    char buffer[1024];
    
    // Construct file paths
    snprintf(src_path, sizeof(src_path), "%s/%s", SOURCE_DIR, data->filename);
    snprintf(dest_path, sizeof(dest_path), "%s/%s", DEST_DIR, data->filename);
    
    // Open source file
    int src_fd = open(src_path, O_RDONLY);
    if (src_fd < 0) {
        perror("Failed to open source file");
        pthread_exit(NULL);
    }
    
    // Create destination file
    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd < 0) {
        perror("Failed to open/create destination file");
        close(src_fd);
        pthread_exit(NULL);
    }
    
    // Copy contents
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytes) != bytes) {
            perror("Failed to write to destination file");
            close(src_fd);
            close(dest_fd);
            pthread_exit(NULL);
        }
    }

    // Close files
    close(src_fd);
    close(dest_fd);
    
    printf("Thread %d: %s backed up successfully!\n", data->thread_id, data->filename);
    free(data->filename);
    free(data);
    pthread_exit(NULL);
}

void create_backup_directory() {
    struct stat st = {0};
    if (stat(DEST_DIR, &st) == -1) {
        mkdir(DEST_DIR, 0700);
    }
}

int main() {
    create_backup_directory();

    DIR *d;
    struct dirent *dir;
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    d = opendir(SOURCE_DIR);
    if (!d) {
        perror("Could not open source directory");
        return EXIT_FAILURE;
    }

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
            // Allocate space for thread data
            FileData *data = malloc(sizeof(FileData));
            data->filename = strdup(dir->d_name);
            data->thread_id = thread_count;

            // Create a new thread for backup
            pthread_create(&threads[thread_count], NULL, backup_file, (void *)data);
            thread_count++;
            
            // Limit number of threads
            if (thread_count >= MAX_THREADS) {
                for (int i = 0; i < MAX_THREADS; i++) {
                    pthread_join(threads[i], NULL);
                }
                thread_count = 0; // Reset thread count
            }
        }
    }

    closedir(d);

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Backup completed.\n");
    return EXIT_SUCCESS;
}