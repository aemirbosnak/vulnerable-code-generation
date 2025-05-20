//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function prototypes
void sync_files(const char *source_dir, const char *dest_dir);
int file_exists(const char *filepath);
void copy_file(const char *source, const char *destination);
void print_usage(const char *program_name);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    return EXIT_SUCCESS;
}

// Function to display usage information
void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
}

// Function to synchronize files from source to destination
void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_file_path[512];
        snprintf(source_file_path, sizeof(source_file_path), "%s/%s", source_dir, entry->d_name);

        char dest_file_path[512];
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", dest_dir, entry->d_name);

        struct stat source_stat;
        if (stat(source_file_path, &source_stat) == -1) {
            perror("Error reading source file stats");
            continue;
        }

        // If it's a regular file, check if it exists in the destination
        if (S_ISREG(source_stat.st_mode)) {
            if (!file_exists(dest_file_path) || source_stat.st_mtime > stat(dest_file_path, &source_stat)) {
                copy_file(source_file_path, dest_file_path);
                printf("Copying: %s to %s\n", source_file_path, dest_file_path);
            }
        } else if (S_ISDIR(source_stat.st_mode)) {
            // If it's a directory, create it in the destination and sync its content
            mkdir(dest_file_path, 0755);
            sync_files(source_file_path, dest_file_path);
        }
    }

    closedir(dir);
}

// Function to check if a file exists
int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

// Function to copy a file from source to destination
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        fclose(src);
        perror("Error opening destination file");
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