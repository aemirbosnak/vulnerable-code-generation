//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

Node* createNode(char character, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct Heap {
    Node* array[MAX_TREE_NODES];
    int size;
} Heap;

Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    return heap;
}

void insertHeap(Heap* heap, Node* node) {
    int i = heap->size++;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

Node* extractMin(Heap* heap) {
    if (heap->size == 0) return NULL;
    Node* minNode = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= heap->size) break;
        int smallest = (right < heap->size && heap->array[right]->frequency < heap->array[left]->frequency) ? right : left;
        if (heap->array[i]->frequency <= heap->array[smallest]->frequency) break;
        Node* temp = heap->array[i];
        heap->array[i] = heap->array[smallest];
        heap->array[smallest] = temp;
        i = smallest;
    }
    return minNode;
}

void buildHuffmanTree(Heap* heap) {
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insertHeap(heap, combined);
    }
}

void generateCodes(Node* root, char codes[MAX_TREE_NODES][MAX_CODE_LENGTH], char* code, int depth) {
    if (root->left) {
        code[depth] = '0';
        generateCodes(root->left, codes, code, depth + 1);
    }
    if (root->right) {
        code[depth] = '1';
        generateCodes(root->right, codes, code, depth + 1);
    }
    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->character], code);
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char text[1000];
    printf("Enter a string to encode: ");
    fgets(text, sizeof(text), stdin);
    
    unsigned frequency[MAX_TREE_NODES] = {0};
    for (int i = 0; text[i]; i++) {
        frequency[(unsigned char)text[i]]++;
    }
    
    Heap* heap = createHeap();
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (frequency[i]) {
            insertHeap(heap, createNode((char)i, frequency[i]));
        }
    }
    
    buildHuffmanTree(heap);
    Node* root = extractMin(heap);
    
    char codes[MAX_TREE_NODES][MAX_CODE_LENGTH] = {0};
    char code[MAX_CODE_LENGTH] = {0};
    generateCodes(root, codes, code, 0);
    
    printf("Huffman Codes:\n");
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (codes[i][0] != '\0') {
            printf("'%c': %s\n", (char)i, codes[i]);
        }
    }
    
    printf("Encoded string:\n");
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 0) {
            printf("%s", codes[(unsigned char)text[i]]);
        }
    }
    
    freeTree(root);
    free(heap);
    return 0;
}