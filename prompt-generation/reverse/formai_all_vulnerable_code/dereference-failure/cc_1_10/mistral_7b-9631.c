//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_CHAR 128

typedef struct Node {
    unsigned char data;
    unsigned char freq;
    struct Node *left, *right;
} Node;

void initNode(Node *node, unsigned char data) {
    node->data = data;
    node->freq = 0;
    node->left = NULL;
    node->right = NULL;
}

Node *createNode(unsigned char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    initNode(newNode, data);
    return newNode;
}

void updateFreq(Node **root, unsigned char data) {
    Node *current = *root;

    while (current != NULL) {
        if (current->data == data) {
            current->freq++;
            return;
        }

        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    // If not found, add a new node
    *root = createNode(data);
}

void traverseAndBuildHuffmanTree(Node **root, Node **left, Node **right) {
    if (*root == NULL)
        return;

    traverseAndBuildHuffmanTree(left, *root, (*root)->left);
    traverseAndBuildHuffmanTree(right, (*root)->right, (*root)->right);

    free(*root);
    *root = NULL;

    *left = *left ? *left : createNode('\0');
    (*left)->freq = (*left)->freq + (*right)->freq;
    *right = *right;
}

void buildHuffmanTree(unsigned char *input, int len) {
    Node **root = NULL, **left = NULL, **right = NULL;

    for (int i = 0; i < len; i++) {
        updateFreq(root, input[i]);
    }

    while (numNodes(root) > 1) {
        Node *newNode = createNode('\0');
        newNode->left = *left;
        newNode->right = *right;
        newNode->freq = (*left)->freq + (*right)->freq;

        *root = newNode;
        left = &(*root)->left;
        right = &(*root)->right;

        traverseAndBuildHuffmanTree(root, left, right);
    }

    traverseAndBuildHuffmanTree(root, left, right);
}

void printHuffmanCodes(Node *root, char *codes, int len) {
    if (root == NULL)
        return;

    if (root->data != '\0') {
        printf("%c : %s\n", root->data, codes);
    }

    printHuffmanCodes(root->left, codes ? (codes + strlen(codes) + 1) : " ", len);
    printHuffmanCodes(root->right, codes ? (codes + strlen(codes) + 1) : " ", len);
}

int numNodes(Node **root) {
    if (*root == NULL)
        return 0;
    return 1 + numNodes((*root)->left) + numNodes((*root)->right);
}

int main() {
    clock_t start = clock();

    unsigned char input[] = "Huffman coding algorithm example program in C securely.";
    int len = sizeof(input) / sizeof(input[0]);

    Node *root = NULL;
    buildHuffmanTree(input, len);
    printHuffmanCodes(root, NULL, len);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime spent : %f seconds\n", time_spent);

    free(root);
    return 0;
}