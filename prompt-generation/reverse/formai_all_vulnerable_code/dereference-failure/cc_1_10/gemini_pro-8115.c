//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct HuffmanNode {
    int frequency;
    char character;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct HuffmanTree {
    HuffmanNode *root;
    int size;
} HuffmanTree;

HuffmanTree* createHuffmanTree(char *message) {
    int characterFrequencies[MAX_TREE_SIZE] = {0};
    for (int i = 0; i < strlen(message); i++) {
        characterFrequencies[(int)message[i]]++;
    }

    HuffmanNode *nodes[MAX_TREE_SIZE];
    int nodeCount = 0;
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        if (characterFrequencies[i] > 0) {
            nodes[nodeCount] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
            nodes[nodeCount]->frequency = characterFrequencies[i];
            nodes[nodeCount]->character = (char)i;
            nodes[nodeCount]->left = NULL;
            nodes[nodeCount]->right = NULL;
            nodeCount++;
        }
    }

    while (nodeCount > 1) {
        HuffmanNode *smallestNode1 = NULL;
        HuffmanNode *smallestNode2 = NULL;
        int smallestFrequency1 = -1;
        int smallestFrequency2 = -1;
        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->frequency < smallestFrequency1 || smallestNode1 == NULL) {
                smallestNode2 = smallestNode1;
                smallestFrequency2 = smallestFrequency1;
                smallestNode1 = nodes[i];
                smallestFrequency1 = smallestNode1->frequency;
            } else if (nodes[i]->frequency < smallestFrequency2 || smallestNode2 == NULL) {
                smallestNode2 = nodes[i];
                smallestFrequency2 = smallestNode2->frequency;
            }
        }

        HuffmanNode *parentNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        parentNode->frequency = smallestNode1->frequency + smallestNode2->frequency;
        parentNode->character = '\0';
        parentNode->left = smallestNode1;
        parentNode->right = smallestNode2;
        nodes[nodeCount] = parentNode;
        nodeCount++;
    }

    HuffmanTree *tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    tree->root = nodes[nodeCount - 1];
    tree->size = strlen(message);
    return tree;
}

void freeHuffmanTree(HuffmanTree *tree) {
    if (tree == NULL) {
        return;
    }

    freeHuffmanTree(tree->root->left);
    freeHuffmanTree(tree->root->right);
    free(tree->root);
    free(tree);
}

void printHuffmanCode(HuffmanNode *node, char *code) {
    if (node == NULL) {
        return;
    }

    if (node->character != '\0') {
        printf("%c: %s\n", node->character, code);
        return;
    }

    char leftCode[MAX_TREE_SIZE + 1];
    strcpy(leftCode, code);
    strcat(leftCode, "0");
    printHuffmanCode(node->left, leftCode);

    char rightCode[MAX_TREE_SIZE + 1];
    strcpy(rightCode, code);
    strcat(rightCode, "1");
    printHuffmanCode(node->right, rightCode);
}

char* encodeMessage(HuffmanTree *tree, char *message) {
    char *encodedMessage = (char*)malloc(sizeof(char) * tree->size * 8);
    int encodedMessageIndex = 0;
    for (int i = 0; i < strlen(message); i++) {
        HuffmanNode *node = tree->root;
        while (node->character != message[i]) {
            if (node->left != NULL && message[i] == node->left->character) {
                node = node->left;
                encodedMessage[encodedMessageIndex] = '0';
                encodedMessageIndex++;
            } else if (node->right != NULL && message[i] == node->right->character) {
                node = node->right;
                encodedMessage[encodedMessageIndex] = '1';
                encodedMessageIndex++;
            } 
        }
    }
    encodedMessage[encodedMessageIndex] = '\0';
    return encodedMessage;
}

char* decodeMessage(HuffmanTree *tree, char *encodedMessage) {
    int encodedMessageLength = strlen(encodedMessage);
    char *decodedMessage = (char*)malloc(sizeof(char) * encodedMessageLength);
    int decodedMessageIndex = 0;
    HuffmanNode *node = tree->root;
    for (int i = 0; i < encodedMessageLength; i++) {
        if (encodedMessage[i] == '0') {
            node = node->left;
        } else if (encodedMessage[i] == '1') {
            node = node->right;
        }

        if (node->character != '\0') {
            decodedMessage[decodedMessageIndex] = node->character;
            decodedMessageIndex++;
            node = tree->root;
        }
    }
    decodedMessage[decodedMessageIndex] = '\0';
    return decodedMessage;
}

int main() {
    char *message = "Huffman coding is a lossless data compression algorithm";

    HuffmanTree *tree = createHuffmanTree(message);
    
    printf("Huffman Codes:\n");
    printHuffmanCode(tree->root, "");
    
    char *encodedMessage = encodeMessage(tree, message);
    printf("\nEncoded Message:\n%s\n", encodedMessage);
    
    char *decodedMessage = decodeMessage(tree, encodedMessage);
    printf("\nDecoded Message:\n%s\n", decodedMessage);
    
    freeHuffmanTree(tree);
    free(encodedMessage);
    free(decodedMessage);
    return 0;
}