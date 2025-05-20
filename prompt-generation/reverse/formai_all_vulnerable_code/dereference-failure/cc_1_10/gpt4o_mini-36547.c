//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

// Function prototypes
void create_backup(const char *source, const char *destination);
void copy_file(const char *source_file, const char *dest_file);
int is_directory(const char *path);
void copy_directory(const char *source_dir, const char *destination_dir);
void create_directory_if_not_exists(const char *path);
void log_event(const char *message);

// Log file path
const char *log_file_path = "backup_log.txt";

int main(int argc, char *argv[]) {
    // Checking if the correct number of arguments is passed
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_path> <destination_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a backup from source to destination
    create_backup(argv[1], argv[2]);
    log_event("Backup completed successfully.");

    return EXIT_SUCCESS;
}

// Function to create a backup
void create_backup(const char *source, const char *destination) {
    // Check if the source path is a directory
    if (is_directory(source)) {
        // If it is a directory, copy it
        copy_directory(source, destination);
    } else {
        // If it is a file, just copy that file
        copy_file(source, destination);
    }
}

// Function to copy a single file
void copy_file(const char *source_file, const char *dest_file) {
    FILE *source, *dest;
    char buffer[1024];
    size_t bytes;

    source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        log_event("Error opening source file.");
        exit(EXIT_FAILURE);
    }

    dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(source);
        log_event("Error opening destination file.");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    log_event("File copied successfully.");
}

// Function to check if a path is a directory
int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to copy an entire directory
void copy_directory(const char *source_dir, const char *destination_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("Error opening directory");
        log_event("Error opening directory.");
        exit(EXIT_FAILURE);
    }

    // Create destination directory if it doesn't exist
    create_directory_if_not_exists(destination_dir);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[1024];
            char dest_path[1024];

            // Construct the full path for source and destination
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", destination_dir, entry->d_name);

            // If entry is a directory, recursively copy it; else copy the file
            if (is_directory(source_path)) {
                copy_directory(source_path, dest_path);
            } else {
                copy_file(source_path, dest_path);
            }
        }
    }

    closedir(dir);
    log_event("Directory copied successfully.");
}

// Function to create a directory if it doesn't exist
void create_directory_if_not_exists(const char *path) {
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        if (mkdir(path, 0700) == -1) {
            perror("Error creating directory");
            log_event("Error creating directory.");
            exit(EXIT_FAILURE);
        }
        log_event("Directory created successfully.");
    }
}

// Function to log events to a file
void log_event(const char *message) {
    FILE *log_file = fopen(log_file_path, "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Error writing to log file");
    }
}