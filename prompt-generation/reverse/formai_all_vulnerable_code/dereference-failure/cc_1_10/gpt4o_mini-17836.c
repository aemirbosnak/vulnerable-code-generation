//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a file
typedef struct File {
    char name[100];
    char content[1024];
    int size;
} File;

// Define a structure for a directory
typedef struct Directory {
    char name[100];
    struct Directory *subDirs[10];
    File *files[10];
    int fileCount;
    int dirCount;
} Directory;

// Function to create a new file
File* createFile(const char* name, const char* content) {
    File* newFile = (File*) malloc(sizeof(File));
    strncpy(newFile->name, name, sizeof(newFile->name));
    strncpy(newFile->content, content, sizeof(newFile->content));
    newFile->size = strlen(content);
    return newFile;
}

// Function to create a new directory
Directory* createDirectory(const char* name) {
    Directory* newDir = (Directory*) malloc(sizeof(Directory));
    strncpy(newDir->name, name, sizeof(newDir->name));
    newDir->fileCount = 0;
    newDir->dirCount = 0;
    return newDir;
}

// Function to add a file to a directory
void addFileToDirectory(Directory* dir, File* file) {
    if (dir->fileCount < 10) {
        dir->files[dir->fileCount++] = file;
        printf("File '%s' added to directory '%s'.\n", file->name, dir->name);
    } else {
        printf("Cannot add file. Directory is full.\n");
    }
}

// Function to add a subdirectory to a directory
void addSubdirectory(Directory* parentDir, Directory* subDir) {
    if (parentDir->dirCount < 10) {
        parentDir->subDirs[parentDir->dirCount++] = subDir;
        printf("Subdirectory '%s' added to directory '%s'.\n", subDir->name, parentDir->name);
    } else {
        printf("Cannot add subdirectory. Directory is full.\n");
    }
}

// Function to display the contents of a directory
void displayDirectory(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    printf("Files:\n");
    for (int i = 0; i < dir->fileCount; i++) {
        printf(" - %s (Size: %d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
    printf("Subdirectories:\n");
    for (int i = 0; i < dir->dirCount; i++) {
        printf(" - %s\n", dir->subDirs[i]->name);
    }
}

// Function to initialize the simulation
void initializeSimulation(Directory* root) {
    Directory* dir1 = createDirectory("Documents");
    Directory* dir2 = createDirectory("Downloads");
    Directory* dir3 = createDirectory("Images");

    addSubdirectory(root, dir1);
    addSubdirectory(root, dir2);
    addSubdirectory(root, dir3);

    File* file1 = createFile("Resume.txt", "This is my resume.");
    File* file2 = createFile("Photo.jpg", "This is my photo.");
    File* file3 = createFile("Report.pdf", "This is a detailed report.");

    addFileToDirectory(dir1, file1);
    addFileToDirectory(dir2, file2);
    addFileToDirectory(dir3, file3);
}

// Main function
int main() {
    // Create root directory
    Directory* rootDirectory = createDirectory("Root");

    // Initialize the file system simulation
    initializeSimulation(rootDirectory);

    // Display the root directory and its contents
    displayDirectory(rootDirectory);
    for (int i = 0; i < rootDirectory->dirCount; i++) {
        displayDirectory(rootDirectory->subDirs[i]);
    }

    // Free allocated memory
    for (int i = 0; i < rootDirectory->dirCount; i++) {
        for (int j = 0; j < rootDirectory->subDirs[i]->fileCount; j++) {
            free(rootDirectory->subDirs[i]->files[j]);
        }
        free(rootDirectory->subDirs[i]);
    }
    free(rootDirectory);
    
    return 0;
}