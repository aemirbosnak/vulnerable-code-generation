//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 1024

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
        buffer[0] = '\0';
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);

        char prefix[2];
        prefix[0] = node->character;
        prefix[1] = '\0';
        strcat(buffer, prefix);
    }
}

int main() {
    struct Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    char buffer[1024];
    huffmanEncode(root, buffer);

    printf("%s", buffer);

    return 0;
}