//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (!src || !dest) {
        fprintf(stderr, "Error opening files!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

int is_modified(const char *source, const char *destination) {
    struct stat src_stat, dest_stat;
    if (stat(source, &src_stat) == -1 || stat(destination, &dest_stat) == -1) {
        return 1; // If the destination file doesn't exist or can't be read
    }
    return difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0;
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        fprintf(stderr, "Failed to open directory: %s\n", source_dir);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the special directories
        }

        char source_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // If it's a directory, create it in the destination and sync recursively
            mkdir(dest_path, 0755);
            sync_directory(source_path, dest_path);
        } else {
            // If it's a file, check if it needs copying or updating
            if (access(dest_path, F_OK) == -1 || is_modified(source_path, dest_path)) {
                printf("Copying %s to %s\n", source_path, dest_path);
                copy_file(source_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Create the destination directory if it doesn't exist
    if (access(destination_directory, F_OK) == -1) {
        mkdir(destination_directory, 0755);
    }

    sync_directory(source_directory, destination_directory);
    printf("Synchronization completed from %s to %s.\n", source_directory, destination_directory);

    return EXIT_SUCCESS;
}