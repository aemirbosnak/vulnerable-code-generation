//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to check if a file exists
int file_exists(const char *filepath) {
    struct stat buffer;   
    return (stat(filepath, &buffer) == 0) ? 1 : 0;
}

// Function to get the modification time of a file
time_t get_modification_time(const char *filepath) {
    struct stat attr;
    stat(filepath, &attr);
    return attr.st_mtime;
}

// Function to copy contents from source to destination
void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (source == NULL || destination == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

// Function to synchronize files from source to destination directory
void sync_files(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);
    
    if (dp == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char src_filepath[PATH_MAX];
            char dest_filepath[PATH_MAX];

            snprintf(src_filepath, sizeof(src_filepath), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_filepath, sizeof(dest_filepath), "%s/%s", dest_dir, entry->d_name);

            if (file_exists(dest_filepath)) {
                // If the destination file exists, compare modification times
                if (get_modification_time(src_filepath) > get_modification_time(dest_filepath)) {
                    printf("Updating: %s -> %s\n", src_filepath, dest_filepath);
                    copy_file(src_filepath, dest_filepath);
                }
            } else {
                // If the destination file doesn't exist, copy it
                printf("Copying: %s -> %s\n", src_filepath, dest_filepath);
                copy_file(src_filepath, dest_filepath);
            }
        }
    }

    closedir(dp);
}

// Function to handle directory synchronization recursively
void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *dp = opendir(src_dir);
    struct dirent *entry;

    if (dp == NULL) {
        perror("Could not open source directory");
        return;
    }

    // Synchronize files
    sync_files(src_dir, dest_dir);
    
    // Synchronize subdirectories
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char new_src_dir[PATH_MAX];
            char new_dest_dir[PATH_MAX];

            snprintf(new_src_dir, sizeof(new_src_dir), "%s/%s", src_dir, entry->d_name);
            snprintf(new_dest_dir, sizeof(new_dest_dir), "%s/%s", dest_dir, entry->d_name);

            // Create the destination subdirectory if it doesn't exist
            if (!file_exists(new_dest_dir)) {
                mkdir(new_dest_dir, 0755);
            }

            sync_directory(new_src_dir, new_dest_dir);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    // Create destination directory if it doesn't exist
    if (!file_exists(destination_dir)) {
        mkdir(destination_dir, 0755);
    }

    sync_directory(source_dir, destination_dir);
    printf("Synchronization complete!\n");

    return 0;
}