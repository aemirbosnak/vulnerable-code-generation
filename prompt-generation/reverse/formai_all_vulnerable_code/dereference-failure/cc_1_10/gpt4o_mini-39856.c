//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024

void copyFile(const char *srcPath, const char *destPath);
int needsSync(const char *srcPath, const char *destPath);
void syncDirectory(const char *srcDir, const char *destDir);
void printUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *srcDir = argv[1];
    const char *destDir = argv[2];
    
    syncDirectory(srcDir, destDir);
    
    printf("Synchronization completed!\n");
    
    return EXIT_SUCCESS;
}

void printUsage(const char *programName) {
    printf("Usage: %s <source_directory> <destination_directory>\n", programName);
}

void syncDirectory(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    if (!dir) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char srcPath[MAX_PATH];
            char destPath[MAX_PATH];
            snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);
            
            if (needsSync(srcPath, destPath)) {
                printf("Copying %s to %s\n", srcPath, destPath);
                copyFile(srcPath, destPath);
            }
        }
    }
    
    closedir(dir);
}

int needsSync(const char *srcPath, const char *destPath) {
    struct stat srcStat, destStat;

    // Check if the destination file exists
    if (stat(destPath, &destStat) != 0) {
        // File does not exist; needs to be copied
        return 1;
    }

    // Get the stats of the source file
    if (stat(srcPath, &srcStat) != 0) {
        perror("Unable to obtain file stats");
        return 0; // Do not sync if we cannot access the source
    }

    // Compare modification times
    return difftime(srcStat.st_mtime, destStat.st_mtime) > 0;
}

void copyFile(const char *srcPath, const char *destPath) {
    FILE *srcFile = fopen(srcPath, "rb");
    if (!srcFile) {
        perror("Unable to open source file");
        return;
    }

    FILE *destFile = fopen(destPath, "wb");
    if (!destFile) {
        fclose(srcFile);
        perror("Unable to open destination file");
        return;
    }

    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}