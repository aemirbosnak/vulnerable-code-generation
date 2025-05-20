//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 255
#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILE_SIZE 1024

#define ROOT_DIR_NAME "/"

typedef struct Node {
    char dir_name[MAX_DIR_NAME_LENGTH];
    struct Node* next;
    struct Node* child;
} Node;

Node* newNode(char* dir_name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->dir_name, dir_name);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void insertDir(Node* node, char* dir_name) {
    if (node == NULL) {
        node = newNode(dir_name);
        node->next = NULL;
        node->child = NULL;
        return;
    }

    if (strcmp(dir_name, node->dir_name) == 0) {
        return;
    }

    if (node->child == NULL) {
        insertDir(node, dir_name);
    } else {
        insertDir(node->child, dir_name);
    }
}

void listDir(Node* node) {
    if (node != NULL) {
        printf("%s\n", node->dir_name);
        listDir(node->child);
    }
}

int main() {
    Node* root = newNode(ROOT_DIR_NAME);
    insertDir(root, "home");
    insertDir(root, "documents");
    insertDir(root, "pictures");
    insertDir(root, "music");

    listDir(root);

    return 0;
}