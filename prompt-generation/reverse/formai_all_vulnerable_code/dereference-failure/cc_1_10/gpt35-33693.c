//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char alpha;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Heap {
    int size;
    int capacity;
    Node** array;
} Heap;

Node* createNode(char alpha, int freq) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->alpha = alpha;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node**) malloc(heap->capacity * sizeof(Node*));
    return heap;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap* heap, int index) {
    int minIndex = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size &&
        heap->array[left]->freq < heap->array[minIndex]->freq)
        minIndex = left;
    if (right < heap->size &&
        heap->array[right]->freq < heap->array[minIndex]->freq)
        minIndex = right;
    if (minIndex != index) {
        swapNodes(&heap->array[minIndex], &heap->array[index]);
        heapify(heap, minIndex);
    }
}

void buildHeap(Heap* heap) {
    int n = heap->size;
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(heap, i);
}

void insertIntoHeap(Heap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

Node* extractMin(Heap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}

int isLeaf(Node* node) {
    return !(node->left) && !(node->right);
}

Heap* buildHuffmanTree(char* string) {
    Heap* heap = createHeap(50);
    int count[256] = { 0 };
    for (int i = 0; string[i]; i++)
        count[string[i]]++;
    for (int i = 0; i < 256; i++)
        if (count[i])
            insertIntoHeap(heap, createNode(i, count[i]));
    while (heap->size != 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* parent =
            createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insertIntoHeap(heap, parent);
    }
    return heap;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->alpha);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char* string =
        "O Romeo, Romeo, wherefore art thou Romeo? \
        Deny thy father and refuse thy name;\
        And I'll no longer be a Capulet.";
    Heap* heap = buildHuffmanTree(string);
    int arr[100], top = 0;
    Node* root = extractMin(heap);
    printf("Huffman Codes are:\n");
    printCodes(root, arr, top);
    return 0;
}