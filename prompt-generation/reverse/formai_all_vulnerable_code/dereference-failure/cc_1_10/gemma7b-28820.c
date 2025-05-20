//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

Node* createNode(char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
    return newNode;
}

void insertDir(Node* node, char* dirName) {
    Node* newDir = createNode(dirName);
    if (node->dir == NULL) {
        node->dir = newDir;
    } else {
        insertDir(node->dir, dirName);
    }
}

void insertFile(Node* node, char* fileName) {
    Node* newFile = createNode(fileName);
    if (node->dir == NULL) {
        insertDir(node, "");
    }
    insertDir(node->dir, fileName);
}

void listDir(Node* node) {
    printf("%s\n", node->name);
    if (node->dir) {
        listDir(node->dir);
    }
}

int main() {
    Node* root = createNode("root");
    insertDir(root, "dir1");
    insertDir(root, "dir2");
    insertFile(root, "file1.txt");
    insertFile(root, "file2.txt");

    listDir(root);

    return 0;
}