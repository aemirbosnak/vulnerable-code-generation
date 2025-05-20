//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_SIZE 20
#define MAX_FILE_SIZE 10

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
    FILE* file;
} Node;

Node* newNode(char* name) {
    Node* node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    node->file = NULL;
    return node;
}

void addDir(Node* node, char* dirName) {
    Node* newDir = newNode(dirName);
    if (node->dir == NULL) {
        node->dir = newDir;
    } else {
        node->dir->next = newDir;
        node->dir = newDir;
    }
}

void addFile(Node* node, char* fileName, int fileSize) {
    Node* newFile = newNode(fileName);
    newFile->file = fopen(fileName, "w");
    if (node->dir == NULL) {
        node->dir = newFile;
    } else {
        node->dir->next = newFile;
        node->dir = newFile;
    }
}

void listDir(Node* node) {
    printf("Directory: ");
    for (Node* dir = node->dir; dir; dir = dir->next) {
        printf("%s ", dir->name);
    }
    printf("\n");
}

void listFiles(Node* node) {
    for (Node* file = node->dir; file; file = file->next) {
        printf("%s ", file->name);
    }
    printf("\n");
}

int main() {
    Node* root = newNode("root");
    addDir(root, "home");
    addDir(root, "documents");
    addDir(root, "pictures");
    addFile(root, "home/test.txt", 10);
    addFile(root, "documents/document.doc", 20);
    addFile(root, "pictures/image.jpg", 30);

    listDir(root);
    listFiles(root);

    return 0;
}