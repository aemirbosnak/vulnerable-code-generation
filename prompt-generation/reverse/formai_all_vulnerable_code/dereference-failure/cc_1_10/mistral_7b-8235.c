//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHAR 256

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

node* createNode(char ch, int freq) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addCharFreq(node** root, char ch, int freq) {
    if (*root == NULL) {
        *root = createNode(ch, freq);
        return;
    }

    if (freq < (*root)->freq) {
        addCharFreq(&((*root)->left), ch, freq);
    } else {
        addCharFreq(&((*root)->right), ch, freq);
    }
}

void generateHuffmanCodes(node* root, char code[], int len) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c : %s\n", root->ch, code);
        return;
    }

    generateHuffmanCodes(root->left, code, len + 1);
    generateHuffmanCodes(root->right, code, len + 1);
}

void buildHuffmanTree(char input[], int length) {
    node* root = NULL;

    int freq[MAX_CHAR] = {0};

    for (int i = 0; i < length; i++) {
        freq[input[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            addCharFreq(&root, (char)i, freq[i]);
            freq[i] = 0;
        }
    }

    generateHuffmanCodes(root, "", 0);
}

int main() {
    char input[20] = "Huffman coding example program in C language";

    int length = strlen(input);

    printf("Input Character : %s\n", input);
    printf("Frequency Table : \n");

    buildHuffmanTree(input, length);

    return 0;
}