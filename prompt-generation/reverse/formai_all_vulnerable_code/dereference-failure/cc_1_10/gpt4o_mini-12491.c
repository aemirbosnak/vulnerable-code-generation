//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024

void sync_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (!src) {
        fprintf(stderr, "Error opening source file: %s\n", src_file);
        return;
    }
    if (!dest) {
        fprintf(stderr, "Error opening destination file: %s\n", dest_file);
        fclose(src);
        return;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    struct stat src_stat, dest_stat;
    DIR *d = opendir(src_dir);

    if (!d) {
        fprintf(stderr, "Error opening source directory: %s\n", src_dir);
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (stat(src_path, &src_stat) == 0) {
            // Check if it's a directory or file
            if (S_ISDIR(src_stat.st_mode)) {
                mkdir(dest_path, 0755);
                sync_directory(src_path, dest_path);
            } else {
                // Sync the file if it doesn't exist or is different
                if (stat(dest_path, &dest_stat) != 0 || difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                    printf("Syncing file: %s -> %s\n", src_path, dest_path);
                    sync_file(src_path, dest_path);
                }
            }
        } else {
            fprintf(stderr, "Error retrieving stats for: %s\n", src_path);
        }
    }

    closedir(d);
}

void create_directory_if_not_exists(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        mkdir(path, 0755);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    create_directory_if_not_exists(dest_dir);
    
    sync_directory(src_dir, dest_dir);

    printf("Synchronization complete from %s to %s\n", src_dir, dest_dir);
    return EXIT_SUCCESS;
}