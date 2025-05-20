//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODE 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node* node, char character, int frequency) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
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
    if (node->left == NULL && node->right == NULL) {
        encoded_string[0] = node->character;
        encoded_string[1] = '\0';
    } else {
        char left_code[256] = "";
        char right_code[256] = "";
        huffman_encode(node->left, left_code);
        huffman_encode(node->right, right_code);
        sprintf(encoded_string, "%s%s", left_code, right_code);
    }
}

int main() {
    char text[] = "This is a sample text for huffman coding.";
    Node* root = NULL;
    insert(root, text[0], 1);
    for (int i = 1; text[i] != '\0'; i++) {
        insert(root, text[i], 1);
    }

    char encoded_string[256] = "";
    huffman_encode(root, encoded_string);

    printf("Encoded string: %s\n", encoded_string);

    return 0;
}