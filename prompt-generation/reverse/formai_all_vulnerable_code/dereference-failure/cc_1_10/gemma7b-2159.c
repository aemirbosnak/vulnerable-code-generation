//Gemma-7B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

typedef struct FileData {
    char *data;
    int size;
    FILE *file;
} FileData;

FileData *createFileData(char *filename) {
    FileData *fileData = malloc(sizeof(FileData));

    fileData->data = malloc(BUFFER_SIZE);
    fileData->size = BUFFER_SIZE;
    fileData->file = fopen(filename, "r");

    return fileData;
}

void readFileData(FileData *fileData) {
    int readBytes = fread(fileData->data, 1, fileData->size, fileData->file);

    fileData->size = readBytes;
}

void writeFileData(FileData *fileData) {
    int writeBytes = fwrite(fileData->data, 1, fileData->size, fileData->file);

    fileData->size = writeBytes;
}

void destroyFileData(FileData *fileData) {
    free(fileData->data);
    fclose(fileData->file);
    free(fileData);
}

int main() {
    FileData *fileData = createFileData("my_file.txt");

    readFileData(fileData);

    printf("Data: %s", fileData->data);

    writeFileData(fileData);

    destroyFileData(fileData);

    return 0;
}