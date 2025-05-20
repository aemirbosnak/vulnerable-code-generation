//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
}

int file_exists(const char *file_path) {
    struct stat buffer;   
    return (stat(file_path, &buffer) == 0); 
}

void copy_file(const char *source_file, const char *destination_file) {
    FILE *source = fopen(source_file, "rb");
    FILE *destination = fopen(destination_file, "wb");
    
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void sync_directory(const char *source_dir, const char *destination_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(source_dir)) == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries:
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[PATH_MAX];
        char destination_path[PATH_MAX];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(destination_path, sizeof(destination_path), "%s/%s", destination_dir, entry->d_name);

        struct stat file_info;
        if (stat(source_path, &file_info) == 0) {
            if (S_ISDIR(file_info.st_mode)) {
                // Create a new directory in the destination if it doesn't exist
                if (!file_exists(destination_path)) {
                    mkdir(destination_path, 0755);
                }
                // Recursively sync the directory
                sync_directory(source_path, destination_path);
            } else {
                // If the file exists in the destination, check for differences
                if (!file_exists(destination_path) || (file_info.st_mtime > (stat(destination_path, &file_info), file_info.st_mtime))) {
                    printf("Copying: %s -> %s\n", source_path, destination_path);
                    copy_file(source_path, destination_path);
                }
            }
        } else {
            perror("Error reading file info");
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Ensure destination directory exists
    if (!file_exists(destination_directory)) {
        mkdir(destination_directory, 0755);
    }

    // Start the synchronization process
    sync_directory(source_directory, destination_directory);
    
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}