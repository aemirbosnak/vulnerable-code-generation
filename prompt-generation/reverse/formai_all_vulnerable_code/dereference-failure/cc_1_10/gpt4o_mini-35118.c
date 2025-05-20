//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *sourceFile, *destFile;
    char buffer[1024];
    size_t bytesRead;

    sourceFile = fopen(src, "rb");
    if (!sourceFile) {
        perror("Error opening source file");
        return -1;
    }

    destFile = fopen(dest, "wb");
    if (!destFile) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return -1;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    return 0;
}

// Function to synchronize files in the source directory to the destination directory
void sync_files(const char *sourceDir, const char *destDir) {
    DIR *dir;
    struct dirent *entry;
    char srcPath[1024];
    char destPath[1024];

    dir = opendir(sourceDir);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            snprintf(srcPath, sizeof(srcPath), "%s/%s", sourceDir, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

            // If the file doesn't exist in the destination, copy it
            if (!file_exists(destPath)) {
                printf("Copying %s to %s\n", srcPath, destPath);
                if (copy_file(srcPath, destPath) != 0) {
                    fprintf(stderr, "Failed to copy %s\n", srcPath);
                }
            }
        }
    }

    closedir(dir);
}

// Function to display usage instructions
void display_usage(const char *programName) {
    printf("Usage: %s <source_directory> <destination_directory>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    // Check if source directory exists
    if (!file_exists(sourceDir)) {
        fprintf(stderr, "Source directory does not exist: %s\n", sourceDir);
        return EXIT_FAILURE;
    }

    // Create destination directory if it doesn't exist
    if (!file_exists(destDir)) {
        if (mkdir(destDir, 0777) == -1) {
            perror("Error creating destination directory");
            return EXIT_FAILURE;
        }
    }

    // Synchronize files
    sync_files(sourceDir, destDir);

    printf("Synchronization completed.\n");
    return EXIT_SUCCESS;
}