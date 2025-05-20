//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct Directory {
    char name[MAX_DIR_NAME_LENGTH];
    struct Directory* nextDir;
    struct File* files;
} Directory;

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    struct File* nextFile;
    struct Directory* dir;
} File;

Directory* createDirectory(char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->nextDir = NULL;
    newDir->files = NULL;
    return newDir;
}

File* createFile(char* name, int size, Directory* dir) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->nextFile = NULL;
    newFile->dir = dir;
    dir->files = newFile;
    return newFile;
}

void listDirectory(Directory* dir) {
    printf("%s:\n", dir->name);
    for (File* file = dir->files; file; file = file->nextFile) {
        printf("%s (%d bytes)\n", file->name, file->size);
    }
}

int main() {
    Directory* root = createDirectory("root");
    createFile("a.txt", 10, root);
    createFile("b.txt", 20, root);
    createFile("c/d.txt", 30, root);
    listDirectory(root);

    return 0;
}