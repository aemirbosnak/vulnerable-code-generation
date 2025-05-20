//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 50

typedef struct Directory {
    char **files;
    struct Directory *next;
} Directory;

typedef struct File {
    char *name;
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
    newFile->name = name;
    newFile->size = size;
    newFile->next = NULL;
    return newFile;
}

Directory *searchDirectory(Directory *dir, char *name) {
    for (Directory *currDir = dir; currDir; currDir = currDir->next) {
        if (strcmp(currDir->files[0], name) == 0) {
            return currDir;
        }
    }
    return NULL;
}

int main() {
    Directory *root = createDirectory("root");
    File *file1 = createFile("file1.txt", 20);
    File *file2 = createFile("file2.txt", 30);
    file1->next = file2;
    root->files[0] = file1->name;

    Directory *dir = searchDirectory(root, "file2.txt");
    if (dir) {
        printf("File found: %s\n", dir->files[0]);
    } else {
        printf("File not found.\n");
    }

    return 0;
}