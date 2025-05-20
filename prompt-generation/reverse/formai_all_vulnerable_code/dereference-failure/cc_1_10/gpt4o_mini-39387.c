//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHARACTERS 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

Node* createNode(char character, unsigned frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node, aborting...\n");
        exit(EXIT_FAILURE);
    }
    newNode->left = newNode->right = NULL;
    newNode->character = character;
    newNode->frequency = frequency;
    return newNode;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node** heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left]->frequency < heap[smallest]->frequency) {
        smallest = left;
    }

    if (right < size && heap[right]->frequency < heap[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

Node* extractMin(Node** heap, int* size) {
    if (*size <= 0) {
        fprintf(stderr, "Heap is empty, inability to extract min...\n");
        exit(EXIT_FAILURE);
    }
    Node* minNode = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return minNode;
}

void insert(Node** heap, int* size, Node* node) {
    heap[(*size)++] = node;
    for (int i = (*size) / 2 - 1; i >= 0; i--) {
        minHeapify(heap, *size, i);
    }
}

Node* buildHuffmanTree(char characters[], int freq[], int size) {
    Node** heap = (Node**)malloc(size * sizeof(Node*));
    if (heap == NULL) {
        fprintf(stderr, "Memory allocation for heap failed, exiting...\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        heap[i] = createNode(characters[i], freq[i]);
    }

    int heapSize = size;

    while (heapSize > 1) {
        Node* left = extractMin(heap, &heapSize);
        Node* right = extractMin(heap, &heapSize);
        Node* newNode = createNode('$', left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        insert(heap, &heapSize, newNode);
    }

    Node* root = extractMin(heap, &heapSize);
    free(heap);
    return root;
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

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCoding(char characters[], int freq[], int size) {
    Node* root = buildHuffmanTree(characters, freq, size);
    int arr[MAX_TREE_HEIGHT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(characters) / sizeof(characters[0]);

    printf("Character Codes:\n");
    HuffmanCoding(characters, freq, size);

    return 0;
}