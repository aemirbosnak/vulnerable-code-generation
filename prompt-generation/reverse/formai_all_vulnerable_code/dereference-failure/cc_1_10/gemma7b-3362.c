//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    char character;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insert(struct Node* node, char character) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->character = character;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        node->left = insert(node->left, character);
    } else {
        node->right = insert(node->right, character);
    }

    return node;
}

void huffman_encode(struct Node* node, char* buffer, int index) {
    if (node == NULL) {
        return;
    }

    buffer[index] = node->character;
    index++;

    huffman_encode(node->left, buffer, index);
    huffman_encode(node->right, buffer, index);
}

int main() {
    struct Node* root = insert(NULL, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');

    char* buffer = (char*)malloc(MAX);
    int index = 0;

    huffman_encode(root, buffer, index);

    printf("%s", buffer);

    return 0;
}