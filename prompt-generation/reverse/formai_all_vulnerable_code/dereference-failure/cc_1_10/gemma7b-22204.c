//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
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

void insert(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        insert(node->left, character, frequency);
    } else {
        insert(node->right, character, frequency);
    }
}

void huffman_encode(Node* node, char* encoded_string) {
    if (node) {
        encoded_string[0] = '\0';
        huffman_encode(node->left, encoded_string);
        huffman_encode(node->right, encoded_string);

        int frequency = node->frequency;
        char character = node->character;
        sprintf(encoded_string, "%c%d ", character, frequency);
        strcat(encoded_string, encoded_string);
    }
}

int main() {
    Node* root = NULL;
    insert(root, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    char* encoded_string = malloc(1024);
    huffman_encode(root, encoded_string);

    printf("Encoded string: %s\n", encoded_string);

    return 0;
}