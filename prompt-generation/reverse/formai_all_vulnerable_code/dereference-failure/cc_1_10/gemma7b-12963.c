//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

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

void huffmanEncode(Node* node, char* buffer) {
    if (node) {
        buffer[0] = '\0';
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);

        sprintf(buffer, "%s%c", buffer, node->character);
        printf("%s", buffer);
    }
}

int main() {
    Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 3);

    char buffer[256];
    huffmanEncode(root, buffer);

    return 0;
}