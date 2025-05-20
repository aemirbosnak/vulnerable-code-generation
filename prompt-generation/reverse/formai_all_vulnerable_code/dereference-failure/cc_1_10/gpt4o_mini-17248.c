//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

// Node structure for the Huffman Tree
typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Priority Queue structure
typedef struct PriorityQueue {
    Node *nodes[MAX_TREE_NODES];
    int size;
} PriorityQueue;

// Function prototypes
Node* createNode(char character, unsigned frequency);
PriorityQueue* createPriorityQueue();
void insertPriorityQueue(PriorityQueue *pq, Node *node);
Node* deleteMin(PriorityQueue *pq);
void buildHuffmanTree(char *data, int *frequency, int size);
void generateCodes(Node *root, char *codes[], char *code, int depth);
void encodeData(char *data, char *codes[], int size);
void decodeData(char *encodedData, Node *root);
void freeHuffmanTree(Node *root);

// Entry point of the program
int main() {
    char data[] = "huffman coding is fun";
    int frequency[MAX_TREE_NODES] = {0};

    // Calculate frequency of each character
    for (int i = 0; data[i] != '\0'; i++) {
        frequency[(unsigned char)data[i]]++;
    }
    
    // Build the Huffman Tree
    buildHuffmanTree(data, frequency, sizeof(frequency) / sizeof(frequency[0]));
    
    return 0;
}

// Function to create a new Node
Node* createNode(char character, unsigned frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a Priority Queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// Function to insert a node into the Priority Queue
void insertPriorityQueue(PriorityQueue *pq, Node *node) {
    int i = pq->size++;
    while (i && node->frequency < pq->nodes[(i - 1) / 2]->frequency) {
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->nodes[i] = node;
}

// Function to delete the minimum node from the Priority Queue
Node* deleteMin(PriorityQueue *pq) {
    Node *minNode = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];
    int i = 0, j;
    while (1) {
        j = 2 * i + 1;
        if (j >= pq->size) break;
        if (j + 1 < pq->size && pq->nodes[j]->frequency > pq->nodes[j + 1]->frequency) {
            j++;
        }
        if (pq->nodes[i]->frequency <= pq->nodes[j]->frequency) break;
        Node *temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[j];
        pq->nodes[j] = temp;
        i = j;
    }
    return minNode;
}

// Function to build the Huffman Tree
void buildHuffmanTree(char *data, int *frequency, int size) {
    PriorityQueue *pq = createPriorityQueue();
    
    // Create nodes for each character and insert into Priority Queue
    for (char c = 0; c < MAX_TREE_NODES; c++) {
        if (frequency[(unsigned char)c] != 0) {
            insertPriorityQueue(pq, createNode(c, frequency[(unsigned char)c]));
        }
    }
    
    // Build the Huffman Tree
    while (pq->size > 1) {
        Node *left = deleteMin(pq);
        Node *right = deleteMin(pq);
        Node *combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insertPriorityQueue(pq, combined);
    }

    Node *root = deleteMin(pq);
    
    // Generate Huffman Codes
    char *codes[MAX_TREE_NODES];
    char code[MAX_CODE_LENGTH];
    generateCodes(root, codes, code, 0);

    // Encode the data
    printf("Encoded Data:\n");
    encodeData(data, codes, sizeof(frequency) / sizeof(frequency[0]));

    // Decode the data
    printf("Decoded Data:\n");
    decodeData(data, root);
    
    // Free the Huffman Tree
    freeHuffmanTree(root);
    
    free(pq);
}

// Function to generate Huffman Codes
void generateCodes(Node *root, char *codes[], char *code, int depth) {
    // If leaf node, store the code
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0'; // terminate the string
        codes[(unsigned char)root->character] = strdup(code);
        printf("Character: '%c' | Code: %s\n", root->character, codes[(unsigned char)root->character]);
        return;
    }
    
    // Traverse left
    code[depth] = '0';
    generateCodes(root->left, codes, code, depth + 1);
    
    // Traverse right
    code[depth] = '1';
    generateCodes(root->right, codes, code, depth + 1);
}

// Function to encode data using the generated codes
void encodeData(char *data, char *codes[], int size) {
    for (int i = 0; data[i] != '\0'; i++) {
        char c = data[i];
        if (codes[(unsigned char)c] != NULL) {
            printf("%s", codes[(unsigned char)c]);
        }
    }
    printf("\n");
}

// Function to decode data
void decodeData(char *encodedData, Node *root) {
    Node *current = root;
    for (int i = 0; encodedData[i] != '\0'; i++) {
        current = (encodedData[i] == '0') ? current->left : current->right;
        
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->character);
            current = root; // Reset to root
        }
    }
    printf("\n");
}

// Function to free the Huffman Tree
void freeHuffmanTree(Node *root) {
    if (root == NULL) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}