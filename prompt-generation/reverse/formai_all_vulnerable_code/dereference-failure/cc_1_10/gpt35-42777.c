//FormAI DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to check if a directory exists
int directoryExists(const char* path) {
    struct stat info;
    if(stat(path, &info) != 0) {
        return 0;
    } else if(info.st_mode & S_IFDIR) { // S_ISDIR() doesn't exist on my windows
        return 1;
    } else {
        return 0;
    }
}

// Function to copy a file from source to destination
int copyFile(const char* source, const char* destination) {
    int fdSource, fdDest;
    ssize_t bytesRead;
    char buffer[BUFFER_SIZE];
    mode_t filePermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; // Set permissions for the copied file
    fdSource = open(source, O_RDONLY);
    if(fdSource == -1) {
        printf("Error opening source file: %s\n", source);
        return -1;
    }
    fdDest = creat(destination, filePermissions);
    if(fdDest == -1) {
        printf("Error creating destination file: %s\n", destination);
        close(fdSource);
        return -1;
    }
    while((bytesRead = read(fdSource, buffer, BUFFER_SIZE)) > 0) {
        write(fdDest, buffer, bytesRead);
    }
    close(fdSource);
    close(fdDest);
    return 0;
}

// Function to synchronize two directories
int syncDirectories(const char* sourceDir, const char* destDir) {
    DIR* dir;
    struct dirent* entry;
    char* sourcePath;
    char* destPath;
    if(!directoryExists(sourceDir)) {
        printf("Source directory does not exist: %s\n", sourceDir);
        return -1;
    }
    if(!directoryExists(destDir)) {
        printf("Destination directory does not exist: %s\n", destDir);
        return -1;
    }
    dir = opendir(sourceDir);
    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Construct source and destination paths
        sourcePath = (char*)malloc(strlen(sourceDir) + strlen(entry->d_name) + 2); // 2 for '/' and '\0'
        sprintf(sourcePath, "%s/%s", sourceDir, entry->d_name);
        destPath = (char*)malloc(strlen(destDir) + strlen(entry->d_name) + 2); // 2 for '/' and '\0'
        sprintf(destPath, "%s/%s", destDir, entry->d_name);
        if(entry->d_type == DT_DIR) { // If it's a directory, recursively sync it
            syncDirectories(sourcePath, destPath);
        } else if(entry->d_type == DT_REG) { // If it's a file, copy it to the destination if it doesn't already exist or has been modified
            struct stat sourceStat, destStat;
            if(stat(sourcePath, &sourceStat) == -1) {
                printf("Error getting file info: %s\n", sourcePath);
                continue;
            }
            if(stat(destPath, &destStat) == -1) { // If the destination file doesn't exist, copy the source file
                printf("Destination file does not exist: %s\n", destPath);
                copyFile(sourcePath, destPath);
            } else if(sourceStat.st_mtime > destStat.st_mtime) { // If the source file has been modified more recently than the destination file, overwrite the destination file
                printf("Overwriting file: %s\n", destPath);
                if(copyFile(sourcePath, destPath) == -1) {
                    printf("Error copying file: %s\n", sourcePath);
                }
            } else {
                printf("File already exists and is up to date: %s\n", destPath);
            }
        }
        free(sourcePath);
        free(destPath);
    }
    closedir(dir);
    return 0;
}

int main(int argc, const char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return -1;
    }
    syncDirectories(argv[1], argv[2]);
    return 0;
}