//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

// This is our Huffman coding node struct
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left, *right;
};

// This function initializes a new Huffman node with a given character and frequency
struct HuffmanNode* newNode(char character, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// This function is used to print the Huffman code for each character in the input string
void printCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// This function is used to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    int n = size;
    struct HuffmanNode* nodes[n];
    for (int i = 0; i < n; ++i) {
        nodes[i] = newNode(data[i], freq[i]);
    }
    int sizeNodes = n;
    while (sizeNodes > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[0]->frequency > nodes[1]->frequency) {
            min1 = 1;
            min2 = 0;
        }
        for (int i = 2; i < sizeNodes; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }
        struct HuffmanNode* newNode = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
        newNode->left = nodes[min1];
        newNode->right = nodes[min2];
        newNode->frequency = nodes[min1]->frequency + nodes[min2]->frequency;
        char newCharacter[MAX_TREE_HT] = "#";
        strcat(newCharacter, newNode->left->character < newNode->right->character ? &newNode->left->character : &newNode->right->character);
        strcat(newCharacter, newNode->left->character < newNode->right->character ? &newNode->right->character : &newNode->left->character);
        newNode->character = newCharacter;
        nodes[min1] = newNode;
        nodes[min2] = nodes[--sizeNodes];
    }
    return nodes[0];
}

// This function is used to traverse the Huffman tree to decode the encoded input string
void traverseHuffmanTree(struct HuffmanNode* root, char* inputString) {
    struct HuffmanNode* currentNode = root;
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (currentNode->left == NULL && currentNode->right == NULL) {
            printf("%c", currentNode->character);
            currentNode = root;
        }
    }
}

int main() {
    char data[] = { 'B', 'C', 'D', 'E', 'F' };
    int freq[] = { 3, 6, 1, 2, 1 };
    int size = sizeof(data) / sizeof(data[0]);
    
    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0; 
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
    
    char inputString[] = "10101000010111011110101111001";
    printf("\nDecoded input string: ");
    traverseHuffmanTree(root, inputString);
    
    return 0;
}