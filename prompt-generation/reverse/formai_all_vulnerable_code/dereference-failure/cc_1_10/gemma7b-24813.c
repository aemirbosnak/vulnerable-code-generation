//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024

typedef struct FileNode {
    char *name;
    int size;
    struct FileNode *next;
} FileNode;

typedef struct DirectoryNode {
    char *name;
    struct DirectoryNode *next;
    FileNode **files;
} DirectoryNode;

DirectoryNode *rootDir = NULL;

void createDirectory(char *name) {
    DirectoryNode *newNode = malloc(sizeof(DirectoryNode));
    newNode->name = strdup(name);
    newNode->next = rootDir;
    rootDir = newNode;
}

void createFile(char *name, int size) {
    FileNode *newNode = malloc(sizeof(FileNode));
    newNode->name = strdup(name);
    newNode->size = size;
    newNode->next = NULL;

    DirectoryNode *currDir = rootDir;
    while (currDir->next) {
        currDir = currDir->next;
    }

    currDir->files = &newNode;
}

int main() {
    createDirectory("myDir");
    createDirectory("anotherDir");
    createFile("myFile.txt", 1024);
    createFile("anotherFile.txt", 512);

    FileNode *currFile = rootDir->files[0];
    printf("File name: %s\n", currFile->name);
    printf("File size: %d\n", currFile->size);

    return 0;
}