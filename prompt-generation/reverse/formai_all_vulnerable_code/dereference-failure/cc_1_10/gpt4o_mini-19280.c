//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_SIZE 256

void printUsage() {
    printf("Usage: sync <source_directory> <target_directory>\n");
}

void copyFile(const char *source, const char *target) {
    FILE *srcFile, *tgtFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    srcFile = fopen(source, "rb");
    if (!srcFile) {
        perror("Error opening source file");
        return;
    }

    tgtFile = fopen(target, "wb");
    if (!tgtFile) {
        perror("Error opening target file");
        fclose(srcFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, tgtFile);
    }

    fclose(srcFile);
    fclose(tgtFile);
}

int isFileModified(const char *source, const char *target) {
    struct stat sourceStat, targetStat;

    if (stat(source, &sourceStat) != 0 || stat(target, &targetStat) != 0) {
        return 1; // File does not exist, considered modified
    }
    
    return sourceStat.st_mtime > targetStat.st_mtime;
}

void syncDirectories(const char *sourceDir, const char *targetDir) {
    DIR *dir;
    struct dirent *entry;
    char sourcePath[MAX_PATH_SIZE];
    char targetPath[MAX_PATH_SIZE];

    dir = opendir(sourceDir);
    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Ignore hidden files and directories

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(targetPath, sizeof(targetPath), "%s/%s", targetDir, entry->d_name);

        if (entry->d_type == DT_REG) {
            // If it's a regular file, check if it needs to be synchronized
            if (access(targetPath, F_OK) != 0 || isFileModified(sourcePath, targetPath)) {
                printf("Copying file: %s to %s\n", sourcePath, targetPath);
                copyFile(sourcePath, targetPath);
            }
        } else if (entry->d_type == DT_DIR) {
            // If it's a directory, sync recursively
            mkdir(targetPath, 0755);
            syncDirectories(sourcePath, targetPath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    syncDirectories(argv[1], argv[2]);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}