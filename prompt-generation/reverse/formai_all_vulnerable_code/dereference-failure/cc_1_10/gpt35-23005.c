//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void syncFiles(char *src, char *dest) {
    DIR *dir;
    struct dirent *entry;
    struct stat srcStat, destStat;
    char srcFile[256], destFile[256];
    int status;

    // Open source directory
    dir = opendir(src);

    // Read source directory contents
    while ((entry = readdir(dir)) != NULL) {
        // Ignore parent and current directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct source file path
        sprintf(srcFile, "%s/%s", src, entry->d_name);

        // Get source file stats
        status = stat(srcFile, &srcStat);
        if (status != 0) {
            printf("Error getting file stats for %s\n", srcFile);
            continue;
        }

        // Construct destination file path
        sprintf(destFile, "%s/%s", dest, entry->d_name);

        // Check if destination file exists
        if (access(destFile, F_OK) != -1) {
            // Get destination file stats
            status = stat(destFile, &destStat);
            if (status != 0) {
                printf("Error getting file stats for %s\n", destFile);
                continue;
            }

            // Compare source and destination file modified times
            if (srcStat.st_mtime > destStat.st_mtime) {
                // Source file is newer, copy it to destination
                status = copyFile(srcFile, destFile);
                if (status != 0) {
                    printf("Error copying file %s to %s\n", srcFile, destFile);
                    continue;
                }
                printf("File %s copied to %s successfully.\n", srcFile, destFile);
            }
        } else {
            // Destination file does not exist, copy source file to destination
            status = copyFile(srcFile, destFile);
            if (status != 0) {
                printf("Error copying file %s to %s\n", srcFile, destFile);
                continue;
            }
            printf("File %s copied to %s successfully.\n", srcFile, destFile);
        }
    }

    // Close directory stream
    closedir(dir);
}

int copyFile(char *src, char *dest) {
    FILE *srcFile, *destFile;
    char buffer[1024];
    size_t size;

    srcFile = fopen(src, "r");
    if (srcFile == NULL) {
        return -1;
    }

    destFile = fopen(dest, "w");
    if (destFile == NULL) {
        fclose(srcFile);
        return -1;
    }

    while ((size = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, size, destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_dir destination_dir\n", argv[0]);
        return 1;
    }

    printf("Starting C File Synchronizer...\n");

    // Sync files from source to destination
    syncFiles(argv[1], argv[2]);

    printf("C File Synchronizer completed successfully.\n");

    return 0;
}