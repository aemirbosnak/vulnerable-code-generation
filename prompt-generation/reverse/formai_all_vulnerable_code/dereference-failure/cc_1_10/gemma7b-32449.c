//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct FileSystem {
    char **directories;
    char **files;
    int size;
} FileSystem;

// Create a new file system
FileSystem *createFileSystem(int size) {
    FileSystem *fs = malloc(sizeof(FileSystem));
    fs->directories = malloc(size * sizeof(char *));
    fs->files = malloc(size * sizeof(char *));
    fs->size = size;
    return fs;
}

// Add a new directory to the file system
void addDirectory(FileSystem *fs, char *directory) {
    fs->directories[fs->size++] = directory;
}

// Add a new file to the file system
void addFile(FileSystem *fs, char *file) {
    fs->files[fs->size++] = file;
}

// List the files in a directory
void listFiles(FileSystem *fs, char *directory) {
    for (int i = 0; i < fs->size; i++) {
        if (strcmp(fs->directories[i], directory) == 0) {
            printf("%s\n", fs->files[i]);
        }
    }
}

int main() {
    // Create a new file system with a size of 10
    FileSystem *fs = createFileSystem(10);

    // Add some directories to the file system
    addDirectory(fs, "home");
    addDirectory(fs, "docs");
    addDirectory(fs, "music");

    // Add some files to the file system
    addFile(fs, "home/alice.txt");
    addFile(fs, "docs/john.doc");
    addFile(fs, "music/bob.mp3");

    // List the files in the "home" directory
    listFiles(fs, "home");

    return 0;
}