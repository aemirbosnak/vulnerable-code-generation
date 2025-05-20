//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// Function to create a Huffman Tree Node
struct Node* createNode(char data, unsigned freq)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// Function to create a priority queue for Huffman Tree
struct Queue {
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

// Function to create a new node with given data
struct Node* newNode(char data, unsigned freq);

// Function to create a priority queue with given capacity
struct Queue* createQueue(unsigned capacity);

// Function to check if size of queue is 1
int isSizeOne(struct Queue* queue);

// Function to check if given character is a leaf node
int isLeaf(struct Node* root);

// Function to swap two nodes of the queue
void swapNode(struct Node** node1, struct Node** node2);

// Function to create min-heap queue
void minHeapify(struct Queue* queue, int index);

// Function to check if queue is empty
int isQueueEmpty(struct Queue* queue);

// Function to extract the minimum node from queue
struct Node* extractMin(struct Queue* queue);

// Function to insert node into queue
void insertNode(struct Queue* queue, struct Node* node);

// Function to build Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int size);

// Function to encode Huffman Tree
void encodeHuffmanTree(struct Node* root, int arr[], int top);

// Function to print Huffman Code for each character
void printHuffmanCodes(struct Node* root, int arr[], int top);

// Main driver function
int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, size);

    int arr[100], top = 0;
    printHuffmanCodes(root, arr, top);

    return 0;
}


// Function to create a new node with given data
struct Node* newNode(char data, unsigned freq)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// Function to create a priority queue with given capacity
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));

    return queue;
}

// Function to check if size of queue is 1
int isSizeOne(struct Queue* queue)
{
    return queue->size == 1;
}

// Function to check if given character is a leaf node
int isLeaf(struct Node* root)
{
    return !(root->left) && !(root->right);
}

// Function to swap two nodes of the queue
void swapNode(struct Node** node1, struct Node** node2)
{
    struct Node* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Function to create min-heap queue
void minHeapify(struct Queue* queue, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq)
        smallest = left;

    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swapNode(&queue->array[smallest], &queue->array[index]);
        minHeapify(queue, smallest);
    }
}

// Function to check if queue is empty
int isQueueEmpty(struct Queue* queue)
{
    return queue->size == 0;
}

// Function to extract the minimum node from queue
struct Node* extractMin(struct Queue* queue)
{
    struct Node* node = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return node;
}

// Function to insert node into queue
void insertNode(struct Queue* queue, struct Node* node)
{
    ++queue->size;
    int index = queue->size - 1;

    while (index && node->freq < queue->array[(index - 1) / 2]->freq) {
        queue->array[index] = queue->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    queue->array[index] = node;
}

// Function to build Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int size)
{
    struct Node* root, * left, * right;

    struct Queue* queue = createQueue(size);

    for (int i = 0; i < size; ++i)
        insertNode(queue, createNode(data[i], freq[i]));

    while (!isSizeOne(queue)) {
        left = extractMin(queue);
        right = extractMin(queue);

        root = createNode('$', left->freq + right->freq);
        root->left = left;
        root->right = right;

        insertNode(queue, root);
    }

    return extractMin(queue);
}

// Function to encode Huffman Tree
void encodeHuffmanTree(struct Node* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        encodeHuffmanTree(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        encodeHuffmanTree(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to print Huffman Code for each character
void printHuffmanCodes(struct Node* root, int arr[], int top)
{
    encodeHuffmanTree(root, arr, top);
}