//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct {
    char source[MAX_PATH];
    char destination[MAX_PATH];
} SyncData;

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void sync_files(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char src_file[MAX_PATH];
        char dest_file[MAX_PATH];
        
        snprintf(src_file, sizeof(src_file), "%s/%s", source, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", destination, entry->d_name);
        
        struct stat stat_buf;
        if (stat(src_file, &stat_buf) == 0) {
            // If it's a directory, create it in the destination and sync recursively
            if (S_ISDIR(stat_buf.st_mode)) {
                mkdir(dest_file, 0755);
                sync_files(src_file, dest_file);
            } else {
                // If file doesn't exist or is modified, copy the file
                if (!file_exists(dest_file) || stat_buf.st_mtime > stat_buf.st_mtime) {
                    printf("Copying: %s to %s\n", src_file, dest_file);
                    copy_file(src_file, dest_file);
                }
            }
        }
    }

    closedir(dir);
}

void *sync_worker(void *arg) {
    SyncData *data = (SyncData *)arg;
    sync_files(data->source, data->destination);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SyncData data;
    strncpy(data.source, argv[1], MAX_PATH);
    strncpy(data.destination, argv[2], MAX_PATH);

    pthread_t sync_thread;
    if (pthread_create(&sync_thread, NULL, sync_worker, (void *)&data) != 0) {
        perror("Failed to create sync thread");
        return EXIT_FAILURE;
    }

    pthread_join(sync_thread, NULL);
    printf("Synchronization completed.\n");
    
    return EXIT_SUCCESS;
}