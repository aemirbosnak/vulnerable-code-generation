//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

Node* createNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    return node;
}

void addDir(Node* node, char* dirName) {
    Node* dirNode = createNode(dirName);
    dirNode->dir = node;
    node->dir = dirNode;
}

void addFile(Node* dirNode, char* fileName) {
    Node* fileNode = createNode(fileName);
    fileNode->dir = dirNode;
    dirNode->next = fileNode;
}

void ls(Node* node) {
    printf("%s\n", node->name);
    if (node->dir) {
        ls(node->dir);
    }
    if (node->next) {
        ls(node->next);
    }
}

int main() {
    Node* root = createNode("root");
    addDir(root, "home");
    addDir(root, "work");
    addDir(root, "tmp");

    addFile(root->dir->dir, "a.txt");
    addFile(root->dir->dir, "b.txt");
    addFile(root->dir->dir, "c.txt");

    ls(root);

    return 0;
}