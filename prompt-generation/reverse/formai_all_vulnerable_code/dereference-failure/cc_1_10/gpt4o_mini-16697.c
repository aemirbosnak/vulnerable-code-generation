//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

typedef struct Node {
    char character;
    unsigned freq;
    struct Node *left, *right;
} Node;

typedef struct Heap {
    Node *nodes[MAX_TREE_NODES];
    int size;
} Heap;

Node* createNode(char character, unsigned freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    return heap;
}

void insertHeap(Heap* heap, Node* node) {
    heap->nodes[heap->size++] = node;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Heap* heap, int idx) {
    int smallest = idx, left = 2*idx + 1, right = 2*idx + 2;
    if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&heap->nodes[smallest], &heap->nodes[idx]);
        minHeapify(heap, smallest);
    }
}

Node* extractMin(Heap* heap) {
    if (heap->size == 0) {
        return NULL;
    }
    Node* minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    minHeapify(heap, 0);
    return minNode;
}

int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

void buildHuffmanTree(Heap* heap) {
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* top = createNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertHeap(heap, top);
    }
}

void generateCodes(Node* root, char* code, int depth, char codes[256][MAX_CODE_LENGTH]) {
    if (isLeaf(root)) {
        code[depth] = '\0';
        codes[(unsigned char)root->character][0] = depth;
        strcpy(codes[(unsigned char)root->character] + 1, code);
        return;
    }
    if (root->left) {
        code[depth] = '0';
        generateCodes(root->left, code, depth + 1, codes);
    }
    if (root->right) {
        code[depth] = '1';
        generateCodes(root->right, code, depth + 1, codes);
    }
}

void encode(char* text, char codes[256][MAX_CODE_LENGTH], char* encodedStr) {
    for (int i = 0; text[i]; i++) {
        strcat(encodedStr, codes[(unsigned char)text[i]] + 1);
    }
}

void decode(Node* root, char* encodedStr) {
    Node* current = root;
    for (int i = 0; encodedStr[i]; i++) {
        current = encodedStr[i] == '0' ? current->left : current->right;
        if (isLeaf(current)) {
            printf("%c", current->character);
            current = root;
        }
    }
}

int main() {
    char text[] = "Huffman coding is a compression algorithm";
    int freq[MAX_TREE_NODES] = {0};
    
    for (int i = 0; text[i]; i++) {
        freq[(unsigned char)text[i]]++;
    }

    Heap* heap = createHeap();
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (freq[i]) {
            insertHeap(heap, createNode(i, freq[i]));
        }
    }

    buildHuffmanTree(heap);
    char codes[256][MAX_CODE_LENGTH] = {0};
    char code[MAX_CODE_LENGTH];

    generateCodes(extractMin(heap), code, 0, codes);
    
    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i][0]) {
            printf("Character: '%c' Code: %s\n", i, codes[i] + 1);
        }
    }

    char encodedStr[MAX_TREE_NODES * MAX_CODE_LENGTH] = "";
    encode(text, codes, encodedStr);
    printf("Encoded String:\n%s\n", encodedStr);

    printf("Decoded String:\n");
    decode(extractMin(heap), encodedStr);
    printf("\n");

    return 0;
}