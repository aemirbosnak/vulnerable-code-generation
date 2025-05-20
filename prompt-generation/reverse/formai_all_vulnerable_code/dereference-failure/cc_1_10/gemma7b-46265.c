//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct FileNode {
    char name[256];
    struct FileNode* next;
    struct DirNode* dir;
} FileNode;

typedef struct DirNode {
    char name[256];
    struct DirNode* next;
    FileNode** files;
} DirNode;

DirNode* root = NULL;

void createFile(char* name, char* dir) {
    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;

    DirNode* currentDir = root;
    if (currentDir == NULL) {
        currentDir = (DirNode*)malloc(sizeof(DirNode));
        strcpy(currentDir->name, dir);
        currentDir->next = NULL;
        currentDir->files = NULL;
        root = currentDir;
    } else {
        while (currentDir->next != NULL) {
            currentDir = currentDir->next;
        }
        currentDir->next = (DirNode*)malloc(sizeof(DirNode));
        strcpy(currentDir->next->name, dir);
        currentDir->next->files = NULL;
    }

    newNode->dir = currentDir;
    currentDir->files = &newNode;
}

void listFiles(char* dir) {
    DirNode* currentDir = root;
    while (currentDir) {
        if (strcmp(currentDir->name, dir) == 0) {
            FileNode* file = *currentDir->files;
            while (file) {
                printf("%s\n", file->name);
            }
        }
        currentDir = currentDir->next;
    }
}

int main() {
    createFile("hello.txt", "mydir");
    createFile("world.txt", "mydir");
    listFiles("mydir");

    return 0;
}