//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
typedef struct Node {
    char ch;
    unsigned freq;
    struct Node *left, *right;
} Node;

// Priority queue for nodes
typedef struct PriorityQueue {
    Node **array;
    int size;
} PriorityQueue;

// Function to create a new node
Node* createNode(char ch, unsigned freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Node**)malloc(capacity * sizeof(Node*));
    pq->size = 0;
    return pq;
}

// Function to insert a node into the priority queue
void insertPriorityQueue(PriorityQueue* pq, Node* node) {
    pq->array[pq->size++] = node;
    // Simple bubble up (not optimal for large data)
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->array[i]->freq < pq->array[(i - 1) / 2]->freq) {
            Node* temp = pq->array[i];
            pq->array[i] = pq->array[(i - 1) / 2];
            pq->array[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

// Function to remove min node from the priority queue
Node* removeMin(PriorityQueue* pq) {
    Node* min = pq->array[0];
    pq->array[0] = pq->array[--pq->size];
    int index = 0;
    
    while (index * 2 + 1 < pq->size) {
        int smallest = index;
        if (pq->array[index * 2 + 1]->freq < pq->array[smallest]->freq) {
            smallest = index * 2 + 1;
        }
        if (index * 2 + 2 < pq->size && pq->array[index * 2 + 2]->freq < pq->array[smallest]->freq) {
            smallest = index * 2 + 2;
        }
        if (smallest == index) {
            break;
        }
        Node* temp = pq->array[index];
        pq->array[index] = pq->array[smallest];
        pq->array[smallest] = temp;
        index = smallest;
    }
    return min;
}

// Function to print the Huffman codes
void printCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->ch, code);
    }
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char* str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    PriorityQueue* pq = createPriorityQueue(256);
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            insertPriorityQueue(pq, createNode((char)i, freq[i]));
        }
    }

    while (pq->size > 1) {
        Node* left = removeMin(pq);
        Node* right = removeMin(pq);
        Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        insertPriorityQueue(pq, newNode);
    }
    
    Node* root = removeMin(pq);
    free(pq->array);
    free(pq);
    return root;
}

// Main function
int main() {
    char str[100];
    printf("Enter a string to encode: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; 

    Node* root = buildHuffmanTree(str);
    char code[256];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);
    
    free(root);
    return 0;
}