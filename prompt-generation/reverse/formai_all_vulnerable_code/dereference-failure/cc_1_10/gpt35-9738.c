//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a brave implementation of a unique compression algorithm
// which uses a combination of run-length encoding and Huffman coding

/* Run-length encoding: replaces repeated consecutive characters 
with the character followed by the count of the repetition */

typedef struct RLE {
    char c;
    int count;
} RLE;

void compressRLE(char *input_string, RLE **output_rle, int *output_size) {
    int input_size = strlen(input_string);
    *output_rle = malloc(sizeof(RLE) * input_size);
    *output_size = 0;

    char current_char = input_string[0];
    int current_count = 1;

    for (int i = 1; i <= input_size; i++) {
        if (input_string[i] == current_char) {
            current_count++;
        } else {
            (*output_rle)[*output_size].c = current_char;
            (*output_rle)[*output_size].count = current_count;
            (*output_size)++;
            current_char = input_string[i];
            current_count = 1;
        }
    }
}

void printRLE(RLE *rle, int size) {
    printf("RLE: ");
    for (int i = 0; i < size; i++) {
        printf("%c%d", rle[i].c, rle[i].count);
    }
    printf("\n");
}

/* Huffman coding: assigns variable-length codes to individual characters 
based on their frequency of occurrence in the input string */

typedef struct HuffmanNode {
    char c;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

HuffmanNode *createHuffmanNode(char c, int freq) {
    HuffmanNode *node = malloc(sizeof(HuffmanNode));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

HuffmanNode *createHuffmanTree(RLE *rle, int size) {
    // initialize frequency table
    int freq[256] = {0};
    for (int i = 0; i < size; i++) {
        freq[(int) rle[i].c] += rle[i].count;
    }

    // create priority queue, sorted by frequency
    HuffmanNode *queue[256];
    int queue_size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            queue[queue_size] = createHuffmanNode((char) i, freq[i]);
            queue_size++;
        }
    }
    for (int i = 0; i < queue_size - 1; i++) {
        for (int j = 0; j < queue_size - i - 1; j++) {
            if (queue[j]->freq > queue[j+1]->freq) {
                HuffmanNode *temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }

    // build Huffman tree from priority queue
    while (queue_size > 1) {
        HuffmanNode *node1 = queue[0];
        HuffmanNode *node2 = queue[1];
        HuffmanNode *parent = createHuffmanNode('\0', node1->freq + node2->freq);
        parent->left = node1;
        parent->right = node2;
        queue[0] = parent;
        queue_size--;

        for (int i = 1; i < queue_size; i++) {
            queue[i] = queue[i+1];
        }

        int insert_index = queue_size - 1;
        for (int i = 0; i < queue_size - 1; i++) {
            if (queue[i]->freq > parent->freq) {
                insert_index = i;
                break;
            }
        }

        for (int i = queue_size - 1; i > insert_index; i--) {
            queue[i] = queue[i-1];
        }

        queue[insert_index] = parent;
        queue_size++;
    }

    return queue[0];
}

void printHuffmanTree(HuffmanNode *root, int depth) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("| ");
    }
    if (root->c == '\0') {
        printf("%d\n", root->freq);
    } else {
        printf("%c:%d\n", root->c, root->freq);
    }
    printHuffmanTree(root->left, depth+1);
    printHuffmanTree(root->right, depth+1);
}

/* Putting it all together */

void compress(char *input_string, char **output_string, int *output_size) {
    RLE *rle;
    int rle_size;
    compressRLE(input_string, &rle, &rle_size);
    printRLE(rle, rle_size);

    HuffmanNode *huffman_tree = createHuffmanTree(rle, rle_size);
    printHuffmanTree(huffman_tree, 0);

    // TODO: implement encoding using Huffman tree
}

int main() {
    char input_string[] = "aabbbccddd";
    char *output_string;
    int output_size;

    compress(input_string, &output_string, &output_size);

    free(output_string);

    return 0;
}