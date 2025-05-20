//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insertNode(struct Node* node, char character, int frequency) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
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

void huffmanCoding(struct Node* node) {
    printf("Character: %c, Frequency: %d, Code: ", node->character, node->frequency);
    if (node->left) {
        printf("0 ");
        huffmanCoding(node->left);
    }
    if (node->right) {
        printf("1 ");
        huffmanCoding(node->right);
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    huffmanCoding(root);

    return 0;
}