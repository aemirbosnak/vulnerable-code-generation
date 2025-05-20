//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode
{
    unsigned char data;
    unsigned freq;

    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct PriorityQueue
{
    int size;
    int capacity;
    HuffmanNode **nodes;
} PriorityQueue;

typedef struct EncodedText
{
    unsigned char *data;
    int size;
} EncodedText;

HuffmanNode* createNode(unsigned char data, unsigned freq)
{
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

PriorityQueue* createPriorityQueue(int capacity)
{
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (HuffmanNode**) malloc(queue->capacity * sizeof(HuffmanNode*));
 
   return queue;
}

void swapNodes(HuffmanNode** a, HuffmanNode** b)
{
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeap(PriorityQueue *queue, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->nodes[left]->freq < queue->nodes[smallest]->freq)
        smallest = left;

    if (right < queue->size && queue->nodes[right]->freq < queue->nodes[smallest]->freq)
        smallest = right;

    if (smallest != index)
    {
        swapNodes(&queue->nodes[smallest], &queue->nodes[index]);
        minHeap(queue, smallest);   
    }
}

int isLeaf(HuffmanNode* node)
{
    return !(node->left) && !(node->right);
}

PriorityQueue* createAndBuildPriorityQueue(unsigned char data[], unsigned freq[],
                                            int size)
{
    PriorityQueue* queue = createPriorityQueue(size);

    for (int i = 0; i < size; ++i)
        queue->nodes[i] = createNode(data[i], freq[i]);

    queue->size = size;
    for (int i = (queue->size - 1) / 2; i >= 0; --i)
        minHeap(queue, i);

    return queue;
}

HuffmanNode* buildHuffmanTree(unsigned char data[], unsigned freq[], int size)
{
    HuffmanNode *left, *right, *top;

    PriorityQueue* queue = createAndBuildPriorityQueue(data, freq, size);

    while (queue->size != 1) {

        left = queue->nodes[0];
        right = queue->nodes[1];

        queue->nodes[0] = createNode('$', left->freq + right->freq);
        queue->nodes[0]->left = left;
        queue->nodes[0]->right = right;

        queue->size = queue->size - 1;
  
        minHeap(queue, 0);
    }

    return queue->nodes[0];
}

void printCodesHelper(HuffmanNode* root, unsigned char *code, int top)
{
    if (root->left) {
        code[top] = '0';
        printCodesHelper(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printCodesHelper(root->right, code, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%c", code[i]);
        printf("\n");
    }
}   

void printCodes(HuffmanNode* root)
{
    unsigned char code[MAX_TREE_HT];
    printCodesHelper(root, code, 0);
}

void encodeHelper(HuffmanNode* root, unsigned char* data, int index, EncodedText *encoded)
{
    if (root->left) {
        encoded->size++;
        encodeHelper(root->left, data, index, encoded);
    }
 
    if (root->right) {
        encoded->size++;
        encodeHelper(root->right, data, index, encoded);
    }

    if (isLeaf(root)) {
        for (int i = 0; i < index; ++i) {
            encoded->data[encoded->size++] = data[i];
        }
    }
}

EncodedText encode(HuffmanNode* root, unsigned char* data, int size)
{
    EncodedText encoded;
    encoded.size = 0;
    encoded.data = (unsigned char*) calloc(size+1, sizeof(unsigned char));

    encodeHelper(root, data, 0, &encoded);

    return encoded;
}

void decodeHelper(HuffmanNode* root, EncodedText encoded, int* index, unsigned char *data)
{
    if (!root || !index || !encoded.data)
        return;

    if (isLeaf(root)) {
        data[*index] = root->data;
        ++(*index);
    }

    if (encoded.data[(*index)] == '0') {
        ++(*index);
        decodeHelper(root->left, encoded, index, data);
    }
    else if (encoded.data[(*index)] == '1') {
        ++(*index);
        decodeHelper(root->right, encoded, index, data);
    }
}

void decode(HuffmanNode* root, EncodedText encoded, int size, unsigned char *data)
{
    int index = 0;
    decodeHelper(root, encoded, &index, data);
}

int main()
{
    unsigned char data[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    unsigned freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanNode* root = buildHuffmanTree(data, freq, size);

    printCodes(root);

    EncodedText encoded = encode(root, data, size);
    unsigned char decoded[size];
    decode(root, encoded, size, decoded);

    printf("Encoded text is:");
    for (int i = 0; i < encoded.size; ++i)
        printf("%c", encoded.data[i]);
    printf("\n");

    printf("Decoded text is:");
    for (int i = 0; i < size; ++i)
        printf("%c", decoded[i]);
    printf("\n");

    return 0;
}