//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
// Huffman Coding Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman Tree
struct HuffmanTreeNode
{
    char data;
    unsigned frequency;
    struct HuffmanTreeNode *left, *right;
};

// Create a new Node
struct HuffmanTreeNode* createNode(char data, unsigned frequency)
{
    struct HuffmanTreeNode* node = (struct HuffmanTreeNode*)malloc(sizeof(struct HuffmanTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// In order traversal of Huffman Tree
void inOrderTraversal(struct HuffmanTreeNode* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%c - %d\n", root->data, root->frequency);
        inOrderTraversal(root->right);
    }
}

// Creating a Min Heap
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct HuffmanTreeNode** array;
};

struct MinHeap* createHeap(unsigned capacity)
{
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HuffmanTreeNode**)malloc(heap->capacity * sizeof(struct HuffmanTreeNode*));
    return heap;
}

void swapNodes(struct HuffmanTreeNode** x, struct HuffmanTreeNode** y)
{
    struct HuffmanTreeNode* temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(struct MinHeap* heap, int index)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
    {
        smallest = left;
    }
    if(right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
    {
        smallest = right;
    }
    if(smallest != index)
    {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(struct MinHeap* heap)
{
    return heap->size == 1;
}

struct HuffmanTreeNode* extractMin(struct MinHeap* heap)
{
    struct HuffmanTreeNode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insertHeap(struct MinHeap* heap, struct HuffmanTreeNode* node)
{
    heap->size++;
    int i = heap->size - 1;
    while(i != 0 && node->frequency < heap->array[(i-1)/2]->frequency)
    {
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }
    heap->array[i] = node;
}

int isLeaf(struct HuffmanTreeNode* root)
{
    return !(root->left) && !(root->right);
}

struct HuffmanTreeNode* buildHuffmanTree(char data[], int frequency[], int size)
{
    struct HuffmanTreeNode *left, *right, *top;
    struct MinHeap* heap = createHeap(size);
    for(int i=0; i<size; ++i)
    {
        insertHeap(heap, createNode(data[i], frequency[i]));
    }
    while(!isSizeOne(heap))
    {
        left = extractMin(heap);
        right = extractMin(heap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertHeap(heap, top);
    }
    return extractMin(heap);
}

void printCodes(struct HuffmanTreeNode* root, int arr[], int top)
{
    if(root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(isLeaf(root))
    {
        printf("%c: ", root->data);
        for(int i=0; i<top; ++i)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[], int frequency[], int size)
{
    struct HuffmanTreeNode* root = buildHuffmanTree(data, frequency, size);
    int arr[100], top=0;
    printCodes(root, arr, top);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    printf("Huffman Codes:\n");
    HuffmanCodes(data, frequency, size);
    return 0;
}