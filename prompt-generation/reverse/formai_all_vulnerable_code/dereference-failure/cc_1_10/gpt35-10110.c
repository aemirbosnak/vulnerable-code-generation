//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 256

// Define the Huffman tree node
typedef struct HuffmanNode{
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// Define the priority queue node
typedef struct PriorityQueueNode{
    HuffmanNode *huffmanNode;
    struct PriorityQueueNode *next;
} PriorityQueueNode;

// Define the priority queue
typedef struct PriorityQueue{
    PriorityQueueNode *head;
} PriorityQueue;

// Function to create a new Huffman node
HuffmanNode* createHuffmanNode(char character, int frequency){
    HuffmanNode* huffmanNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    huffmanNode->character = character;
    huffmanNode->frequency = frequency;
    huffmanNode->left = NULL;
    huffmanNode->right = NULL;
    return huffmanNode;
}

// Function to create a new priority queue node
PriorityQueueNode* createPriorityQueueNode(HuffmanNode* huffmanNode){
    PriorityQueueNode* priorityQueueNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    priorityQueueNode->huffmanNode = huffmanNode;
    priorityQueueNode->next = NULL;
    return priorityQueueNode;
}

// Function to create a new priority queue
PriorityQueue* createPriorityQueue(){
    PriorityQueue* priorityQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    priorityQueue->head = NULL;
    return priorityQueue;
}

// Function to check if the priority queue is empty
int isPriorityQueueEmpty(PriorityQueue* priorityQueue){
    return priorityQueue->head == NULL;
}

// Function to insert a Huffman node into the priority queue
void insertIntoPriorityQueue(PriorityQueue* priorityQueue, HuffmanNode* huffmanNode){
    PriorityQueueNode* newNode = createPriorityQueueNode(huffmanNode);
    if(isPriorityQueueEmpty(priorityQueue)){
        priorityQueue->head = newNode;
        return;
    }
    if(huffmanNode->frequency < priorityQueue->head->huffmanNode->frequency){
        newNode->next = priorityQueue->head;
        priorityQueue->head = newNode;
        return;
    }
    PriorityQueueNode* current = priorityQueue->head;
    while(current->next != NULL && current->next->huffmanNode->frequency < huffmanNode->frequency){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to remove the minimum node from the priority queue
HuffmanNode* popFromPriorityQueue(PriorityQueue* priorityQueue){
    if(isPriorityQueueEmpty(priorityQueue)){
        return NULL;
    }
    PriorityQueueNode* poppedNode = priorityQueue->head;
    priorityQueue->head = priorityQueue->head->next;
    HuffmanNode* huffmanNode = poppedNode->huffmanNode;
    free(poppedNode);
    return huffmanNode;
}

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(int frequencies[MAX_CHARS]){
    PriorityQueue* priorityQueue = createPriorityQueue();
    for(int i=0; i<MAX_CHARS; i++){
        if(frequencies[i]){
            HuffmanNode* huffmanNode = createHuffmanNode(i, frequencies[i]);
            insertIntoPriorityQueue(priorityQueue, huffmanNode);
        }
    }
    while(priorityQueue->head->next){
        HuffmanNode* left = popFromPriorityQueue(priorityQueue);
        HuffmanNode* right = popFromPriorityQueue(priorityQueue);
        HuffmanNode* parent = createHuffmanNode(-1, left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        insertIntoPriorityQueue(priorityQueue, parent);
    }
    return popFromPriorityQueue(priorityQueue);
}

// Function to print the Huffman codes
void printHuffmanCodes(HuffmanNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top+1);
    }
    if(!root->left && !root->right){
        printf("%c: ", root->character);
        for(int i=0; i<top; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main(){
    char str[] = "hello world";
    int frequencies[MAX_CHARS] = {0};
    for(int i=0; str[i]; i++){
        frequencies[str[i]]++;
    }
    HuffmanNode* root = buildHuffmanTree(frequencies);
    int arr[MAX_CHARS], top=0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    return 0;
}