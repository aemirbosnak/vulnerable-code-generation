//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to compare two strings
int compare(const char *a, const char *b) {
    return strcmp(a, b);
}

// Function to copy a file from source to destination
void copyFile(const char *source, const char *destination) {
    FILE *sourceFile, *destinationFile;

    // Open the source file
    sourceFile = fopen(source, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        exit(1);
    }

    // Create the destination file
    destinationFile = fopen(destination, "wb");
    if (destinationFile == NULL) {
        perror("Error creating destination file");
        exit(1);
    }

    // Copy the file contents
    char buffer[1024];
    while (fread(buffer, 1, 1024, sourceFile) == 1024) {
        fwrite(buffer, 1, 1024, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);
}

// Function to synchronize two directories
void synchronizeDirectories(const char *source, const char *destination) {
    DIR *sourceDir, *destinationDir;
    struct dirent *sourceEntry, *destinationEntry;
    char sourcePath[1024], destinationPath[1024];

    // Open the source directory
    sourceDir = opendir(source);
    if (sourceDir == NULL) {
        perror("Error opening source directory");
        exit(1);
    }

    // Open the destination directory
    destinationDir = opendir(destination);
    if (destinationDir == NULL) {
        perror("Error opening destination directory");
        exit(1);
    }

    // Loop through the source directory
    while ((sourceEntry = readdir(sourceDir)) != NULL) {
        // Skip hidden files
        if (sourceEntry->d_name[0] == '.') {
            continue;
        }

        // Construct the source path
        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", source, sourceEntry->d_name);

        // Check if the file exists in the destination directory
        destinationEntry = opendir(destinationPath);
        if (destinationEntry != NULL) {
            // File exists in the destination directory
            // Compare the files
            int result = compare(sourcePath, destinationPath);
            if (result != 0) {
                // Files are different
                // Copy the source file to the destination directory
                copyFile(sourcePath, destinationPath);
            }
        } else {
            // File does not exist in the destination directory
            // Copy the source file to the destination directory
            copyFile(sourcePath, destinationPath);
        }

        // Close the destination directory entry
        closedir(destinationEntry);
    }

    // Close the source directory
    closedir(sourceDir);

    // Close the destination directory
    closedir(destinationDir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    // Synchronize the directories
    synchronizeDirectories(argv[1], argv[2]);

    return 0;
}