//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

typedef struct Node {
    int id;
    char name[20];
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(Tree* tree, int id, const char* name) {
    Node* newNode = createNode(id, name);
    if (!tree->root) {
        tree->root = newNode;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;
    while (1) {
        parent = current;
        if (id < current->id) {
            current = current->left;
            if (!current) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (!current) {
                parent->right = newNode;
                return;
            }
        }
    }
}

void inorderTraversal(Node* node) {
    if (node) {
        inorderTraversal(node->left);
        printf("Node ID: %d, Name: %s\n", node->id, node->name);
        inorderTraversal(node->right);
    }
}

void visualizeTree(Node* node, int space) {
    if (node == NULL) return;

    space += 10; 

    visualizeTree(node->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->id);

    visualizeTree(node->left, space);
}

void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    Tree tree;
    tree.root = NULL;

    addNode(&tree, 5, "Root");
    addNode(&tree, 3, "Left Child");
    addNode(&tree, 8, "Right Child");
    addNode(&tree, 1, "Left Left Child");
    addNode(&tree, 4, "Left Right Child");
    addNode(&tree, 6, "Right Left Child");
    addNode(&tree, 9, "Right Right Child");

    printf("Inorder Traversal of the Tree:\n");
    inorderTraversal(tree.root);
    
    printf("\nVisual Representation of the Tree:\n");
    visualizeTree(tree.root, 0);

    freeTree(tree.root);
    return 0;
}