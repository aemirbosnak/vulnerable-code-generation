//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// Structure to hold the Huffman Tree Node
struct node {
    char data;
    unsigned frequency;
    struct node *left, *right;
};

// Structure to hold a heap node
struct minHeapNode {
    struct node* data;
    unsigned frequency;
};

// Heap structure to hold all the nodes in the form of minHeapNodes
struct minHeap {
    unsigned capacity;
    unsigned size;
    struct minHeapNode** array;
};

// Function to create a new Huffman Tree Node
struct node* makeNode(char data, int frequency) {
    struct node* node =
        (struct node*) malloc(sizeof(struct node));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Function to create a new min heap node
struct minHeapNode* makeMinHeapNode(struct node* data, unsigned frequency)
{
    struct minHeapNode* node = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Function to create a min heap
struct minHeap* createMinHeap(unsigned capacity) {
    struct minHeap* minHeap =
        (struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (struct minHeapNode**)malloc(minHeap->
                                      capacity * sizeof(struct minHeapNode*));
    return minHeap;
}

// Function to swap two nodes
void swapMinHeapNode(struct minHeapNode** a,
                     struct minHeapNode** b)
{
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function to restore properties of the min heap
void minHeapify(struct minHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(struct minHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from the heap
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to add a new minHeapNode to the heap
void insertMinHeap(struct minHeap* minHeap, struct minHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct minHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to check if node is a leaf node
bool isLeaf(struct node* root) {
    return !(root->left) && !(root->right);
}

// Function to create the Huffman Tree
struct node* buildHuffmanTree(char data[], int frequency[], int size) {
    struct node *left, *right, *top;

    // Create a min heap and insert all the nodes from the frequency[] array
    struct minHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        insertMinHeap(minHeap, makeMinHeapNode(makeNode(data[i], frequency[i]), frequency[i]));

    buildMinHeap(minHeap);

    // While there is more than one node in the heap, keep extracting
    // minimum value nodes and create a new internal node and insert
    // it back into the heap. This repeats until the heap has only
    // one node left, which will be the root node of the Huffman Tree
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap)->data;
        right = extractMin(minHeap)->data;

        // Create a new internal node with 'data' equal to NULL and
        // frequency equal to the sum of 'left' and 'right's frequency
        // values, and left and right subtrees as the left and right children
        top = makeNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, makeMinHeapNode(top, top->frequency));
    }

    // Last value remaining in the min heap will be the root of the
    // Huffman Tree
    return extractMin(minHeap)->data;
}

// Function to print encoded message and corresponding Huffman codes
void printHuffmanCodes(struct node* root, int arr[], int top) {
    // If leaf node is reached, print the data and corresponding Huffman code
    if (isLeaf(root)) {
        printf("%c : ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }

    // If it is moving to the left, add "0" to the Huffman code
    arr[top] = 0;
    printHuffmanCodes(root->left, arr, top + 1);

    // If it is moving to the right, add "1" to the Huffman code
    arr[top] = 1;
    printHuffmanCodes(root->right, arr, top + 1);
}

// Code driver function
void HuffmanCodes(char data[], int frequency[], int size) {
    // Build the Huffman Tree
    struct node* root = buildHuffmanTree(data, frequency, size);

    // Print encoded message and corresponding Huffman codes
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, frequency, size);
    return 0;
}