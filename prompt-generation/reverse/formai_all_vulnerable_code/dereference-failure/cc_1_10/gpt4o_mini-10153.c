//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DIRS 10
#define MAX_NAME_LENGTH 50

// Define file structure
typedef struct File {
    char name[MAX_NAME_LENGTH];
    int size; // in bytes
} File;

// Define directory structure
typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory *subDirs[MAX_DIRS];
    File *files[MAX_FILES];
    int dirCount;
    int fileCount;
} Directory;

// Function prototypes
Directory* createDirectory(const char* name);
void addFile(Directory* dir, const char* fileName, int size);
void deleteFile(Directory* dir, const char* fileName);
void listContents(Directory* dir);
Directory* changeDirectory(Directory* current, const char* dirName);
void freeDirectory(Directory* dir);

// Create the root directory
Directory* root;

// Main function
int main() {
    root = createDirectory("root");
    Directory* currentDir = root;

    char command[100];
    char arg1[MAX_NAME_LENGTH], arg2[MAX_NAME_LENGTH];

    while (1) {
        printf("Current Directory: %s\n", currentDir->name);
        printf("Enter command (add, delete, list, cd, exit): ");
        fgets(command, 100, stdin);
        sscanf(command, "%s %s %s", command, arg1, arg2);

        if (strcmp(command, "add") == 0) {
            int size = atoi(arg2);
            addFile(currentDir, arg1, size);
        } else if (strcmp(command, "delete") == 0) {
            deleteFile(currentDir, arg1);
        } else if (strcmp(command, "list") == 0) {
            listContents(currentDir);
        } else if (strcmp(command, "cd") == 0) {
            currentDir = changeDirectory(currentDir, arg1);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unrecognized command.\n");
        }
    }

    freeDirectory(root);
    return 0;
}

// Create new directory
Directory* createDirectory(const char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->dirCount = 0;
    newDir->fileCount = 0;
    for (int i = 0; i < MAX_DIRS; i++) {
        newDir->subDirs[i] = NULL;
    }
    for (int j = 0; j < MAX_FILES; j++) {
        newDir->files[j] = NULL;
    }
    return newDir;
}

// Add file to the directory
void addFile(Directory* dir, const char* fileName, int size) {
    if (dir->fileCount < MAX_FILES) {
        File* newFile = (File*)malloc(sizeof(File));
        strcpy(newFile->name, fileName);
        newFile->size = size;
        dir->files[dir->fileCount++] = newFile;
        printf("File '%s' added with size %d bytes.\n", fileName, size);
    } else {
        printf("Cannot add more files. Maximum limit reached.\n");
    }
}

// Delete a file from the directory
void deleteFile(Directory* dir, const char* fileName) {
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i]->name, fileName) == 0) {
            free(dir->files[i]);
            dir->files[i] = dir->files[--dir->fileCount];
            printf("File '%s' deleted.\n", fileName);
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

// List contents of the directory
void listContents(Directory* dir) {
    printf("Directories:\n");
    for (int i = 0; i < dir->dirCount; i++) {
        printf("  - %s\n", dir->subDirs[i]->name);
    }
    printf("Files:\n");
    for (int j = 0; j < dir->fileCount; j++) {
        printf("  - %s (%d bytes)\n", dir->files[j]->name, dir->files[j]->size);
    }
}

// Change to a subdirectory
Directory* changeDirectory(Directory* current, const char* dirName) {
    for (int i = 0; i < current->dirCount; i++) {
        if (strcmp(current->subDirs[i]->name, dirName) == 0) {
            return current->subDirs[i];
        }
    }
    printf("Directory '%s' not found.\n", dirName);
    return current;
}

// Free the directory
void freeDirectory(Directory* dir) {
    for (int i = 0; i < dir->fileCount; i++) {
        free(dir->files[i]);
    }
    for (int j = 0; j < dir->dirCount; j++) {
        freeDirectory(dir->subDirs[j]);
    }
    free(dir);
}