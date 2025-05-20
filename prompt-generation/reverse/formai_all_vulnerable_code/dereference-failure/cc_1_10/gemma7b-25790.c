//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

typedef struct FileSystem {
    Node** directories;
    Node** files;
    int currentDir;
} FileSystem;

FileSystem* createFileSystem() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->directories = (Node**)malloc(MAX_DIR * sizeof(Node));
    fs->files = (Node**)malloc(MAX_FILES * sizeof(Node));
    fs->currentDir = 0;

    return fs;
}

void addFile(FileSystem* fs, char* name) {
    Node* file = (Node*)malloc(sizeof(Node));
    strcpy(file->name, name);
    file->next = NULL;

    fs->files[fs->currentDir]->next = file;
    fs->files[fs->currentDir]->next->next = NULL;
}

void addDirectory(FileSystem* fs, char* name) {
    Node* directory = (Node*)malloc(sizeof(Node));
    strcpy(directory->name, name);
    directory->next = NULL;

    fs->directories[fs->currentDir]->next = directory;
    fs->directories[fs->currentDir]->next->next = NULL;
}

void listFiles(FileSystem* fs) {
    Node* file = fs->files[fs->currentDir]->next;
    while (file) {
        printf("%s\n", file->name);
        file = file->next;
    }
}

int main() {
    FileSystem* fs = createFileSystem();

    addDirectory(fs, "home");
    addDirectory(fs, "work");

    addFile(fs, "documents.txt");
    addFile(fs, "pictures.jpg");

    listFiles(fs);

    return 0;
}