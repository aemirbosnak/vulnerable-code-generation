//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 512

typedef struct Node {
    char name[256];
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
    Node* dirNode = newNode(dirName);
    dirNode->dir = node;
    node->dir = dirNode;
}

void addFile(Node* node, char* fileName) {
    FILE* file = fopen(fileName, "w");
    node->file = file;
}

void listDir(Node* node) {
    printf("%s:\n", node->name);
    for (Node* dirNode = node->dir; dirNode; dirNode = dirNode->next) {
        printf("  %s\n", dirNode->name);
    }
    for (Node* fileNode = node->file; fileNode; fileNode = fileNode->next) {
        printf("  %s\n", fileNode->name);
    }
}

int main() {
    Node* root = newNode("/");
    addDir(root, "home");
    addDir(root, "data");
    addDir(root, "tmp");
    addFile(root->dir->dir, "test.txt");
    listDir(root);

    return 0;
}