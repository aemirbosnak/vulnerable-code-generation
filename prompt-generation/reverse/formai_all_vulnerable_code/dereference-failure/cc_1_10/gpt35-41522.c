//FormAI DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODE_LEN 20

// Priority Queue Node
typedef struct pqNode
{
    unsigned char data;
    int freq;
    struct pqNode *left, *right;
} pqNode;

// Priority Queue
typedef struct pq
{
    int size;
    int capacity;
    pqNode** arr;
} pq;

// Huffman Node
typedef struct huffNode
{
    unsigned char data;
    char code[MAX_CODE_LEN];
    struct huffNode *left, *right;
} huffNode;

// Function declarations
pqNode* newPqNode(unsigned char data, int freq);
pq* createPq(int capacity);
void swapNodes(pqNode **a, pqNode **b);
void minHeapify(pq *Q, int i);
int isSizeOne(pq* Q);
pqNode* extractMin(pq* Q);
void insertPq(pq* Q, pqNode* root);
pqNode* buildHuffmanTree(char *text, int len);
void generateCodes(huffNode* root, char *code, int depth, int *freqTable);
void printCodes(huffNode* root, int *freqTable);
void compress(char *text, int len, huffNode* root);

// Create a new priority queue node
pqNode* newPqNode(unsigned char data, int freq)
{
    pqNode* node = (pqNode*) malloc(sizeof(pqNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Create a new priority queue
pq* createPq(int capacity)
{
    pq* Q = (pq*) malloc(sizeof(pq));
    Q->size = 0;
    Q->capacity = capacity;
    Q->arr = (pqNode**) malloc(capacity * sizeof(pqNode*));
    return Q;
}

// Swap two nodes
void swapNodes(pqNode **a, pqNode **b)
{
    pqNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the PQ
void minHeapify(pq *Q, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < Q->size && Q->arr[left]->freq < Q->arr[smallest]->freq)
        smallest = left;

    if (right < Q->size && Q->arr[right]->freq < Q->arr[smallest]->freq)
        smallest = right;

    if (smallest != i)
    {
        swapNodes(&Q->arr[i], &Q->arr[smallest]);
        minHeapify(Q, smallest);
    }
}

// Check if PQ has only one node
int isSizeOne(pq* Q)
{
    return Q->size == 1;
}

// Extract the node with minimum frequency
pqNode* extractMin(pq* Q)
{
    pqNode* node = Q->arr[0];
    Q->arr[0] = Q->arr[Q->size - 1];
    --Q->size;
    minHeapify(Q, 0);
    return node;
}

// Insert a new node in the PQ
void insertPq(pq* Q, pqNode* node)
{
    ++Q->size;
    int i = Q->size - 1;

    while (i && node->freq < Q->arr[(i - 1) / 2]->freq)
    {
        Q->arr[i] = Q->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    Q->arr[i] = node;
}

// Build the Huffman Tree
pqNode* buildHuffmanTree(char *text, int len)
{
    // Initialize the Frequency Table
    int i;
    int freqTable[MAX_CHARS] = {0};
    for (i = 0; i < len; ++i)
        ++freqTable[text[i]];

    // Create a priority queue with the characters
    pq* Q = createPq(len);
    for (i = 0; i < MAX_CHARS; ++i)
    {
        if (freqTable[i])
            insertPq(Q, newPqNode(i, freqTable[i]));
    }

    // Build the Huffman Tree
    while (!isSizeOne(Q))
    {
        pqNode *left = extractMin(Q);
        pqNode *right = extractMin(Q);

        pqNode *node = newPqNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;
        insertPq(Q, node);
    }

    // The final node is the root of the Huffman Tree
    return extractMin(Q);
}

// Generate the Huffman Codes
void generateCodes(huffNode* root, char *code, int depth, int *freqTable)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        strcpy(root->code, code);
        ++freqTable[root->data];
    }

    code[depth] = '0';
    code[depth+1] = '\0';
    generateCodes(root->left, code, depth+1, freqTable);

    code[depth] = '1';
    code[depth+1] = '\0';
    generateCodes(root->right, code, depth+1, freqTable);
}

// Print the Huffman Codes
void printCodes(huffNode* root, int *freqTable)
{
    printf("\n-- Huffman Codes --\n\n");
    int i;
    for (i = 0; i < MAX_CHARS; ++i)
    {
        if (freqTable[i])
            printf("%c: %s\n", i, root[i].code);
    }
}

// Compress the Text
void compress(char *text, int len, huffNode* root)
{
    printf("\n-- Compressed Text --\n\n");
    int i;
    for (i = 0; i < len; ++i)
        printf("%s", root[text[i]].code);
    printf("\n");
}

int main()
{
    char text[] = "hello world";
    int len = strlen(text);

    pqNode* root = buildHuffmanTree(text, len);

    huffNode rootCodes[MAX_CHARS];
    memset(rootCodes, 0, sizeof(rootCodes));

    char code[MAX_CODE_LEN];
    code[0] = '\0';

    int freqTable[MAX_CHARS] = {0};

    generateCodes(root, code, 0, freqTable);

    printCodes(rootCodes, freqTable);

    compress(text, len, rootCodes);

    return 0;
}