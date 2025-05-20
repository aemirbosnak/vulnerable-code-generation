//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* child;
} Node;

Node* root = NULL;

void createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->child = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        Node* current = root;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void listFiles(Node* node) {
    printf("%s\n", node->name);

    if (node->child) {
        listFiles(node->child);
    }
}

int main() {
    createNode("home");
    createNode("home/Documents");
    createNode("home/Pictures");
    createNode("home/Downloads");

    listFiles(root);

    return 0;
}