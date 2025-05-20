//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 1024

void sync_files(const char *src, const char *dest);
void copy_file(const char *src_file, const char *dest_file);
int file_exists(const char *path);
time_t get_modification_time(const char *path);
void create_directory(const char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    const char *dest_directory = argv[2];

    sync_files(src_directory, dest_directory);
    
    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}

void sync_files(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    struct dirent *entry;

    if (!dir) {
        fprintf(stderr, "Failed to open source directory: %s\n", src);
        return;
    }

    create_directory(dest);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular files
            char src_path[MAX_PATH];
            char dest_path[MAX_PATH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

            if (!file_exists(dest_path) || 
                get_modification_time(src_path) > get_modification_time(dest_path)) {
                copy_file(src_path, dest_path);
                printf("Copied: %s to %s\n", src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    if (!src || !dest) {
        fprintf(stderr, "Error opening file for copy: %s\n", src_file);
        if (src) fclose(src);
        if (dest) fclose(dest);
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

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

time_t get_modification_time(const char *path) {
    struct stat buffer;
    if (stat(path, &buffer) == 0) {
        return buffer.st_mtime;
    }
    return 0; // Return 0 if file does not exist
}

void create_directory(const char *path) {
    struct stat st = {0};
    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
    }
}