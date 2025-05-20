//Gemma-7B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileData {
    char *data;
    int size;
    FILE *fp;
} FileData;

FileData *readFileData(char *filename) {
    FileData *fileData = malloc(sizeof(FileData));
    fileData->data = malloc(MAX_BUFFER_SIZE);
    fileData->size = 0;
    fileData->fp = fopen(filename, "r");

    if (fileData->fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read file data and update fileData size
    int readSize = 0;
    while ((readSize = fread(fileData->data, 1, MAX_BUFFER_SIZE, fileData->fp)) > 0) {
        fileData->size += readSize;
    }

    fclose(fileData->fp);
    return fileData;
}

void writeFileData(FileData *fileData, char *data, int size) {
    int writeSize = 0;
    fileData->data = realloc(fileData->data, fileData->size + size);

    if ((writeSize = fwrite(data, 1, size, fileData->fp)) < size) {
        perror("Error writing to file");
        exit(1);
    }

    fileData->size += size;
}

int main() {
    char *filename = "my_file.txt";
    FileData *fileData = readFileData(filename);

    // Use fileData->data to access and modify file data
    FILE *fp = fileData->fp;
    fprintf(fp, "Hello, world!");

    writeFileData(fileData, "New data", 12);

    fclose(fp);
    free(fileData->data);
    free(fileData);

    return 0;
}