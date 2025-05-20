//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define structure for Huffman tree nodes
struct node {
    int val;
    char ch;
    struct node *left;
    struct node *right;
};

// Helper function to create a new Huffman node
struct node* createNode(int val, char ch) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->val = val;
    newNode->ch = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to check if node is a leaf
bool isLeaf(struct node* node) {
    return !(node->left) && !(node->right);
}

// Huffman encoding function
void encode(struct node* root, char* str, int index, char codes[][100]) {
    if(root == NULL) return;

    if(root->ch != '-') {
        str[index] = '\0';
        strcpy(codes[(int)(root->ch)],str);
    }

    str[index] = '0';
    encode(root->left, str, index + 1, codes);

    str[index] = '1';
    encode(root->right, str, index + 1, codes);
}

// Compare function for qsort
int compare(const void* x, const void* y) {
    return ((struct node*)x)->val - ((struct node*)y)->val;
}

// Huffman decoding function
void decode(struct node* root, char* str) {
    struct node* curr = root;
    int i = 0;
    while(str[i]) {
        if(str[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        if(isLeaf(curr)) {
            printf("%c", curr->ch);
            curr = root;
        }
        i++;
    }
}

// Main Huffman function
void huffman(char c[], int freq[], int size) {
    struct node* left, *right, *top;
    struct node* nodes[size];

    // Initialize nodes array with Huffman tree nodes
    for(int i = 0; i < size; i++) {
        nodes[i] = createNode(freq[i], c[i]);
    }

    while(size > 1) {
        qsort(nodes, size, sizeof(struct node*), compare);

        left = nodes[0];
        right = nodes[1];

        top = createNode(left->val + right->val, '-');
        top->left = left;
        top->right = right;

        nodes[0] = top;
        for(int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }

        size--;
    }

    // Encode each character using the Huffman tree
    char codes[256][100] = {""};
    char str[100];
    encode(nodes[0], str, 0, codes);

    // Print the character, frequency, and Huffman code for each character
    printf("\nCharacter\tFrequency\tHuffman Code\n");
    for(int i = 0; i < 256; i++) {
        if(strlen(codes[i]) > 0) {
            printf("%c\t\t%d\t\t%s\n", (char)i, freq[i], codes[i]);
        }
    }

    // Decode encoded string using Huffman tree
    char encoded[1000] = "110000111011101010101010";
    printf("\nEncoded string: %s\n", encoded);
    printf("Decoded string: ");
    decode(nodes[0], encoded);
}

// Driver code
int main() {
    char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(c) / sizeof(c[0]);

    huffman(c, freq, size);

    return 0;
}