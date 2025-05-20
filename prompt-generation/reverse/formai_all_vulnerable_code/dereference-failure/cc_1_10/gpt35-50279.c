//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode
{
    char data; // Character data
    unsigned freq; // Frequency of data
    struct MinHeapNode *left, *right; // Left and right child
}MinHeapNode;

typedef struct MinHeap
{
    unsigned size; // Size of heap
    unsigned capacity; // Capacity of heap
    MinHeapNode **heapArray; // Array of min heap nodes
}MinHeap;

typedef struct HuffmanNode
{
    char data; // Character data
    char *code; // Huffman code
}HuffmanNode;

typedef struct HuffmanTree
{
    unsigned size; // Number of nodes in the tree
    HuffmanNode **treeArray; // Array of huffman nodes
}HuffmanTree;

// Utility function to create a new min heap node
MinHeapNode* newMinHeapNode(char data, unsigned freq) 
{
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// Utility function to create a min heap
MinHeap* createMinHeap(unsigned capacity) 
{
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->heapArray = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));

    return minHeap;
}

// Utility function to swap two min heap nodes
void swapMinHeapNodes(MinHeapNode** node1, MinHeapNode** node2) 
{
    MinHeapNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Utility function to maintain the MinHeap property
void minHeapify(MinHeap* minHeap, int index) 
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < minHeap->size && minHeap->heapArray[leftChild]->freq < minHeap->heapArray[smallest]->freq)
    {
        smallest = leftChild;
    }

    if (rightChild < minHeap->size && minHeap->heapArray[rightChild]->freq < minHeap->heapArray[smallest]->freq) 
    {
        smallest = rightChild;
    }

    if (smallest != index) 
    {
        swapMinHeapNodes(&minHeap->heapArray[smallest], &minHeap->heapArray[index]);
        minHeapify(minHeap, smallest);
    }
}

// Check to see if the MinHeap is size 1
int isSizeOne(MinHeap* minHeap) 
{
    return (minHeap->size == 1);
}

// Extract the minimum value from the min heap
MinHeapNode* extractMin(MinHeap* minHeap) 
{
    MinHeapNode* temp = minHeap->heapArray[0];
    minHeap->heapArray[0] = minHeap->heapArray[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// Insert a min heap node into the min heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* node) 
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->heapArray[(i - 1) / 2]->freq) 
    {
        minHeap->heapArray[i] = minHeap->heapArray[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->heapArray[i] = node;
}

// Check to see if the given node is a leaf node
int isLeaf(MinHeapNode* root) 
{
    return !(root->left) && !(root->right);
}

// Create a min heap and add all characters with their frequencies to the heap
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
{
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) 
    {
        minHeap->heapArray[i] = newMinHeapNode(data[i], freq[i]);
    }

    minHeap->size = size;
    int n = minHeap->size - 1;

    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(minHeap, i);
    }

    return minHeap;
}

// Build the Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{
    MinHeapNode *left, *right, *top;

    // Create a minheap and add the root nodes
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) 
    {
        // Extract the minimum nodes from the min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create a new parent node
        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Insert the parent node back into the min heap
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Assign Huffman codes to each character
void HuffmanCodes(MinHeapNode* root, char str[], int top, HuffmanTree* huffmanTree) 
{
    // Check to make sure the passed node is not null
    if (root == NULL)
    {
        return;
    }

    // If a leaf node is found, print the huffman code for that character
    if (isLeaf(root)) 
    {
        int index = root->data - 'a';
        HuffmanNode* node = huffmanTree->treeArray[index];
        node->data = root->data;
        node->code = (char*) calloc(100, sizeof(char));
        strncpy(node->code, str, top);
    } 
    else 
    {
        // If a left child exists, add 0 to the huffman code string and traverse the left subtree
        str[top] = '0';
        HuffmanCodes(root->left, str, top + 1, huffmanTree);

        // If a right child exists, add 1 to the huffman code string and traverse the right subtree
        str[top] = '1';
        HuffmanCodes(root->right, str, top + 1, huffmanTree);
    }
}

// Print the Huffman codes for each character
void printHuffmanCodes(HuffmanTree* huffmanTree) 
{
    printf("Huffman Codes:\n");
    for (int i = 0; i < 26; ++i) 
    {
        HuffmanNode* node = huffmanTree->treeArray[i];
        printf("%c:%s\n", node->data, node->code);
    }
}

// Thread to build the Huffman Tree
void* HuffmanThread(void* arg)
{
    // Initialize the data and frequency arrays
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);

    // Create the huffman tree
    HuffmanTree* huffmanTree = (HuffmanTree*) malloc(sizeof(HuffmanTree));
    huffmanTree->size = size;
    huffmanTree->treeArray = (HuffmanNode**) malloc(size * sizeof(HuffmanNode*));

    for (int i = 0; i < size; ++i)
    {
        huffmanTree->treeArray[i] = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    }

    MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Initialize the huffman code string
    char str[MAX_TREE_HT];
    int top = 0;

    // Traverse the tree and assign huffman codes
    HuffmanCodes(root, str, top, huffmanTree);

    // Print the huffman codes
    printHuffmanCodes(huffmanTree);
}

int main()
{
    pthread_t tid;

    // Create a new thread to build the huffman tree
    pthread_create(&tid, NULL, HuffmanThread, NULL);

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    return 0;
}