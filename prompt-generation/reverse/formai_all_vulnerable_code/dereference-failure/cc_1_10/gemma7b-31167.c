//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insert(struct Node* node, char character, int frequency) {
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    } else if (character < node->character) {
        node->left = insert(node->left, character, frequency);
    } else {
        node->right = insert(node->right, character, frequency);
    }

    return node;
}

void huffman_encode(struct Node* node, char* encoded_string) {
    if (node->left == NULL && node->right == NULL) {
        encoded_string[0] = node->character;
        encoded_string[1] = '\0';
    } else {
        huffman_encode(node->left, encoded_string);
        huffman_encode(node->right, encoded_string);

        int left_length = strlen(encoded_string);
        char left_code[left_length + 1];
        strcpy(left_code, encoded_string);

        int right_length = strlen(encoded_string);
        char right_code[right_length + 1];
        strcpy(right_code, encoded_string);

        char encoded_character = node->character;
        encoded_string[0] = encoded_character;
        encoded_string[1] = left_code[0] == right_code[0] ? '/' : '\\';
        encoded_string[2] = '\0';
    }
}

int main() {
    struct Node* root = insert(NULL, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    char* encoded_string = malloc(MAX_TREE_HEIGHT);

    huffman_encode(root, encoded_string);

    printf("%s\n", encoded_string);

    return 0;
}