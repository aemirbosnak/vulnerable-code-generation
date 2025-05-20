//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: unmistakable
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

void traverse(Node* node) {
    printf("%s ", node->name);
    if (node->dir) {
        traverse(node->dir);
    }
    printf("\n");
}

int main() {
    Node* root = NULL;

    // Create a root node
    root = (Node*)malloc(sizeof(Node));
    strcpy(root->name, "root");
    root->dir = NULL;
    root->next = NULL;

    // Create a few directories
    Node* dir1 = (Node*)malloc(sizeof(Node));
    strcpy(dir1->name, "dir1");
    dir1->dir = NULL;
    dir1->next = NULL;
    root->dir = dir1;

    Node* dir2 = (Node*)malloc(sizeof(Node));
    strcpy(dir2->name, "dir2");
    dir2->dir = NULL;
    dir2->next = NULL;
    dir1->dir = dir2;

    // Create a few files
    Node* file1 = (Node*)malloc(sizeof(Node));
    strcpy(file1->name, "file1.txt");
    file1->dir = dir1;
    file1->next = NULL;

    Node* file2 = (Node*)malloc(sizeof(Node));
    strcpy(file2->name, "file2.txt");
    file2->dir = dir2;
    file2->next = NULL;

    // Traverse the file system
    traverse(root);

    return 0;
}