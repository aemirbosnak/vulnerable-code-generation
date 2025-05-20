//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct File {
    char name[20];
    struct File* next;
} File;

typedef struct Dir {
    char name[20];
    struct Dir* next;
    File** files;
} Dir;

Dir* root = NULL;

void createFile(char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;

    if (root == NULL) {
        root = (Dir*)malloc(sizeof(Dir));
        strcpy(root->name, "/");
        root->next = NULL;
        root->files = &newFile;
    } else {
        Dir* currentDir = root;
        while (currentDir->next) {
            currentDir = currentDir->next;
        }
        currentDir->files = &newFile;
    }
}

void listFiles() {
    Dir* currentDir = root;
    while (currentDir) {
        printf("%s\n", currentDir->name);
        File* file = currentDir->files;
        while (file) {
            printf("%s\n", file->name);
            file = file->next;
        }
        currentDir = currentDir->next;
    }
}

int main() {
    createFile("a.txt");
    createFile("b.txt");
    createFile("c/d.txt");
    listFiles();

    return 0;
}