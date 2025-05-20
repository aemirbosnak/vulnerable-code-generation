//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store a node in the Huffman tree
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

// Struct to store the Huffman codes
typedef struct Code {
    char code[256];
    int len;
} Code;

// Function to compare two nodes by frequency
int compare(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    return n1->freq - n2->freq;
}

// Function to create a new node
Node *create_node(char ch, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to build the Huffman tree
Node *build_tree(char *str, int n) {
    // Create an array of nodes, one for each unique character in the string
    Node *nodes[256];
    for (int i = 0; i < 256; i++) {
        nodes[i] = create_node(0, 0);
    }

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        nodes[str[i]]->freq++;
    }

    // Sort the nodes by frequency
    qsort(nodes, 256, sizeof(Node *), compare);

    // Build the Huffman tree
    while (nodes[0]->freq != 0) {
        // Find the two nodes with the lowest frequencies
        Node *n1 = nodes[0];
        Node *n2 = nodes[1];

        // Create a new node with the sum of the frequencies of the two nodes
        Node *new_node = create_node(0, n1->freq + n2->freq);
        new_node->left = n1;
        new_node->right = n2;

        // Insert the new node into the array of nodes
        for (int i = 0; i < 256; i++) {
            if (nodes[i]->freq == 0) {
                nodes[i] = new_node;
                break;
            }
        }

        // Sort the nodes by frequency
        qsort(nodes, 256, sizeof(Node *), compare);
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to generate the Huffman codes
void generate_codes(Node *root, Code *codes, char *code, int len) {
    // If the node is a leaf, then its code is the current code
    if (root->left == NULL && root->right == NULL) {
        strcpy(codes[root->ch].code, code);
        codes[root->ch].len = len;
        return;
    }

    // If the node is not a leaf, then add a '0' to the code if the left child is taken, and a '1' if the right child is taken
    generate_codes(root->left, codes, strcat(code, "0"), len + 1);
    generate_codes(root->right, codes, strcat(code, "1"), len + 1);
}

// Function to print the Huffman codes
void print_codes(char *str, int n, Code *codes) {
    for (int i = 0; i < n; i++) {
        printf("%c: %s\n", str[i], codes[str[i]].code);
    }
}

// Function to compress the string using the Huffman codes
int compress(char *str, int n, Code *codes, char *compressed_str) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        strcat(compressed_str, codes[str[i]].code);
        len += codes[str[i]].len;
    }
    return len;
}

// Function to decompress the string using the Huffman codes
char *decompress(char *compressed_str, Node *root, int len) {
    int i = 0;
    char *decompressed_str = (char *)malloc(len + 1);
    Node *node = root;
    while (i < len) {
        if (compressed_str[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decompressed_str[i - 1] = node->ch;
            node = root;
        }

        i++;
    }

    decompressed_str[len] = '\0';
    return decompressed_str;
}

// Main function
int main() {
    // Input string
    char str[] = "Huffman coding is a lossless data compression algorithm";
    int n = strlen(str);

    // Build the Huffman tree
    Node *root = build_tree(str, n);

    // Generate the Huffman codes
    Code codes[256];
    generate_codes(root, codes, "", 0);

    // Print the Huffman codes
    print_codes(str, n, codes);

    // Compress the string using the Huffman codes
    char compressed_str[n * 8 + 1];
    int compressed_len = compress(str, n, codes, compressed_str);

    // Decompress the string using the Huffman codes
    char *decompressed_str = decompress(compressed_str, root, compressed_len);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_str);

    // Free the memory allocated for the Huffman tree and the decompressed string
    free(root);
    free(decompressed_str);

    return 0;
}