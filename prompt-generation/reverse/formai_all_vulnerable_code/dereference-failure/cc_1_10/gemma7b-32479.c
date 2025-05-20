//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1000

typedef struct Node {
    char character;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insertNode(struct Node* node, char character) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->character = character;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        node->left = insertNode(node->left, character);
    } else {
        node->right = insertNode(node->right, character);
    }

    return node;
}

void huffmanEncode(struct Node* node, char* buffer) {
    if (node) {
        buffer[0] = '\0';
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);

        char prefix[] = "";
        int i = 0;
        for (; prefix[i] = buffer[i]; i++) {}

        int length = strlen(prefix) + 1;
        buffer[0] = prefix[0];
        for (i = 1; i < length; i++) {
            buffer[i] = prefix[i - 1] ^ 1;
        }

        buffer[length] = '\0';
    }
}

int main() {
    struct Node* root = insertNode(NULL, 'a');
    insertNode(root, 'b');
    insertNode(root, 'c');
    insertNode(root, 'd');
    insertNode(root, 'e');

    char buffer[MAX_TREE_SIZE];
    huffmanEncode(root, buffer);

    printf("%s", buffer);

    return 0;
}