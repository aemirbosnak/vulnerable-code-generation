//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node structure for Huffman Tree
typedef struct Node {
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    return n1->freq - n2->freq;
}

// Function to create a new node
Node *createNode(char data, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build a Huffman Tree
Node *buildHuffmanTree(char *data, int *freq, int size) {
    Node *root = NULL;

    // Create a priority queue
    Node *pq[size];
    int pqSize = 0;

    // Insert nodes into the priority queue
    for (int i = 0; i < size; i++) {
        if (freq[i] != 0) {
            Node *node = createNode(data[i], freq[i]);
            pq[pqSize++] = node;
        }
    }

    // Sort the priority queue
    qsort(pq, pqSize, sizeof(Node *), compare);

    // Build the Huffman Tree
    while (pqSize > 1) {
        // Remove the two nodes with the lowest frequencies
        Node *n1 = pq[0];
        Node *n2 = pq[1];
        pq[0] = pq[pqSize - 1];
        pqSize--;

        // Create a new node with the sum of the frequencies
        Node *parent = createNode('\0', n1->freq + n2->freq);
        parent->left = n1;
        parent->right = n2;

        // Insert the new node into the priority queue
        pq[0] = parent;

        // Sort the priority queue
        qsort(pq, pqSize, sizeof(Node *), compare);
    }

    // The root of the Huffman Tree is the last node in the priority queue
    root = pq[0];

    return root;
}

// Function to print the Huffman code
void printHuffmanCode(Node *root, char code[]) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
    } else {
        // Traverse the left subtree
        char leftCode[100];
        strcpy(leftCode, code);
        strcat(leftCode, "0");
        printHuffmanCode(root->left, leftCode);

        // Traverse the right subtree
        char rightCode[100];
        strcpy(rightCode, code);
        strcat(rightCode, "1");
        printHuffmanCode(root->right, rightCode);
    }
}

// Function to encode a string using the Huffman code
char *encodeString(char *data, Node *root) {
    int dataLen = strlen(data);
    char *encodedString = (char *)malloc(dataLen * 10);
    int encodedLen = 0;

    for (int i = 0; i < dataLen; i++) {
        char c = data[i];
        Node *node = root;

        while (node != NULL) {
            if (node->data == c) {
                break;
            } else if (node->left != NULL && node->left->data == c) {
                node = node->left;
                strcat(encodedString, "0");
            } else {
                node = node->right;
                strcat(encodedString, "1");
            }
        }
    }

    encodedString[encodedLen] = '\0';
    return encodedString;
}

// Function to decode a string using the Huffman code
char *decodeString(char *encodedString, Node *root) {
    int encodedLen = strlen(encodedString);
    char *decodedString = (char *)malloc(encodedLen);
    int decodedLen = 0;

    Node *node = root;
    for (int i = 0; i < encodedLen; i++) {
        char c = encodedString[i];

        if (c == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decodedString[decodedLen++] = node->data;
            node = root;
        }
    }

    decodedString[decodedLen] = '\0';
    return decodedString;
}

// Main function
int main() {
    // Input data and frequencies
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    // Build the Huffman Tree
    Node *root = buildHuffmanTree(data, freq, size);

    // Print the Huffman code
    printf("Huffman Code:\n");
    printHuffmanCode(root, "");

    // Encode the string
    char *encodedString = encodeString("ABACABAD", root);
    printf("\nEncoded String: %s\n", encodedString);

    // Decode the string
    char *decodedString = decodeString(encodedString, root);
    printf("\nDecoded String: %s\n", decodedString);

    return 0;
}