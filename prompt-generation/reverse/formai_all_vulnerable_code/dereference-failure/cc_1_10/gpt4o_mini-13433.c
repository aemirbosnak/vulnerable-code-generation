//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define LOG_FILE "sync_log.txt"

// Function prototypes
void log_message(const char *message);
int is_file_modified(const char *src_file, const char *dest_file);
void sync_files(const char *src_dir, const char *dest_dir);
void copy_file(const char *src_file, const char *dest_file);

// Main entry point
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    log_message("Starting file synchronization...");
    sync_files(source_directory, destination_directory);
    log_message("File synchronization completed.");

    return EXIT_SUCCESS;
}

// Function to log messages
void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

// Function to check if a file has been modified
int is_file_modified(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    if (stat(src_file, &src_stat) != 0) {
        fprintf(stderr, "Could not get stats for source file: %s\n", src_file);
        return 1; // Treat as modified
    }

    if (stat(dest_file, &dest_stat) != 0) {
        return 1; // Destination file does not exist, treat as modified
    }

    return (src_stat.st_mtime > dest_stat.st_mtime);
}

// Function to copy files
void copy_file(const char *src_file, const char *dest_file) {
    FILE *source = fopen(src_file, "rb");
    if (source == NULL) {
        fprintf(stderr, "Could not open source file: %s\n", src_file);
        return;
    }

    FILE *destination = fopen(dest_file, "wb");
    if (destination == NULL) {
        fprintf(stderr, "Could not open destination file: %s\n", dest_file);
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    log_message("File copied successfully.");
    fclose(source);
    fclose(destination);
}

// Function to synchronize files from source to destination
void sync_files(const char *src_dir, const char *dest_dir) {
    DIR *src_directory = opendir(src_dir);
    if (src_directory == NULL) {
        fprintf(stderr, "Could not open source directory: %s\n", src_dir);
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];

    while ((entry = readdir(src_directory)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (is_file_modified(src_path, dest_path)) {
                log_message("Synchronizing file: ");
                log_message(src_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(src_directory);
}