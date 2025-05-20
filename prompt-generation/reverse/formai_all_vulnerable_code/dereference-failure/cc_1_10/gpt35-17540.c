//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// A Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
};

// A Min Heap node
struct MinHeapNode {
    struct Node *node;
    struct MinHeapNode *next;
};

// Min Heap
struct MinHeap {
    unsigned size;
    struct MinHeapNode *head, *tail;
};

// Function to create a new Min Heap node
struct MinHeapNode* createMinHeapNode(struct Node *node) {
    struct MinHeapNode* newNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Huffman tree node
struct Node* createNode(char data, unsigned frequency) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    newNode->frequency = frequency;
    return newNode;
}

// Function to compare two Min Heap nodes
int compareNodes(struct MinHeapNode* a, struct MinHeapNode* b) {
    return (a->node->frequency) < (b->node->frequency);
}

// Function to swap two Min Heap nodes
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to insert a new Min Heap node
void insertMinHeap(struct MinHeap* heap, struct Node *node) {
    struct MinHeapNode* newNode = createMinHeapNode(node);
    if (!heap->tail) {
        heap->head = heap->tail = newNode;
    } else {
        heap->tail->next = newNode;
        heap->tail = newNode;
    }
    heap->size++;
    struct MinHeapNode *current = heap->tail;
    while (current != heap->head && compareNodes(current, current->next)) {
        swapNodes(&current, &(current->next));
        current = current->next;
    }
}

// Function to extract the minimum node from Min Heap
struct Node* extractMin(struct MinHeap* heap) {
    if (!heap->size) {
        return NULL;
    }
    struct MinHeapNode* head = heap->head;
    struct Node* node = head->node;
    heap->head = head->next;
    heap->size--;
    free(head);
    return node;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char *text) {
    int count[256] = {0};
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        count[(int)text[i]]++;
    }
    struct MinHeap* heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->head = heap->tail = NULL;
    for (int i = 0; i < 256; i++) {
        if (count[i]) {
            struct Node* node = createNode((char)i, count[i]);
            insertMinHeap(heap, node);
        }
    }
    while (heap->size > 1) {
        struct Node *left = extractMin(heap);
        struct Node *right = extractMin(heap);
        struct Node* node = createNode('$', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        insertMinHeap(heap, node);
    }
    return extractMin(heap);
}

// Function to perform the Huffman coding
void performHuffmanCoding(struct Node *root, char *str, int top, char **codes) {
    if (root->left) {
        str[top] = '0';
        performHuffmanCoding(root->left, str, top + 1, codes);
    }
    if (root->right) {
        str[top] = '1';
        performHuffmanCoding(root->right, str, top + 1, codes);
    }
    if (!root->left && !root->right) {
        str[top] = '\0';
        int index = (int)root->data;
        codes[index] = (char*) malloc(top + 1);
        strcpy(codes[index], str);
    }
}

// Main function
int main() {
    char text[] = "Huffman Coding Example";
    struct Node* root = buildHuffmanTree(text);
    char *str = (char*) malloc(256 * sizeof(char));
    char **codes = (char**) malloc(256 * sizeof(char*));
    performHuffmanCoding(root, str, 0, codes);
    printf("Char\tFrequency\tCode\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i]) {
            printf("%c\t%d\t\t%s\n", i, (int)codes[i][0], codes[i]);
        }
    }
    return 0;
}