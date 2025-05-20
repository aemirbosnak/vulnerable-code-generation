//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node** root, char symbol, int frequency) {
    Node* newNode = malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
    } else {
        Node* current = *root;
        Node* parent = NULL;
        while (current) {
            if (newNode->frequency < current->frequency) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        }

        if (parent) {
            if (parent->left) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }
}

void traverseTree(Node* root) {
    if (root) {
        printf("%c ", root->symbol);
        traverseTree(root->left);
        traverseTree(root->right);
    }
}

int main() {
    Node* root = NULL;
    insertNode(&root, 'a', 5);
    insertNode(&root, 'b', 3);
    insertNode(&root, 'c', 4);
    insertNode(&root, 'd', 2);
    insertNode(&root, 'e', 4);

    traverseTree(root);

    return 0;
}