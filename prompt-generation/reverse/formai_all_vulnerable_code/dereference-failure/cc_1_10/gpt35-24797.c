//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void synchronizeFiles(char *srcDirectory, char *destDirectory) {

    DIR *dirPtr = opendir(srcDirectory);
    struct dirent *entryPtr;

    if (dirPtr == NULL) {
        printf("Error: Failed to open directory %s\n", srcDirectory);
        return;
    }

    // For each file in the source directory
    while ((entryPtr = readdir(dirPtr))) { 
        if (entryPtr->d_name[0] == '.') continue; // Ignore hidden files

        char filePath[BUFFER_SIZE];
        sprintf(filePath, "%s/%s", srcDirectory, entryPtr->d_name);

        struct stat fileStat;
        lstat(filePath, &fileStat);

        // If the file is a directory, recurse into it
        if (S_ISDIR(fileStat.st_mode)) {
            char newSourceDir[BUFFER_SIZE];
            sprintf(newSourceDir, "%s/%s", srcDirectory, entryPtr->d_name);

            char newDestDir[BUFFER_SIZE];
            sprintf(newDestDir, "%s/%s", destDirectory, entryPtr->d_name);

            mkdir(newDestDir, fileStat.st_mode);
            synchronizeFiles(newSourceDir, newDestDir);
        }
        else {
            // If the file already exists in the destination directory
            char destFilePath[BUFFER_SIZE];
            sprintf(destFilePath, "%s/%s", destDirectory, entryPtr->d_name);

            if (access(destFilePath, F_OK) != -1) {
                struct stat destFileStat;
                lstat(destFilePath, &destFileStat);

                // Compare modification times
                if (fileStat.st_mtime <= destFileStat.st_mtime) {
                    continue; // File in destination is up to date
                }
            }

            // Copy file from source to destination
            FILE *srcFile, *destFile;
            srcFile = fopen(filePath, "r");
            destFile = fopen(destFilePath, "w");

            char buffer[BUFFER_SIZE];
            size_t bytes;

            while ((bytes = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
                fwrite(buffer, 1, bytes, destFile);
            }

            fclose(srcFile);
            fclose(destFile);

            printf("Synchronized file: %s/%s\n", destDirectory, entryPtr->d_name);
        }
    }

    closedir(dirPtr);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    synchronizeFiles(argv[1], argv[2]);

    return 0;
}