//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    if (source == NULL || destination == NULL) {
        if (source != NULL) fclose(source);
        if (destination != NULL) fclose(destination);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}

// Function to get the modification time of a file
time_t get_file_mod_time(const char *filename) {
    struct stat attr;
    if (stat(filename, &attr) == 0) {
        return attr.st_mtime;
    }
    return 0;
}

// Function to synchronize files from source to destination
void synchronize(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the special directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Construct full path for source and destination
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Check if it's a file or directory
        struct stat statbuf;
        if (stat(src_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // If it's a directory, create the same directory in dest_dir
            mkdir(dest_path, 0755);
            synchronize(src_path, dest_path); // Recursive call for sub-directory
        } else {
            // If it's a file, check if we need to copy it
            if (access(dest_path, F_OK) == -1 || get_file_mod_time(src_path) > get_file_mod_time(dest_path)) {
                if (copy_file(src_path, dest_path) == 0) {
                    printf("Copied: %s to %s\n", src_path, dest_path);
                } else {
                    perror("copy_file");
                }
            } else {
                printf("Already up-to-date: %s\n", dest_path);
            }
        }
    }
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    // Create destination directory if it doesn't exist
    if (access(dest_dir, F_OK) == -1) {
        if (mkdir(dest_dir, 0755) == -1) {
            perror("mkdir");
            return EXIT_FAILURE;
        }
    }

    // Start the synchronization process
    synchronize(src_dir, dest_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}