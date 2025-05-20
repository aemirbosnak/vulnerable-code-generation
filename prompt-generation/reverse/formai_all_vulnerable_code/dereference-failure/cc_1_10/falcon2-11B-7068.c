//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a file
typedef struct {
    char* name;
    int size;
} File;

// Function to create a new file
File* createFile(char* name, int size) {
    File* newFile = (File*) malloc(sizeof(File));
    if (newFile == NULL) {
        fprintf(stderr, "Failed to allocate memory for new file.\n");
        return NULL;
    }

    newFile->name = (char*) malloc(strlen(name) + 1);
    if (newFile->name == NULL) {
        fprintf(stderr, "Failed to allocate memory for new file name.\n");
        free(newFile);
        return NULL;
    }

    strcpy(newFile->name, name);
    newFile->size = size;

    return newFile;
}

// Function to print the details of a file
void printFile(File* file) {
    printf("Name: %s\n", file->name);
    printf("Size: %d\n", file->size);
}

// Function to free the memory allocated for a file
void freeFile(File* file) {
    if (file!= NULL) {
        free(file->name);
        free(file);
    }
}

// Function to copy a file
File* copyFile(File* source, char* destName) {
    File* newFile = createFile(destName, source->size);
    if (newFile == NULL) {
        fprintf(stderr, "Failed to allocate memory for new file.\n");
        return NULL;
    }

    // Copy the contents of the source file to the new file
    char* buffer = (char*) malloc(source->size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer.\n");
        freeFile(newFile);
        return NULL;
    }

    int bytesRead = fread(buffer, 1, source->size, source->name);
    if (bytesRead == 0) {
        fprintf(stderr, "Failed to read from source file.\n");
        freeFile(newFile);
        free(buffer);
        return NULL;
    }

    strcpy(newFile->name, destName);
    newFile->size = bytesRead;

    memcpy(newFile->name, buffer, bytesRead);
    free(buffer);

    return newFile;
}

// Main function
int main() {
    // Create a source file
    File* source = createFile("file1.txt", 1024);
    if (source == NULL) {
        return 1;
    }

    // Copy the source file to a new file
    File* dest = copyFile(source, "file2.txt");
    if (dest == NULL) {
        return 1;
    }

    // Print the details of the copied file
    printFile(dest);

    // Free the memory allocated for the source and destination files
    freeFile(source);
    freeFile(dest);

    return 0;
}