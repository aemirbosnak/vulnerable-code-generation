//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copyFile(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    
    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Copied: %s -> %s\n", source, destination);
}

void syncFiles(const char *sourceDir, const char *destDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;
    struct stat srcStat, destStat;
    
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }
        
        char srcPath[1024];
        char destPath[1024];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);
        
        if (stat(srcPath, &srcStat) == -1) {
            perror("Could not get source file status");
            continue;
        }
        
        if (S_ISDIR(srcStat.st_mode)) {
            mkdir(destPath, 0755); // Create destination directory if it does not exist
            syncFiles(srcPath, destPath); // Recursively sync directories
        } else {
            if (stat(destPath, &destStat) == -1) {
                // File doesn't exist in destination, copy it.
                copyFile(srcPath, destPath);
            } else if (srcStat.st_mtime > destStat.st_mtime) {
                // If source file is newer, copy over it
                copyFile(srcPath, destPath);
            } else {
                printf("Skipping (no update needed): %s\n", destPath);
            }
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    struct stat st;
    if (stat(sourceDir, &st) == -1 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source path is not a valid directory.\n");
        return EXIT_FAILURE;
    }

    if (stat(destDir, &st) == -1) {
        // Destination directory does not exist, create it
        if (mkdir(destDir, 0755) == -1) {
            perror("Could not create destination directory");
            return EXIT_FAILURE;
        }
    } else if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Destination path is not a valid directory.\n");
        return EXIT_FAILURE;
    }
    
    printf("Syncing from '%s' to '%s'\n", sourceDir, destDir);
    syncFiles(sourceDir, destDir);
    
    return EXIT_SUCCESS;
}