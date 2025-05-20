//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

void createDir(Node* node, char* dirName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, dirName);
    newNode->next = NULL;
    newNode->dir = node;
    node->dir->next = newNode;
}

void createFile(Node* node, char* fileName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, fileName);
    newNode->next = NULL;
    newNode->dir = node;
    node->dir->next = newNode;
}

void listDir(Node* node) {
    printf("Directory: ");
    for (Node* i = node->dir; i; i = i->next) {
        printf("%s ", i->name);
    }
    printf("\n");
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->next = NULL;
    root->dir = NULL;

    createDir(root, "home");
    createDir(root, "bin");
    createDir(root, "tmp");

    createFile(root->dir->next, "a.txt");
    createFile(root->dir->next, "b.txt");
    createFile(root->dir->next, "c.txt");

    listDir(root);

    return 0;
}