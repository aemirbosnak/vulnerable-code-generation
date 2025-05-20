//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR_NAME_LEN 256
#define MAX_FILE_NAME_LEN 256

typedef struct Node {
    char name[MAX_FILE_NAME_LEN];
    struct Node* next;
    struct Node* dir;
} Node;

void mkdir(Node* node, char* dirName) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->name[0] = '\0';
    newNode->next = NULL;
    newNode->dir = node;

    char* newDirName = strdup(dirName);
    strcpy(newNode->name, newDirName);

    if (node->dir) {
        node->dir->next = newNode;
    } else {
        node->dir = newNode;
    }
}

void listDir(Node* node) {
    struct Node* currentDir = node->dir;
    while (currentDir) {
        printf("%s\n", currentDir->name);
        currentDir = currentDir->next;
    }
}

int main() {
    Node* root = malloc(sizeof(struct Node));
    root->name[0] = '\0';
    root->next = NULL;
    root->dir = NULL;

    mkdir(root, "test");
    mkdir(root, "test/sub");
    mkdir(root, "test/sub/nested");

    listDir(root);

    return 0;
}