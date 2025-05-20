//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct node {
    char name[50];
    struct node* next;
};

// Function to create a new node
struct node* createNode(const char* name) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to print the file system
void printFileSystem(struct node* root) {
    printf("File System:\n");
    struct node* current = root;
    while (current!= NULL) {
        printf("Directory: %s\n", current->name);
        current = current->next;
    }
}

// Function to create a new directory
void createDirectory(struct node* root, const char* name) {
    struct node* newNode = createNode(name);
    if (root == NULL) {
        root = newNode;
    } else {
        struct node* current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to create a new file
void createFile(struct node* root, const char* name, const char* content) {
    struct node* newNode = createNode(name);
    newNode->next = NULL;
    if (root == NULL) {
        root = newNode;
    } else {
        struct node* current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the content of a file
void printFile(struct node* root, const char* name) {
    struct node* current = root;
    while (current->name!= name) {
        current = current->next;
    }
    printf("File content: %s\n", current->name);
}

int main() {
    struct node* root = NULL;
    createDirectory(root, "root");
    createFile(root, "file1.txt", "Hello, world!");
    createFile(root, "file2.txt", "This is a test file.");
    printf("File System:\n");
    printFileSystem(root);
    printf("File content: %s\n", root->name);
    return 0;
}