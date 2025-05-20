//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 1024

typedef struct Node {
    char name[256];
    struct Node* parent;
    struct Node** children;
    int size;
    FILE* file;
} Node;

Node* newNode(char* name, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->parent = parent;
    node->children = NULL;
    node->size = 0;
    node->file = NULL;
    return node;
}

void addChild(Node* parent, Node* child) {
    parent->children = (Node**)realloc(parent->children, (parent->size + 1) * sizeof(Node*));
    parent->children[parent->size++] = child;
}

void listDirectory(Node* node) {
    printf("%s\n", node->name);
    for (int i = 0; i < node->size; i++) {
        listDirectory(node->children[i]);
    }
}

int main() {
    Node* root = newNode("root", NULL);
    Node* dir1 = newNode("dir1", root);
    Node* dir2 = newNode("dir2", root);
    Node* file1 = newNode("file1.txt", dir1);
    Node* file2 = newNode("file2.txt", dir2);

    addChild(root, dir1);
    addChild(root, dir2);
    addChild(dir1, file1);
    addChild(dir2, file2);

    listDirectory(root);

    return 0;
}