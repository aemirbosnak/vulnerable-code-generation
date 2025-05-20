//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(char character, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *createTree(char *string) {
    int length = strlen(string);
    int frequencies[256] = {0};
    for (int i = 0; i < length; i++) {
        frequencies[string[i]]++;
    }

    Node *nodes[256];
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[i] = createNode(i, frequencies[i]);
        }
    }

    while (nodes[0] != NULL) {
        Node *left = nodes[0];
        Node *right = nodes[1];
        for (int i = 2; i < 256; i++) {
            if (nodes[i] != NULL && nodes[i]->frequency < left->frequency) {
                left = nodes[i];
            }
            if (nodes[i] != NULL && nodes[i]->frequency < right->frequency) {
                right = nodes[i];
            }
        }

        Node *parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        for (int i = 0; i < 256; i++) {
            if (nodes[i] == left || nodes[i] == right) {
                nodes[i] = NULL;
            }
        }

        nodes[0] = parent;
    }

    return nodes[0];
}

void encode(Node *tree, char character, char *code, int length) {
    if (tree->left == NULL && tree->right == NULL) {
        if (tree->character == character) {
            printf("%s", code);
        }
        return;
    }

    code[length] = '0';
    encode(tree->left, character, code, length + 1);

    code[length] = '1';
    encode(tree->right, character, code, length + 1);
}

void decode(Node *tree, char *code) {
    int length = strlen(code);
    Node *current = tree;
    for (int i = 0; i < length; i++) {
        if (code[i] == '0') {
            current = current->left;
        } else if (code[i] == '1') {
            current = current->right;
        }
    }

    if (current->left == NULL && current->right == NULL) {
        printf("%c", current->character);
    }
}

int main() {
    char string[] = "Hello world";
    Node *tree = createTree(string);
    char code[256];
    for (int i = 0; i < strlen(string); i++) {
        encode(tree, string[i], code, 0);
    }

    printf("%s", code);

    printf("\n");

    decode(tree, code);

    return 0;
}