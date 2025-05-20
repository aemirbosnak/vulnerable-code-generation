//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to check if a file exists
int file_exists(const char *file_path) {
    struct stat buffer;   
    return (stat(file_path, &buffer) == 0);
}

// Function to get the file size
long get_file_size(const char *file_path) {
    struct stat st;
    if (stat(file_path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to copy file from source to destination
void copy_file(const char *src, const char *dst) {
    FILE *source = fopen(src, "rb");
    FILE *dest = fopen(dst, "wb");

    if (source == NULL || dest == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    printf("File copied from %s to %s\n", src, dst);
}

// Function to synchronize files from src_dir to dst_dir
void sync_files(const char *src_dir, const char *dst_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(src_dir)) == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            // If file does not exist or is different, copy it
            if (!file_exists(dst_path) || get_file_size(src_path) != get_file_size(dst_path)) {
                copy_file(src_path, dst_path);
            }
        } else if (entry->d_type == DT_DIR) { // Directory
            // Recursively synchronize directories
            if (!file_exists(dst_path)) {
                mkdir(dst_path, 0755); // Create directory if it does not exist
            }
            sync_files(src_path, dst_path); // Recursive call
        }
    }

    closedir(dir);
}

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    // Start file synchronization
    sync_files(src_dir, dst_dir);
    
    printf("Synchronization complete from '%s' to '%s'.\n", src_dir, dst_dir);
    return 0;
}