//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

// Function declarations
void sync_files(char* src_path, char* dest_path);
void copy_files(char* src_path, char* dest_path, char* filename);

int main(int argc, char* argv[]) {
    // Check for correct usage
    if (argc != 3) {
        printf("Usage: ./file_sync [source directory] [destination directory]\n");
        exit(EXIT_FAILURE);
    }

    // Run synchronization function
    sync_files(argv[1], argv[2]);

    return 0;
}

void sync_files(char* src_path, char* dest_path) {
    DIR* src_dir = opendir(src_path);
    DIR* dest_dir = opendir(dest_path);
    struct dirent* src_entry;
    struct dirent* dest_entry;
    char src_file[BUF_SIZE];
    char dest_file[BUF_SIZE];
    struct stat src_stat;
    struct stat dest_stat;

    // Loop through source directory
    while ((src_entry = readdir(src_dir)) != NULL) {
        // Ignore hidden files and directories
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        // Build full path of source file
        snprintf(src_file, BUF_SIZE, "%s/%s", src_path, src_entry->d_name);

        // Get file stats
        if (stat(src_file, &src_stat) != 0) {
            printf("Error: Could not get stat data for %s\n", src_file);
            continue;
        }

        // Check if file exists in destination directory
        int exists = 0;
        rewinddir(dest_dir);
        while ((dest_entry = readdir(dest_dir)) != NULL) {
            // Ignore hidden files and directories
            if (strcmp(dest_entry->d_name, ".") == 0 || strcmp(dest_entry->d_name, "..") == 0) {
                continue;
            }

            // Build full path of destination file
            snprintf(dest_file, BUF_SIZE, "%s/%s", dest_path, dest_entry->d_name);

            // Get file stats
            if (stat(dest_file, &dest_stat) != 0) {
                printf("Error: Could not get stat data for %s\n", dest_file);
                continue;
            }

            // Check if files have the same name and size
            if (strcmp(src_entry->d_name, dest_entry->d_name) == 0 && src_stat.st_size == dest_stat.st_size) {
                exists = 1;
                break;
            }
        }

        // Copy file if it doesn't exist or is out of date
        if (!exists || src_stat.st_mtime > dest_stat.st_mtime) {
            copy_files(src_path, dest_path, src_entry->d_name);
        }
    }

    // Close directories
    closedir(src_dir);
    closedir(dest_dir);

    // Recurse through directories
    src_dir = opendir(src_path);
    while ((src_entry = readdir(src_dir)) != NULL) {
        // Ignore hidden files and directories
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        // Build full path of source file
        snprintf(src_file, BUF_SIZE, "%s/%s", src_path, src_entry->d_name);

        // Get file stats
        if (stat(src_file, &src_stat) != 0) {
            printf("Error: Could not get stat data for %s\n", src_file);
            continue;
        }

        // Recurse through directories
        if (S_ISDIR(src_stat.st_mode)) {
            // Build full path of destination directory
            snprintf(dest_file, BUF_SIZE, "%s/%s", dest_path, src_entry->d_name);

            // Create directory if it doesn't exist
            if (mkdir(dest_file, 0755) != 0) {
                printf("Error: Could not create directory %s\n", dest_file);
                continue;
            }

            // Recurse through subdirectory
            sync_files(src_file, dest_file);
        }
    }
}

void copy_files(char* src_path, char* dest_path, char* filename) {
    char src_file[BUF_SIZE];
    char dest_file[BUF_SIZE];
    FILE* src;
    FILE* dest;
    char buffer[BUF_SIZE];
    size_t nread;

    // Build full path of source and destination files
    snprintf(src_file, BUF_SIZE, "%s/%s", src_path, filename);
    snprintf(dest_file, BUF_SIZE, "%s/%s", dest_path, filename);

    // Open files for reading and writing
    src = fopen(src_file, "rb");
    dest = fopen(dest_file, "w");

    // Copy data from source to destination
    while ((nread = fread(buffer, sizeof(char), sizeof(buffer), src)) > 0) {
        fwrite(buffer, sizeof(char), nread, dest);
    }

    // Close files
    fclose(src);
    fclose(dest);

    // Print success message
    printf("Copied %s to %s\n", src_file, dest_file);
}