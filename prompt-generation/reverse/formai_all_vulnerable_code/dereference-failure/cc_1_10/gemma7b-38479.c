//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
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

void insertNode(Node* node, char* name) {
    Node* newNode = createNode(name);
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

void traverseDirectory(Node* dir) {
    printf("%s\n", dir->name);
    Node* file = dir->dir;
    while (file) {
        printf("%s\n", file->name);
        file = file->next;
    }
}

int main() {
    Node* root = NULL;
    insertNode(root, "home");
    insertNode(root, "documents");
    insertNode(root, "pictures");
    insertNode(root, "music");

    traverseDirectory(root->next);

    return 0;
}