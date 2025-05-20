//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_NAME_SIZE 255

typedef struct Directory {
    char **files;
    struct Directory *next;
} Directory;

typedef struct File {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    struct File *next;
} File;

Directory *createDirectory(char *name) {
    Directory *newDir = malloc(sizeof(Directory));
    newDir->files = malloc(MAX_DIR_SIZE * sizeof(char *));
    newDir->next = NULL;
    newDir->files[0] = name;

    return newDir;
}

File *createFile(char *name, int size) {
    File *newFile = malloc(sizeof(File));
    newFile->name[0] = '\0';
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;

    return newFile;
}

void listDirectory(Directory *dir) {
    for (int i = 0; dir->files[i] != NULL; i++) {
        printf("%s\n", dir->files[i]);
    }
}

void listFiles(Directory *dir) {
    for (Directory *subDir = dir; subDir; subDir = subDir->next) {
        listDirectory(subDir);
    }

    for (File *file = dir->files; file; file = file->next) {
        printf("%s (size: %d)\n", file->name, file->size);
    }
}

int main() {
    Directory *root = createDirectory("root");

    createFile("file1.txt", 10);
    createFile("dir1", 0);
    createDirectory("dir1/subdir");
    createFile("dir1/subdir/file2.txt", 20);

    listFiles(root);

    return 0;
}