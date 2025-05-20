//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to get the last modified time of a file
time_t get_file_mod_time(const char *filename) {
    struct stat file_info;
    if (stat(filename, &file_info) != 0) {
        perror("Error accessing the file");
        return -1;
    }
    return file_info.st_mtime;
}

// Function to copy a file from source to destination
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    
    FILE *dst = fopen(destination, "wb");
    if (!dst) {
        fclose(src);
        perror("Failed to open destination file");
        return;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
}

// Function to synchronize files from source directory to target directory
void sync_files(const char *src_dir, const char *dst_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // skip hidden files and directories
        }

        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        // Check if the file exists in destination or if it has been modified
        if (!file_exists(dst_path) || get_file_mod_time(src_path) > get_file_mod_time(dst_path)) {
            printf("Copying %s to %s\n", src_path, dst_path);
            copy_file(src_path, dst_path);
        } else {
            printf("Skipping %s; no changes detected.\n", src_path);
        }
    }

    closedir(dir);
}

// Main function to handle command line arguments and execute sync
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_directory> <dst_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    sync_files(src_dir, dst_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}