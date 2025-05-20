//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void fileSync(const char* srcPath, const char* destPath) {
    DIR* dir = opendir(srcPath);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char* filename = strdup(entry->d_name);
        char* srcFile = malloc(strlen(srcPath) + strlen(filename) + 2);
        strcpy(srcFile, srcPath);
        strcat(srcFile, "/");
        strcat(srcFile, filename);

        char* destFile = malloc(strlen(destPath) + strlen(filename) + 2);
        strcpy(destFile, destPath);
        strcat(destFile, "/");
        strcat(destFile, filename);

        FILE* srcFilePtr = fopen(srcFile, "rb");
        FILE* destFilePtr = fopen(destFile, "wb");
        if (srcFilePtr == NULL || destFilePtr == NULL) {
            printf("Error opening file\n");
            continue;
        }

        fseek(srcFilePtr, 0, SEEK_END);
        long srcFileSize = ftell(srcFilePtr);
        fseek(srcFilePtr, 0, SEEK_SET);

        fseek(destFilePtr, 0, SEEK_END);
        long destFileSize = ftell(destFilePtr);
        fseek(destFilePtr, 0, SEEK_SET);

        if (srcFileSize!= destFileSize) {
            printf("Source file size does not match destination file size\n");
            continue;
        }

        fread(destFilePtr, 1, srcFileSize, srcFilePtr);

        fclose(srcFilePtr);
        fclose(destFilePtr);
        free(srcFile);
        free(destFile);
    }

    closedir(dir);
}

int main() {
    const char* srcPath = "/path/to/source";
    const char* destPath = "/path/to/destination";

    fileSync(srcPath, destPath);

    return 0;
}