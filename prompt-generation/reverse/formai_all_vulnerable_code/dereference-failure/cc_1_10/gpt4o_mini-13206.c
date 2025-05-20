//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to compute the size of a file
long getFileSize(const char *filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) != 0) {
        perror("Failed to get file size");
        return -1;
    }
    return statbuf.st_size;
}

// Function to compare two files based on size and modification time
int areFilesIdentical(const char *file1, const char *file2) {
    long size1 = getFileSize(file1);
    long size2 = getFileSize(file2);
    if (size1 != size2) {
        return 0; // Files are not identical
    }

    struct stat stat1, stat2;
    stat(file1, &stat1);
    stat(file2, &stat2);

    return (stat1.st_mtime == stat2.st_mtime);
}

// Function to copy a file from one location to another
int copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *destFile = fopen(destination, "wb");
    if (destFile == NULL) {
        perror("Failed to open destination file");
        fclose(srcFile);
        return -1;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    return 0; // This indicates success
}

// Function to synchronize files from srcDir to destDir
void synchronizeFiles(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[512];
        char destPath[512];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat statbuf;
        if (stat(srcPath, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // Recursively sync subdirectory
                mkdir(destPath, 0755);
                synchronizeFiles(srcPath, destPath);
            } else {
                // Copy files if they are different
                if (!areFilesIdentical(srcPath, destPath) || access(destPath, F_OK) == -1) {
                    printf("Copying %s to %s\n", srcPath, destPath);
                    if (copyFile(srcPath, destPath) < 0) {
                        fprintf(stderr, "Error copying file from %s to %s\n", srcPath, destPath);
                    }
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *srcDir = argv[1];
    const char *destDir = argv[2];

    // Create the destination directory if it doesn't exist
    mkdir(destDir, 0755);

    // Start synchronization
    synchronizeFiles(srcDir, destDir);

    printf("Synchronization completed successfully.\n");
    return 0;
}