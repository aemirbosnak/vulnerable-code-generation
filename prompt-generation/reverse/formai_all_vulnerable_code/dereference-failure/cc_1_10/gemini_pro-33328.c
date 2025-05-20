//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int frequency;
    char character;
    struct _node *left;
    struct _node *right;
} node;

typedef struct _heap {
    node **heap;
    int size;
} heap;

node *createNode(char character, int frequency) {
    node *newNode = malloc(sizeof(node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

heap *createHeap(int size) {
    heap *newHeap = malloc(sizeof(heap));
    newHeap->heap = malloc(size * sizeof(node *));
    newHeap->size = 0;
    return newHeap;
}

void insertNode(heap *heap, node *newNode) {
    int i = heap->size;
    while (i > 0 && newNode->frequency < heap->heap[(i - 1) / 2]->frequency) {
        heap->heap[i] = heap->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->heap[i] = newNode;
    heap->size++;
}

node *extractNode(heap *heap) {
    node *root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    int i = 0;
    while (i < heap->size) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        int minChildIndex = i;
        if (leftChildIndex < heap->size && heap->heap[leftChildIndex]->frequency < heap->heap[minChildIndex]->frequency) {
            minChildIndex = leftChildIndex;
        }
        if (rightChildIndex < heap->size && heap->heap[rightChildIndex]->frequency < heap->heap[minChildIndex]->frequency) {
            minChildIndex = rightChildIndex;
        }
        if (minChildIndex == i) {
            break;
        }
        node *temp = heap->heap[i];
        heap->heap[i] = heap->heap[minChildIndex];
        heap->heap[minChildIndex] = temp;
        i = minChildIndex;
    }
    return root;
}

node *buildHuffmanTree(char *string, int size) {
    int frequencies[256] = {0};
    for (int i = 0; i < size; i++) {
        frequencies[string[i]]++;
    }
    heap *heap = createHeap(size);
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            insertNode(heap, createNode(i, frequencies[i]));
        }
    }
    while (heap->size > 1) {
        node *leftNode = extractNode(heap);
        node *rightNode = extractNode(heap);
        node *parentNode = createNode('\0', leftNode->frequency + rightNode->frequency);
        parentNode->left = leftNode;
        parentNode->right = rightNode;
        insertNode(heap, parentNode);
    }
    return extractNode(heap);
}

void printHuffmanCode(node *root, char *code, int length) {
    if (root->character != '\0') {
        printf("%c: %s\n", root->character, code);
        return;
    }
    code[length] = '0';
    printHuffmanCode(root->left, code, length + 1);
    code[length] = '1';
    printHuffmanCode(root->right, code, length + 1);
}

int main() {
    char string[] = "Hello, world!";
    int size = strlen(string);
    node *root = buildHuffmanTree(string, size);
    char code[size];
    printHuffmanCode(root, code, 0);
    return 0;
}