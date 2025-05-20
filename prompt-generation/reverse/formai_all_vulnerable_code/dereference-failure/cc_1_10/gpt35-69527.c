//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILESIZE 1024

void syncFiles(char *srcPath, char *destPath) {

    DIR *srcDir, *destDir;
    struct dirent *dp;
    struct stat srcStat, destStat;
    char srcFilePath[MAX_FILESIZE], destFilePath[MAX_FILESIZE];
    size_t srcPathLen = strlen(srcPath);
    size_t destPathLen = strlen(destPath);

    // Open source and destination directories
    srcDir = opendir(srcPath);
    destDir = opendir(destPath);

    if (srcDir == NULL || destDir == NULL) {
        printf("%s", "Could not open source or destination directory.");
        exit(EXIT_FAILURE);
    }

    // Syncronize source with destination directory
    while ((dp = readdir(srcDir)) != NULL) {
        strcpy(srcFilePath, srcPath);
        strcat(srcFilePath, "/");
        strcat(srcFilePath, dp->d_name);
        stat(srcFilePath, &srcStat);

        if (S_ISDIR(srcStat.st_mode)) {
            // Recursively sync directories
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
                strcpy(destFilePath, destPath);
                strcat(destFilePath, "/");
                strcat(destFilePath, dp->d_name);
                mkdir(destFilePath, srcStat.st_mode);
                syncFiles(srcFilePath, destFilePath);
            }
        } else {
            // Sync files
            strcpy(destFilePath, destPath);
            strcat(destFilePath, "/");
            strcat(destFilePath, dp->d_name);
            if (stat(destFilePath, &destStat) == -1) {
                // File doesn't exist in destination
                FILE *srcFile = fopen(srcFilePath, "rb");
                FILE *destFile = fopen(destFilePath, "wb");
                char fileData[MAX_FILESIZE];
                size_t bytesRead;

                while ((bytesRead = fread(fileData, 1, MAX_FILESIZE, srcFile))) {
                    fwrite(fileData, 1, bytesRead, destFile);
                }
                fclose(srcFile);
                fclose(destFile);
            } else {
                // Check if files are same
                char srcData[MAX_FILESIZE], destData[MAX_FILESIZE];
                FILE *srcFile = fopen(srcFilePath, "rb");
                FILE *destFile = fopen(destFilePath, "rb");
                size_t bytesReadSrc, bytesReadDest;

                do {
                    bytesReadSrc = fread(srcData, 1, MAX_FILESIZE, srcFile);
                    bytesReadDest = fread(destData, 1, MAX_FILESIZE, destFile);
                    if (bytesReadSrc != bytesReadDest || memcmp(srcData, destData, bytesReadSrc)) {
                        // Files are different
                        fclose(srcFile);
                        fclose(destFile);
                        srcFile = fopen(srcFilePath, "rb");
                        destFile = fopen(destFilePath, "wb");
                        while ((bytesReadSrc = fread(srcData, 1, MAX_FILESIZE, srcFile))) {
                            fwrite(srcData, 1, bytesReadSrc, destFile);
                        }
                        break;
                    }
                } while (bytesReadSrc > 0 && bytesReadDest > 0);

                fclose(srcFile);
                fclose(destFile);
            }
        }
    }

    closedir(srcDir);
    closedir(destDir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("%s %s %s", "Usage:", argv[0], "<source> <destination>");
        exit(EXIT_FAILURE);
    }
    syncFiles(argv[1], argv[2]);
    printf("%s", "Files synchronized successfully.");
    return 0;
}