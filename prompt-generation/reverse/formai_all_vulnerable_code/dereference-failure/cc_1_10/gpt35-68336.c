//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int copyFile(char *source, char *destination) {
    int bytesRead, bytesWritten, totalBytes = 0;
    int buffer[1024];
    int sourceFD, destFD;
    sourceFD = open(source, O_RDONLY);
    if (sourceFD == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return errno;
    }
    destFD = open(destination, O_WRONLY | O_CREAT);
    if (destFD == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        return errno;
    }
    while ((bytesRead = read(sourceFD, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destFD, buffer, bytesRead);
        if (bytesWritten == -1) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            return errno;
        }
        totalBytes += bytesWritten;
    }
    close(sourceFD);
    close(destFD);
    return 0;
}

//function to sync two directories
int syncDirectories(char *source, char *destination) {
    DIR *sourceDir, *destDir;
    struct dirent *sourceEntry, *destEntry;
    char sourcePath[PATH_MAX], destPath[PATH_MAX], tempDestPath[PATH_MAX];
    int status = 0;
    sourceDir = opendir(source);
    if (sourceDir == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", strerror(errno));
        return errno;
    }
    destDir = opendir(destination);
    if (destDir == NULL) {
        fprintf(stderr, "Error opening destination directory: %s\n", strerror(errno));
        return errno;
    }
    while ((sourceEntry = readdir(sourceDir)) != NULL) {
        if (strcmp(sourceEntry->d_name, ".") == 0 || strcmp(sourceEntry->d_name, "..") == 0)
            continue;
        snprintf(sourcePath, PATH_MAX, "%s/%s", source, sourceEntry->d_name);
        snprintf(destPath, PATH_MAX, "%s/%s", destination, sourceEntry->d_name);
        struct stat s;
        if (stat(sourcePath, &s) < 0) {
            fprintf(stderr, "Error getting file info for %s: %s\n", sourcePath, strerror(errno));
            return errno;
        }
        if (S_ISDIR(s.st_mode)) {
            mkdir(destPath, s.st_mode);
            syncDirectories(sourcePath, destPath);
        }
        else {
            destEntry = readdir(destDir);
            if (destEntry != NULL && strcmp(sourceEntry->d_name, destEntry->d_name) == 0) {
                snprintf(tempDestPath, PATH_MAX, "%s.tmp", destPath);
                if (copyFile(sourcePath, tempDestPath))
                    return errno;
                if (rename(tempDestPath, destPath)) {
                    fprintf(stderr, "Error renaming temp file to %s: %s\n", destPath, strerror(errno));
                    return errno;
                }
            }
            else {
                if (copyFile(sourcePath, destPath))
                    return errno;
            }
        }
    }
    closedir(sourceDir);
    closedir(destDir);
    return status;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s SOURCE DEST\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *source = argv[1];
    char *destination = argv[2];
    printf("Syncing directory %s to %s\n", source, destination);
    syncDirectories(source, destination);
    printf("Directory sync complete!\n");
    return 0;
}