//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    size_t size;      // Size in bytes
    struct File* next; // Pointer to next file in the linked list
} File;

typedef struct FileSystem {
    File* head; // Head of the linked list of files
} FileSystem;

// Function to initialize the file system
FileSystem* initFileSystem() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->head = NULL;
    return fs;
}

// Function to create a new file
void createFile(FileSystem* fs, const char* filename, size_t filesize) {
    File* newFile = (File*)malloc(sizeof(File));
    strncpy(newFile->name, filename, MAX_FILENAME_LENGTH);
    newFile->size = filesize;
    newFile->next = fs->head;
    fs->head = newFile;
    printf("File created: %s, Size: %zu bytes\n", newFile->name, newFile->size);
}

// Function to delete a file
void deleteFile(FileSystem* fs, const char* filename) {
    File* current = fs->head;
    File* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, filename) == 0) {
            if (previous == NULL) {
                fs->head = current->next; // Delete head file
            } else {
                previous->next = current->next; // Bypass current file
            }
            free(current);
            printf("File deleted: %s\n", filename);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("File not found: %s\n", filename);
}

// Function to list all files
void listFiles(FileSystem* fs) {
    File* current = fs->head;
    if (current == NULL) {
        printf("No files in the file system.\n");
        return;
    }
    printf("Listing files:\n");
    while (current != NULL) {
        printf("File: %s, Size: %zu bytes\n", current->name, current->size);
        current = current->next;
    }
}

// Function to free the file system
void freeFileSystem(FileSystem* fs) {
    File* current = fs->head;
    File* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(fs);
}

// Main function to demonstrate the file system
int main() {
    FileSystem* fs = initFileSystem();
    
    createFile(fs, "file1.txt", 500);
    createFile(fs, "file2.txt", 750);
    createFile(fs, "file3.txt", 1024);
    
    listFiles(fs);
    
    deleteFile(fs, "file2.txt");
    
    listFiles(fs);
    
    deleteFile(fs, "file4.txt"); // Attempt to delete a non-existent file
    
    freeFileSystem(fs);
    
    return 0;
}