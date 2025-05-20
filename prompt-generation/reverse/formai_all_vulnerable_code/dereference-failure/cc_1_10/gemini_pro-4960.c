//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256

typedef struct {
    unsigned char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
    int size;
} HuffmanTree;

Node *createNode(unsigned char character, int frequency) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

HuffmanTree *createHuffmanTree(unsigned char *message, int length) {
    int frequencies[MAX_CHARACTERS] = {0};
    for (int i = 0; i < length; i++) {
        frequencies[message[i]]++;
    }

    Node *nodes[MAX_CHARACTERS];
    int nodeCount = 0;
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            nodes[nodeCount++] = createNode(i, frequencies[i]);
        }
    }

    while (nodeCount > 1) {
        Node *left = nodes[0];
        Node *right = nodes[1];
        for (int i = 2; i < nodeCount; i++) {
            if (left->frequency > nodes[i]->frequency) {
                left = nodes[i];
            } else if (right->frequency > nodes[i]->frequency) {
                right = nodes[i];
            }
        }

        Node *parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        nodes[nodeCount - 2] = parent;
        nodes[nodeCount - 1] = NULL;
        nodeCount--;
    }

    HuffmanTree *tree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
    tree->root = nodes[0];
    tree->size = length;
    return tree;
}

void encode(HuffmanTree *tree, unsigned char *message, int length, unsigned char **encodedMessage, int *encodedLength) {
    unsigned char *buffer = (unsigned char *) malloc(tree->size * 8);
    int bufferIndex = 0;

    for (int i = 0; i < length; i++) {
        Node *node = tree->root;
        while (node->left != NULL || node->right != NULL) {
            if (message[i] == node->character) {
                break;
            } else if (message[i] < node->character) {
                node = node->left;
                buffer[bufferIndex++] = '0';
            } else {
                node = node->right;
                buffer[bufferIndex++] = '1';
            }
        }

        while (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                buffer[bufferIndex++] = '0';
            } else {
                buffer[bufferIndex++] = '1';
                if (node->left != NULL) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
        }
    }

    *encodedMessage = buffer;
    *encodedLength = bufferIndex;
}

void decode(HuffmanTree *tree, unsigned char *encodedMessage, int length, unsigned char **decodedMessage, int *decodedLength) {
    Node *node = tree->root;
    unsigned char *buffer = (unsigned char *) malloc(tree->size);
    int bufferIndex = 0;

    for (int i = 0; i < length; i++) {
        if (encodedMessage[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            buffer[bufferIndex++] = node->character;
            node = tree->root;
        }
    }

    *decodedMessage = buffer;
    *decodedLength = bufferIndex;
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: %d\n", root->character, root->frequency);
    } else {
        printf("0: %d\n", root->frequency);
        printTree(root->left);
        printTree(root->right);
        printf("1: %d\n", root->frequency);
    }
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    unsigned char message[] = "Hello, world!";
    int length = strlen(message);

    HuffmanTree *tree = createHuffmanTree(message, length);
    printTree(tree->root);

    unsigned char *encodedMessage;
    int encodedLength;
    encode(tree, message, length, &encodedMessage, &encodedLength);

    unsigned char *decodedMessage;
    int decodedLength;
    decode(tree, encodedMessage, encodedLength, &decodedMessage, &decodedLength);

    printf("Original message: %s\n", message);
    printf("Encoded message: ");
    for (int i = 0; i < encodedLength; i++) {
        printf("%c", encodedMessage[i]);
    }
    printf("\n");
    printf("Decoded message: %s\n", decodedMessage);

    freeTree(tree->root);
    free(encodedMessage);
    free(decodedMessage);

    return 0;
}