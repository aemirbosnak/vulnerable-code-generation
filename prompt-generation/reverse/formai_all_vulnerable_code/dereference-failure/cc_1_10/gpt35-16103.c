//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct MinHeapNode
{
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};

// MinHeap that stores Huffman tree nodes
struct MinHeap
{
    int size;
    int capacity;
    struct MinHeapNode **array;
};

// Helper function to create a new MinHeap node
struct MinHeapNode* newNode(char data, int freq)
{
    struct MinHeapNode* tmp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    tmp->left = tmp->right = NULL;
    tmp->data = data;
    tmp->freq = freq;
    return tmp;
}

// Helper function to swap two MinHeap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Helper function to heapify a MinHeap subtree rooted at index i
void minHeapify(struct MinHeap* minHeap, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < minHeap->size &&
        minHeap->array[l]->freq < minHeap->array[smallest]->freq)
        smallest = l;

    if (r < minHeap->size &&
        minHeap->array[r]->freq < minHeap->array[smallest]->freq)
        smallest = r;

    if (smallest != i)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[i]);
        minHeapify(minHeap, smallest);
    }
}

// Helper function to check if MinHeap has size 1
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// Helper function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* tmp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return tmp;
}

// Helper function to insert a new node to MinHeap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Helper function to build MinHeap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Helper function to check if a given node is leaf node
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Create a MinHeap of given capacity
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Returns root of Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    // Step 1: Create a min heap of capacity equal to size.\
    And insert all character data and frequency.
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    // Step 2: Extract two minimum freq items from heap
    // Iterate until we only have one node left in heap
    while (!isSizeOne(minHeap))
    {
        // First min freq item
        left = extractMin(minHeap);

        // Second min freq item
        right = extractMin(minHeap);

        // Create new internal node as parent, with frequency equal to the sum of the children nodes
        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        // Insert parent node to MinHeap
        insertMinHeap(minHeap, top);
    }

    // The remaining node is the root node
    return extractMin(minHeap);
}

// Helper function to print Huffman codes from the root of the Huffman tree
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    // Assign 0 to left branch and iterate to print the code
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right branch and iterate to print the code
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // Handle the case of a leaf node. Print the character and the code
    if (isLeaf(root))
    {
        printf(" %c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function to build the entire Huffman code dictionary
void HuffmanCodes(char data[], int freq[], int size)
{
    // Build the Huffman tree and store the root node
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Print the code dictionary from the root node
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// Testing program
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    printf("Huffman codes:\n");
    HuffmanCodes(data, freq, size);

    return 0;
}