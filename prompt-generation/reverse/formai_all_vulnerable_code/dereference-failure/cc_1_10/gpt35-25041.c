//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Struct to hold the Huffman tree node
struct HuffmanTreeNode {
    char character;
    unsigned frequency;
    struct HuffmanTreeNode *left, *right;
};

// Struct to hold the Huffman code for each character
struct HuffmanCode {
    char character;
    char *code;
};

// Function to create a new node for the Huffman tree
struct HuffmanTreeNode* newNode(char character, unsigned frequency)
{
    struct HuffmanTreeNode* node =
        (struct HuffmanTreeNode*)malloc(sizeof(struct HuffmanTreeNode));
    node->left = node->right = NULL;
    node->character = character;
    node->frequency = frequency;
    return node;
}

// Function to swap two Huffman tree nodes
void swapNodes(struct HuffmanTreeNode** a, struct HuffmanTreeNode** b)
{
    struct HuffmanTreeNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to sort an array of Huffman tree node pointers
void insertionSort(struct HuffmanTreeNode** a, int n)
{
    int i, j;
    struct HuffmanTreeNode* key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j]->frequency > key->frequency) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Function to build the Huffman tree and return the root node
struct HuffmanTreeNode* buildHuffmanTree(char* characters, int* frequencies, int n)
{
    struct HuffmanTreeNode *left, *right, *top;
    int i;

    // Create an array of Huffman tree node pointers
    struct HuffmanTreeNode** nodeArr =
        (struct HuffmanTreeNode**)malloc(n * sizeof(struct HuffmanTreeNode*));

    // Create a new Huffman tree node for each character and
    // add it to the array of Huffman tree node pointers
    for (i = 0; i < n; ++i)
        nodeArr[i] = newNode(characters[i], frequencies[i]);

    // Build the Huffman tree
    while (n > 1) {
        // Sort the array of Huffman tree node pointers
        insertionSort(nodeArr, n);

        // Create a new internal node with the two lowest frequency nodes as children
        left = nodeArr[0];
        right = nodeArr[1];
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        // Remove the first two nodes and add the new internal node
        nodeArr[0] = top;
        nodeArr[1] = NULL;
        n--;
    }

    // Return the root node of the Huffman tree
    return nodeArr[0];
}

// Function to print the Huffman code for each character
void printHuffmanCode(struct HuffmanCode* huffmanCodeArr, int n)
{
    int i;

    printf("Huffman code:\n");
    for (i = 0; i < n; ++i)
        printf("%c: %s\n", huffmanCodeArr[i].character, huffmanCodeArr[i].code);
}

// Function to encode a string using Huffman code
void encodeString(struct HuffmanTreeNode* root, char* str, char* encodedStr)
{
    int i;
    int len = strlen(str);
    char code[MAX_TREE_HT];

    // Traverse the Huffman tree to generate the code for each character in the string
    for (i = 0; i < len; ++i) {
        struct HuffmanTreeNode* node = root;
        int j = 0;

        while (node->left || node->right) {
            if (str[i] == node->left->character) {
                code[j] = '0';
                node = node->left;
            }
            else {
                code[j] = '1';
                node = node->right;
            }
            j++;
        }
        code[j] = '\0';
        strcat(encodedStr, code);
    }
}

int main()
{
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequencies[] = { 5, 9, 12, 13, 16, 45 };
    int n = sizeof(characters) / sizeof(characters[0]);

    // Build the Huffman tree and get the root node
    struct HuffmanTreeNode* root = buildHuffmanTree(characters, frequencies, n);

    // Generate Huffman code for each character
    struct HuffmanCode* huffmanCodeArr =
        (struct HuffmanCode*)malloc(n * sizeof(struct HuffmanCode));
    int i;
    for (i = 0; i < n; ++i) {
        huffmanCodeArr[i].character = characters[i];
        huffmanCodeArr[i].code = (char*)malloc(MAX_TREE_HT * sizeof(char));
        encodeString(root, &characters[i], huffmanCodeArr[i].code);
    }

    // Print Huffman code for each character
    printHuffmanCode(huffmanCodeArr, n);

    return 0;
}