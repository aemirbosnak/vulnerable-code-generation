//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

// Function to copy a file from source directory to destination directory
void copyFile(char *srcFile, char *dstDir) {
    // Open the source file for reading
    FILE *src = fopen(srcFile, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    // Extract the filename from the source file path
    char *filename = strrchr(srcFile, '/');
    if (filename == NULL) {
        filename = srcFile;
    } else {
        filename++;
    }

    // Construct the destination file path
    char dstFile[256];
    snprintf(dstFile, sizeof(dstFile), "%s/%s", dstDir, filename);

    // Open the destination file for writing
    FILE *dst = fopen(dstFile, "wb");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    // Copy the contents of the source file to the destination file
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    // Close the source and destination files
    fclose(src);
    fclose(dst);
}

// Function to synchronize a single file from the source directory to the destination directory
void syncFile(char *srcFile, char *dstDir) {
    // Extract the filename from the source file path
    char *filename = strrchr(srcFile, '/');
    if (filename == NULL) {
        filename = srcFile;
    } else {
        filename++;
    }

    // Construct the destination file path
    char dstFile[256];
    snprintf(dstFile, sizeof(dstFile), "%s/%s", dstDir, filename);

    // Get the modification times of the source and destination files
    struct stat srcStat, dstStat;
    if (stat(srcFile, &srcStat) != 0) {
        perror("Error getting source file stats");
        return;
    }
    if (stat(dstFile, &dstStat) != 0 && errno != ENOENT) {
        perror("Error getting destination file stats");
        return;
    }

    // If the source file is newer than the destination file, copy the file to the destination directory
    if (srcStat.st_mtime > dstStat.st_mtime) {
        copyFile(srcFile, dstDir);
        printf("%s -> %s\n", srcFile, dstFile);
    }
}

// Function to synchronize all files from the source directory to the destination directory
void syncDirectory(char *srcDir, char *dstDir) {
    // Open the source directory for reading
    DIR *dir = opendir(srcDir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    // Loop through all files in the source directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the path of the source file or directory
        char srcPath[256];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);

        // If the entry is a directory, recursively synchronize the directory
        if (entry->d_type == DT_DIR) {
            // Construct the path of the destination directory
            char dstPath[256];
            snprintf(dstPath, sizeof(dstPath), "%s/%s", dstDir, entry->d_name);

            // Create the destination directory if it does not exist
            struct stat dstStat;
            if (stat(dstPath, &dstStat) != 0 && errno == ENOENT) {
                if (mkdir(dstPath, 0755) != 0) {
                    perror("Error creating destination directory");
                    continue;
                }
            }

            // Recursively synchronize the directory
            syncDirectory(srcPath, dstPath);
        } else if (entry->d_type == DT_REG) {
            // If the entry is a regular file, synchronize the file
            syncFile(srcPath, dstDir);
        }
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char **argv) {
    // Check for the correct number of command line arguments
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    // Synchronize the source directory with the destination directory
    syncDirectory(argv[1], argv[2]);

    return 0;
}