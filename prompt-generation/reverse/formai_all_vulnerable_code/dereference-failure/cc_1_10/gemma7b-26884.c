//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 256
#define MAX_FILE_NAME_LEN 256

typedef struct Node {
    char name[MAX_FILE_NAME_LEN];
    struct Node* next;
    struct Node* dir;
    FILE* file;
} Node;

Node* newNode(char* name)
{
    Node* node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    node->file = NULL;
    return node;
}

void insertNode(Node* node, Node* newNode)
{
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

void listDirectory(Node* node)
{
    printf("Directory:");
    while (node) {
        printf("/%s ", node->name);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Node* root = newNode("root");
    insertNode(root, newNode("home"));
    insertNode(root, newNode("documents"));
    insertNode(root->dir->dir, newNode("my_file.txt"));

    listDirectory(root);

    return 0;
}