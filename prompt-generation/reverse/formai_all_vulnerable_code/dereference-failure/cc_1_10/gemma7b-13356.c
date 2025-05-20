//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
} Node;

void createNode(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->next = NULL;
    (*head)->dir = NULL;
}

void insertFile(Node* node, char* filename) {
    struct Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, filename);
    newNode->next = node->next;
    node->next = newNode;
}

void listFiles(Node* node) {
    struct Node* current = node->next;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
}

int main() {
    Node* root = NULL;
    createNode(&root);

    insertFile(root, "file1.txt");
    insertFile(root, "file2.txt");
    insertFile(root, "folder1");

    insertFile(root->dir, "file3.txt");
    insertFile(root->dir, "file4.txt");

    listFiles(root);

    printf("\n");
    listFiles(root->dir);

    return 0;
}