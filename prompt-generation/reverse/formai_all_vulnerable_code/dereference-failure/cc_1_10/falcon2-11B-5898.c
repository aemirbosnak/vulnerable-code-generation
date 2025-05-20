//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char source[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];
} SyncFile;

void copyFile(SyncFile *source, SyncFile *destination) {
    FILE *srcFile = fopen(source->source, "rb");
    FILE *destFile = fopen(destination->destination, "wb");

    if (srcFile == NULL || destFile == NULL) {
        printf("Error opening files\n");
        return;
    }

    fseek(srcFile, 0, SEEK_END);
    long srcSize = ftell(srcFile);
    fseek(srcFile, 0, SEEK_SET);

    if (srcSize == 0) {
        fclose(srcFile);
        fclose(destFile);
        printf("Source file is empty\n");
        return;
    }

    char *srcBuffer = malloc(srcSize);
    if (srcBuffer == NULL) {
        printf("Error allocating memory\n");
        fclose(srcFile);
        fclose(destFile);
        return;
    }

    fread(srcBuffer, 1, srcSize, srcFile);
    fclose(srcFile);

    if (fwrite(srcBuffer, 1, srcSize, destFile)!= srcSize) {
        printf("Error writing to destination file\n");
        free(srcBuffer);
        fclose(destFile);
        return;
    }

    free(srcBuffer);
    fclose(destFile);
    printf("File copied successfully\n");
}

int main() {
    SyncFile sourceFile;
    strcpy(sourceFile.source, "source.txt");
    strcpy(sourceFile.destination, "destination.txt");

    SyncFile destinationFile;
    strcpy(destinationFile.source, "destination.txt");
    strcpy(destinationFile.destination, "source.txt");

    copyFile(&sourceFile, &destinationFile);

    return 0;
}