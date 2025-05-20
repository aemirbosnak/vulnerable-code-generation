//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Asynchronous Huffman Coding Implementation

struct node
{
    char data;
    int freq;
    struct node *left;
    struct node *right;
};

struct node* getNode(char ch, int freq, struct node* left, struct node* right)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct MinHeap
{
    int size;
    int capacity;
    struct node** array;
};

struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->array = (struct node**)malloc(capacity * sizeof(struct node*));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    return minHeap;
}

void swapMinHeapNode(struct node** a, struct node** b)
{
    struct node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

struct node* extractMin(struct MinHeap* minHeap)
{
    struct node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct node* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct node* root)
{
    return !(root->left) && !(root->right) ;
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = getNode(data[i], freq[i], NULL, NULL);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct node* buildHuffmanTree(char data[], int freq[], int size)
{
    struct node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = getNode('$', left->freq + right->freq, left, right);
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct node* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf(" %c | ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct node* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main()
{
    char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'}; // Input "data" to be encoded
    int freq[6] = {5, 9, 12, 13, 16, 45}; // Frequency of Input data
    int size = sizeof(arr)/sizeof(arr[0]); // Size of array 
    printf("Data | Huffman Code\n");
    printf("-------------------\n");
    HuffmanCodes(arr, freq, size);
    return 0;
}