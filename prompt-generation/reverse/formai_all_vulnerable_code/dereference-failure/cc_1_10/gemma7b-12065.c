//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: genius
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

void huffmanEncode(struct Node* node, char* encodedString, int* encodedStringIndex) {
    if (node != NULL) {
        encodedString[*encodedStringIndex] = node->character;
        *encodedStringIndex += 1;

        if (node->left && node->right) {
            huffmanEncode(node->left, encodedString, encodedStringIndex);
            huffmanEncode(node->right, encodedString, encodedStringIndex);
        }
    }
}

int main() {
    struct Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    char* encodedString = (char*)malloc(MAX_TREE_SIZE);
    int encodedStringIndex = 0;

    huffmanEncode(root, encodedString, &encodedStringIndex);

    printf("%s", encodedString);

    return 0;
}