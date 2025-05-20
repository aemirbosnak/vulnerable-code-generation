//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a file
typedef struct {
    char filename[100];
    char content[10000];
} File;

// A structure to represent a directory
typedef struct {
    char name[100];
    File* files[100];
} Directory;

// A function to create a new file
File* createFile(const char* filename, const char* content) {
    File* newFile = (File*) malloc(sizeof(File));
    if (newFile == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }
    strcpy(newFile->filename, filename);
    strcpy(newFile->content, content);
    return newFile;
}

// A function to open an existing file
File* openFile(const char* filename) {
    File* file = (File*) malloc(sizeof(File));
    if (file == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }
    strcpy(file->filename, filename);
    return file;
}

// A function to write to a file
void writeFile(File* file, const char* content) {
    strcpy(file->content, content);
}

// A function to read from a file
char* readFile(File* file) {
    return file->content;
}

// A function to delete a file
void deleteFile(File* file) {
    free(file);
}

// A function to create a new directory
Directory* createDirectory(const char* name) {
    Directory* newDirectory = (Directory*) malloc(sizeof(Directory));
    if (newDirectory == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }
    strcpy(newDirectory->name, name);
    return newDirectory;
}

// A function to open an existing directory
Directory* openDirectory(const char* name) {
    Directory* directory = (Directory*) malloc(sizeof(Directory));
    if (directory == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }
    strcpy(directory->name, name);
    return directory;
}

// A function to create a new file in a directory
File* createFileInDirectory(Directory* directory, const char* filename, const char* content) {
    File* newFile = createFile(filename, content);
    if (newFile == NULL) {
        return NULL;
    }
    directory->files[strlen(directory->files)] = newFile;
    return newFile;
}

// A function to open an existing file in a directory
File* openFileInDirectory(Directory* directory, const char* filename) {
    File* file = openFile(filename);
    if (file == NULL) {
        return NULL;
    }
    directory->files[strlen(directory->files)] = file;
    return file;
}

// A function to delete a file from a directory
void deleteFileFromDirectory(Directory* directory, File* file) {
    for (int i = 0; i < strlen(directory->files); i++) {
        if (directory->files[i] == file) {
            for (int j = i; j < strlen(directory->files) - 1; j++) {
                directory->files[j] = directory->files[j + 1];
            }
            strcpy(directory->files[strlen(directory->files) - 1], "");
            break;
        }
    }
}

// A function to print the contents of a directory
void printDirectory(Directory* directory) {
    printf("Directory: %s\n", directory->name);
    printf("Files:\n");
    for (int i = 0; i < strlen(directory->files); i++) {
        printf(" - %s\n", directory->files[i]->filename);
    }
}

int main() {
    Directory* rootDirectory = createDirectory("root");

    createFileInDirectory(rootDirectory, "file1.txt", "This is file 1");
    createFileInDirectory(rootDirectory, "file2.txt", "This is file 2");
    createFileInDirectory(rootDirectory, "file3.txt", "This is file 3");

    printDirectory(rootDirectory);

    return 0;
}