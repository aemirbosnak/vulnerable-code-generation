//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[256];
    struct Node* parent;
    struct Node** children;
    int files;
} Node;

Node* newNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->parent = NULL;
    newNode->children = NULL;
    newNode->files = 0;
    return newNode;
}

void insertChild(Node* parent, Node* child) {
    parent->children = realloc(parent->children, (parent->files + 1) * sizeof(Node*));
    parent->children[parent->files++] = child;
}

void createDir(Node* parent, char* dirName) {
    Node* newDir = newNode(dirName);
    insertChild(parent, newDir);
}

void createFile(Node* parent, char* fileName, int size) {
    Node* newFile = newNode(fileName);
    insertChild(parent, newFile);
    newFile->files = size;
}

void listDir(Node* node) {
    printf("%s\n", node->name);
    for (int i = 0; i < node->files; i++) {
        printf("%s (%d bytes)\n", node->children[i]->name, node->children[i]->files);
    }
}

int main() {
    Node* root = newNode("/");
    createDir(root, "home");
    createDir(root, "documents");
    createDir(root, "pictures");
    createFile(root->children[0], "test.txt", 10);
    createFile(root->children[1], "document.doc", 20);
    createFile(root->children[2], "photo.jpg", 50);

    listDir(root);

    return 0;
}