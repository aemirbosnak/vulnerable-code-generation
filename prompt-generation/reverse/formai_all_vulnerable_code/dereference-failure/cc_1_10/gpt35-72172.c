//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct huffmanNode {
    char data;
    unsigned frequency;
    struct huffmanNode *left, *right;
};

// Huffman priority queue node
struct huffmanQueueNode {
    struct huffmanNode* data;
    struct huffmanQueueNode* next;
};

// Create empty queue node
struct huffmanQueueNode* createQueueNode(struct huffmanNode* data)
{
    struct huffmanQueueNode* queueNode = (struct huffmanQueueNode*) malloc(sizeof(struct huffmanQueueNode));
    queueNode->data = data;
    queueNode->next = NULL;

    return queueNode;
}

// Create empty Huffman tree node
struct huffmanNode* createHuffmanNode(char data, unsigned frequency) {
    struct huffmanNode* hNode = (struct huffmanNode*) malloc(sizeof(struct huffmanNode));
    hNode->left = hNode->right = NULL;
    hNode->data = data;
    hNode->frequency = frequency;

    return hNode;
}

// Insert queue node
void insertQueueNode(struct huffmanQueueNode** queueNode, struct huffmanNode* data) {
    struct huffmanQueueNode* newQueueNode = createQueueNode(data);
    struct huffmanQueueNode* currentQueueNode = (*queueNode);

    if(*queueNode == NULL || data->frequency < (*queueNode)->data->frequency) {
        newQueueNode->next = (*queueNode);
        (*queueNode) = newQueueNode;
    } else {
        while (currentQueueNode->next != NULL && currentQueueNode->next->data->frequency < data->frequency)
            currentQueueNode = currentQueueNode->next;

        newQueueNode->next = currentQueueNode->next;
        currentQueueNode->next = newQueueNode;
    }
}

// Check if node is leaf node
int isLeafNode(struct huffmanNode* root) {
    return !(root->left) && !(root->right);
}

// Print Huffman codes in output file
void printHuffmanCodes(struct huffmanNode* root, int arr[], int top, FILE *outputFile)
{
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1, outputFile);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1, outputFile);
    }

    if (isLeafNode(root)) {
        fprintf(outputFile, "%c: ", root->data);
        for (int i = 0; i < top; i++) {
            fprintf(outputFile, "%d", arr[i]);
        }
        fprintf(outputFile, "\n");
    }
}

// Huffman coding algorithm
void huffmanCoding(char data[], int frequency[], int length, FILE *outputFile)
{
    int i;
    struct huffmanQueueNode *leftNode, *rightNode, *topNode;
    struct huffmanNode *hNode;
    struct huffmanQueueNode *queueNode = NULL;

    for (i = 0; i < length; ++i) {
        hNode = createHuffmanNode(data[i], frequency[i]);
        insertQueueNode(&queueNode, hNode);
    }

    while (queueNode->next != NULL) {
        leftNode = queueNode;
        rightNode = queueNode->next;

        hNode = createHuffmanNode('$', leftNode->data->frequency + rightNode->data->frequency);
        hNode->left = leftNode->data;
        hNode->right = rightNode->data;

        queueNode = queueNode->next;
        free(leftNode);
        free(rightNode);
        insertQueueNode(&queueNode, hNode);
    }

    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(queueNode->data, arr, top, outputFile);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};

    int length = sizeof(data)/sizeof(data[0]);

    FILE *outputFile;
    outputFile = fopen("output.txt", "w");

    huffmanCoding(data, frequency, length, outputFile);

    fclose(outputFile);

    return 0;
}