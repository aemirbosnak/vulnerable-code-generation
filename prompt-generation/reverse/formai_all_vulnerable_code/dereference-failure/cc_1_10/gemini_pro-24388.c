//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a Huffman tree
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(char data, int freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two nodes based on their frequencies
int compare(const void *a, const void *b) {
    struct Node *n1 = (struct Node *)a;
    struct Node *n2 = (struct Node *)b;
    return n1->freq - n2->freq;
}

// Function to create a Huffman tree
struct Node *buildHuffmanTree(char *str, int n) {
    // Create an array of nodes
    struct Node *nodes[n];

    // Calculate the frequency of each character
    int freq[256] = {0};
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    // Create nodes for each character
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[index++] = createNode(i, freq[i]);
        }
    }

    // Sort the nodes based on their frequencies
    qsort(nodes, index, sizeof(struct Node *), compare);

    // Build the Huffman tree
    while (index > 1) {
        // Take the two nodes with the lowest frequencies
        struct Node *left = nodes[0];
        struct Node *right = nodes[1];

        // Create a new node with the sum of the frequencies of the two nodes
        struct Node *parent = createNode('\0', left->freq + right->freq);

        // Set the left and right children of the new node
        parent->left = left;
        parent->right = right;

        // Remove the two nodes from the array
        for (int i = 0; i < index - 2; i++) {
            nodes[i] = nodes[i + 2];
        }

        // Add the new node to the array
        nodes[index - 2] = parent;

        // Decrement the index
        index--;

        // Sort the nodes based on their frequencies
        qsort(nodes, index, sizeof(struct Node *), compare);
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to print the Huffman codes for each character
void printCodes(struct Node *root, char *code, int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }

    // Recursively traverse the left subtree
    printCodes(root->left, strcat(code, "0"), top + 1);

    // Recursively traverse the right subtree
    printCodes(root->right, strcat(code, "1"), top + 1);
}

// Function to encode a string using Huffman coding
char *encode(struct Node *root, char *str, int n) {
    char *encodedStr = (char *)malloc(n * sizeof(char));
    int index = 0;

    for (int i = 0; i < n; i++) {
        struct Node *node = root;
        while (node->left != NULL || node->right != NULL) {
            if (str[i] == node->data) {
                break;
            } else if (str[i] < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        while (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                encodedStr[index++] = '1';
            } else {
                encodedStr[index++] = '0';
            }

            if (node->left != NULL) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    return encodedStr;
}

// Function to decode a string using Huffman coding
char *decode(struct Node *root, char *encodedStr, int n) {
    char *decodedStr = (char *)malloc(n * sizeof(char));
    int index = 0;

    struct Node *node = root;
    for (int i = 0; i < n; i++) {
        if (encodedStr[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decodedStr[index++] = node->data;
            node = root;
        }
    }

    return decodedStr;
}

// Driver code
int main() {
    char str[] = "Follow your dreams";
    int n = strlen(str);

    // Build the Huffman tree
    struct Node *root = buildHuffmanTree(str, n);

    // Print the Huffman codes for each character
    char code[n];
    code[0] = '\0';
    printCodes(root, code, 0);

    // Encode the string
    char *encodedStr = encode(root, str, n);

    // Print the encoded string
    printf("Encoded string: %s\n", encodedStr);

    // Decode the string
    char *decodedStr = decode(root, encodedStr, strlen(encodedStr));

    // Print the decoded string
    printf("Decoded string: %s\n", decodedStr);

    return 0;
}