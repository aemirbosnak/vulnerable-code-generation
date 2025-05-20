//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Define the maximum input size
#define MAX_INPUT_SIZE 100
 
// Define the maximum length of a Huffman code
#define MAX_HUFFMAN_CODE_LENGTH 20
 
// Define the maximum number of Huffman codes
#define MAX_HUFFMAN_CODES 256
 
// Define the Huffman code 
typedef struct
{
    unsigned char symbol;        // the ASCII character
    char code[MAX_HUFFMAN_CODE_LENGTH];  // the Huffman code for the character
    int length;                 // the length of the Huffman code
} HuffmanCode;
 
// Define the node for the Huffman tree
typedef struct node
{
    unsigned char value;
    int frequency;
    struct node* left;
    struct node* right;
} Node;
 
// Define the priority queue for building the Huffman tree
typedef struct queue
{
    int size;
    int capacity;
    Node** nodes;
} Queue;
 
// Function to print the Huffman codes
void printHuffmanCodes(HuffmanCode* huffmanCodes, int size)
{
    printf("Huffman Codes:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c : %s\n", huffmanCodes[i].symbol, huffmanCodes[i].code);
    }
}
 
// Function to swap two nodes in the priority queue
void swap(Node** x, Node** y)
{
    Node* temp = *x;
    *x = *y;
    *y = temp;
}
 
// Function to return the index of the parent node
int getParentIndex(int index)
{
    return (index - 1) / 2;
}
 
// Function to return the index of the left child node
int getLeftChildIndex(int index)
{
    return (2 * index) + 1;
}
 
// Function to return the index of the right child node
int getRightChildIndex(int index)
{
    return (2 * index) + 2;
}
 
// Function to check if the heap is empty
int isEmpty(Queue* q)
{
    return (q->size == 0);
}
 
// Function to check if the heap is full
int isFull(Queue* q)
{
    return (q->size == q->capacity);
}
 
// Function to create a new node
Node* newNode(unsigned char value, int frequency)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
// Function to create a new priority queue
Queue* newQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (Node**)malloc(sizeof(Node*) * capacity);
    return queue;
}
 
// Function to insert a node into the priority queue
void insert(Queue* q, Node* node)
{
    if (isFull(q))
    {
        return;
    }
 
    int i = q->size;
    q->nodes[i] = node;
    q->size++;
 
    while (i != 0 && q->nodes[getParentIndex(i)]->frequency > q->nodes[i]->frequency)
    {
        swap(&q->nodes[getParentIndex(i)], &q->nodes[i]);
        i = getParentIndex(i);
    }
}
 
// Function to remove the minimum value (i.e. the root) from the priority queue
Node* removeMin(Queue* q)
{
    if (isEmpty(q))
    {
        return NULL;
    }
 
    Node* root = q->nodes[0];
    q->size--;
    q->nodes[0] = q->nodes[q->size];
 
    int i = 0;
    while (getLeftChildIndex(i) < q->size)
    {
        int leftChildIndex = getLeftChildIndex(i);
        int rightChildIndex = getRightChildIndex(i);
        int minIndex = i;
 
        if (q->nodes[leftChildIndex]->frequency < q->nodes[minIndex]->frequency)
        {
            minIndex = leftChildIndex;
        }
 
        if (rightChildIndex < q->size && q->nodes[rightChildIndex]->frequency < q->nodes[minIndex]->frequency)
        {
            minIndex = rightChildIndex;
        }
 
        if (minIndex != i)
        {
            swap(&q->nodes[i], &q->nodes[minIndex]);
            i = minIndex;
        }
        else
        {
            break;
        }
    }
 
    return root;
}
 
// Function to build the Huffman tree
Node* buildHuffmanTree(int* frequencyTable)
{
    Queue* q = newQueue(MAX_HUFFMAN_CODES);
 
    for (int i = 0; i < MAX_HUFFMAN_CODES; i++)
    {
        if (frequencyTable[i] != 0)
        {
            Node* node = newNode((unsigned char)i, frequencyTable[i]);
            insert(q, node);
        }
    }
 
    while (q->size > 1)
    {
        Node* left = removeMin(q);
        Node* right = removeMin(q);
 
        Node* parent = newNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
 
        insert(q, parent);
    }
 
    Node* root = removeMin(q);
    return root;
}
 
// Function to traverse the Huffman tree and assign codes
void traverseHuffmanTree(Node* node, char* code, int length, HuffmanCode* huffmanCodes, int* index)
{
    if (node->left == NULL && node->right == NULL)
    {
        HuffmanCode huffmanCode;
        huffmanCode.symbol = node->value;
        strcpy(huffmanCode.code, code);
        huffmanCode.length = length;
        huffmanCodes[*index] = huffmanCode;
        (*index)++;
    }
    else
    {
        char leftCode[MAX_HUFFMAN_CODE_LENGTH] = "";
        char rightCode[MAX_HUFFMAN_CODE_LENGTH] = "";
        strcpy(leftCode, code);
        strcat(leftCode, "0");
        strcpy(rightCode, code);
        strcat(rightCode, "1");
 
        traverseHuffmanTree(node->left, leftCode, length + 1, huffmanCodes, index);
        traverseHuffmanTree(node->right, rightCode, length + 1, huffmanCodes, index);
    }
}
 
// Function to generate the Huffman codes
void generateHuffmanCodes(Node* root, HuffmanCode* huffmanCodes)
{
    char code[MAX_HUFFMAN_CODE_LENGTH] = "";
    int length = 0;
    int index = 0;
 
    traverseHuffmanTree(root, code, length, huffmanCodes, &index);
}
 
int main()
{
    char input[MAX_INPUT_SIZE] = "";
    int frequencyTable[MAX_HUFFMAN_CODES] = { 0 };
 
    printf("Enter input:\n");
    fgets(input,MAX_INPUT_SIZE,stdin);
 
    // Process input to generate frequency table
    for (int i = 0; i < strlen(input); i++)
    {
        frequencyTable[(int)input[i]]++;
    }
 
    // Build Huffman tree
    Node* root = buildHuffmanTree(frequencyTable);
 
    // Generate Huffman codes
    HuffmanCode huffmanCodes[MAX_HUFFMAN_CODES];
    generateHuffmanCodes(root, huffmanCodes);
 
    // Print Huffman codes
    printHuffmanCodes(huffmanCodes, MAX_HUFFMAN_CODES);
 
    return 0;
}