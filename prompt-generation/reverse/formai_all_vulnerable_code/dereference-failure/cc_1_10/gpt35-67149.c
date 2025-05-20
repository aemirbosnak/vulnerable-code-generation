//FormAI DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct File {
    char name[50];
    char data[MAX_FILE_SIZE];
    int size;
} File;

typedef struct Directory {
    char name[50];
    struct Directory* parent;
    struct Directory* subDirectories[50];
    int numSubDirs;
    File* files[50];
    int numFiles;
} Directory;

Directory* root;

void initializeFileSystem() {
    root = (Directory*) malloc(sizeof(Directory));
    strcpy(root->name, "root");
    root->parent = NULL;
    root->numSubDirs = 0;
    root->numFiles = 0;
}

void createFile(char* name, char* data, int size, Directory* parent) {
    File* newFile = (File*) malloc(sizeof(File));
    strcpy(newFile->name, name);
    strcpy(newFile->data, data);
    newFile->size = size;
    parent->files[parent->numFiles] = newFile;
    parent->numFiles++;
}

void createDirectory(char* name, Directory* parent) {
    Directory* newDirectory = (Directory*) malloc(sizeof(Directory));
    strcpy(newDirectory->name, name);
    newDirectory->parent = parent;
    newDirectory->numSubDirs = 0;
    newDirectory->numFiles = 0;
    parent->subDirectories[parent->numSubDirs] = newDirectory;
    parent->numSubDirs++;
}

Directory* navigateToDirectory(char* path, Directory* currentDirectory) {
    char* directoryName = strtok(path, "/");
    while(directoryName != NULL) {
        for(int i=0; i<currentDirectory->numSubDirs; i++) {
            if(strcmp(directoryName, currentDirectory->subDirectories[i]->name) == 0) {
                currentDirectory = currentDirectory->subDirectories[i];
                directoryName = strtok(NULL, "/");
                break;
            }
        }
    }
    return currentDirectory;
}

void printFile(File* file) {
    printf("File name: %s\n", file->name);
    printf("File size: %d\n", file->size);
    printf("File data: %s", file->data);
}

void printDirectory(Directory* directory) {
    printf("Directory name: %s\n", directory->name);
    printf("Number of subdirectories: %d\n", directory->numSubDirs);
    for(int i=0; i<directory->numSubDirs; i++) {
        printf("Subdirectory %d: %s\n", i+1, directory->subDirectories[i]->name);
    }
    printf("Number of files: %d\n", directory->numFiles);
    for(int i=0; i<directory->numFiles; i++) {
        printf("File %d: %s\n", i+1, directory->files[i]->name);
    }
}

int main() {
    initializeFileSystem();

    createDirectory("docs", root);
    createDirectory("pictures", root);
    createDirectory("notes", root);

    Directory* docs = navigateToDirectory("docs", root);
    createFile("file1.txt", "This is file 1", 14, docs);
    createFile("file2.txt", "This is file 2", 14, docs);

    Directory* pictures = navigateToDirectory("pictures", root);
    createFile("pic1.jpg", "This is picture 1", 18, pictures);
    createFile("pic2.jpg", "This is picture 2", 18, pictures);

    Directory* notes = navigateToDirectory("notes", root);
    createFile("note1.txt", "This is note 1", 14, notes);
    createFile("note2.txt", "This is note 2", 14, notes);

    printDirectory(root);

    return 0;
}