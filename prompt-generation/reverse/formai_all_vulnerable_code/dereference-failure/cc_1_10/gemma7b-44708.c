//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char name[MAX_FILE_NAME_LEN];
    struct Node* next;
    struct Node* parent;
    char type;
    char data[MAX_FILE_NAME_LEN];
} Node;

Node* newNode(char* name, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->parent = parent;
    newNode->type = 'f';
    newNode->data[0] = '\0';
    return newNode;
}

Node* newDir(char* name, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->parent = parent;
    newNode->type = 'd';
    newNode->data[0] = '\0';
    return newNode;
}

void traverse(Node* node) {
    printf("%s (%c)\n", node->name, node->type);
    if (node->type == 'd') {
        traverse(node->next);
    }
}

int main() {
    Node* root = newDir("root", NULL);
    newNode("file1.txt", root);
    newNode("dir1", root);
    newDir("dir2", root);
    newNode("file2.txt", root);

    traverse(root);

    return 0;
}