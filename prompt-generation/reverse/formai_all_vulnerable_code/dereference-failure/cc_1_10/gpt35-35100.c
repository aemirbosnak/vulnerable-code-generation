//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256

// Helper function to check if a file exists
bool file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to copy a file from source to destination directory
bool copy_file(const char *source_directory, const char *destination_directory, const char *filename) {
    // Create full filepath for source and destination files
    char source_filepath[MAX_FILENAME_LENGTH];
    char destination_filepath[MAX_FILENAME_LENGTH];
    sprintf(source_filepath, "%s/%s", source_directory, filename);
    sprintf(destination_filepath, "%s/%s", destination_directory, filename);

    // Check if source file exists
    if (!file_exists(source_filepath)) {
        fprintf(stderr, "Error: Source file %s does not exist\n", source_filepath);
        return false;
    }

    // Open source and destination files
    FILE *source_file = fopen(source_filepath, "rb");
    FILE *destination_file = fopen(destination_filepath, "wb");
    if (!source_file || !destination_file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return false;
    }

    // Copy contents of source file to destination file
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

    return true;
}

// Function to synchronize the two directories
void synchronize_directories(const char *source_directory, const char *destination_directory) {
    // Open source directory
    DIR *source_dir = opendir(source_directory);
    if (!source_dir) {
        fprintf(stderr, "Error: Cannot open source directory %s\n", source_directory);
        return;
    }

    // Open destination directory
    DIR *destination_dir = opendir(destination_directory);
    if (!destination_dir) {
        fprintf(stderr, "Error: Cannot open destination directory %s\n", destination_directory);
        closedir(source_dir);
        return;
    }

    // Loop through files in source directory
    struct dirent *dir_entry;
    while ((dir_entry = readdir(source_dir)) != NULL) {
        // Check if entry is a regular file
        if (dir_entry->d_type == DT_REG) {
            // Skip hidden files
            if (dir_entry->d_name[0] == '.') {
                continue;
            }

            // Check if file exists in destination directory
            char destination_filepath[MAX_FILENAME_LENGTH];
            sprintf(destination_filepath, "%s/%s", destination_directory, dir_entry->d_name);
            if (file_exists(destination_filepath)) {
                // TODO: check if contents of files are the same
                printf("File %s already exists in destination directory, skipping copy\n", dir_entry->d_name);
                continue;
            }

            // Otherwise, copy file to destination directory
            printf("Copying file %s to destination directory\n", dir_entry->d_name);
            copy_file(source_directory, destination_directory, dir_entry->d_name);
        }
    }

    // Close directories
    closedir(source_dir);
    closedir(destination_dir);
}

int main(int argc, char **argv) {
    // Check if there are enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s SOURCE_DIR DESTINATION_DIR\n", argv[0]);
        return 1;
    }

    // Get source and destination directories from arguments
    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Synchronize directories
    synchronize_directories(source_directory, destination_directory);
    
    return 0;
}