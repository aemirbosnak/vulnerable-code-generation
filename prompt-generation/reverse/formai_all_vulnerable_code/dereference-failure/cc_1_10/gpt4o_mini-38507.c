//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

// Function to compare file modification times
int is_file_modified(const char *source_path, const char *target_path) {
    struct stat source_info, target_info;
    
    // Get file info for both source and target files
    if (stat(source_path, &source_info) == -1) {
        perror("stat() error on source file");
        return 1; // Assume modified if unable to stat
    }
    if (stat(target_path, &target_info) == -1) {
        return 1; // Assume modified since target doesn't exist
    }

    return source_info.st_mtime > target_info.st_mtime;
}

// Function to copy file from source to target
void copy_file(const char *source_path, const char *target_path) {
    FILE *source_file = fopen(source_path, "rb");
    FILE *target_file = fopen(target_path, "wb");
    
    if (!source_file || !target_file) {
        perror("Error opening files");
        if (source_file) fclose(source_file);
        if (target_file) fclose(target_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes, target_file);
    }

    fclose(source_file);
    fclose(target_file);
}

// Function to synchronize files from source to target directory
void synchronize_directories(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory references
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH];
        char target_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        struct stat path_stat;
        stat(source_path, &path_stat);

        if (S_ISDIR(path_stat.st_mode)) {
            // Create the target directory if it does not exist
            mkdir(target_path, 0755);
            // Recurse into the subdirectory
            synchronize_directories(source_path, target_path);
        } else {
            // Check if file needs to be copied
            if (!access(target_path, F_OK) || is_file_modified(source_path, target_path)) {
                copy_file(source_path, target_path);
                printf("Copied: %s to %s\n", source_path, target_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        return 1;
    }

    const char *source_directory = argv[1];
    const char *target_directory = argv[2];

    // Ensure target directory exists
    mkdir(target_directory, 0755);

    // Synchronize the directories
    synchronize_directories(source_directory, target_directory);
    
    printf("Synchronization completed!\n");
    return 0;
}