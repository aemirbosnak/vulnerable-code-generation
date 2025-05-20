//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

struct FileSystem {
    Node** directories;
    int size;
    int currentDirIndex;
};

void initFileSystem(struct FileSystem* fs) {
    fs->directories = NULL;
    fs->size = 0;
    fs->currentDirIndex = -1;
}

void mkdir(struct FileSystem* fs, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (fs->directories == NULL) {
        fs->directories = &newNode;
    } else {
        fs->directories[fs->size++] = newNode;
    }

    fs->currentDirIndex = fs->size - 1;
}

void ls(struct FileSystem* fs) {
    int i = 0;
    for (Node* dir = fs->directories; dir; dir = dir->next) {
        printf("%s ", dir->name);
        i++;
    }
    printf("\n");
    printf("Total directories: %d\n", i);
}

int main() {
    struct FileSystem* fs = malloc(sizeof(struct FileSystem));
    initFileSystem(fs);

    mkdir(fs, "home");
    mkdir(fs, "home/documents");
    mkdir(fs, "home/pictures");

    ls(fs);

    free(fs);

    return 0;
}