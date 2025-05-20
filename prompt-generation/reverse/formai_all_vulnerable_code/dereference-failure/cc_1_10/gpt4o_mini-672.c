//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHAR 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *nodes[MAX_CHAR];
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

void insertMinHeap(MinHeap* heap, Node* node) {
    int i = heap->size++;
    while (i && node->frequency < heap->nodes[(i - 1) / 2]->frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->nodes[i] = node;
}

Node* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    Node* root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];

    int i = 0, left, right;
    while ((left = 2 * i + 1) < heap->size) {
        right = left + 1;
        if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[left]->frequency) {
            left = right;
        }
        if (heap->nodes[i]->frequency <= heap->nodes[left]->frequency) break;
        
        Node* temp = heap->nodes[i];
        heap->nodes[i] = heap->nodes[left];
        heap->nodes[left] = temp;
        i = left;
    }
    return root;
}

void buildHuffmanTree(MinHeap* heap) {
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* merged = createNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        insertMinHeap(heap, merged);
    }
}

void generateHuffmanCodes(Node* root, char* code, int depth, char codes[MAX_CHAR][MAX_TREE_HEIGHT]) {
    if (root->left) {
        code[depth] = '0';
        generateHuffmanCodes(root->left, code, depth + 1, codes);
    }
    if (root->right) {
        code[depth] = '1';
        generateHuffmanCodes(root->right, code, depth + 1, codes);
    }
    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->character], code);
    }
}

void printHuffmanCodes(char codes[MAX_CHAR][MAX_TREE_HEIGHT]) {
    printf("Character Huffman Codes:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (strlen(codes[i]) > 0) {
            printf("'%c': %s\n", i, codes[i]);
        }
    }
}

int main() {
    char input[100];
    int frequency[MAX_CHAR] = {0};
    
    printf("Enter a string to encode: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        frequency[(unsigned char)input[i]]++;
    }

    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i]) {
            insertMinHeap(minHeap, createNode(i, frequency[i]));
        }
    }

    buildHuffmanTree(minHeap);
    Node* root = extractMin(minHeap);
    
    char codes[MAX_CHAR][MAX_TREE_HEIGHT] = {0};
    char code[MAX_TREE_HEIGHT];
    
    generateHuffmanCodes(root, code, 0, codes);
    printHuffmanCodes(codes);
    
    printf("\nEncoded output:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        printf("%s", codes[(unsigned char)input[i]]);
    }
    
    printf("\n");
    free(minHeap);
    
    return 0;
}