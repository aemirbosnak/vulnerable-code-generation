//Gemma-7B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store file information
typedef struct FileInfo {
    char name[255];
    int size;
    FILE* file;
} FileInfo;

// Function to open a file
FileInfo* openFile(char* name) {
    FileInfo* fileInfo = malloc(sizeof(FileInfo));
    strcpy(fileInfo->name, name);

    // Open the file
    fileInfo->file = fopen(name, "r");
    if (fileInfo->file == NULL) {
        printf("Error opening file: %s", name);
        exit(1);
    }

    // Get the file size
    fileInfo->size = fileSize(fileInfo->file);

    return fileInfo;
}

// Function to close a file
void closeFile(FileInfo* fileInfo) {
    // Close the file
    fclose(fileInfo->file);

    // Free the memory
    free(fileInfo);
}

// Function to get the file size
int fileSize(FILE* file) {
    long size = 0;
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    return size;
}

int main() {
    // Open a file
    FileInfo* fileInfo = openFile("my_file.txt");

    // Get the file size
    int size = fileSize(fileInfo->file);

    // Print the file size
    printf("File size: %d bytes", size);

    // Close the file
    closeFile(fileInfo);

    return 0;
}