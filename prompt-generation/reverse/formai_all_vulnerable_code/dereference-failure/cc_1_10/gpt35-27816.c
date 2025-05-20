//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the Huffman tree node
struct Node {
    char c;
    int freq;
    struct Node *left, *right;
};

// Structure to store the Huffman coding table
struct Code {
    char c;
    char code[256];
};

// Function to create a new node for the Huffman tree
struct Node* newNode(char c, int freq) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to sort the nodes based on their frequency
void sortNodes(struct Node** nodes, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (nodes[j]->freq > nodes[j+1]->freq) {
                struct Node* temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char* s) {
    int freq[256] = {0};
    int n = strlen(s);

    // Count the frequency of each character in the string
    for (int i = 0; i < n; i++) {
        freq[(int)s[i]]++;
    }

    // Create a list of nodes for each character and their frequency
    struct Node** nodes = (struct Node**) malloc(sizeof(struct Node*) * 256);
    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[count++] = newNode((char)i, freq[i]);
        }
    }

    // Sort the nodes based on their frequency
    sortNodes(nodes, count);

    // Build the Huffman tree by merging the nodes
    while (count > 1) {
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];
        struct Node* parent = newNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        count--;
        for (int i = 1; i < count; i++) {
            nodes[i] = nodes[i+1];
        }
        sortNodes(nodes, count);
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to generate the Huffman code table
void generateHuffmanCodeTable(struct Node* root, struct Code* codes, int index, char* buffer) {
    if (root->left == NULL && root->right == NULL) {
        codes[index].c = root->c;
        codes[index].code[0] = '\0';
        strcat(codes[index].code, buffer);
        return;
    }
    int len = strlen(buffer);

    buffer[len] = '0';
    buffer[len+1] = '\0';
    generateHuffmanCodeTable(root->left, codes, index, buffer);
    buffer[len] = '1';
    buffer[len+1] = '\0';
    generateHuffmanCodeTable(root->right, codes, index+1, buffer);
    buffer[len] = '\0';
}

// Function to encode the input string using Huffman coding
void encodeString(char* s, struct Code* codes, char* result) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 256; j++) {
            if (codes[j].c == s[i]) {
                strcat(result, codes[j].code);
                break;
            }
        }
    }
}

// Function to decode the input string using Huffman coding
void decodeString(char* s, struct Node* root, char* result) {
    int n = strlen(s);
    struct Node* current = root;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            strcat(result, &current->c);
            current = root;
        }
    }
}

// Function to print a binary string in groups of 8
void printBinaryString(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        printf("%c", s[i]);
        if ((i+1) % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char s[] = "hello world";

    // Build the Huffman tree
    struct Node* root = buildHuffmanTree(s);

    // Generate the Huffman code table
    struct Code codes[256];
    char buffer[256] = {'\0'};
    generateHuffmanCodeTable(root, codes, 0, buffer);

    // Print the Huffman code table
    printf("Huffman Code Table:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i].c == '\0') {
            break;
        }
        printf("%c: %s\n", codes[i].c, codes[i].code);
    }
    printf("\n");

    // Encode the input string
    char encoded[1024] = {'\0'};
    encodeString(s, codes, encoded);
    printf("Encoded String:\n");
    printBinaryString(encoded);
    printf("\n");

    // Decode the input string
    char decoded[1024] = {'\0'};
    decodeString(encoded, root, decoded);
    printf("Decoded String:\n%s\n", decoded);

    return 0;
}