//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100
 
// structure to represent a node in Huffman Tree
struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};
 
// structure to represent heap
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};
 
// function to create a new min heap node
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 
// function for swapping two nodes in min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
// function for heapifying the min heap
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
 
// function to check size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
 
// function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}
 
// function to insert node into heap
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
 
// function to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 
// function to print Huffman codes of each character
void printHuffman(struct MinHeapNode* root, int arr[], int top)
{
    // if leaf node then print character and its code
    if (root->left)
    {
        arr[top] = 0;
        printHuffman(root->left, arr, top + 1);
    }
 
    if (root->right)
    {
        arr[top] = 1;
        printHuffman(root->right, arr, top + 1);
    }
 
    if (!(root->left) && !(root->right))
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}
 
// function to create the min heap and print Huffman codes
void Huffman(char data[], int freq[], int size)
{
    // initialize min heap with given characters and their frequency
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    // build Huffman tree
    while (!isSizeOne(minHeap))
    {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);
 
        struct MinHeapNode *top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
 
    // print Huffman codes
    int arr[MAX_TREE_HT], top = 0;
    printHuffman(extractMin(minHeap), arr, top);
}
 
// driver function
int main()
{
    // input data and frequency
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
 
    // call Huffman function
    Huffman(data, freq, size);
 
    return 0;
}