//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the Huffman tree
typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

// Structure for the Huffman tree
typedef struct Tree {
    Node *root;
} Tree;

// Structure for each code in the Huffman code table
typedef struct Code {
    char symbol;
    char *bits;
} Code;

// Helper function to create a new node in the Huffman tree
Node *newNode(char data, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Helper function to build the Huffman tree from the given letter frequencies
void buildTree(Tree *tree, int *freq) {
    Node *min1, *min2, *node;
    int i, j, n = 256;
    Node **nodes = (Node **)malloc(n * sizeof(Node *));
    for (i = 0, j = 0; i < n; i++) {
        if (freq[i] > 0) {
            nodes[j++] = newNode((char)i, freq[i]);
        }
    }
    n = j;
    while (n > 1) {
        min1 = nodes[0];
        min2 = nodes[1];
        for (i = 2; i < n; i++) {
            if (nodes[i]->freq < min1->freq) {
                min2 = min1;
                min1 = nodes[i];
            } else if (nodes[i]->freq < min2->freq) {
                min2 = nodes[i];
            }
        }
        node = newNode('\0', min1->freq + min2->freq);
        node->left = min1;
        node->right = min2;
        for (i = 0; i < n; i++) {
            if (nodes[i] == min1 || nodes[i] == min2) {
                nodes[i] = node;
                break;
            }
        }
        for (j = i; j < n - 1; j++) {
            nodes[j] = nodes[j + 1];
        }
        n--;
    }
    tree->root = nodes[0];
    free(nodes);
}

// Helper function to generate the Huffman codes for each character in the tree
void generateCodes(Node *node, char *prefix, int depth, Code *codes, int *n) {
    if (node->left == NULL && node->right == NULL) {
        codes[*n].symbol = node->data;
        codes[*n].bits = (char *)malloc((depth + 1) * sizeof(char));
        codes[*n].bits[depth] = '\0';
        for (int i = 0; i < depth; i++) {
            codes[*n].bits[i] = prefix[i];
        }
        (*n)++;
    } else {
        prefix[depth] = '0';
        generateCodes(node->left, prefix, depth + 1, codes, n);
        prefix[depth] = '1';
        generateCodes(node->right, prefix, depth + 1, codes, n);
    }
}

// Main Huffman coding function that takes in a message as input and returns its encoded form
char *huffmanEncode(char *message, int *size, Code *codes) {
    int i, j, n = 256, m = strlen(message);
    int *freq = (int *)malloc(n * sizeof(int));
    char *encoded = (char *)malloc(m * sizeof(char));
    for (i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (i = 0; i < m; i++) {
        freq[(int)message[i]]++;
    }
    Tree tree;
    buildTree(&tree, freq);
    char prefix[256];
    int depth = 0, k = 0;
    generateCodes(tree.root, prefix, depth, codes, &k);
    for (i = 0, j = 0; i < m; i++) {
        for (k = 0; k < n; k++) {
            if (message[i] == codes[k].symbol) {
                for (int l = 0; l < strlen(codes[k].bits); l++) {
                    encoded[j++] = codes[k].bits[l];
                }
                break;
            }
        }
    }
    encoded[j] = '\0';
    *size = j;
    free(freq);
    return encoded;
}

// Main function to test the Huffman coding implementation
int main() {
    Code codes[256];
    char message[1000];
    int size;
    printf("Enter a message to encode: ");
    fgets(message, 1000, stdin);
    char *encoded = huffmanEncode(message, &size, codes);
    printf("Encoded message: %s\n", encoded);
    printf("Huffman codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i].symbol != '\0') {
            printf("%c: %s\n", codes[i].symbol, codes[i].bits);
        }
    }
    return 0;
}