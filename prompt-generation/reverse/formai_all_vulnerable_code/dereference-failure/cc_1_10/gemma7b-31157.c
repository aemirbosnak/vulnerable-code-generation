//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file system node
typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* child;
    int isDir;
    FILE* file;
} Node;

// Function to create a new file system node
Node* newNode(char* name, int isDir, FILE* file) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->child = NULL;
    node->isDir = isDir;
    node->file = file;
    return node;
}

// Function to traverse the file system
void traverse(Node* node) {
    printf("%s ", node->name);
    if (node->child) {
        traverse(node->child);
    }
    if (node->next) {
        traverse(node->next);
    }
}

int main() {
    // Create a root node
    Node* root = newNode("root", 1, NULL);

    // Create a few directories
    newNode("dir1", 1, NULL);
    newNode("dir2", 1, NULL);
    newNode("dir3", 1, NULL);

    // Create a few files
    newNode("file1.txt", 0, fopen("file1.txt", "w"));
    newNode("file2.txt", 0, fopen("file2.txt", "w"));
    newNode("file3.txt", 0, fopen("file3.txt", "w"));

    // Traverse the file system
    traverse(root);

    return 0;
}