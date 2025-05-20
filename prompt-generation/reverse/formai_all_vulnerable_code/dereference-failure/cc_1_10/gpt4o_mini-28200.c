//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 4096
#define BUFFER_SIZE 1024

// Function to check if a file exists
int file_exists(const char *path) {
    struct stat buffer;   
    return (stat(path, &buffer) == 0);
}

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    stat(file1, &stat1);
    stat(file2, &stat2);
    return stat1.st_mtime == stat2.st_mtime && stat1.st_size == stat2.st_size;
}

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    char buffer[BUFFER_SIZE];
    size_t bytes;

    FILE *source = fopen(src, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", src);
        return -1;
    }

    FILE *destination = fopen(dest, "wb");
    if (destination == NULL) {
        fclose(source);
        fprintf(stderr, "Error opening destination file: %s\n", dest);
        return -1;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}

// Function to synchronize files from source to destination
void synchronize_files(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(src_dir)) == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", src_dir);
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LEN];
        char dest_path[MAX_PATH_LEN];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (!file_exists(dest_path) || !compare_files(src_path, dest_path)) {
                printf("Copying file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        } else if (entry->d_type == DT_DIR) { // Directory
            if (!file_exists(dest_path)) {
                printf("Creating directory: %s\n", dest_path);
                mkdir(dest_path, 0755);
            }
            synchronize_files(src_path, dest_path); // Recursive call
        } else {
            printf("Skipping file: %s\n", src_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Start synchronization
    synchronize_files(source_directory, destination_directory);
    
    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}