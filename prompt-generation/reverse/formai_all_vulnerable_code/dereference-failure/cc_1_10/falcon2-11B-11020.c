//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
struct Node {
    char data;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to build Huffman tree
void buildHuffmanTree(struct Node **root, int *frequency) {
    int i, j, k;
    struct Node *left, *right, *smaller, *parent, *newNode;

    // Create two empty nodes for left and right
    left = (struct Node *)malloc(sizeof(struct Node));
    right = (struct Node *)malloc(sizeof(struct Node));

    // Set frequency and data for the two empty nodes
    left->frequency = frequency[1];
    left->data = 'a';

    right->frequency = frequency[2];
    right->data = 'b';

    // Create a parent node for left and right
    parent = (struct Node *)malloc(sizeof(struct Node));
    parent->frequency = 1;
    parent->left = left;
    parent->right = right;

    // Insert parent node into the frequency array
    for (i = 0; i < 3; i++) {
        frequency[i] = 0;
    }
    frequency[0] = parent->frequency;

    // Recursive call to build Huffman tree for left and right subtrees
    buildHuffmanTree(&left, frequency);
    buildHuffmanTree(&right, frequency);

    // Merge the two subtrees
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (frequency[i] < frequency[j]) {
                smaller = left;
                left = right;
                right = smaller;
            }
        }

        // Create a new node for the merged subtree
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->frequency = frequency[i];
        newNode->data = left->data + right->data;

        // Update the frequency array
        for (k = 0; k < 2; k++) {
            frequency[k] = 0;
        }
        frequency[k] = newNode->frequency;

        // Set the left and right child pointers of the new node
        newNode->left = left;
        newNode->right = right;

        // Update the parent node's left and right child pointers
        if (parent->left!= NULL) {
            parent->left->right = newNode;
        } else {
            parent->left = newNode;
        }
        if (parent->right!= NULL) {
            parent->right->left = newNode;
        } else {
            parent->right = newNode;
        }

        // Recursive call to build Huffman tree for new node
        buildHuffmanTree(&newNode, frequency);
    }
}

// Function to print Huffman tree
void printHuffmanTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    printHuffmanTree(root->left);
    printHuffmanTree(root->right);
}

// Function to generate Huffman code for a given string
void generateHuffmanCode(char *string, struct Node *root, int *frequency) {
    int i, len;
    char *code;

    // Calculate the length of the string
    len = strlen(string);

    // Allocate memory for the Huffman code
    code = (char *)malloc(len * sizeof(char));

    // Generate the Huffman code
    for (i = 0; i < len; i++) {
        if (string[i] == root->data) {
            code[i] = '0';
        } else {
            code[i] = '1';
        }
    }

    // Print the Huffman code
    printf("Huffman Code: %s\n", code);

    // Free the memory allocated for the Huffman code
    free(code);
}

int main() {
    int frequency[3] = {0, 0, 0};
    struct Node *root;

    // Build the Huffman tree
    buildHuffmanTree(&root, frequency);

    // Print the Huffman tree
    printf("Huffman Tree:\n");
    printHuffmanTree(root);

    // Generate Huffman code for a given string
    char string[] = "ab";
    generateHuffmanCode(string, root, frequency);

    return 0;
}