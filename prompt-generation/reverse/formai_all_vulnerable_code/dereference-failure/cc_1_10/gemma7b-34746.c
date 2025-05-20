//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 1024

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
    int size;
} Node;

Node* newNode(char* name, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
    newNode->size = size;
    return newNode;
}

void addDir(Node* node, char* name) {
    Node* newDir = newNode(name, MAX_DIR_SIZE);
    node->dir = newDir;
}

void addFile(Node* node, char* name, int size) {
    Node* newFile = newNode(name, size);
    node->dir->next = newFile;
}

void ls(Node* node) {
    printf("%s:\n", node->name);
    for (Node* dir = node->dir; dir; dir = dir->next) {
        printf("  %s\n", dir->name);
    }
    for (Node* file = node->dir->next; file; file = file->next) {
        printf("  %s (%d bytes)\n", file->name, file->size);
    }
}

int main() {
    Node* root = newNode("root", MAX_DIR_SIZE);
    addDir(root, "home");
    addDir(root, "data");
    addDir(root, "tmp");

    addFile(root->dir->next, "my_file.txt", 128);
    addFile(root->dir->next, "another_file.txt", 512);

    ls(root);

    return 0;
}