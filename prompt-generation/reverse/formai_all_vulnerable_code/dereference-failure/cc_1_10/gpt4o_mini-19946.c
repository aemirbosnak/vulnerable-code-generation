//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int id;
    char name[50];
    struct Node *left;  // left child
    struct Node *right; // right child
} Node;

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addConnection(Node* root, int parentId, int childId, const char* childName) {
    if (root == NULL) return;

    if (root->id == parentId) {
        if (root->left == NULL) {
            root->left = createNode(childId, childName);
        } else if (root->right == NULL) {
            root->right = createNode(childId, childName);
        } else {
            printf("Node %d already has two children.\n", parentId);
        }
    } else {
        addConnection(root->left, parentId, childId, childName);
        addConnection(root->right, parentId, childId, childName);
    }
}

void printTopology(Node* root, int level) {
    if (root == NULL) return;

    printTopology(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%s (ID: %d)\n", root->name, root->id);
    printTopology(root->left, level + 1);
}

void freeTopology(Node* root) {
    if (root == NULL) return;
    freeTopology(root->left);
    freeTopology(root->right);
    free(root);
}

int main() {
    Node* root = createNode(1, "Router");

    addConnection(root, 1, 2, "Switch 1");
    addConnection(root, 1, 3, "Switch 2");
    addConnection(root, 2, 4, "PC 1");
    addConnection(root, 2, 5, "PC 2");
    addConnection(root, 3, 6, "Server 1");
    addConnection(root, 3, 7, "Server 2");

    printf("Network Topology:\n");
    printTopology(root, 0);

    freeTopology(root);
    return 0;
}