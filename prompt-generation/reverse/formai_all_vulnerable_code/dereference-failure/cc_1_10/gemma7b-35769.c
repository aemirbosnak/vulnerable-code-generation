//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_NAME_SIZE 255

typedef struct Directory {
    char name[MAX_DIR_SIZE];
    struct Directory* next;
    struct File** files;
} Directory;

typedef struct File {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    struct File* next;
    struct Directory* dir;
} File;

Directory* createDirectory(char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->next = NULL;
    newDir->files = NULL;
    return newDir;
}

File* createFile(char* name, int size, Directory* dir) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    newFile->dir = dir;
    return newFile;
}

void listDirectory(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    for (File* file = dir->files; file; file = file->next) {
        printf("  File: %s, Size: %d\n", file->name, file->size);
    }
}

int main() {
    Directory* root = createDirectory("root");
    File* file1 = createFile("file1.txt", 10, root);
    File* file2 = createFile("file2.txt", 20, root);
    listDirectory(root);

    return 0;
}