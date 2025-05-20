//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

typedef enum { TEXT, BINARY } FileType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    FileType type;
    int size; // in bytes
} File;

typedef struct {
    File* files[MAX_FILES];
    int fileCount;
} FileSystem;

FileSystem fs;

// Function to initialize the file system
void initializeFileSystem() {
    fs.fileCount = 0;
    printf("File System Initialized\n");
}

// Function to create a file
void createFile(char* name, FileType type) {
    if (fs.fileCount >= MAX_FILES) {
        printf("File system full! Cannot create more files.\n");
        return;
    }
    
    File* newFile = (File*)malloc(sizeof(File));
    strncpy(newFile->name, name, MAX_NAME_LENGTH);
    newFile->type = type;
    newFile->size = 0; // New file starts with size 0

    fs.files[fs.fileCount++] = newFile;
    printf("File '%s' created.\n", name);
}

// Function to write data to a file
void writeFile(char* name, int dataSize) {
    for (int i = 0; i < fs.fileCount; i++) {
        if (strcmp(fs.files[i]->name, name) == 0) {
            fs.files[i]->size += dataSize;
            printf("Wrote %d bytes to file '%s'. New size: %d bytes.\n", dataSize, name, fs.files[i]->size);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

// Function to read a file's details
void readFile(char* name) {
    for (int i = 0; i < fs.fileCount; i++) {
        if (strcmp(fs.files[i]->name, name) == 0) {
            printf("File Name: %s\nType: %s\nSize: %d bytes\n",
                   fs.files[i]->name,
                   fs.files[i]->type == TEXT ? "Text" : "Binary",
                   fs.files[i]->size);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

// Function to delete a file
void deleteFile(char* name) {
    for (int i = 0; i < fs.fileCount; i++) {
        if (strcmp(fs.files[i]->name, name) == 0) {
            free(fs.files[i]);
            for (int j = i; j < fs.fileCount - 1; j++) {
                fs.files[j] = fs.files[j + 1];
            }
            fs.fileCount--;
            printf("File '%s' deleted.\n", name);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

// Function to list all files
void listFiles() {
    printf("Files in the system:\n");
    for (int i = 0; i < fs.fileCount; i++) {
        printf("-- %s (Size: %d bytes, Type: %s)\n",
               fs.files[i]->name,
               fs.files[i]->size,
               fs.files[i]->type == TEXT ? "Text" : "Binary");
    }
}

// Function to cleanup and free up memory
void cleanUp() {
    for (int i = 0; i < fs.fileCount; i++) {
        free(fs.files[i]);
    }
    fs.fileCount = 0;
    printf("Cleaned up the file system.\n");
}

int main() {
    initializeFileSystem();

    createFile("example.txt", TEXT);
    writeFile("example.txt", 100);
    readFile("example.txt");
    
    createFile("image.png", BINARY);
    writeFile("image.png", 2048);
    readFile("image.png");
    
    listFiles();

    deleteFile("example.txt");
    listFiles();
    
    cleanUp();
    return 0;
}