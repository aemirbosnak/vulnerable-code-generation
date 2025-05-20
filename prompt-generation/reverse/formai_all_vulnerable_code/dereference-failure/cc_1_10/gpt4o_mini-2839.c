//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *nodes[MAX_TREE_NODES];
    int count;
} MinHeap;

Node *createNode(char character, unsigned frequency) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeap *createHeap() {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->count = 0;
    return heap;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(MinHeap *heap, Node *node) {
    heap->nodes[heap->count++] = node;
}

void buildHeap(MinHeap *heap) {
    for (int i = (heap->count / 2) - 1; i >= 0; i--) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        
        if (left < heap->count && heap->nodes[left]->frequency < heap->nodes[largest]->frequency) {
            largest = left;
        }
        
        if (right < heap->count && heap->nodes[right]->frequency < heap->nodes[largest]->frequency) {
            largest = right;
        }
        
        if (largest != i) {
            swap(&heap->nodes[i], &heap->nodes[largest]);
        }
    }
}

Node *removeMin(MinHeap *heap) {
    if (heap->count <= 0) return NULL;
    Node *minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->count];
    buildHeap(heap);
    return minNode;
}

Node *buildHuffmanTree(char *data, int *freq, int size) {
    MinHeap *heap = createHeap();

    for (int i = 0; i < size; i++) {
        insertHeap(heap, createNode(data[i], freq[i]));
    }

    buildHeap(heap);

    while (heap->count > 1) {
        Node *left = removeMin(heap);
        Node *right = removeMin(heap);
        Node *parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        insertHeap(heap, parent);
        buildHeap(heap);
    }

    Node *root = removeMin(heap);
    free(heap);
    return root;
}

void generateCodes(Node *root, char **codes, char *codeBuffer, int depth) {
    if (root->left) {
        codeBuffer[depth] = '0';
        generateCodes(root->left, codes, codeBuffer, depth + 1);
    }

    if (root->right) {
        codeBuffer[depth] = '1';
        generateCodes(root->right, codes, codeBuffer, depth + 1);
    }

    if (!(root->left) && !(root->right)) {
        codeBuffer[depth] = '\0';
        codes[(unsigned char)root->character] = strdup(codeBuffer);
    }
}

void huffmanCoding(char *data, int *frequencies, int size) {
    Node *root = buildHuffmanTree(data, frequencies, size);
    char *codes[MAX_TREE_NODES] = { NULL };
    char codeBuffer[MAX_TREE_NODES];
    generateCodes(root, codes, codeBuffer, 0);

    printf("Character Codes:\n");
    for (int i = 0; i < size; i++) {
        printf("%c: %s\n", data[i], codes[(unsigned char)data[i]]);
        free(codes[(unsigned char)data[i]]);
    }
}

void decodeHuffman(Node *root, const char *str) {
    Node *current = root;
    printf("Decoded String: ");
    for (int i = 0; str[i]; i++) {
        current = (str[i] == '0') ? current->left : current->right;
        if (!(current->left) && !(current->right)) {
            putchar(current->character);
            current = root;
        }
    }
    putchar('\n');
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e' };
    int freq[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(data) / sizeof(data[0]);

    huffmanCoding(data, freq, size);

    char *encodedString = "110011001111"; // Example encoded string
    Node *root = buildHuffmanTree(data, freq, size); // recreate tree for decoding
    decodeHuffman(root, encodedString);

    return 0;
}