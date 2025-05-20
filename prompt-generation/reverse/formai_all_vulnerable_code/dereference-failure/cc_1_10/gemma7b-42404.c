//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: standalone
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

Node* newNode(char* name) {
    Node* node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    return node;
}

void addDir(Node* node, char* dirName) {
    Node* newDir = newNode(dirName);
    node->dir = newDir;
}

void addFile(Node* node, char* fileName) {
    Node* newFile = newNode(fileName);
    node->dir->next = newFile;
}

int main() {
    Node* root = newNode("Root");
    addDir(root, "Directory A");
    addDir(root, "Directory B");
    addDir(root, "Directory C");

    addFile(root->dir->next, "File 1.txt");
    addFile(root->dir->next, "File 2.txt");
    addFile(root->dir->next->next, "File 3.txt");

    printf("Directory List:");
    for (Node* dir = root->dir; dir; dir = dir->next) {
        printf("\n%s", dir->name);
        for (Node* file = dir->next; file; file = file->next) {
            printf("\t%s", file->name);
        }
    }

    return 0;
}