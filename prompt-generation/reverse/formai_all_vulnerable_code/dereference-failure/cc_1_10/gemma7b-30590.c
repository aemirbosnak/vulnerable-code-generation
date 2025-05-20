//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: futuristic
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

struct Node* createNode(char* name) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
    return newNode;
}

void addDir(struct Node* node, char* dirName) {
    struct Node* newDir = createNode(dirName);
    if (node->dir == NULL) {
        node->dir = newDir;
    } else {
        node->dir->next = newDir;
        node->dir = newDir;
    }
}

void addFile(struct Node* node, char* fileName) {
    struct Node* newFile = createNode(fileName);
    if (node->dir == NULL) {
        printf("Error: No directory selected.");
        return;
    }
    addDir(node->dir, fileName);
}

void listDir(struct Node* node) {
    struct Node* currentDir = node->dir;
    while (currentDir) {
        printf("%s\n", currentDir->name);
        currentDir = currentDir->next;
    }
}

void main() {
    struct Node* root = createNode("C:\\");
    addDir(root, "Users");
    addDir(root, "Documents");
    addDir(root, "Pictures");
    addFile(root, "Users\\John Doe\\Documents\\My Document.txt");
    addFile(root, "Pictures\\My Picture.jpg");
    listDir(root);
}