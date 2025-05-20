//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SYMBOLS 256

/* Huffman coding structure */
struct HuffmanNode {
    int symbol;
    int weight;
    struct HuffmanNode *left, *right;
};

/* Count the frequency of each symbol in the input file */
int *countFrequency(FILE *in) {
    int *frequency = (int *) calloc(MAX_SYMBOLS, sizeof(int));
    unsigned char c;
    while ((c = fgetc(in)) != EOF) {
        frequency[c]++;
    }
    rewind(in);
    return frequency;
}

/* Create a Huffman tree based on the frequency of symbols */
struct HuffmanNode *buildHuffmanTree(int *frequency) {
    struct HuffmanNode *nodes[MAX_SYMBOLS];
    int num_nodes = 0;
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (frequency[i] > 0) {
            nodes[num_nodes] = (struct HuffmanNode *)
                malloc(sizeof(struct HuffmanNode));
            nodes[num_nodes]->symbol = i;
            nodes[num_nodes]->weight = frequency[i];
            nodes[num_nodes]->left = nodes[num_nodes]->right = NULL;
            num_nodes++;
        }
    }
    while (num_nodes > 1) {
        /* Find the two nodes with the smallest weight */
        int min1 = 0, min2 = 1;
        if (nodes[min2]->weight < nodes[min1]->weight) {
            min1 = 1;
            min2 = 0;
        }
        for (int i = 2; i < num_nodes; i++) {
            if (nodes[i]->weight < nodes[min1]->weight) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->weight < nodes[min2]->weight) {
                min2 = i;
            }
        }
        /* Create a new node with the combined weight */
        struct HuffmanNode *new_node = (struct HuffmanNode *)
            malloc(sizeof(struct HuffmanNode));
        new_node->symbol = -1;
        new_node->weight = nodes[min1]->weight + nodes[min2]->weight;
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];
        /* Remove the two nodes with the smallest weight */
        nodes[min1] = new_node;
        nodes[min2] = nodes[--num_nodes];
    }
    return nodes[0];
}

/* Recursive function to print the code for each symbol */
void printCodes(struct HuffmanNode *root, int code[], int code_len) {
    if (root->symbol >= 0) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < code_len; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return;
    }
    code[code_len] = 0;
    printCodes(root->left, code, code_len + 1);
    code[code_len] = 1;
    printCodes(root->right, code, code_len + 1);
}

/* Compress the input file using the Huffman coding */
void compress(FILE *in, FILE *out) {
    int *frequency = countFrequency(in);
    struct HuffmanNode *root = buildHuffmanTree(frequency);
    int code[MAX_SYMBOLS];
    printCodes(root, code, 0);
    free(frequency);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Cannot open input file %s\n", argv[1]);
        return 1;
    }
    FILE *out = fopen(argv[2], "wb");
    if (out == NULL) {
        printf("Cannot open output file %s\n", argv[2]);
        return 1;
    }
    compress(in, out);
    fclose(out);
    fclose(in);
    return 0;
}