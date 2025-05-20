//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to get the file modification time
time_t get_mod_time(const char *file_path) {
    struct stat attr;
    if (stat(file_path, &attr) != 0) {
        perror("Failed to get file status");
        return 0;
    }
    return attr.st_mtime;
}

// Function to copy a file from source to destination
void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    if (!source) {
        perror("Unable to open source file");
        return;
    }
    
    FILE *destination = fopen(dest, "wb");
    if (!destination) {
        perror("Unable to open destination file");
        fclose(source);
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

// Function to synchronize files from source directory to destination directory
void sync_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Unable to open source directory");
        return;
    }

    struct dirent *entry;
    char src_path[1024];
    char dest_path[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            // Skip hidden files and directories
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create subdirectory in destination if not exists
            mkdir(dest_path, 0755);
            // Recur into subdirectory
            sync_directories(src_path, dest_path);
        } else {
            // Check if the file exists in destination
            if (access(dest_path, F_OK) != -1) {
                // File exists, check modification times
                if (get_mod_time(src_path) > get_mod_time(dest_path)) {
                    printf("Updating file: %s\n", dest_path);
                    copy_file(src_path, dest_path);
                }
            } else {
                printf("Copying new file: %s\n", dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

// Function to display help menu
void display_help() {
    printf("File Synchronizer Help:\n");
    printf("Usage: sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    const char *dest_directory = argv[2];

    // Ensure destination directory exists
    struct stat st = {0};
    if (stat(dest_directory, &st) == -1) {
        mkdir(dest_directory, 0755);
    }

    // Start synchronization process
    printf("Synchronizing files from \"%s\" to \"%s\"...\n", src_directory, dest_directory);
    sync_directories(src_directory, dest_directory);
    
    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}