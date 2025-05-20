//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *array[MAX_TREE_NODES];
    int size;
} MinHeap;

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->array[minHeap->size++] = node;
    for (int i = minHeap->size - 1; i > 0; i = (i - 1) / 2) {
        if (minHeap->array[i]->frequency < minHeap->array[(i - 1) / 2]->frequency) {
            Node* temp = minHeap->array[i];
            minHeap->array[i] = minHeap->array[(i - 1) / 2];
            minHeap->array[(i - 1) / 2] = temp;
        } else {
            break;
        }
    }
}

Node* removeMin(MinHeap* minHeap) {
    Node* minNode = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];    
    int i = 0, smallest = 0, left, right;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;
        if (left < minHeap->size && 
            minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
            smallest = left;
        }
        if (right < minHeap->size && 
            minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
            smallest = right;
        }
        if (smallest == i) break;
        Node* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[smallest];
        minHeap->array[smallest] = temp;
        i = smallest;
    }
    return minNode;
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createNode(characters[i], frequencies[i]));
    }

    while (minHeap->size > 1) {
        Node* left = removeMin(minHeap);
        Node* right = removeMin(minHeap);
        Node* internalNode = createNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        insertMinHeap(minHeap, internalNode);
    }

    return removeMin(minHeap);
}

void generateCodes(Node* root, int arr[], int top, char codes[][MAX_TREE_NODES]) {
    if (root->left) {
        arr[top] = 0;
        generateCodes(root->left, arr, top + 1, codes);
    }
    if (root->right) {
        arr[top] = 1;
        generateCodes(root->right, arr, top + 1, codes);
    }
    if (!root->left && !root->right) {
        codes[(unsigned char)root->character][0] = '\0';
        for (int i = 0; i < top; i++) {
            codes[(unsigned char)root->character][i + 1] = arr[i] + '0';
        }
        codes[(unsigned char)root->character][top + 1] = '\0';
    }
}

void printCodes(char codes[][MAX_TREE_NODES]) {
    printf("Character Codes:\n");
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (codes[i][0] != '\0') {
            printf("'%c': %s\n", i, codes[i] + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char characters[MAX_TREE_NODES];
    int frequencies[MAX_TREE_NODES] = {0};

    for (int i = 0; input[i] != '\0'; i++) {
        frequencies[(unsigned char)input[i]]++;
    }

    int size = 0;
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (frequencies[i] > 0) {
            characters[size++] = (char)i;
        }
    }

    Node* root = buildHuffmanTree(characters, frequencies, size);
    char codes[MAX_TREE_NODES][MAX_TREE_NODES] = {0};
    int arr[MAX_TREE_NODES], top = 0;

    generateCodes(root, arr, top, codes);
    printCodes(codes);

    return 0;
}