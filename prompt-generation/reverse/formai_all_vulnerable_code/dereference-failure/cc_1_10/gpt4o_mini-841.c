//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

typedef struct Node {
    char data;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char data, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int compare(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return nodeA->frequency - nodeB->frequency;
}

Node* buildHuffmanTree(char* data, int* frequency, int size) {
    Node** nodes = malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], frequency[i]);
    }

    while (size > 1) {
        qsort(nodes, size, sizeof(Node*), compare);
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        nodes[1] = combined;
        size--;
        memmove(&nodes[0], &nodes[1], size * sizeof(Node*));
    }

    Node* root = nodes[0];
    free(nodes);
    return root;
}

void printCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        code[top] = '\0';
        printf("Character: %c | Code: %s\n", root->data, code);
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = buildHuffmanTree(data, frequency, size);
    char code[MAX_CODE_LENGTH];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    freeTree(root);
    return 0;
}