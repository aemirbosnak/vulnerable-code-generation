//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 4096 // Buffer size for copying files
#define MAX_PATH_LENGTH 4096 // Maximum length of file path

void checkAndCreateDirectory(const char *dirPath) {
    struct stat directoryStat;
    if(stat(dirPath, &directoryStat) == 0) {
        if(!S_ISDIR(directoryStat.st_mode)) {
            printf("Error: %s already exists and is not a directory\n", dirPath);
            exit(EXIT_FAILURE);
        }
    } else {
        // Directory does not exist
        mkdir(dirPath, 0700); // Create directory with read, write, and execute permissions
    }
}

long getFileSize(const char *filePath) {
    struct stat fileStat;
    if(stat(filePath, &fileStat) == 0)
        return fileStat.st_size;
    else
        return -1;
}

void copyFile(const char *srcPath, const char *dstPath) {
    FILE *srcFile = fopen(srcPath, "r");
    if(srcFile == NULL) {
        printf("Error: failed to open file %s for reading\n", srcPath);
        return;
    }
    FILE *dstFile = fopen(dstPath, "w");
    if(dstFile == NULL) {
        printf("Error: failed to open file %s for writing\n", dstPath);
        fclose(srcFile);
        return;
    }
    char buffer[BUFFER_SIZE];
    size_t bytesCopied;
    while((bytesCopied = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesCopied, dstFile);
    }
    fclose(srcFile);
    fclose(dstFile);
}

void backupDirectory(const char *srcDir, const char *dstDir) {
    DIR *dir = opendir(srcDir);
    if(dir == NULL) {
        printf("Error: failed to open directory %s\n", srcDir);
        return;
    }
    // First create destination directory if doesn't exist
    checkAndCreateDirectory(dstDir);
    // Loop through all files and directories and copy recursively
    struct dirent *entry;
    char srcPath[MAX_PATH_LENGTH];
    char dstPath[MAX_PATH_LENGTH];
    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue; // Skip current directory and parent directory
        snprintf(srcPath, MAX_PATH_LENGTH, "%s/%s", srcDir, entry->d_name);
        snprintf(dstPath, MAX_PATH_LENGTH, "%s/%s", dstDir, entry->d_name);
        struct stat entryStat;
        if(stat(srcPath, &entryStat) == 0) {
            if(S_ISDIR(entryStat.st_mode)) {
                // If directory, recurse
                backupDirectory(srcPath, dstPath);
            } else if(S_ISREG(entryStat.st_mode)) {
                // If regular file, copy
                copyFile(srcPath, dstPath);
            } else {
                printf("Warning: %s is not a regular file or directory, skipping\n", srcPath);
            }
        } else {
            printf("Warning: failed to get information for %s, skipping\n", srcPath);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Error: not enough arguments. Usage: %s <source directory> <destination directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *srcDir = argv[1];
    char *dstDir = argv[2];
    // Get current time to use in backup directory name
    time_t rawTime;
    struct tm *timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    char backupDirName[MAX_PATH_LENGTH];
    strftime(backupDirName, sizeof(backupDirName), "backup_%Y-%m-%d_%H-%M-%S", timeInfo);
    char backupDirPath[MAX_PATH_LENGTH];
    snprintf(backupDirPath, MAX_PATH_LENGTH, "%s/%s", dstDir, backupDirName);
    backupDirectory(srcDir, backupDirPath);
    long totalBytesCopied = 0;
    DIR *backupDir = opendir(backupDirPath);
    if(backupDir == NULL) {
        printf("Error: failed to open backup directory %s\n", backupDirPath);
        return EXIT_FAILURE;
    }
    struct dirent *entry;
    char entryPath[MAX_PATH_LENGTH];
    while((entry = readdir(backupDir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue; // Skip current directory and parent directory
        snprintf(entryPath, sizeof(entryPath), "%s/%s", backupDirPath, entry->d_name);
        long fileSize = getFileSize(entryPath);
        if(fileSize < 0) {
            printf("Warning: failed to get size of file %s, skipping\n", entryPath);
        } else {
            totalBytesCopied += fileSize;
        }
    }
    closedir(backupDir);
    printf("Backup completed successfully. %ld bytes copied.\n", totalBytesCopied);
    return EXIT_SUCCESS;
}