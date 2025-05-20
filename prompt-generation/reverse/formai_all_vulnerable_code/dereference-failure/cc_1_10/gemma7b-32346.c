//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct FileSystem {
    char **dirs;
    char **files;
    int size;
} FileSystem;

// Function to create a new file system
FileSystem *createFileSystem(int size) {
    FileSystem *fs = malloc(sizeof(FileSystem));
    fs->dirs = malloc(size * sizeof(char *));
    fs->files = malloc(size * sizeof(char *));
    fs->size = size;
    return fs;
}

// Function to add a new directory to the file system
void addDirectory(FileSystem *fs, char *dirName) {
    fs->dirs[fs->size] = strdup(dirName);
    fs->size++;
}

// Function to add a new file to the file system
void addFile(FileSystem *fs, char *fileName, char *data) {
    fs->files[fs->size] = strdup(fileName);
    fs->files[fs->size] = strdup(data);
    fs->size++;
}

// Function to list all directories in the file system
void listDirectories(FileSystem *fs) {
    for (int i = 0; i < fs->size; i++) {
        if (fs->dirs[i] != NULL) {
            printf("%s\n", fs->dirs[i]);
        }
    }
}

// Function to list all files in a directory
void listFiles(FileSystem *fs, char *dirName) {
    for (int i = 0; i < fs->size; i++) {
        if (strcmp(fs->dirs[i], dirName) == 0) {
            printf("%s\n", fs->files[i]);
        }
    }
}

// Main function
int main() {
    // Create a new file system
    FileSystem *fs = createFileSystem(10);

    // Add some directories and files
    addDirectory(fs, "test");
    addDirectory(fs, "data");
    addFile(fs, "test/my.txt", "This is a file");
    addFile(fs, "data/config.txt", "The configuration file");

    // List all directories
    listDirectories(fs);

    // List all files in the "test" directory
    listFiles(fs, "test");

    return 0;
}