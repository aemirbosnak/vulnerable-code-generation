//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 10

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* child;
} Node;

void createDir(Node* node, char* dirName) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, dirName);
    newNode->next = NULL;
    newNode->child = NULL;
    node->child = newNode;
}

void createFile(Node* node, char* fileName, char* content) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, fileName);
    newNode->next = NULL;
    newNode->child = NULL;
    node->child = newNode;
    FILE* file = fopen(newNode->name, "w");
    fprintf(file, content);
    fclose(file);
}

void listFiles(Node* node) {
    for (Node* child = node->child; child; child = child->next) {
        printf("%s\n", child->name);
    }
}

int main() {
    Node* root = malloc(sizeof(Node));
    root->next = NULL;
    root->child = NULL;

    createDir(root, "test");
    createDir(root, "test/sub");
    createFile(root, "test/sub/file.txt", "This is a file");

    listFiles(root);

    return 0;
}