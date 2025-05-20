//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char *content;
} File;

typedef struct {
    File *files[MAX_FILES];
    int count;
} FileSystem;

FileSystem *initFileSystem() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->count = 0;
    return fs;
}

void createFile(FileSystem *fs, const char *filename, const char *content) {
    if (fs->count >= MAX_FILES) {
        printf("Unable to create file: File system is full.\n");
        return;
    }
    
    File *newFile = (File *)malloc(sizeof(File));
    strncpy(newFile->name, filename, MAX_FILENAME_LENGTH);
    newFile->content = (char *)malloc(strlen(content) + 1);
    strcpy(newFile->content, content);
    newFile->size = strlen(content);
    
    fs->files[fs->count++] = newFile;
    printf("File '%s' created successfully with size %d bytes.\n", filename, newFile->size);
}

void readFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, filename) == 0) {
            printf("Reading file '%s':\n%s\n", filename, fs->files[i]->content);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}

void deleteFile(FileSystem *fs, const char *filename) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, filename) == 0) {
            free(fs->files[i]->content);
            free(fs->files[i]);
            fs->files[i] = fs->files[--fs->count]; // Remove file and maintain array continuity
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}

void listFiles(FileSystem *fs) {
    printf("Listing files in the file system:\n");
    for (int i = 0; i < fs->count; i++) {
        printf("  - %s (%d bytes)\n", fs->files[i]->name, fs->files[i]->size);
    }
}

void freeFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->count; i++) {
        free(fs->files[i]->content);
        free(fs->files[i]);
    }
    free(fs);
}

int main() {
    FileSystem *fs = initFileSystem();
    
    createFile(fs, "example.txt", "This is the content of example.txt.");
    createFile(fs, "notes.txt", "These are some important notes.");
    createFile(fs, "readme.md", "This file serves as a readme for the project.");
    
    listFiles(fs);
    
    readFile(fs, "example.txt");
    readFile(fs, "notes.txt");
    
    deleteFile(fs, "notes.txt");
    listFiles(fs);
    
    deleteFile(fs, "example.txt");
    deleteFile(fs, "nonexistent.txt"); // Attempt to delete a non-existing file
    listFiles(fs);
    
    freeFileSystem(fs);
    
    return 0;
}