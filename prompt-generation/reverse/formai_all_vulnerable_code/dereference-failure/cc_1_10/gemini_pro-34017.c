//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a Huffman tree
typedef struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *createNode(char data, int freq) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to compare two nodes based on their frequencies
int compareNodes(const void *a, const void *b) {
    node *node1 = (node *)a;
    node *node2 = (node *)b;
    return node1->freq - node2->freq;
}

// Function to build a Huffman tree
node *buildTree(char data[], int freq[], int size) {
    // Create a min heap of nodes
    node **nodes = (node **)malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }
    qsort(nodes, size, sizeof(node *), compareNodes);

    // Build the Huffman tree
    node *left, *right, *top;
    while (size > 1) {
        left = nodes[0];
        right = nodes[1];
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        nodes[0] = top;
        nodes[1] = nodes[size - 1];
        size--;
        qsort(nodes, size, sizeof(node *), compareNodes);
    }
    return nodes[0];
}

// Function to print the Huffman codes
void printCodes(node *root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, code);
    }
}

// Function to encode a string using the Huffman codes
void encode(node *root, char data[], int size) {
    char code[size];
    for (int i = 0; i < size; i++) {
        printCodes(root, code, 0);
        printf("%s\n", code);
    }
}

// Function to decode a string using the Huffman codes
void decode(node *root, char code[], int size) {
    node *current = root;
    for (int i = 0; i < size; i++) {
        if (code[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (!current->left && !current->right) {
            printf("%c", current->data);
            current = root;
        }
    }
    printf("\n");
}

// Driver code
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    node *root = buildTree(data, freq, size);

    char code[size];
    encode(root, data, size);

    char inputCode[] = "0100110011111011011110011000";
    decode(root, inputCode, strlen(inputCode));

    return 0;
}