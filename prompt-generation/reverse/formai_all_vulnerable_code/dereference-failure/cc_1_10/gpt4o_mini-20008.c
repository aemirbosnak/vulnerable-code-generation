//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void countFrequency(unsigned char *input, int *frequency) {
    for (int i = 0; input[i]; i++) {
        frequency[input[i]]++;
    }
}

void buildHuffmanTree(int *frequency, unsigned char *huffmanCodes[], int *codeLengths) {
    int n = MAX;
    unsigned char *leafNodes[MAX];
    for (int i = 0; i < MAX; i++) {
        if (frequency[i]) {
            leafNodes[n--] = malloc(2);
            strcpy(leafNodes[n], (unsigned char *)&i);
        }
    }
    // Simple Huffman-like encoding (not a full implementation)
    for (int i = 0; n < MAX; i++, n++) {
        huffmanCodes[i] = malloc(10);
        snprintf(huffmanCodes[i], 10, "0%d", i);
        codeLengths[i] = 2; // Example length
    }
}

void compressData(unsigned char *input, unsigned char *output, unsigned char *huffmanCodes[], int *codeLengths) {
    int bitIndex = 0;
    for (int i = 0; input[i]; i++) {
        int codeIndex = input[i]; // Using ASCII as index for simplicity
        for (int j = 0; j < codeLengths[codeIndex]; j++) {
            if (bitIndex / 8 >= MAX) return; // Check bounds
            output[bitIndex / 8] <<= 1;
            if (huffmanCodes[codeIndex][j] == '1') {
                output[bitIndex / 8] |= 1;
            }
            bitIndex++;
        }
    }
    output[bitIndex / 8] <<= (8 - (bitIndex % 8)); // Pad the last byte
}

void printEncodedData(unsigned char *compressed, int length) {
    printf("Compressed Data: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", compressed[i]);
    }
    printf("\n");
}

int main() {
    unsigned char input[MAX] = "The quick brown fox jumps over the lazy dog";
    unsigned char compressed[MAX / 8]; // Rough estimation for space
    int frequency[MAX] = {0};
    unsigned char *huffmanCodes[MAX] = {0};
    int codeLengths[MAX] = {0};
    
    countFrequency(input, frequency);
    buildHuffmanTree(frequency, huffmanCodes, codeLengths);
    
    memset(compressed, 0, sizeof(compressed));
    
    compressData(input, compressed, huffmanCodes, codeLengths);
    
    int compressedLength = (strlen(input) * 8) / 8; // Rough length estimation
    printEncodedData(compressed, compressedLength);
    
    // Free allocated memory
    for (int i = 0; i < MAX; i++) {
        free(huffmanCodes[i]);
    }

    return 0;
}