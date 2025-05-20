//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    int size;
    Node* array[MAX_TREE_NODES];
} MinHeap;

// Function to create a new node
Node* newNode(char character, unsigned frequency) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min heap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to insert a node into the min heap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size] = node;
    minHeap->size++;
}

// Function to build the min heap
void buildMinHeap(MinHeap* minHeap) {
    for (int i = (minHeap->size / 2) - 1; i >= 0; i--) {
        for (int j = 0; j < minHeap->size; j++) {
            if (minHeap->array[j]->frequency < minHeap->array[i]->frequency) {
                Node* temp = minHeap->array[i];
                minHeap->array[i] = minHeap->array[j];
                minHeap->array[j] = temp;
            }
        }
    }
}

// Function to extract the minimum node from the heap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    return temp;
}

// Function to create the Huffman tree
Node* buildHuffmanTree(char characters[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap();
    
    for (int i = 0; i < size; ++i) {
        Node* node = newNode(characters[i], freq[i]);
        insertMinHeap(minHeap, node);
    }

    buildMinHeap(minHeap);

    while (minHeap->size != 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);

        Node* sumNode = newNode('$', left->frequency + right->frequency);
        sumNode->left = left;
        sumNode->right = right;

        insertMinHeap(minHeap, sumNode);
        buildMinHeap(minHeap);
    }

    return extractMin(minHeap);
}

// Function to store the Huffman codes
void storeCodes(Node* root, char arr[], int top) {
    if (root->left) {
        arr[top] = '0';
        storeCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = '1';
        storeCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%c", arr[i]);
        }
        printf("\n");
    }
}

// Function to perform Huffman Coding on the input string
void huffmanCoding(char* input) {
    int freq[MAX_TREE_NODES] = {0};
    char characters[MAX_TREE_NODES];
    int size = 0;

    for (int i = 0; input[i]; i++) {
        unsigned char ch = input[i];
        if (freq[ch] == 0) {
            characters[size++] = ch;
        }
        freq[ch]++;
    }

    Node* root = buildHuffmanTree(characters, freq, size);
    char arr[MAX_TREE_NODES];
    storeCodes(root, arr, 0);
}

// Main function
int main() {
    char input[MAX_TREE_NODES];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    huffmanCoding(input);
    return 0;
}