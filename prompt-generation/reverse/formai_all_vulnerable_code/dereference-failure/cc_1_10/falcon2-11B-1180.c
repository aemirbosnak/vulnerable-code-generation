//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the Huffman tree
typedef struct Node {
    int freq;
    char data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the minimum frequency among all the nodes
int findMin(Node* root) {
    int min = root->freq;
    while (root->left!= NULL) {
        min = root->left->freq < min? root->left->freq : min;
        root = root->left;
    }
    return min;
}

// Function to build the Huffman tree
void buildTree(Node* root) {
    Node* current = root;
    while (current->left!= NULL || current->right!= NULL) {
        if (current->left!= NULL) {
            current->right = newNode(0, 0);
            current = current->right;
        } else {
            current->left = newNode(0, 0);
            current = current->left;
        }
    }
}

// Function to print the Huffman tree
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%c %d\n", root->data, root->freq);
    printTree(root->right);
}

// Function to encode a string using Huffman coding
void encode(char* str, Node* root) {
    if (str == NULL) {
        return;
    }
    encode(str + 1, root);
    if (root->left!= NULL) {
        printf("%c", root->data);
        encode(str, root->left);
    }
}

// Function to decode a string using Huffman coding
char* decode(Node* root, char* str) {
    if (root == NULL) {
        return str;
    }
    if (root->data == *str) {
        str++;
        return decode(root->left, str);
    } else {
        return decode(root->right, str);
    }
}

int main() {
    // Example usage
    Node* root = NULL;
    buildTree(root);
    printf("Huffman tree:\n");
    printTree(root);

    char str[] = "HELLO";
    printf("String to encode: %s\n", str);
    encode(str, root);

    char* decoded = decode(root, str);
    printf("Decoded string: %s\n", decoded);

    return 0;
}