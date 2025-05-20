//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insertNode(struct Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
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

void huffmanEncode(struct Node* node, char* buffer) {
    if (node) {
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);

        int length = node->frequency * 8;
        buffer[length] = node->character;
    }
}

int main() {
    struct Node* root = insertNode(NULL, 'a', 10);
    insertNode(root, 'b', 5);
    insertNode(root, 'c', 15);
    insertNode(root, 'd', 20);

    char* buffer = malloc(MAX_TREE_HEIGHT);

    huffmanEncode(root, buffer);

    printf("%s", buffer);

    return 0;
}