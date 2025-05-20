//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate Huffman tree
void generateHuffmanTree(int* freq, int len, int* tree) {
    int i, j, k, minIndex;
    int left[len], right[len], root[len];

    // Initialize the frequency array
    for (i = 0; i < len; i++) {
        freq[i] = i;
    }

    // Sort the frequency array
    for (i = 0; i < len - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < len; j++) {
            if (freq[j] < freq[minIndex]) {
                minIndex = j;
            }
        }
        k = freq[i];
        freq[i] = freq[minIndex];
        freq[minIndex] = k;
    }

    // Generate the Huffman tree
    root[0] = 0;
    for (i = 1; i < len; i++) {
        left[i] = root[freq[i] - 1];
        right[i] = i;
        root[i] = i;
    }

    // Build the Huffman tree
    for (i = 1; i < len; i++) {
        int parent = left[i];
        if (parent == i) {
            tree[i] = 1;
        } else {
            tree[i] = 0;
            tree[parent] = 1;
        }
    }
}

// Function to generate Huffman encoded string
char* generateHuffmanEncodedString(char* str, int* freq, int len) {
    int i, j, k;
    char* encodedString = (char*)malloc(len * sizeof(char));

    // Generate Huffman tree
    int tree[len];
    generateHuffmanTree(freq, len, tree);

    // Generate Huffman encoded string
    for (i = 0; i < len; i++) {
        int index = tree[freq[str[i]]];
        encodedString[i] = (index == 0)? '0' : '1';
    }

    return encodedString;
}

// Function to print Huffman encoded string
void printHuffmanEncodedString(char* encodedString, int len) {
    for (int i = 0; i < len; i++) {
        printf("%c", encodedString[i]);
    }
    printf("\n");
}

int main() {
    char* str = "abracadabra";
    int freq[26] = {0};
    int len = strlen(str);

    // Count frequency of characters in the string
    for (int i = 0; i < len; i++) {
        freq[str[i] - 'a']++;
    }

    // Generate Huffman encoded string
    char* encodedString = generateHuffmanEncodedString(str, freq, len);

    // Print Huffman encoded string
    printHuffmanEncodedString(encodedString, len);

    // Free memory
    free(encodedString);

    return 0;
}