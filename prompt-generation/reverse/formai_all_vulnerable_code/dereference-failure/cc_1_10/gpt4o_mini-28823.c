//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to get the full file path
void get_full_path(const char *base_path, const char *file_name, char *full_path) {
    snprintf(full_path, MAX_PATH, "%s/%s", base_path, file_name);
}

// Function to check if a file needs to be synchronized
int needs_sync(const char *src_path, const char *dest_path) {
    struct stat src_stat, dest_stat;

    if (stat(src_path, &src_stat) == -1) {
        perror("Could not stat source file");
        return 0;
    }
    if (stat(dest_path, &dest_stat) == -1) {
        return 1; // Destination file does not exist, needs sync
    }

    // Compare modification times
    return src_stat.st_mtime > dest_stat.st_mtime;
}

// Function to copy file from source to destination
void copy_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");

    if (src_file == NULL || dest_file == NULL) {
        perror("Error opening file for copying");
        if (src_file) fclose(src_file);
        if (dest_file) fclose(dest_file);
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

// Function to synchronize files between two directories
void sync_directories(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *src = opendir(src_dir);
    DIR *dest = opendir(dest_dir);

    if (!src) {
        perror("Could not open source directory");
        return;
    }

    if (!dest) {
        perror("Could not open destination directory");
        closedir(src);
        return;
    }

    while ((entry = readdir(src)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];
        get_full_path(src_dir, entry->d_name, src_path);
        get_full_path(dest_dir, entry->d_name, dest_path);

        if (entry->d_type == DT_REG) { // Regular file
            if (needs_sync(src_path, dest_path)) {
                printf("Copying %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(src);
    closedir(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directories(argv[1], argv[2]);
    return EXIT_SUCCESS;
}