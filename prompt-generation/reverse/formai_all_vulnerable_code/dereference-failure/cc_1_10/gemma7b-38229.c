//Gemma-7B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

typedef struct FileInfo {
    char *filename;
    int size;
    FILE *fp;
} FileInfo;

FileInfo *createFileInfo(char *filename) {
    FileInfo *fileInfo = malloc(sizeof(FileInfo));
    fileInfo->filename = strdup(filename);
    fileInfo->size = 0;
    fileInfo->fp = NULL;

    return fileInfo;
}

void openFile(FileInfo *fileInfo) {
    fileInfo->fp = fopen(fileInfo->filename, "r");
    if (fileInfo->fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
}

void closeFile(FileInfo *fileInfo) {
    fclose(fileInfo->fp);
    fileInfo->fp = NULL;
}

int main() {
    // Create a file info structure
    FileInfo *fileInfo = createFileInfo("my_file.txt");

    // Open the file
    openFile(fileInfo);

    // Read the file contents
    char buffer[MAX_FILE_SIZE];
    int bytesRead = read(fileInfo->fp, buffer, MAX_FILE_SIZE);

    // Print the file contents
    printf("File contents:\n");
    printf("%s", buffer);

    // Close the file
    closeFile(fileInfo);

    return 0;
}