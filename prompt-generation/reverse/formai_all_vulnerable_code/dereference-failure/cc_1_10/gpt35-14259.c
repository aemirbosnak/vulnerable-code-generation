//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256
#define BUFSIZE 1024

bool isDirectory(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return false;
    return S_ISDIR(statbuf.st_mode);
}

void syncFiles(const char* sourcePath, const char* destinationPath) {
    DIR* sourceDir = opendir(sourcePath);
    if (!sourceDir) {
        printf("Failed to open source directory  '%s' : %s\n", sourcePath, strerror(errno));
        return;
    }

    DIR* destinationDir = opendir(destinationPath);
    if (!destinationDir) {
        printf("Failed to open destination directory '%s': %s\n", destinationPath, strerror(errno));
        return;
    }

    struct dirent* sourceEntry;
    while ((sourceEntry = readdir(sourceDir))) {
        if (sourceEntry->d_name[0] == '.') 
            continue;
        
        char sourceEntryPath[MAX_PATH_LENGTH];
        snprintf(sourceEntryPath, MAX_PATH_LENGTH, "%s/%s", sourcePath, sourceEntry->d_name);
        bool isSourceDirectory = isDirectory(sourceEntryPath);

        char destinationEntryPath[MAX_PATH_LENGTH];
        snprintf(destinationEntryPath, MAX_PATH_LENGTH, "%s/%s", destinationPath, sourceEntry->d_name);
        bool isDestinationDirectory = isDirectory(destinationEntryPath);

        if (!isSourceDirectory && !isDestinationDirectory) {
            // If both source and destination are files
            int sourceFD = open(sourceEntryPath, O_RDONLY);
            if (sourceFD == -1) {
                printf("Failed to open source file '%s': %s\n", sourceEntryPath, strerror(errno));
                continue;
            }

            int destinationFD = open(destinationEntryPath, O_WRONLY | O_CREAT, 0666);
            if (destinationFD == -1) {
                printf("Failed to create or open destination file '%s': %s\n", destinationEntryPath, strerror(errno));
                close(sourceFD);
                continue;
            }

            char buf[BUFSIZE];
            ssize_t nread;
            while ((nread = read(sourceFD, buf, sizeof buf)) > 0) {
                if (write(destinationFD, buf, nread) != nread) {
                    printf("Failed to write to destination file '%s': %s\n", destinationEntryPath, strerror(errno));
                close(sourceFD);
                close(destinationFD);
                }
            }

            if (nread == -1) {
                printf("Failed to read source file '%s': %s\n", sourceEntryPath, strerror(errno));
                close(sourceFD);
                close(destinationFD);
                continue;
            }

            close(sourceFD);
            close(destinationFD);

            printf("Synced file '%s' with '%s'\n", sourceEntryPath, destinationEntryPath);

        } else if (isSourceDirectory && isDestinationDirectory) {
            // If both source and destination are directories
            syncFiles(sourceEntryPath, destinationEntryPath);
        } else {
            printf("Source and destination are not of the same type: '%s' and '%s'\n", sourceEntryPath, destinationEntryPath);
        }
    }

    closedir(sourceDir);
    closedir(destinationDir);
}

int main() {
    syncFiles("example/source", "example/destination");
    return 0;
}