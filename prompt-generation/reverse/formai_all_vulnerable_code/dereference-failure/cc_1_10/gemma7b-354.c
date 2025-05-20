//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

struct file {
    char name[256];
    int size;
    struct file* next;
};

struct dir {
    char name[256];
    struct dir* next;
    struct file* files;
};

struct dir* root;

void createFile(char* name, int size) {
    struct file* newFile = (struct file*)malloc(sizeof(struct file));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;

    if (root == NULL) {
        root = (struct dir*)malloc(sizeof(struct dir));
        strcpy(root->name, "/");
        root->next = NULL;
        root->files = newFile;
    } else {
        struct dir* currentDir = root;
        while (currentDir->next) {
            currentDir = currentDir->next;
        }
        currentDir->next = (struct dir*)malloc(sizeof(struct dir));
        strcpy(currentDir->next->name, name);
        currentDir->next->files = newFile;
    }
}

void listFiles() {
    struct dir* currentDir = root;
    while (currentDir) {
        printf("%s\n", currentDir->name);
        struct file* currentFile = currentDir->files;
        while (currentFile) {
            printf("%s (%d bytes)\n", currentFile->name, currentFile->size);
            currentFile = currentFile->next;
        }
        currentDir = currentDir->next;
    }
}

int main() {
    createFile("test.txt", 1024);
    createFile("another.txt", 512);
    listFiles();

    return 0;
}