//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1024

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insert(struct Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        node->left = insert(node->left, character, frequency);
    } else if (character > node->character) {
        node->right = insert(node->right, character, frequency);
    } else {
        node->frequency++;
    }

    return node;
}

void huffman_encode(struct Node* node, int index, char* buffer) {
    if (node != NULL) {
        buffer[index] = node->character;
        huffman_encode(node->left, index + 1, buffer);
        huffman_encode(node->right, index + 1, buffer);
    }
}

int main() {
    struct Node* root = insert(NULL, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    char* buffer = malloc(MAX_TREE_SIZE);
    huffman_encode(root, 0, buffer);

    printf("%s", buffer);

    return 0;
}