//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1024

typedef struct Node {
    char symbol;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, char symbol) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->symbol = symbol;
        node->left = NULL;
        node->right = NULL;
    } else if (symbol < node->symbol) {
        node->left = insert(node->left, symbol);
    } else {
        node->right = insert(node->right, symbol);
    }
    return node;
}

void huffman_encode(Node* node, char* buffer, int index) {
    if (node) {
        huffman_encode(node->left, buffer, index * 2);
        huffman_encode(node->right, buffer, index * 2 + 1);

        buffer[index] = node->symbol;
        buffer[index + 1] = node->symbol == '\n' ? '\0' : '0' + index;
    }
}

int main() {
    Node* root = insert(NULL, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');
    insert(root, 'f');
    insert(root, '\n');

    char buffer[1024];
    huffman_encode(root, buffer, 0);

    printf("%s", buffer);

    return 0;
}