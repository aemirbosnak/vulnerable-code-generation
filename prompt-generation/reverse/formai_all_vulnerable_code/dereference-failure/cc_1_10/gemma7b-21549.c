//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

struct Node {
    char name[20];
    struct Node* next;
    struct Node* child;
    FILE* file;
};

struct Directory {
    char name[20];
    struct Directory* next;
    struct Node* head;
};

struct FileSystem {
    struct Directory* root;
    int size;
};

void createFileSystem(struct FileSystem* fs) {
    fs->root = NULL;
    fs->size = 0;
}

void addDirectory(struct FileSystem* fs, char* name) {
    struct Directory* newDir = (struct Directory*)malloc(sizeof(struct Directory));
    strcpy(newDir->name, name);
    newDir->next = fs->root;
    fs->root = newDir;
    fs->size++;
}

void addFile(struct FileSystem* fs, char* name, char* content) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->file = fopen(name, "w");
    fprintf(newNode->file, content);
    fclose(newNode->file);
    newNode->next = NULL;
    newNode->child = NULL;
    addDirectory(fs, name);
    fs->size++;
}

void listFiles(struct FileSystem* fs) {
    struct Directory* currentDir = fs->root;
    while (currentDir) {
        struct Node* currentFile = currentDir->head;
        while (currentFile) {
            printf("%s\n", currentFile->name);
        }
        currentDir = currentDir->next;
    }
}

int main() {
    struct FileSystem* fs = (struct FileSystem*)malloc(sizeof(struct FileSystem));
    createFileSystem(fs);

    addDirectory(fs, "home");
    addDirectory(fs, "data");
    addDirectory(fs, "documents");

    addFile(fs, "home/test.txt", "This is a file.");
    addFile(fs, "data/images/photo.jpg", "This is a picture.");
    addFile(fs, "documents/report.doc", "This is a report.");

    listFiles(fs);

    return 0;
}