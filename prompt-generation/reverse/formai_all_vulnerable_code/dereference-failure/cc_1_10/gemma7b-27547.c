//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node *next;
    struct Node *dir;
} Node;

Node *newNode(char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    return node;
}

void insertDir(Node *node, char *dirName) {
    Node *newDir = newNode(dirName);
    if (node->dir == NULL) {
        node->dir = newDir;
    } else {
        node->dir->next = newDir;
        node->dir = newDir;
    }
}

void insertFile(Node *node, char *fileName) {
    Node *newFile = newNode(fileName);
    if (node->dir == NULL) {
        insertDir(node, "/");
    }
    insertDir(node->dir, fileName);
}

void listDir(Node *node) {
    printf("Directory: ");
    for (Node *dir = node->dir; dir; dir = dir->next) {
        printf("%s ", dir->name);
    }
    printf("\n");
}

int main() {
    Node *root = newNode("/");
    insertDir(root, "/home");
    insertDir(root, "/usr");
    insertDir(root, "/var");
    insertFile(root, "/home/user/my_file.txt");
    insertFile(root, "/usr/local/bin/bash");
    listDir(root);

    return 0;
}