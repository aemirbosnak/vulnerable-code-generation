//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1024

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char character;
    int frequency;
} Node;

Node* insertNode(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->character = character;
        node->frequency = frequency;
    } else if (frequency < node->frequency) {
        node->left = insertNode(node->left, character, frequency);
    } else {
        node->right = insertNode(node->right, character, frequency);
    }

    return node;
}

void huffmanCoding(Node* node) {
    printf("Character: %c, Frequency: %d, Code: ", node->character, node->frequency);
    if (node->left) {
        printf("%c ", node->left->character);
    }
    if (node->right) {
        printf("%c ", node->right->character);
    }
    printf("\n");
}

int main() {
    Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    huffmanCoding(root);

    return 0;
}