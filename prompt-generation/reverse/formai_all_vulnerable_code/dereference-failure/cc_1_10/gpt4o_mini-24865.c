//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

// Function to create a directory if it doesn't exist
void create_directory(const char *path) {
    struct stat st = {0};
    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
    }
}

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    if (!source) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *destination = fopen(dest, "wb");
    if (!destination) {
        perror("Failed to open destination file");
        fclose(source);
        return -1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}

// Function to backup files from the source directory to the backup directory
void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];

        snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, entry->d_name);

        // Check if it's a directory
        if (entry->d_type == DT_DIR) {
            create_directory(dest_path);
            backup_files(src_path, dest_path);  // Recursive call for subdirectories
        } else {
            // It's a file, copy it
            if (copy_file(src_path, dest_path) != 0) {
                fprintf(stderr, "Failed to copy '%s' to '%s'\n", src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

// Function to display the usage
void display_usage() {
    printf("Usage: ./backup_system <source_directory> <backup_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    // Create backup directory if it doesn't exist
    create_directory(backup_directory);

    // Start the backup process
    backup_files(source_directory, backup_directory);
    printf("Backup completed from '%s' to '%s'\n", source_directory, backup_directory);

    return EXIT_SUCCESS;
}