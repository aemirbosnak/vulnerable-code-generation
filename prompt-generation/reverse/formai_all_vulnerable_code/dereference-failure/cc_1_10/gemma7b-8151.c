//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 1024

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char symbol;
    int frequency;
} Node;

void insertNode(Node* node, char symbol, int frequency) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->symbol = symbol;
        node->frequency = frequency;
    } else if (symbol < node->symbol) {
        insertNode(node->left, symbol, frequency);
    } else {
        insertNode(node->right, symbol, frequency);
    }
}

void huffmanEncode(Node* node, char* buffer) {
    if (node) {
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);

        int length = node->frequency * 2;
        buffer[length - 1] = node->symbol;
        buffer[length - 2] = (node->symbol == '\n' ? ' ' : '.');
    }
}

int main() {
    Node* root = NULL;

    insertNode(root, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    char buffer[MAX_TREE_Nodes] = "";

    huffmanEncode(root, buffer);

    printf("%s\n", buffer);

    return 0;
}