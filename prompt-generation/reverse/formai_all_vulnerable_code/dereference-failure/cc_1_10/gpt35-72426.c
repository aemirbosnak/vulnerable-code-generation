//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// defining the structure of the Huffman tree nodes
struct HuffmanNode
{
    unsigned freq;  // frequency of the character
    char data;      // character data
    struct HuffmanNode *left, *right;  // pointers to the left and right child nodes
};

// defining the structure of the priority queue for Huffman Coding
struct PriorityQueue
{
    int size;
    int capacity;
    struct HuffmanNode **array;  // array of Huffman tree nodes
};

// function to create a new Huffman tree node
struct HuffmanNode* newNode(char data, unsigned freq)
{
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// function to create a new priority queue
struct PriorityQueue* createPriorityQueue(int capacity)
{
    struct PriorityQueue* queue = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (struct HuffmanNode**) malloc(queue->capacity * sizeof(struct HuffmanNode*));
    return queue;
}

// swapping function for sorting the nodes in a priority queue
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b)
{
    struct HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

// function to check if the priority queue is empty
bool isQueueEmpty(struct PriorityQueue* queue)
{
    return (queue->size == 0);
}

// function to get the minimum node from a priority queue
struct HuffmanNode* dequeue(struct PriorityQueue* queue)
{
    if (isQueueEmpty(queue)) return NULL;
    struct HuffmanNode* node = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    return node;
}

// function to heapify the priority queue
void minHeapify(struct PriorityQueue* queue, int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if (leftChild < queue->size && queue->array[leftChild]->freq < queue->array[smallest]->freq) smallest = leftChild;
    if (rightChild < queue->size && queue->array[rightChild]->freq < queue->array[smallest]->freq) smallest = rightChild;
    if (smallest != index)
    {
        swapNodes(&queue->array[smallest], &queue->array[index]);
        minHeapify(queue, smallest);
    }
}

// function to insert a node into the priority queue
void enqueue(struct PriorityQueue* queue, struct HuffmanNode* node)
{
    ++queue->size;
    int newIndex = queue->size - 1;
    int parentIndex = (newIndex - 1) / 2;
    queue->array[newIndex] = node;
    while (newIndex != 0 && queue->array[parentIndex]->freq > queue->array[newIndex]->freq)
    {
        swapNodes(&queue->array[newIndex], &queue->array[parentIndex]);
        newIndex = parentIndex;
        parentIndex = (newIndex - 1) / 2;
    }
}

// function to build the Huffman tree using the priority queue
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct HuffmanNode *left, *right, *top;
    struct PriorityQueue* queue = createPriorityQueue(size);
    for (int i = 0; i < size; ++i) enqueue(queue, newNode(data[i], freq[i]));
    while (queue->size != 1)
    {
        left = dequeue(queue);
        right = dequeue(queue);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        enqueue(queue, top);
    }
    return dequeue(queue);
}

// function for printing the Huffman codes for each character in the Huffman tree
void printCodes(struct HuffmanNode* root, int arr[], int top)
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
    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) printf("%d", arr[i]);
        printf("\n");
    }
}

// main function
int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
    return 0;
}