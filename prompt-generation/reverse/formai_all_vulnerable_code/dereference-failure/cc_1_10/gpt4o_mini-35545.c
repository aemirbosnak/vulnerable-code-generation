//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void sync_files(const char *src, const char *dest);
void copy_file(const char *src_file, const char *dest_file);
int is_directory(const char *path);
void create_directory(const char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// Function to synchronize files from source to destination directory
void sync_files(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    // Create destination directory if it doesn't exist
    create_directory(dest);

    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[1024];
        char dest_path[1024];

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (is_directory(src_path)) {
            // If it's a directory, recurse into it
            sync_files(src_path, dest_path);
        } else {
            // If it's a file, copy it
            copy_file(src_path, dest_path);
        }
    }

    closedir(dir);
}

// Function to check if a path is a directory
int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("Could not get file status");
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

// Function to create a directory if it does not exist
void create_directory(const char *path) {
    if (is_directory(path)) {
        return; // Directory already exists
    }

    if (mkdir(path, 0755) == -1) {
        perror("Could not create directory");
    }
}

// Function to copy a file from source to destination
void copy_file(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    // Check if the destination file already exists
    if (stat(dest_file, &dest_stat) == 0) {
        // If file exists, compare modification times
        stat(src_file, &src_stat);
        if (src_stat.st_mtime <= dest_stat.st_mtime) {
            return; // No need to copy if the source file is not newer
        }
    }

    FILE *src_fp = fopen(src_file, "rb");
    if (src_fp == NULL) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_fp = fopen(dest_file, "wb");
    if (dest_fp == NULL) {
        perror("Failed to create destination file");
        fclose(src_fp);
        return;
    }

    char buffer[8192];
    size_t read_size;
    while ((read_size = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, read_size, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);
}