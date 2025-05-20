//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char name[MAX_FILE_NAME_LEN];
    struct Node* next;
    struct Node* parent;
    int isDirectory;
} Node;

Node* newNode(char* name, int isDirectory) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->parent = NULL;
    newNode->isDirectory = isDirectory;
    return newNode;
}

void insertNode(Node* parent, Node* newNode) {
    if (parent) {
        parent->next = newNode;
        newNode->parent = parent;
    }
}

void listDir(Node* node) {
    if (node) {
        printf("%s ", node->name);
        if (node->isDirectory) {
            printf("/\n");
        }
        listDir(node->next);
    }
}

int main() {
    Node* root = newNode("root", 1);
    insertNode(root, newNode("dir1", 1));
    insertNode(root, newNode("file1.txt", 0));
    insertNode(root, newNode("dir2", 1));
    insertNode(root, newNode("file2.txt", 0));

    listDir(root);

    return 0;
}