//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char symbol;
    unsigned frequency;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* array[MAX_TREE_NODES];
    int size;
} MinHeap;

Node* createNode(char symbol, unsigned frequency);
MinHeap* createMinHeap();
void insertMinHeap(MinHeap* heap, Node* node);
Node* extractMin(MinHeap* heap);
void buildMinHeap(MinHeap* heap);
void buildHuffmanTree(MinHeap* heap);
void printCodes(Node* root, char* code, int depth);
void encode(const char* input);
void decode(Node* root, const char* encoded);
void freeTree(Node* root);

int main() {
    const char* input = "hello huffman";
    printf("Input: %s\n", input);
    
    encode(input);
    return 0;
}

Node* createNode(char symbol, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

void insertMinHeap(MinHeap* heap, Node* node) {
    heap->array[heap->size++] = node;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

Node* extractMin(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    
    int i = 0, child;
    while (i * 2 + 1 < heap->size) {
        child = i * 2 + 1;
        if (child + 1 < heap->size && heap->array[child + 1]->frequency < heap->array[child]->frequency)
            child++;
        
        if (heap->array[i]->frequency > heap->array[child]->frequency) {
            Node* swap = heap->array[i];
            heap->array[i] = heap->array[child];
            heap->array[child] = swap;
            i = child;
        } else {
            break;
        }
    }
    return temp;
}

void buildMinHeap(MinHeap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        Node* temp = extractMin(heap);
        insertMinHeap(heap, temp);
    }
}

void buildHuffmanTree(MinHeap* heap) {
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insertMinHeap(heap, combined);
    }
}

void printCodes(Node* root, char* code, int depth) {
    if (root->left) {
        code[depth] = '0';
        printCodes(root->left, code, depth + 1);
    }

    if (root->right) {
        code[depth] = '1';
        printCodes(root->right, code, depth + 1);
    }

    if (!(root->left) && !(root->right)) {
        code[depth] = '\0';
        printf("Symbol: '%c' Code: %s\n", root->symbol, code);
    }
}

void encode(const char* input) {
    unsigned frequency[MAX_TREE_NODES] = {0};

    for (int i = 0; input[i] != '\0'; i++) {
        frequency[(unsigned char)input[i]]++;
    }

    MinHeap* heap = createMinHeap();
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (frequency[i] > 0) {
            Node* newNode = createNode((char)i, frequency[i]);
            insertMinHeap(heap, newNode);
        }
    }

    buildHuffmanTree(heap);
    char code[MAX_TREE_NODES];
    printCodes(extractMin(heap), code, 0);
}

void decode(Node* root, const char* encoded) {
    Node* current = root;
    for (int i = 0; encoded[i] != '\0'; i++) {
        current = (encoded[i] == '0') ? current->left : current->right;

        if (!(current->left) && !(current->right)) {
            printf("%c", current->symbol);
            current = root;
        }
    }
    printf("\n");
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}