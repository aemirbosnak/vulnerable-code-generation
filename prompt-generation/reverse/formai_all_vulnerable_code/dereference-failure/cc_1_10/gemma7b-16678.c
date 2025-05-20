//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: visionary
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
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    node->file = NULL;
    return node;
}

void insertDir(Node* node, Node* newNode) {
    if (node->dir == NULL) {
        node->dir = newNode;
    } else {
        insertDir(node->dir, newNode);
    }
}

void insertFile(Node* node, Node* newNode) {
    if (node->file == NULL) {
        node->file = newNode;
    } else {
        insertFile(node->file, newNode);
    }
}

void printDir(Node* node) {
    printf("%s\n", node->name);
    if (node->dir) {
        printDir(node->dir);
    }
}

int main() {
    Node* root = newNode("root");
    insertDir(root, newNode("home"));
    insertDir(root, newNode("data"));
    insertDir(root, newNode("documents"));
    insertFile(root->dir->dir->dir, newNode("my_document.txt"));
    insertFile(root->dir->dir, newNode("image.jpg"));

    printDir(root);

    return 0;
}