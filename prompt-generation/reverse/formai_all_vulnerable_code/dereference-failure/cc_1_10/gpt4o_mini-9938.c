//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <target_directory>\n", program_name);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int are_files_identical(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) != 0 || stat(file2, &stat2) != 0) {
        return 0; // Unable to stat one of the files
    }

    if (stat1.st_size != stat2.st_size) {
        return 0; // Sizes differ
    }

    return 1; // Sizes are the same, further checking required if needed
}

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");

    if (source == NULL || destination == NULL) {
        perror("File open error");
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void sync_directories(const char *src_dir, const char *tgt_dir) {
    struct dirent *entry;
    DIR *source = opendir(src_dir);

    if (source == NULL) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(source)) != NULL) {
        char src_path[1024];
        char tgt_path[1024];

        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(tgt_path, sizeof(tgt_path), "%s/%s", tgt_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            printf("Checking file: %s\n", src_path);
            if (!file_exists(tgt_path) || !are_files_identical(src_path, tgt_path)) {
                printf("Copying file to: %s\n", tgt_path);
                copy_file(src_path, tgt_path);
            }
        } else if (entry->d_type == DT_DIR) { // Directory
            printf("Found directory: %s\n", src_path);
            // Recursively sync subdirectories
            char tgt_subdir[1024];
            snprintf(tgt_subdir, sizeof(tgt_subdir), "%s/%s", tgt_dir, entry->d_name);
            mkdir(tgt_subdir, 0755); // Create target subdirectory if it does not exist
            sync_directories(src_path, tgt_subdir);
        }
    }

    closedir(source);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *target_directory = argv[2];

    // Create the target directory if it does not exist
    if (!file_exists(target_directory)) {
        mkdir(target_directory, 0755);
    }

    printf("Starting synchronization from '%s' to '%s'...\n", source_directory, target_directory);
    sync_directories(source_directory, target_directory);

    printf("Synchronization completed successfully.\n");
    return EXIT_SUCCESS;
}