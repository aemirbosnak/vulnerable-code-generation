//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

// Function to copy a file from source to destination
int copy_file(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Couldn't open source file");
        return -1;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Couldn't open destination file");
        fclose(src);
        return -1;
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

// Function to check if a file exists
int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

// Function to synchronize two directories
void sync_directories(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Couldn't open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full source and destination file paths
        char source_path[MAX_PATH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);

        char dest_path[MAX_PATH];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Check if the file exists in the destination directory
        if (!file_exists(dest_path)) {
            printf("Copying new file: %s to %s\n", source_path, dest_path);
            copy_file(source_path, dest_path);
        } else {
            printf("File exists, checking for updates: %s\n", source_path);
            // For simplicity, just copy if it exists
            copy_file(source_path, dest_path);
        }
    }

    closedir(dir);
}

// Function to show a cheerful message
void cheerful_message() {
    printf("🎉🎶 Welcome to the Cheery File Synchronizer! Let's get those files synced! 🎶🎉\n");
}

int main(int argc, char *argv[]) {
    cheerful_message();

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    printf("Starting synchronization from '%s' to '%s'\n", source, destination);
    
    sync_directories(source, destination);

    printf("📁 Synchronization complete! Your files are happily in sync! 📁\n");
    return EXIT_SUCCESS;
}