//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insert(struct Node* node, char symbol, int frequency) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->symbol = symbol;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (symbol < node->symbol) {
        node->left = insert(node->left, symbol, frequency);
    } else {
        node->right = insert(node->right, symbol, frequency);
    }

    return node;
}

void huffman_encode(struct Node* node, char* buffer) {
    if (node) {
        huffman_encode(node->left, buffer);
        huffman_encode(node->right, buffer);

        int i = 0;
        char prefix[MAX_TREE_HT];
        prefix[0] = '\0';

        while (node->symbol) {
            prefix[i++] = node->symbol;
            node->symbol = prefix[0];
            buffer[node->frequency] = prefix;
            node->frequency--;
        }
    }
}

int main() {
    struct Node* root = insert(NULL, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    char buffer[MAX_TREE_HT];

    huffman_encode(root, buffer);

    for (int i = 0; buffer[i] != NULL; i++) {
        printf("%s ", buffer[i]);
    }

    return 0;
}