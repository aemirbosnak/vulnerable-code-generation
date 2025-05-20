//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[256];
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
    node->dir = dirNode;
}

void addFile(Node* dirNode, char* fileName) {
    Node* fileNode = createNode(fileName);
    dirNode->dir = fileNode;
}

void listDir(Node* node) {
    printf("%s:\n", node->name);
    Node* dirNode = node->dir;
    while (dirNode) {
        printf("  %s\n", dirNode->name);
        dirNode = dirNode->next;
    }
    printf("\n");
}

int main() {
    Node* root = createNode("root");
    addDir(root, "home");
    addDir(root, "work");
    addDir(root, "games");

    addFile(root->dir->dir, "test.txt");
    addFile(root->dir->dir, "another.txt");

    listDir(root);

    return 0;
}