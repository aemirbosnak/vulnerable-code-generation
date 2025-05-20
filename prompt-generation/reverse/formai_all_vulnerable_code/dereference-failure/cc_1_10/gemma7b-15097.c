//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char character;
    int frequency;
} Node;

void insertNode(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->character = character;
        node->frequency = frequency;
    } else if (frequency < node->frequency) {
        insertNode(node->left, character, frequency);
    } else {
        insertNode(node->right, character, frequency);
    }
}

void huffmanEncode(Node* node, char* buffer) {
    if (node->left == NULL && node->right == NULL) {
        buffer[0] = node->character;
        buffer[1] = '\0';
    } else {
        huffmanEncode(node->left, buffer);
        huffmanEncode(node->right, buffer);
        sprintf(buffer, "%s%c", buffer, node->character);
    }
}

int main() {
    Node* root = NULL;
    insertNode(root, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    char buffer[1024] = "";
    huffmanEncode(root, buffer);

    printf("%s", buffer);

    return 0;
}