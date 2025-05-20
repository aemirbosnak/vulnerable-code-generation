//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
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

void huffmanEncode(struct Node* node, char* encoded_string) {
    if (node != NULL) {
        encoded_string[0] = '\0';
        huffmanEncode(node->left, encoded_string);
        huffmanEncode(node->right, encoded_string);

        char left_code[MAX_TREE_SIZE] = "";
        char right_code[MAX_TREE_SIZE] = "";

        sprintf(left_code, "%s0", node->left->character);
        sprintf(right_code, "%s1", node->right->character);

        char encoded_character[MAX_TREE_SIZE] = "";
        sprintf(encoded_character, "%s%s", left_code, right_code);

        strcat(encoded_string, encoded_character);
    }
}

int main() {
    struct Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 4);
    insertNode(root, 'e', 6);

    char encoded_string[MAX_TREE_SIZE] = "";

    huffmanEncode(root, encoded_string);

    printf("%s\n", encoded_string);

    return 0;
}