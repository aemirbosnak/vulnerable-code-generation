//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

struct File {
    char name[256];
    struct File* next;
    int size;
    FILE* fp;
};

struct Directory {
    char name[256];
    struct Directory* next;
    struct File* files;
};

struct FileSystem {
    struct Directory* root;
};

void createFile(struct FileSystem* fs, char* name, int size) {
    struct File* newFile = (struct File*)malloc(sizeof(struct File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    newFile->fp = fopen(name, "w");

    if (fs->root == NULL) {
        fs->root = (struct Directory*)malloc(sizeof(struct Directory));
        strcpy(fs->root->name, "/");
        fs->root->next = NULL;
        fs->root->files = newFile;
    } else {
        struct Directory* currentDir = fs->root;
        while (currentDir->next) {
            currentDir = currentDir->next;
        }
        currentDir->next = (struct Directory*)malloc(sizeof(struct Directory));
        strcpy(currentDir->next->name, name);
        currentDir->next->files = newFile;
    }
}

int main() {
    struct FileSystem* fs = (struct FileSystem*)malloc(sizeof(struct FileSystem));
    fs->root = NULL;

    createFile(fs, "my_file.txt", 10);
    createFile(fs, "another_file.txt", 20);

    FILE* fp = fopen("my_file.txt", "r");
    char data[10];
    fread(data, 10, 1, fp);
    printf("%s", data);

    return 0;
}