//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[25];
    struct Node* next;
    struct Node* dir;
} Node;

void createNode(Node* node, char* name) {
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
}

void insertDir(Node* dir, Node* newNode) {
    if (dir == NULL) {
        dir = newNode;
    } else {
        dir->next = newNode;
        dir = newNode;
    }
}

void listDir(Node* dir) {
    while (dir) {
        printf("%s\n", dir->name);
        dir = dir->next;
    }
}

int main() {
    Node* root = NULL;
    Node* dir = NULL;

    createNode(root, "root");
    insertDir(root, dir);

    createNode(dir, "home");
    insertDir(dir, dir);

    createNode(dir, "documents");
    insertDir(dir, dir);

    createNode(dir, "pictures");
    insertDir(dir, dir);

    listDir(root);

    return 0;
}