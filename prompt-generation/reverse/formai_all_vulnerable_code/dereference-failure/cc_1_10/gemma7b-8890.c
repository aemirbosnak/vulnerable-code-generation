//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertNode(Node* node, char symbol, int frequency) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->symbol = symbol;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (symbol < node->symbol) {
        node->left = insertNode(node->left, symbol, frequency);
    } else {
        node->right = insertNode(node->right, symbol, frequency);
    }

    return node;
}

void huffmanCode(Node* node) {
    if (node) {
        printf("%c: ", node->symbol);
        for (int i = 0; i < node->frequency; i++) {
            printf("0");
        }
        printf("\n");
        huffmanCode(node->left);
        huffmanCode(node->right);
    }
}

int main() {
    Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    huffmanCode(root);

    return 0;
}