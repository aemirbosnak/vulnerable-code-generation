//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct Node {
    char *dir_name;
    struct Node *next;
    struct Node *children;
} Node;

void createDirectory(Node *node, char *dir_name) {
    char *new_dir_name = malloc(MAX_DIR_NAME_LENGTH);
    strcpy(new_dir_name, dir_name);

    Node *new_child = malloc(sizeof(Node));
    new_child->dir_name = new_dir_name;
    new_child->next = NULL;
    new_child->children = NULL;

    if (node->children == NULL) {
        node->children = new_child;
    } else {
        Node *current = node->children;
        while (current->next) {
            current = current->next;
        }
        current->next = new_child;
    }
}

void listDirectory(Node *node) {
    printf("%s:", node->dir_name);
    printf("\n");

    if (node->children) {
        Node *current = node->children;
        while (current) {
            listDirectory(current);
        }
    }
}

int main() {
    Node *root = malloc(sizeof(Node));
    root->dir_name = "/";
    root->next = NULL;
    root->children = NULL;

    createDirectory(root, "a");
    createDirectory(root, "b");
    createDirectory(root, "c");

    listDirectory(root);

    return 0;
}