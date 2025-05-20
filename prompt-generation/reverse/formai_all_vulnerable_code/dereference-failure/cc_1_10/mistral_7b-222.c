//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH + 1];
    int height;
    struct Node *left, *right;
} Node;

Node *newNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->height = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(Node *node) {
    if (node == NULL)
        return -1;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int updateHeight(Node *node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node *rotateRight(Node *p) {
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    updateHeight(p);
    updateHeight(q);
    return q;
}

Node *insert(Node *node, const char *name) {
    if (node == NULL)
        return newNode(name);

    if (strcmp(name, node->name) < 0) {
        node->left = insert(node->left, name);
    } else {
        node->right = insert(node->right, name);
    }

    updateHeight(node);

    return node;
}

void depthFirstSearch(Node *node, int visited[], int *numVisited) {
    if (node == NULL)
        return;

    visited[*numVisited] = 1;
    printf("%s ", node->name);
    (*numVisited)++;

    depthFirstSearch(node->left, visited, numVisited);
    depthFirstSearch(node->right, visited, numVisited);
}

int main() {
    srand(time(NULL));
    int numElements = 10;
    Node *root = NULL;
    char names[numElements][MAX_NAME_LENGTH];
    int visited[numElements];
    int numVisited = 0;

    printf("Inserting %d random names into the binary search tree:\n", numElements);

    for (int i = 0; i < numElements; ++i) {
        snprintf(names[i], sizeof(names[i]), "Name%d", i);
        root = insert(root, names[i]);
    }

    printf("\nDepth first search traversal:\n");
    depthFirstSearch(root, visited, &numVisited);
    printf("\n");

    free(root);

    return 0;
}