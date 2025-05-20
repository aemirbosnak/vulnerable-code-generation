//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100 // Maximum Huffman tree height.

// A Huffman tree node structure.
struct Node
{
    char data; // Character data.
    unsigned freq; // Frequency of the character.
    struct Node *left, *right; // Left and right child nodes.
};

// A Huffman code structure.
struct Code
{
    char c; // Character data.
    char *code; // Huffman code for the character.
};

// A Huffman tree structure.
struct Tree
{
    int size; // Number of unique characters.
    struct Node **nodes; // Array of tree nodes.
};

// Function to create a new node.
struct Node* newNode(char data, unsigned freq)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Swap two node pointers.
void swapNodes(struct Node **a, struct Node **b)
{
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify function - to maintain the heap property.
void minHeapify(struct Node **nodes, int size, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && nodes[left]->freq < nodes[smallest]->freq)
        smallest = left;

    if (right < size && nodes[right]->freq < nodes[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapNodes(&nodes[idx], &nodes[smallest]);
        minHeapify(nodes, size, smallest);
    }
}

// Check if a node is leaf.
int isLeaf(struct Node *node)
{
    return !(node->left) && !(node->right);
}

// Function to create a Huffman tree.
struct Node* buildHuffmanTree(char data[], int freq[], int size)
{
    struct Node *left, *right, *top;
    struct Node **nodes = (struct Node**)malloc(size * sizeof(struct Node*));

    for (int i = 0; i < size; ++i)
        nodes[i] = newNode(data[i], freq[i]);

    int n = size;
    while (n > 1)
    {
        minHeapify(nodes, n, 0);
        left = nodes[0];
        swapNodes(&nodes[0], &nodes[n-1]);
        --n;
        minHeapify(nodes, n, 0);
        right = nodes[0];
        swapNodes(&nodes[0], &nodes[n-1]);
        --n;
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        nodes[n] = top;
        ++n;
    }

    return nodes[0];
}

// Function to traverse the Huffman tree and generate codes.
void generateCodes(struct Node* root, char *code, struct Code *codes)
{
    if (root->left)
    {
        int len = strlen(code);
        code[len] = '0';
        generateCodes(root->left, code, codes);
        code[len] = '\0';
    }
    if (root->right)
    {
        int len = strlen(code);
        code[len] = '1';
        generateCodes(root->right, code, codes);
        code[len] = '\0';
    }
    if (isLeaf(root))
    {
        int i;
        for (i = 0; codes[i].c != '\0'; ++i);
        codes[i].c = root->data;
        codes[i].code = (char*) malloc((strlen(code) + 1) * sizeof(char));
        strcpy(codes[i].code, code);
    }
}

// Helper function to print Huffman codes.
void printCodes(struct Code* codes, int size)
{
    printf("Huffman Codes:\n");
    int i;
    for (i = 0; i < size; ++i)
        printf("%c: %s\n", codes[i].c, codes[i].code);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {8, 3, 1, 4, 5, 2};
    int size = sizeof(data)/sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, size);

    char *code = (char *) malloc(MAX_TREE_HT * sizeof(char));
    code[0] = '\0';
    struct Code *codes = (struct Code*) malloc(size * sizeof(struct Code));
    memset(codes, '\0', size * sizeof(struct Code));
    generateCodes(root, code, codes);

    printCodes(codes, size);

    return 0;
}