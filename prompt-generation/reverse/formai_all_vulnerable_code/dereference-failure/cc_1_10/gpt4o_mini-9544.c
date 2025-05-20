//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of directories and files
#define MAX_DIRS 10
#define MAX_FILES 10
#define NAME_LENGTH 50

typedef struct File {
    char name[NAME_LENGTH];
} File;

typedef struct Directory {
    char name[NAME_LENGTH];
    struct Directory* subDirs[MAX_DIRS];
    File* files[MAX_FILES];
    int subDirCount;
    int fileCount;
} Directory;

// Create a new directory
Directory* createDirectory(const char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->subDirCount = 0;
    newDir->fileCount = 0;
    return newDir;
}

// Create a new file
File* createFile(const char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    return newFile;
}

// Add subdirectory to a directory
int addSubDirectory(Directory* parent, Directory* subDir) {
    if (parent->subDirCount < MAX_DIRS) {
        parent->subDirs[parent->subDirCount++] = subDir;
        return 1;
    }
    return 0; // No space for more subdirectories
}

// Add a file to a directory
int addFile(Directory* dir, File* file) {
    if (dir->fileCount < MAX_FILES) {
        dir->files[dir->fileCount++] = file;
        return 1;
    }
    return 0; // No space for more files
}

// List the contents of a directory
void listDirectory(Directory* dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Directory: %s\n", dir->name);
    
    for (int i = 0; i < dir->fileCount; i++) {
        for (int j = 0; j < depth; j++) {
            printf("  ");
        }
        printf("File: %s\n", dir->files[i]->name);
    }
    
    for (int i = 0; i < dir->subDirCount; i++) {
        listDirectory(dir->subDirs[i], depth + 1);
    }
}

// Recursive function to delete a directory
void deleteDirectory(Directory* dir) {
    for (int i = 0; i < dir->fileCount; i++) {
        free(dir->files[i]);
    }
    
    for (int i = 0; i < dir->subDirCount; i++) {
        deleteDirectory(dir->subDirs[i]);
    }
    
    free(dir);
}

// Main program to simulate the file system
int main() {
    Directory* root = createDirectory("root");
    
    Directory* home = createDirectory("home");
    Directory* user = createDirectory("user");
    
    addSubDirectory(root, home);
    addSubDirectory(home, user);
    
    addFile(user, createFile("file1.txt"));
    addFile(user, createFile("file2.txt"));
    
    Directory* documents = createDirectory("documents");
    addSubDirectory(user, documents);
    addFile(documents, createFile("doc1.pdf"));
    
    printf("File System Structure:\n");
    listDirectory(root, 0);
    
    // Cleanup
    deleteDirectory(root);
    
    return 0;
}