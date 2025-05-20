//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000
#define CHAR_RANGE 256

// A structure to hold a node of Huffman tree
struct HuffmanNode {
    unsigned char ch;
    unsigned int freq;
    struct HuffmanNode *left, *right;
};

// A structure to hold a frequency and encoded representation of a character
struct Code {
    char bits[MAX_STR_LEN];
    int len;
};

// An array to hold frequency of each character in the input string
int freq[CHAR_RANGE];

// Function to calculate frequency of each character in the input string
void calculateCharFreq(char *str) {
    for (int i = 0; i < strlen(str); i++)
        freq[(unsigned char) str[i]]++;
}

// Function to create a new node for Huffman tree
struct HuffmanNode *createNewNode(unsigned char ch, unsigned int freq) {
    struct HuffmanNode *newNode = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new node by combining two least frequent nodes
struct HuffmanNode *combineTwoNodes(struct HuffmanNode *left, struct HuffmanNode *right) {
    struct HuffmanNode *newNode = createNewNode('$', left->freq + right->freq);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// Function to build the Huffman tree and return the root
struct HuffmanNode *buildHuffmanTree() {
    struct HuffmanNode *nodes[CHAR_RANGE] = {NULL};
    for (int i = 0; i < CHAR_RANGE; i++) {
        if (freq[i] > 0)
            nodes[i] = createNewNode(i, freq[i]);
    }
    while (1) {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < CHAR_RANGE; i++) {
            if (nodes[i] != NULL) {
                if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq)
                    min1 = i;
            }
        }
        for (int i = 0; i < CHAR_RANGE; i++) {
            if (nodes[i] != NULL) {
                if (min2 == -1 || nodes[i]->freq < nodes[min2]->freq)
                    if (i != min1)
                        min2 = i;
            }
        }
        if (min2 == -1)
            return nodes[min1];
        nodes[min1] = combineTwoNodes(nodes[min1], nodes[min2]);
        nodes[min2] = NULL;
    }
}

// Recursive function to assign bits to each character in the Huffman tree
void assignBits(struct HuffmanNode *root, struct Code *codes, char *bits, int len) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        memcpy(codes[root->ch].bits, bits, len);
        codes[root->ch].len = len;
        return;
    }
    bits[len] = '0';
    assignBits(root->left, codes, bits, len + 1);
    bits[len] = '1';
    assignBits(root->right, codes, bits, len + 1);
}

// Function to compress the input string using Huffman encoding
void compress(char *str) {
    calculateCharFreq(str);
    struct HuffmanNode *root = buildHuffmanTree();
    struct Code codes[CHAR_RANGE] = {"", 0};
    char bits[MAX_STR_LEN] = {"\0"};
    assignBits(root, codes, bits, 0);
    FILE *fp = fopen("compressed.bin", "wb");
    fwrite(freq, sizeof(int), CHAR_RANGE, fp);
    int len = 0;
    for (int i = 0; i < strlen(str); i++) {
        struct Code code = codes[(unsigned char) str[i]];
        fwrite(code.bits, sizeof(char), code.len, fp);
        len += code.len;
    }
    printf("Compressed size: %d bytes\n", len/8);
    fclose(fp);
}

// Function to decompress the compressed file
void decompress() {
    FILE *fp = fopen("compressed.bin", "rb");
    fread(freq, sizeof(int), CHAR_RANGE, fp);
    struct HuffmanNode *root = buildHuffmanTree();
    char bits[MAX_STR_LEN] = {"\0"};
    char ch;
    int len = 0;
    struct HuffmanNode *node = root;
    FILE *decompressed = fopen("decompressed.txt", "w");
    while (fread(&ch, sizeof(char), 1, fp)) {
        for (int i = 7; i >= 0; i--) {
            if ((unsigned char) ch & (1 << i))
                node = node->right;
            else
                node = node->left;
            if (node->left == NULL && node->right == NULL) {
                fwrite(&node->ch, sizeof(char), 1, decompressed);
                node = root;
                len++;
                if (len == freq[ch])
                    break;
            }
        }
    }
    fclose(fp);
    fclose(decompressed);
    printf("Decompression successful!\n");
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter the string to compress:\n");
    fgets(str, MAX_STR_LEN, stdin);
    compress(str);
    decompress();
    return 0;
}