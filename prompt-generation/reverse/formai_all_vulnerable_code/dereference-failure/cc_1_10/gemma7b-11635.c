//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* huffman_tree_insert(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (frequency < node->frequency) {
        node->left = huffman_tree_insert(node->left, character, frequency);
    } else {
        node->right = huffman_tree_insert(node->right, character, frequency);
    }

    return node;
}

void huffman_tree_traverse(Node* node) {
    printf("%c (%d) ", node->character, node->frequency);

    if (node->left) {
        huffman_tree_traverse(node->left);
    }

    if (node->right) {
        huffman_tree_traverse(node->right);
    }
}

int main() {
    Node* root = NULL;

    root = huffman_tree_insert(root, 'a', 10);
    root = huffman_tree_insert(root, 'b', 9);
    root = huffman_tree_insert(root, 'c', 8);
    root = huffman_tree_insert(root, 'd', 7);
    root = huffman_tree_insert(root, 'e', 6);

    huffman_tree_traverse(root);

    return 0;
}