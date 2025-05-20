//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: multivariable
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

void createDir(Node* node, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = node;
    node->dir->next = newNode;
}

void createFile(Node* dirNode, char* name, char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = dirNode;
    dirNode->next = newNode;
    FILE* file = fopen(newNode->name, "w");
    fprintf(file, content);
    fclose(file);
}

void listDir(Node* node) {
    printf("Directory: ");
    for (node = node->dir; node; node = node->next) {
        printf("%s ", node->name);
    }
    printf("\n");
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->next = NULL;
    root->dir = NULL;

    createDir(root, "home");
    createDir(root->dir, "documents");
    createDir(root->dir, "pictures");
    createFile(root->dir->dir, "mydocument.txt", "This is a document.");
    createFile(root->dir->dir, "mypicture.jpg", "This is a picture.");

    listDir(root);

    return 0;
}