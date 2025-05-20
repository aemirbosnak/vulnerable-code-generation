//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>

#define PORT 8080

struct node {
    char name[256];
    struct node* next;
    struct node* child;
    int isDirectory;
    int socketFd;
    FILE* filePtr;
};

void createNode(struct node* node, char* name, int isDirectory, int socketFd) {
    strcpy(node->name, name);
    node->isDirectory = isDirectory;
    node->socketFd = socketFd;
    node->filePtr = NULL;
    node->next = NULL;
    node->child = NULL;
}

void listDirectory(struct node* node) {
    if (node->isDirectory) {
        printf("%s\n", node->name);
        struct node* child = node->child;
        while (child) {
            listDirectory(child);
            child = child->next;
        }
    }
}

int main() {
    struct node* root = NULL;

    // Create a new directory
    createNode(root, "home", 1, 0);

    // Create a new file
    createNode(root, "home/test.txt", 0, 0);

    // List the directory
    listDirectory(root);

    return 0;
}