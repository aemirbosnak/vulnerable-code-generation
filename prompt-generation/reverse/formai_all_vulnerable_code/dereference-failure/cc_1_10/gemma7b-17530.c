//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertNode(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        node->left = insertNode(node->left, character, frequency);
    } else {
        node->right = insertNode(node->right, character, frequency);
    }

    return node;
}

void traverseTree(Node* node) {
    if (node) {
        printf("%c (%d) ", node->character, node->frequency);
        traverseTree(node->left);
        traverseTree(node->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 'a', 10);
    insertNode(root, 'b', 8);
    insertNode(root, 'c', 6);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 2);

    traverseTree(root);

    return 0;
}