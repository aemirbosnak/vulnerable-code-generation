//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50

typedef struct {
    char name[FILENAME_LENGTH];
    int size; // Size of the file
    char *content; // Pointer to the file content
} File;

typedef struct {
    File *files[MAX_FILES];
    int fileCount;
} FileSystem;

// Initialize the file system
void initFileSystem(FileSystem *fs) {
    fs->fileCount = 0;
}

// Create a new file in the file system
void createFile(FileSystem *fs, char *name, char *content) {
    if (fs->fileCount >= MAX_FILES) {
        printf("File system is full. Cannot create more files.\n");
        return;
    }

    File *newFile = (File *)malloc(sizeof(File));
    strncpy(newFile->name, name, FILENAME_LENGTH);
    newFile->size = strlen(content);
    newFile->content = (char *)malloc(newFile->size + 1);
    strcpy(newFile->content, content);
    
    fs->files[fs->fileCount] = newFile;
    fs->fileCount++;
    printf("File '%s' created successfully.\n", name);
}

// Delete a file from the file system
void deleteFile(FileSystem *fs, char *name) {
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]->content);
            free(fs->files[i]);

            // Shift files to fill the gap
            for (int j = i; j < fs->fileCount - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->fileCount--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

// List all files in the file system
void listFiles(FileSystem *fs) {
    if (fs->fileCount == 0) {
        printf("No files in the file system.\n");
        return;
    }

    printf("Files in the file system:\n");
    for (int i = 0; i < fs->fileCount; i++) {
        printf("- %s (Size: %d bytes)\n", fs->files[i]->name, fs->files[i]->size);
    }
}

// Cleanup file system
void cleanupFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->fileCount; i++) {
        free(fs->files[i]->content);
        free(fs->files[i]);
    }
}

// Main function to demonstrate the file system
int main() {
    FileSystem fs;
    initFileSystem(&fs);

    createFile(&fs, "file1.txt", "Hello, this is the content of file1.");
    createFile(&fs, "file2.txt", "This is a short text for file2.");
    listFiles(&fs);

    deleteFile(&fs, "file1.txt");
    listFiles(&fs);

    deleteFile(&fs, "file3.txt"); // Trying to delete a non-existing file
    createFile(&fs, "file3.txt", "Content of file3.");
    listFiles(&fs);

    cleanupFileSystem(&fs);
    return 0;
}