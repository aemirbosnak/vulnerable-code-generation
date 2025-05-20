//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int frequency;
    char symbol;
    struct Node* left;
    struct Node* right;
};

void buildHuffmanTree(int** frequency, int size) {
    struct Node* leaf;
    int i, j;
    for (i = 0; i < size; i++) {
        leaf = (struct Node*) malloc(sizeof(struct Node));
        leaf->frequency = frequency[i][0];
        leaf->symbol = frequency[i][1];
        leaf->left = NULL;
        leaf->right = NULL;
        struct Node* current = leaf;
        while (i < size - 1) {
            j = i + 1;
            while (j < size && frequency[i][0] > frequency[j][0])
                j++;
            struct Node* temp = frequency[i][1];
            frequency[i][1] = frequency[j][1];
            frequency[j][1] = temp;
            current->right = frequency[j][1];
            current = current->right;
            i = j;
        }
        leaf->right = frequency[i][1];
        frequency[i][1] = '\0';
        i = 0;
    }
}

void displayHuffmanTree(struct Node* root) {
    if (root!= NULL) {
        displayHuffmanTree(root->left);
        printf("%c %d ", root->symbol, root->frequency);
        displayHuffmanTree(root->right);
    }
}

void huffmanEncoding(struct Node* root, char* inputString, int* codeLength) {
    int i = 0;
    int length = strlen(inputString);
    char symbol;
    while (i < length) {
        symbol = inputString[i];
        if (symbol!= '\0') {
            struct Node* current = root;
            while (symbol!= '\0') {
                if (symbol == current->symbol)
                    break;
                current = current->left;
            }
            codeLength[0] = codeLength[0] + current->frequency;
            i++;
        } else {
            codeLength[1] = codeLength[1] + 1;
        }
    }
}

void huffmanDecoding(struct Node* root, char* inputString, char* outputString) {
    int i = 0;
    int length = strlen(inputString);
    char symbol;
    while (i < length) {
        symbol = inputString[i];
        if (symbol!= '\0') {
            struct Node* current = root;
            while (symbol!= '\0') {
                if (symbol == current->symbol)
                    break;
                current = current->left;
            }
            if (current->left!= NULL)
                i = i + current->frequency;
            else {
                outputString[i] = current->symbol;
                i++;
            }
        } else {
            outputString[i] = '\0';
            i++;
        }
    }
}

void huffmanCompression(char* inputString, char* outputString) {
    int frequency[256] = {0};
    int codeLength[2] = {0};
    int i, j;
    for (i = 0; i < strlen(inputString); i++) {
        frequency[inputString[i]]++;
    }
    int** frequencyArray = (int**)malloc(sizeof(int*) * 256);
    for (i = 0; i < 256; i++) {
        frequencyArray[i] = (int*)malloc(sizeof(int) * 2);
        frequencyArray[i][0] = 0;
        frequencyArray[i][1] = '\0';
    }
    for (i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            frequencyArray[i][0] = frequency[i];
            frequencyArray[i][1] = i;
        }
    }
    struct Node* root = NULL;
    buildHuffmanTree(frequencyArray, 256);
    displayHuffmanTree(root);
    char* compressedString = (char*)malloc(strlen(inputString) * 2);
    huffmanEncoding(root, inputString, codeLength);
    for (i = 0; i < codeLength[1]; i++) {
        compressedString[i] = '\0';
    }
    for (i = 0; i < codeLength[1]; i++) {
        compressedString[i] = (char)root->symbol;
    }
    huffmanDecoding(root, compressedString, outputString);
    printf("%s\n", outputString);
    free(root);
    free(frequencyArray);
}

int main() {
    char inputString[] = "The quick brown fox jumps over the lazy dog.";
    char outputString[strlen(inputString) * 2 + 1];
    huffmanCompression(inputString, outputString);
    return 0;
}