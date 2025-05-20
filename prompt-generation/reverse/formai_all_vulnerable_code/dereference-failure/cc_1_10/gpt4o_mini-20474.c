//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void printHelp() {
    printf("File Synchronizer - Sync files between two directories.\n");
    printf("Usage: sync <source_directory> <destination_directory>\n");
}

int isDirectory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void syncFiles(const char *src, const char *dest) {
    struct dirent *entry;
    DIR *dp = opendir(src);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char srcPath[BUFFER_SIZE];
            char destPath[BUFFER_SIZE];

            snprintf(srcPath, sizeof(srcPath), "%s/%s", src, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", dest, entry->d_name);

            struct stat srcStat, destStat;

            if (stat(srcPath, &srcStat) == 0) {
                // Check if it's a file or a directory
                if (S_ISDIR(srcStat.st_mode)) {
                    // Create destination directory if it doesn't exist
                    if (!isDirectory(destPath)) {
                        mkdir(destPath, 0755);
                    }
                    // Recur for the directory
                    syncFiles(srcPath, destPath);
                } else {
                    // Sync files only if they don't exist in destination or if src file is newer
                    if (stat(destPath, &destStat) != 0 || srcStat.st_mtime > destStat.st_mtime) {
                        FILE *srcFile = fopen(srcPath, "rb");
                        FILE *destFile = fopen(destPath, "wb");
                        if (srcFile == NULL || destFile == NULL) {
                            perror("File opening failed");
                            exit(EXIT_FAILURE);
                        }

                        char buffer[BUFFER_SIZE];
                        size_t bytesRead;
                        while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
                            fwrite(buffer, 1, bytesRead, destFile);
                        }

                        printf("Synchronized: %s -> %s\n", srcPath, destPath);
                        fclose(srcFile);
                        fclose(destFile);
                    }
                }
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printHelp();
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    // Check if source directory exists and is a directory
    if (!isDirectory(sourceDir)) {
        fprintf(stderr, "Error: Source directory does not exist or is not a directory\n");
        return EXIT_FAILURE;
    }

    // Create destination directory if it doesn't exist
    if (!isDirectory(destDir)) {
        mkdir(destDir, 0755);
    }

    // Start the synchronization process
    printf("Starting synchronization...\n");
    syncFiles(sourceDir, destDir);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}