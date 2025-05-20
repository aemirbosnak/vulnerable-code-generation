//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function prototypes
void syncFile(const char *srcFile, const char *destFile);
void syncDirectory(const char *srcDir, const char *destDir);
int isFile(const char *path);
void copyFile(const char *srcFile, const char *destFile);
void deleteFile(const char *filePath);
int fileExists(const char *filePath);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *srcDir = argv[1];
    const char *destDir = argv[2];

    syncDirectory(srcDir, destDir);
    return EXIT_SUCCESS;
}

// Sync directory
void syncDirectory(const char *srcDir, const char *destDir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(srcDir)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[1024];
        char destPath[1024];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (isFile(srcPath)) {
            syncFile(srcPath, destPath);
        } else {
            struct stat st;
            if (stat(srcPath, &st) == 0 && S_ISDIR(st.st_mode)) {
                // Create destination directory if it doesn't exist
                mkdir(destPath, 0755);
                syncDirectory(srcPath, destPath);
            }
        }
    }

    closedir(dir);
}

// Sync file
void syncFile(const char *srcFile, const char *destFile) {
    if (!fileExists(destFile)) {
        // If destination file doesn't exist, copy it
        printf("Copying new file: %s -> %s\n", srcFile, destFile);
        copyFile(srcFile, destFile);
    } else {
        // Compare files and sync if they differ
        struct stat srcStat, destStat;
        stat(srcFile, &srcStat);
        stat(destFile, &destStat);
        
        if (srcStat.st_mtime > destStat.st_mtime) {
            printf("Updating file: %s -> %s\n", srcFile, destFile);
            copyFile(srcFile, destFile);
        }
    }
}

// Check if the given path is a file
int isFile(const char *path) {
    struct stat st;
    if (stat(path, &st) < 0) {
        return 0; // not a file
    }
    return S_ISREG(st.st_mode);
}

// Copy file
void copyFile(const char *srcFile, const char *destFile) {
    int srcFd = open(srcFile, O_RDONLY);
    if (srcFd < 0) {
        perror("open srcFile");
        return;
    }
    
    int destFd = open(destFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destFd < 0) {
        perror("open destFile");
        close(srcFd);
        return;
    }

    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(srcFd, buffer, sizeof(buffer))) > 0) {
        write(destFd, buffer, bytesRead);
    }

    close(srcFd);
    close(destFd);
}

// Check if file exists
int fileExists(const char *filePath) {
    return access(filePath, F_OK) == 0;
}

// Delete file
void deleteFile(const char *filePath) {
    if (remove(filePath) == 0) {
        printf("Deleted file: %s\n", filePath);
    } else {
        perror("deleteFile");
    }
}