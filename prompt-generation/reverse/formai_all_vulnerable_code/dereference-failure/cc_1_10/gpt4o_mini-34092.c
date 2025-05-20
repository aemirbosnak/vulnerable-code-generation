//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

void copy_file(const char *src, const char *dest);
int file_exists(const char *filepath);
int has_file_changed(const char *src, const char *dest);
void synchronize_directories(const char *src_dir, const char *dest_dir);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    synchronize_directories(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void synchronize_directories(const char *src_dir, const char *dest_dir) {
    DIR *src = opendir(src_dir);
    struct dirent *entry;

    if (src == NULL) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(src)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        struct stat src_stat;

        if (stat(src_path, &src_stat) == -1) {
            perror("Could not get file stats");
            continue;
        }

        if (S_ISREG(src_stat.st_mode)) { // If it's a regular file
            if (!file_exists(dest_path)) {
                // File does not exist in destination, copy it
                printf("Copying new file: %s\n", src_path);
                copy_file(src_path, dest_path);
            } else if (has_file_changed(src_path, dest_path)) {
                // File exists but has changed, update it
                printf("Updating file: %s\n", dest_path);
                copy_file(src_path, dest_path);
            }
        }

        // Uncomment this section to also handle directories
        /*
        else if (S_ISDIR(src_stat.st_mode)) { // If it's a directory
            synchronize_directories(src_path, dest_path); // Recursively sync directories
        }
        */
    }

    closedir(src);
}

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    if (!source || !destination) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, sizeof(char), bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int has_file_changed(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;
    if (stat(src, &src_stat) == -1 || stat(dest, &dest_stat) == -1) {
        perror("Failed to get file stats");
        return 1; // Default to true if error occurs
    }
    return src_stat.st_mtime > dest_stat.st_mtime; // Check last modified time
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}