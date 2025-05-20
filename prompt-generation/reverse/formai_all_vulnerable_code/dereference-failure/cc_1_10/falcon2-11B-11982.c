//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char symbol;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(char symbol, int freq) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal of a binary tree
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c %d\n", root->symbol, root->freq);
    inorder(root->right);
}

// Function to find the minimum element in a binary tree
Node* minValueNode(Node* root) {
    while (root->left!= NULL) {
        root = root->left;
    }
    return root;
}

// Function to construct a Huffman tree from a given array of characters and their frequencies
void constructHuffmanTree(char* chars, int* freqs, Node** root) {
    // Sort the array of characters and their frequencies
    qsort(chars, strlen(chars), sizeof(char), (int (*)(const void*, const void*)) strcmp);
    qsort(freqs, strlen(chars), sizeof(int), (int (*)(const void*, const void*)) strcmp);

    // Create the root node
    Node* rootNode = newNode(chars[0], freqs[0]);
    Node* currentNode = rootNode;

    // Traverse the sorted array and construct the tree
    for (int i = 1; i < strlen(chars); i++) {
        Node* leftChild = newNode(chars[i], freqs[i]);
        Node* rightChild = newNode(chars[0], freqs[0]);
        leftChild->left = rightChild;
        leftChild->right = currentNode;
        currentNode = leftChild;
    }

    *root = rootNode;
}

// Function to encode a given string using Huffman coding
void encode(char* str, Node* root) {
    Node* currentNode = root;
    int strLen = strlen(str);

    // Traverse the Huffman tree and encode the characters
    for (int i = 0; i < strLen; i++) {
        if (currentNode->symbol == str[i]) {
            printf("%c %d\n", currentNode->symbol, currentNode->freq);
        }
        currentNode = currentNode->left;
    }
}

int main() {
    char chars[] = "AAABBBCC";
    int freqs[] = {5, 3, 2, 3};
    Node* root = NULL;

    constructHuffmanTree(chars, freqs, &root);
    inorder(root);
    encode("AAABBBCC", root);

    return 0;
}