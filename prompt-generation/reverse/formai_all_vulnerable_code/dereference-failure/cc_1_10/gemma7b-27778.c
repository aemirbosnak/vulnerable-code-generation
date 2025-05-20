//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_DIR 5

struct file {
    char name[25];
    int size;
    struct file* next;
};

struct dir {
    char name[25];
    struct dir* next;
    struct file* files;
};

struct file* createFile(char* name, int size) {
    struct file* newFile = (struct file*)malloc(sizeof(struct file));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    return newFile;
}

struct dir* createDir(char* name) {
    struct dir* newDir = (struct dir*)malloc(sizeof(struct dir));
    strcpy(newDir->name, name);
    newDir->next = NULL;
    newDir->files = NULL;
    return newDir;
}

void listFiles(struct dir* dir) {
    struct file* file = dir->files;
    while (file) {
        printf("%s (size: %d)\n", file->name, file->size);
        file = file->next;
    }
}

int main() {
    struct dir* root = createDir("root");

    struct file* file1 = createFile("file1.txt", 10);
    struct file* file2 = createFile("file2.txt", 20);
    struct file* file3 = createFile("file3.txt", 30);
    struct file* file4 = createFile("file4.txt", 40);

    struct dir* dir1 = createDir("dir1");
    struct dir* dir2 = createDir("dir2");

    dir1->files = file1;
    dir1->files = file2;
    dir2->files = file3;
    dir2->files = file4;

    listFiles(root);

    return 0;
}