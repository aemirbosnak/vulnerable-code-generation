//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"

void printMessage(const char *message, const char *color) {
    printf("%s%s%s\n", color, message, COLOR_NORMAL);
}

void syncFile(const char *srcPath, const char *destPath) {
    FILE *srcFile = fopen(srcPath, "rb");
    FILE *destFile = fopen(destPath, "wb");
    char buffer[BUFFER_SIZE];
    
    if (!srcFile || !destFile) {
        printMessage("Failed to open files for synchronization", COLOR_RED);
        return;
    }

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printMessage("File synchronized successfully!", COLOR_GREEN);
}

int shouldSync(const char *srcPath, const char *destPath) {
    struct stat srcStat, destStat;
    
    if (stat(srcPath, &srcStat) == -1 || stat(destPath, &destStat) == -1) {
        printMessage("File not found for comparison", COLOR_RED);
        return 0;
    }
    
    if (srcStat.st_size != destStat.st_size || srcStat.st_mtime != destStat.st_mtime) {
        return 1; // Files differ
    }
    
    return 0; // Files are the same
}

void syncDirectory(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    struct dirent *entry;

    if (dir == NULL) {
        printMessage("Could not open source directory", COLOR_RED);
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        
        char srcPath[BUFFER_SIZE], destPath[BUFFER_SIZE];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (access(destPath, F_OK) == -1) {
            // File doesn't exist, just copy it
            printMessage("Copying new file: ", COLOR_YELLOW);
            printf("From: %s\nTo: %s\n", srcPath, destPath);
            syncFile(srcPath, destPath);
        } else {
            // Check if we need to sync
            if (shouldSync(srcPath, destPath)) {
                printMessage("Synchronizing modified file: ", COLOR_YELLOW);
                printf("From: %s\nTo: %s\n", srcPath, destPath);
                syncFile(srcPath, destPath);
            } else {
                printMessage("File is already synchronized: ", COLOR_GREEN);
                printf("%s\n", srcPath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printMessage("Usage: ./sync <source_dir> <destination_dir>", COLOR_RED);
        return EXIT_FAILURE;
    }

    syncDirectory(argv[1], argv[2]);
    printMessage("Synchronization complete!", COLOR_GREEN);
    
    return EXIT_SUCCESS;
}