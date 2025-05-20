//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 1000

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

void huffmanEncode(Node* node, char* encodedString) {
    if (node) {
        encodedString[0] = '\0';
        huffmanEncode(node->left, encodedString);
        huffmanEncode(node->right, encodedString);

        char leftCode = encodedString[0];
        char rightCode = encodedString[1];

        char frequency = '0' + node->frequency;
        char character = node->character;

        sprintf(encodedString, "%c%c%c ", character, frequency, leftCode, rightCode);

        printf("%s ", encodedString);
    }
}

int main() {
    Node* node = insertNode(NULL, 'a', 10);
    insertNode(node, 'b', 5);
    insertNode(node, 'c', 15);
    insertNode(node, 'd', 20);
    insertNode(node, 'e', 12);

    char* encodedString = (char*)malloc(100);

    huffmanEncode(node, encodedString);

    return 0;
}