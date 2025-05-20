//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to copy a file from source to destination
void copy_file(const char *src_file, const char *dest_file) {
    FILE *source = fopen(src_file, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destination = fopen(dest_file, "wb");
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

// Function to backup all files from source directory to destination directory
void backup_directory(const char *src_dir, const char *dest_dir) {
    DIR *d;
    struct dirent *dir;
    char src_path[512], dest_path[512];

    // Open the source directory
    d = opendir(src_dir);
    if (d == NULL) {
        perror("Could not open source directory");
        return;
    }

    // Read each file in the directory
    while ((dir = readdir(d)) != NULL) {
        // Skip the . and .. directories
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination file paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dir->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, dir->d_name);

        // Check if the entry is a file or directory
        struct stat path_stat;
        stat(src_path, &path_stat);
        if (S_ISREG(path_stat.st_mode)) {
            // It's a regular file, copy it
            copy_file(src_path, dest_path);
        } else if (S_ISDIR(path_stat.st_mode)) {
            // It's a directory, recursively back it up
            mkdir(dest_path, 0755); // create directory in destination
            backup_directory(src_path, dest_path);
        }
    }

    closedir(d);
}

int main() {
    char source[256], destination[256];

    printf("Enter the source directory: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0; // Remove newline character

    printf("Enter the destination directory: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0; // Remove newline character

    // Create destination directory if it does not exist
    struct stat st;
    if (stat(destination, &st) != 0) {
        if (mkdir(destination, 0755) != 0) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    }

    // Start the backup process
    backup_directory(source, destination);

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}