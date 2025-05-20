//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
} Node;

Node* newNode(char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
    return newNode;
}

void addDir(Node* node, char dirName[]) {
    struct Node* newDir = newNode(dirName);
    node->dir = newDir;
}

void addFile(Node* node, char fileName[]) {
    struct Node* newFile = newNode(fileName);
    node->dir->next = newFile;
}

void listDir(Node* node) {
    printf("Directory: %s\n", node->name);
    struct Node* dirNode = node->dir;
    while (dirNode) {
        printf("  %s\n", dirNode->name);
        dirNode = dirNode->next;
    }
}

void listFile(Node* node) {
    printf("Directory: %s\n", node->name);
    struct Node* dirNode = node->dir;
    while (dirNode) {
        struct Node* fileNode = dirNode->next;
        while (fileNode) {
            printf("  %s\n", fileNode->name);
            fileNode = fileNode->next;
        }
        dirNode = dirNode->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    // Create a root node
    Node* root = newNode("Root");

    // Add some directories
    addDir(root, "Documents");
    addDir(root, "Pictures");
    addDir(root, "Music");

    // Add some files to the directories
    addFile(root->dir->dir, "Document.txt");
    addFile(root->dir->dir, "Photo.jpg");
    addFile(root->dir->dir, "Song.mp3");

    // List the directories and files
    listDir(root);
    listFile(root);

    return 0;
}