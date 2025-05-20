//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 255
#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILE_SIZE 1024

typedef struct FileNode {
    char *name;
    int size;
    struct FileNode *next;
} FileNode;

typedef struct DirectoryNode {
    char *name;
    struct DirectoryNode *next;
    FileNode *files;
} DirectoryNode;

DirectoryNode *createDirectory(char *name) {
    DirectoryNode *newNode = (DirectoryNode *)malloc(sizeof(DirectoryNode));
    newNode->name = strdup(name);
    newNode->next = NULL;
    newNode->files = NULL;
    return newNode;
}

FileNode *createFile(char *name, int size) {
    FileNode *newNode = (FileNode *)malloc(sizeof(FileNode));
    newNode->name = strdup(name);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

void listDirectory(DirectoryNode *dir) {
    printf("Directory: %s\n", dir->name);
    for (FileNode *file = dir->files; file; file = file->next) {
        printf("  File: %s, Size: %d\n", file->name, file->size);
    }
}

int main() {
    DirectoryNode *root = createDirectory("root");
    createFile("file1.txt", 1024);
    createFile("file2.txt", 512);
    listDirectory(root);
    return 0;
}