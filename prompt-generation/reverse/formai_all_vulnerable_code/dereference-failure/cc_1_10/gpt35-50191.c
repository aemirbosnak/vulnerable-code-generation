//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate frequency of each symbol in the input
void calculateFrequencies(int* freq, char* input) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        freq[(int)input[i]]++;
    }
}

// Node structure for building Huffman tree
typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create new node
Node* createNode(char symbol, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build Huffman tree using provided frequencies
Node* buildHuffmanTree(int* freq) {
    Node* priorityQueue[MAX_LENGTH];
    int n = 0;
    
    // insert nodes with non-zero frequency into the priority queue
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            priorityQueue[n++] = createNode(i, freq[i]);
        }
    }
    
    // while there are more than one node in priority queue, keep merging nodes
    while(n > 1) {
        Node* node1 = priorityQueue[0];
        Node* node2 = priorityQueue[1];
        for(int i = 2; i < n; i++) {
            if(priorityQueue[i]->frequency < node1->frequency) {
                node2 = node1;
                node1 = priorityQueue[i];
            }
            else if(priorityQueue[i]->frequency < node2->frequency) {
                node2 = priorityQueue[i];
            }
        }
        
        // create new node by merging two least frequent nodes
        Node* mergedNode = createNode('\0', node1->frequency + node2->frequency);
        mergedNode->left = node1;
        mergedNode->right = node2;
        
        // remove the merged nodes from priority queue and add merged node
        if(node1 == priorityQueue[0] && node2 == priorityQueue[1]) {
            priorityQueue[0] = mergedNode;
            
            for(int i = 2; i < n; i++) {
                priorityQueue[i-1] = priorityQueue[i];
            }
        }
        else if(node1 == priorityQueue[0]) {
            priorityQueue[0] = mergedNode;
            
            for(int i = 1; i < n; i++) {
                priorityQueue[i-1] = priorityQueue[i];
            }
        }
        else {
            for(int i = 1; i < n; i++) {
                if(priorityQueue[i] == node1) {
                    priorityQueue[i] = mergedNode;
                }
            }
            
            for(int i = 2; i < n; i++) {
                priorityQueue[i-1] = priorityQueue[i];
            }
        }
        
        n--;
    }
    
    return priorityQueue[0];
}

// Function to recursively traverse the Huffman tree and encode each symbol
void encode(Node* root, char* code, char** codes) {
    if(root->left != NULL) {
        char* newCode = (char*)malloc((strlen(code) + 2) * sizeof(char));
        sprintf(newCode, "%s%c", code, '0');
        encode(root->left, newCode, codes);
        
        sprintf(newCode, "%s%c", code, '1');
        encode(root->right, newCode, codes);
    }
    else {
        codes[(int)root->symbol] = (char*)malloc(strlen(code) * sizeof(char));
        strcpy(codes[(int)root->symbol], code);
    }
}

// Function to compress input by encoding each character using Huffman codes
void compress(char* input) {
    int freq[256] = {0};
    calculateFrequencies(freq, input);
    Node* root = buildHuffmanTree(freq);
    char* codes[256] = {0};
    encode(root, "", codes);
    
    printf("Huffman codes:\n");
    for(int i = 0; i < 256; i++) {
        if(codes[i] != NULL) {
            printf("%c: %s\n", (char)i, codes[i]);
        }
    }
    
    printf("Compressed message:\n");
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        printf("%s", codes[(int)input[i]]);
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a message:\n");
    fgets(input, MAX_LENGTH, stdin);
    compress(input);
    return 0;
}