//FormAI DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

// Define maximum length of path name and buffer size
#define PATH_LENGTH 100
#define BUF_SIZE 1024

// Function to read file content and put into buffer
int readFileContent(char *fileName, char *buffer) {
    // Open file in read-only mode
    int file = open(fileName, O_RDONLY);
    if (file == -1) {
        perror("File error");
        return -1;
    }

    // Read file content into buffer
    int n = read(file, buffer, BUF_SIZE);
    if (n == -1) {
        perror("Read error");
        close(file);
        return -1;
    }

    // Close file and return number of bytes read
    close(file);
    return n;
}

// Function to write buffer content into a file
int writeFileContent(char *fileName, char *buffer, int size) {
    // Open file in write-only mode
    int file = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file == -1) {
        perror("File error");
        return -1;
    }

    // Write buffer content into file
    int n = write(file, buffer, size);
    if (n == -1) {
        perror("Write error");
        close(file);
        return -1;
    }

    // Close file and return number of bytes written
    close(file);
    return n;
}

// Function to synchronize two files
int syncFiles(char *srcFile, char *dstFile) {
    // Read content of source file
    char srcContent[BUF_SIZE];
    int srcSize = readFileContent(srcFile, srcContent);
    if (srcSize == -1) {
        return -1;
    }

    // Read content of destination file
    char dstContent[BUF_SIZE];
    int dstSize = readFileContent(dstFile, dstContent);
    if (dstSize == -1) {
        return -1;
    }

    // Compare source and destination file content
    bool needSync = false;
    if (srcSize != dstSize || memcmp(srcContent, dstContent, srcSize) != 0) {
        needSync = true;
    }

    // Synchronize files if needed
    if (needSync) {
        int n = writeFileContent(dstFile, srcContent, srcSize);
        if (n == -1) {
            return -1;
        }
        printf("Synchronized %s to %s\n", srcFile, dstFile);
    }

    // Return success
    return 0;
}

// Function to synchronize two directories
int syncDirectories(char *srcDir, char *dstDir) {
    // Open source directory for reading
    DIR *srcDirp = opendir(srcDir);
    if (srcDirp == NULL) {
        perror("Directory error");
        return -1;
    }

    // Create destination directory if not exists
    struct stat st = {0};
    if (stat(dstDir, &st) == -1) {
        mkdir(dstDir, 0700);
    }

    // Open destination directory for reading and writing
    DIR *dstDirp = opendir(dstDir);
    if (dstDirp == NULL) {
        closedir(srcDirp);
        perror("Directory error");
        return -1;
    }

    // Loop through each file in source directory
    struct dirent *srcEntry;
    while ((srcEntry = readdir(srcDirp)) != NULL) {
        // Ignore "." and ".." files
        if (strcmp(srcEntry->d_name, ".") == 0 || strcmp(srcEntry->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination file paths
        char srcPath[PATH_LENGTH];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, srcEntry->d_name);
        char dstPath[PATH_LENGTH];
        snprintf(dstPath, sizeof(dstPath), "%s/%s", dstDir, srcEntry->d_name);

        // Check if source file is a directory
        struct stat st;
        if (stat(srcPath, &st) == 0 && S_ISDIR(st.st_mode)) {
            // Synchronize subdirectories recursively
            syncDirectories(srcPath, dstPath);
        } else {
            // Synchronize files
            syncFiles(srcPath, dstPath);
        }
    }

    // Close directories and return success
    closedir(srcDirp);
    closedir(dstDirp);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if source and destination directories are provided
    if (argc < 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return 1;
    }

    // Synchronize directories recursively
    syncDirectories(argv[1], argv[2]);

    // Return success
    return 0;
}