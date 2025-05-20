//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileData {
    char name[100];
    int size;
    char *content;
} FileData;

void readFile(const char *path, FileData *fileData) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    fileData->size = fileSize;
    fileData->content = (char *) malloc(fileSize + 1);
    if (!fileData->content) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(fileData->content, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(fileData->content);
        fclose(file);
        return;
    }

    fileData->content[fileSize] = '\0';
    fclose(file);
}

void writeFile(const char *path, const FileData *fileData) {
    FILE *file = fopen(path, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    size_t bytesWritten = fwrite(fileData->content, 1, fileData->size, file);
    if (bytesWritten != fileData->size) {
        perror("Error writing file");
        fclose(file);
        return;
    }

    fclose(file);
}

void printFileData(const FileData *fileData) {
    printf("File: %s\n", fileData->name);
    printf("Size: %d bytes\n", fileData->size);
    printf("Content:\n%s\n", fileData->content);
}

int main() {
    FileData file;

    // Read file
    strcpy(file.name, "example.txt");
    readFile(file.name, &file);

    // Print file data
    printFileData(&file);

    // Write file
    strcpy(file.name, "output.txt");
    strcpy(file.content, "This is a test file.");
    file.size = strlen(file.content) + 1;
    writeFile(file.name, &file);

    // Free memory
    free(file.content);

    return 0;
}