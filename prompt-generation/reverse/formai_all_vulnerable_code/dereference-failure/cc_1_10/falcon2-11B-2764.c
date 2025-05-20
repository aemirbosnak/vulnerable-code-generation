//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the Huffman tree
struct node {
    int freq;
    char bit;
    struct node* left;
    struct node* right;
};

// Function to calculate the frequency of each character in the input string
void countFrequency(char* str, struct node** root) {
    // Create a temporary array to store the frequencies of each character
    int freqs[256] = {0};

    // Count the frequency of each character in the input string
    for (int i = 0; str[i]!= '\0'; i++) {
        freqs[str[i]]++;
    }

    // Create a Huffman tree from the frequencies
    struct node* curr = *root;
    for (int i = 1; i < 256; i++) {
        if (curr->freq!= freqs[i]) {
            struct node* newNode = malloc(sizeof(struct node));
            newNode->freq = freqs[i];
            newNode->bit = '0';
            newNode->left = NULL;
            newNode->right = NULL;
            if (curr->freq > freqs[i]) {
                curr->right = newNode;
            } else {
                curr->left = newNode;
            }
            curr = curr->right;
        }
    }
}

// Function to build the Huffman tree
void buildHuffmanTree(struct node** root) {
    // Create two temporary arrays to store the Huffman codes for the characters
    char codes[256] = {0};
    struct node* curr = *root;
    for (int i = 0; i < 256; i++) {
        if (curr->freq!= 0) {
            char c = i + '0';
            codes[i] = c;
            curr = curr->right;
        }
    }

    // Build the Huffman tree
    curr = *root;
    for (int i = 0; i < 256; i++) {
        if (curr->freq == 0) {
            curr->bit = '0';
            curr->left = NULL;
            curr->right = NULL;
        } else {
            char c = i + '0';
            struct node* newNode = malloc(sizeof(struct node));
            newNode->freq = 0;
            newNode->bit = '0';
            newNode->left = curr;
            newNode->right = NULL;
            curr->right = newNode;
            curr = curr->right;
        }
    }
}

// Function to generate the Huffman encoded output string
char* generateHuffmanEncodedString(char* str, struct node* root) {
    int length = strlen(str);
    char* encodedString = (char*)malloc(length * sizeof(char));
    struct node* curr = root;
    for (int i = 0; i < length; i++) {
        if (curr->freq!= 0) {
            char c = curr->bit;
            encodedString[i] = c;
            curr = curr->right;
        }
    }
    return encodedString;
}

// Function to generate the Huffman decoded output string
char* generateHuffmanDecodedString(char* encodedString, struct node* root) {
    int length = strlen(encodedString);
    char* decodedString = (char*)malloc(length * sizeof(char));
    struct node* curr = root;
    for (int i = 0; i < length; i++) {
        if (curr->bit!= '0') {
            char c = curr->bit;
            decodedString[i] = c;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return decodedString;
}

int main() {
    char input[100] = "abracadabra";
    char* encodedString = generateHuffmanEncodedString(input, NULL);
    printf("Huffman encoded string: %s\n", encodedString);
    free(encodedString);
    encodedString = generateHuffmanEncodedString(input, NULL);
    printf("Huffman encoded string: %s\n", encodedString);
    free(encodedString);

    char* decodedString = generateHuffmanDecodedString(encodedString, NULL);
    printf("Huffman decoded string: %s\n", decodedString);
    free(decodedString);

    return 0;
}