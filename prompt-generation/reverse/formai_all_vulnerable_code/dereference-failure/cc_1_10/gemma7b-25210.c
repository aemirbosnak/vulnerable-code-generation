//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 10

typedef struct Node {
    char name[20];
    struct Node* dir;
    struct Node* file;
} Node;

Node* createNode(char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->dir = NULL;
    newNode->file = NULL;
    return newNode;
}

void insertDir(Node* node, char* dirName) {
    Node* newDir = createNode(dirName);
    node->dir = newDir;
}

void insertFile(Node* node, char* fileName) {
    Node* newFile = createNode(fileName);
    node->file = newFile;
}

void listDir(Node* node) {
    printf("%s:\n", node->name);
    if (node->dir) {
        for (Node* dir = node->dir; dir; dir = dir->dir) {
            printf("  %s\n", dir->name);
        }
    }
    if (node->file) {
        for (Node* file = node->file; file; file = file->file) {
            printf("  %s\n", file->name);
        }
    }
}

int main() {
    Node* root = createNode("root");

    insertDir(root, "home");
    insertDir(root, "work");

    insertFile(root->dir->dir, "my_file.txt");
    insertFile(root->dir, "photo.jpg");

    listDir(root);

    return 0;
}