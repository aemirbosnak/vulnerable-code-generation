//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
    return newNode;
}

void addDir(Node* node, char* dirName) {
    Node* newDir = createNode(dirName);
    if (node->dir == NULL) {
        node->dir = newDir;
    } else {
        node->dir->next = newDir;
    }
}

void printDir(Node* node) {
    printf("Directory: ");
    for (Node* dir = node->dir; dir; dir = dir->next) {
        printf("%s ", dir->name);
    }
    printf("\n");
}

int main() {
    Node* root = createNode("root");
    addDir(root, "home");
    addDir(root, "documents");
    addDir(root, "pictures");
    addDir(root->dir, "john");
    addDir(root->dir, "jane");

    printDir(root);

    return 0;
}