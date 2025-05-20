//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct Directory {
    char name[MAX_DIR_NAME_LENGTH];
    struct Directory* next;
    struct File** files;
} Directory;

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    struct File* next;
    struct Directory* dir;
} File;

Directory* CreateDirectory(char* name) {
    Directory* newDir = malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->next = NULL;
    newDir->files = NULL;
    return newDir;
}

File* CreateFile(char* name, int size, Directory* dir) {
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    newFile->dir = dir;
    return newFile;
}

void ListDirectory(Directory* dir) {
    printf("%s:", dir->name);
    for (File* file = dir->files; file; file = file->next) {
        printf(" %s", file->name);
    }
    printf("\n");
}

int main() {
    Directory* root = CreateDirectory("root");
    File* file1 = CreateFile("file1.txt", 10, root);
    File* file2 = CreateFile("file2.txt", 20, root);
    ListDirectory(root);

    return 0;
}