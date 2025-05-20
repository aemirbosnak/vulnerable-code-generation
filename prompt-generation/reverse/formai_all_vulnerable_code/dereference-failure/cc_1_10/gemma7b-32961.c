//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR_NAME_LENGTH 255
#define MAX_FILE_NAME_LENGTH 255

typedef struct Node {
    char *name;
    struct Node *next;
    struct Node *child;
} Node;

typedef struct Directory {
    char *name;
    Node **children;
    struct Directory *next;
} Directory;

Directory *createDirectory(char *name) {
    Directory *newDir = (Directory *)malloc(sizeof(Directory));
    newDir->name = strdup(name);
    newDir->children = NULL;
    newDir->next = NULL;

    return newDir;
}

void addChildToDirectory(Directory *dir, Node *node) {
    node->child = NULL;
    node->next = dir->children;
    dir->children = node;
}

Node *createNode(char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->next = NULL;
    newNode->child = NULL;

    return newNode;
}

void listDirectory(Directory *dir) {
    for (Node *node = dir->children; node; node = node->next) {
        printf("%s ", node->name);
    }

    printf("\n");
}

int main() {
    Directory *root = createDirectory("The Dream Library");
    Node *book1 = createNode("The Lord of the Flies");
    Node *book2 = createNode("The Great Gatsby");
    addChildToDirectory(root, book1);
    addChildToDirectory(root, book2);

    listDirectory(root);

    return 0;
}