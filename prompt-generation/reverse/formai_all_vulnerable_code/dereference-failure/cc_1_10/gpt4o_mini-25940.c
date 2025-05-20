//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char character, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct MinHeap {
    int size;
    Node* array[MAX_TREE_NODES];
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size] = node;
    int idx = minHeap->size;
    minHeap->size++;
    while (idx && minHeap->array[idx]->frequency < minHeap->array[(idx - 1) / 2]->frequency) {
        swapNode(&minHeap->array[idx], &minHeap->array[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

void printCodes(Node* root, char* arr, int top) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%c", arr[i]);
        printf("\n");
    }
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node* left, * right, * top;
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++)
        insertMinHeap(minHeap, createNode(data[i], freq[i]));
    
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void encode(char* input) {
    int freq[MAX_TREE_NODES] = {0};
    char data[MAX_TREE_NODES];
    int size = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        if (freq[(unsigned char)input[i]] == 0) {
            data[size++] = input[i];
        }
        freq[(unsigned char)input[i]]++;
    }
    
    Node* root = buildHuffmanTree(data, freq, size);
    char arr[MAX_CODE_LENGTH];
    printf("Huffman Codes:\n");
    printCodes(root, arr, 0);
}

int main() {
    char input[100];
    printf("Enter a string to encode: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline
    
    encode(input);
    return 0;
}