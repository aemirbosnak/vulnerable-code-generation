//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define BUFFER_SIZE 1024
#define true 1
#define false 0

typedef int bool;

// Function prototypes
void sync_directories(const char *source, const char *destination);
void copy_file(const char *source_file, const char *dest_file);
bool file_exists(const char *filepath);
void get_file_modification_time(const char *filepath, time_t *mod_time);
void log_message(const char *message);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directories(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

// Synchronize files from source to destination
void sync_directories(const char *source, const char *destination) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_FILE_NAME];
    char dest_path[MAX_FILE_NAME];
    struct stat source_stat, dest_stat;

    if ((dir = opendir(source)) == NULL) {
        perror("Couldn't open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        // Get file stats
        if (stat(source_path, &source_stat) == -1) {
            perror("Error getting source file stats");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(source_stat.st_mode)) {
            // Create destination directory if not exists
            if (!file_exists(dest_path)) {
                mkdir(dest_path, 0755);
                log_message("Created directory: ");
                log_message(dest_path);
            }
            // Recursive call to sync sub-directory
            sync_directories(source_path, dest_path);
        } else {
            // If the file does not exist in destination or is outdated, copy
            if (!file_exists(dest_path) || (get_file_modification_time(dest_path, &dest_stat.st_mtime), difftime(source_stat.st_mtime, dest_stat.st_mtime) > 0)) {
                copy_file(source_path, dest_path);
                log_message("Copied file: ");
                log_message(dest_path);
            }
        }
    }

    closedir(dir);
}

// Copy file from source to destination
void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dst = fopen(dest_file, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (!src || !dst) {
        perror("Error opening files for copy");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dst);
    }

    fclose(src);
    fclose(dst);
}

// Check if file exists
bool file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

// Get the last modification time of the file
void get_file_modification_time(const char *filepath, time_t *mod_time) {
    struct stat buffer;
    if (stat(filepath, &buffer) == 0) {
        *mod_time = buffer.st_mtime;
    }
}

// Log messages to console
void log_message(const char *message) {
    printf("%s", message);
}