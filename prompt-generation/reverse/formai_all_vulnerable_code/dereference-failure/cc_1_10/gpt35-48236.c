//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the limit for the length of the input string
#define MAX_LENGTH 1000

// define the structure for the node in Huffman tree
typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

// define the structure for the priority queue
typedef struct PriorityQueue {
    int size;
    int capacity;
    Node** nodes;
} PriorityQueue;

// create a node with given character and frequency
Node* createNode(char character, int frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// create priority queue with the given capacity
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (Node**) malloc(sizeof(Node*) * capacity);

    return queue;
}

// swap two nodes in priority queue
void swapNodes(Node** node1, Node** node2) {
    Node* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// sort the priority queue in descending order based on the frequency
void heapify(PriorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->nodes[left]->frequency < queue->nodes[smallest]->frequency)
        smallest = left;

    if (right < queue->size && queue->nodes[right]->frequency < queue->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&queue->nodes[smallest], &queue->nodes[index]);
        heapify(queue, smallest);
    }
}

// return the minimum node from the priority queue
Node* getMinNode(PriorityQueue* queue) {
    Node* minNode = queue->nodes[0];
    queue->nodes[0] = queue->nodes[queue->size - 1];
    --queue->size;
    heapify(queue, 0);

    return minNode;
}

// add node to priority queue
void addNodeToQueue(PriorityQueue* queue, Node* node) {
    ++queue->size;
    int index = queue->size - 1;

    while (index && queue->nodes[(index - 1) / 2]->frequency > node->frequency)
    {
        queue->nodes[index] = queue->nodes[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    queue->nodes[index] = node;
}

// build the Huffman tree
Node* buildHuffmanTree(char* input) {
    int frequencies[256] = { 0 };
    int length = strlen(input);

    for (int i = 0; i < length; ++i) {
        ++frequencies[input[i]];
    }

    PriorityQueue* queue = createPriorityQueue(256);

    for (int i = 0; i < 256; ++i) {
        if (frequencies[i])
            addNodeToQueue(queue, createNode(i, frequencies[i]));
    }

    while (queue->size != 1) {
        Node* left = getMinNode(queue);
        Node* right = getMinNode(queue);

        Node* mergeNode = createNode('#', left->frequency + right->frequency);
        mergeNode->left = left;
        mergeNode->right = right;

        addNodeToQueue(queue, mergeNode);
    }

    return getMinNode(queue);
}

// encode the input string using the Huffman tree
void encodeString(Node* root, char* input, char* output) {
    int length = strlen(input);
    int outputIndex = 0;

    for (int i = 0; i < length; ++i) {
        Node* currentNode = root;
        char code[256] = { 0 };
        int codeIndex = 0;

        while (currentNode->left && currentNode->right) {
            if (currentNode->left && strchr(currentNode->left->character, input[i]))
            {
                code[codeIndex++] = '0';
                currentNode = currentNode->left;
            }

            else if (currentNode->right && strchr(currentNode->right->character, input[i]))
            {
                code[codeIndex++] = '1';
                currentNode = currentNode->right;
            }
        }
        sprintf(output + outputIndex, "%s", code);
        outputIndex += codeIndex;
    }
}

// decode the encoded string using the Huffman tree
void decodeString(Node* root, char* input, char* output) {
    int length = strlen(input);
    int outputIndex = 0;
    Node* currentNode = root;

    for (int i = 0; i < length; ++i) {
        if (currentNode->left && input[i] == '0')
            currentNode = currentNode->left;

        else if (currentNode->right && input[i] == '1')
            currentNode = currentNode->right;

        if (!currentNode->left && !currentNode->right) {
            sprintf(output + outputIndex, "%c", currentNode->character);
            currentNode = root;
            ++outputIndex;
        }
    }
    output[outputIndex] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    char encoded[MAX_LENGTH];
    char decoded[MAX_LENGTH];

    printf("Enter the string to encode using Huffman Coding:\n");
    scanf("%[^\n]s", input);

    Node* huffmanTree = buildHuffmanTree(input);

    printf("Huffman Codes:\n");
    encodeString(huffmanTree, input, encoded);
    printf("%s\n", encoded);

    printf("\nDecoded String:\n");
    decodeString(huffmanTree, encoded, decoded);
    printf("%s", decoded);

    return 0;
}