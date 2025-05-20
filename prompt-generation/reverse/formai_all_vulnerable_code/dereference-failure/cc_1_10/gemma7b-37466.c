//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 256

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
    } else if (frequency < node->frequency) {
        node->left = insertNode(node->left, character, frequency);
    } else {
        node->right = insertNode(node->right, character, frequency);
    }

    return node;
}

void huffmanEncode(Node* node, char* encoded_string) {
    if (node) {
        encoded_string[0] = '\0';
        huffmanEncode(node->left, encoded_string);
        huffmanEncode(node->right, encoded_string);

        char left_code = encoded_string[0];
        char right_code = encoded_string[1];

        char character_code = node->character;
        int frequency = node->frequency;

        int i = 0;
        for (i = 0; i < frequency; i++) {
            encoded_string[i] = character_code;
            encoded_string[i + 1] = left_code;
            encoded_string[i + 2] = right_code;
        }
    }
}

int main() {
    char text[] = "This is a sample text for Huffman coding.";
    Node* node = insertNode(NULL, text[0], 1);

    for (int i = 1; i < strlen(text); i++) {
        insertNode(node, text[i], 1);
    }

    char* encoded_string = (char*)malloc(1024);
    huffmanEncode(node, encoded_string);

    printf("%s\n", encoded_string);

    return 0;
}