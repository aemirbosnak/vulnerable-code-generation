//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 128 // Maximum number of unique characters i.e., ASCII values from 0 to 127

// Huffman tree node structure
struct Node {
    char ch; // Stores character
    int freq; // Stores frequency
    struct Node *left, *right; // Pointer to left and right child nodes
};

// Min heap node structure
struct MinHeapNode {
    struct Node *node; // Pointer to Huffman tree node
    struct MinHeapNode *next; // Pointer to next node
};

// Min heap structure
struct MinHeap {
    int size; // Current size of heap
    struct MinHeapNode *head; // Pointer to head of linked list
};

// Create a new node for Huffman tree
struct Node *newNode(char ch, int freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Create a new node for min heap
struct MinHeapNode *newMinHeapNode(struct Node *node) {
    struct MinHeapNode *minHeapNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    minHeapNode->node = node;
    minHeapNode->next = NULL;
    return minHeapNode;
}

// Create a new min heap
struct MinHeap *createMinHeap() {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->head = NULL;
    return minHeap;
}

// Create min heap from given linked list
void buildMinHeap(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->head;
    while(temp) {
        minHeap->size++; // Increase size of heap
        temp = temp->next;
    }
    while(minHeap->size > 1) {
        struct Node *tempNode = newNode('\0', 0); // Dummy node
        tempNode->left = minHeap->head->node; // Assign first node in min heap as left child of dummy node
        minHeap->head = minHeap->head->next; // Remove first node from min heap
        tempNode->right = minHeap->head->node; // Assign second node in min heap as right child of dummy node
        minHeap->head = minHeap->head->next; // Remove second node from min heap
        struct MinHeapNode *minHeapNode = newMinHeapNode(tempNode); // Create new node for min heap with dummy node as its node
        minHeapNode->next = minHeap->head; // Insert new node in min heap
        minHeap->head = minHeapNode;
        minHeap->size--; // Decrease size of heap
    }
}

// Assign codes to characters in Huffman tree recursively
void assignCodes(struct Node *node, int *arr, int top, int **codes) {
    if(node->left) { // If node has left child, assign 0 to its code
        arr[top] = 0;
        assignCodes(node->left, arr, top + 1, codes);
    }
    if(node->right) { // If node has right child, assign 1 to its code
        arr[top] = 1;
        assignCodes(node->right, arr, top + 1, codes);
    }
    if(!node->left && !node->right) { // If node is leaf node, store its code
        int i;
        for(i = 0; i < top; i++) {
            codes[node->ch][i] = arr[i];
        }
        codes[node->ch][i] = '\0'; // Add terminating null character to code
    }
}

// Huffman coding algorithm
void huffman(char *str, int n) {
    int freq[SIZE] = {0}; // Initialize frequency array with all zeroes
    int i;
    for(i = 0; i < n; i++) {
        freq[str[i]]++; // Increase frequency of character
    }
    struct MinHeap *minHeap = createMinHeap(); // Create new min heap
    for(i = 0; i < SIZE; i++) {
        if(freq[i] > 0) { // If character is present in given string
            struct Node *node = newNode(i, freq[i]); // Create new node for Huffman tree
            struct MinHeapNode *minHeapNode = newMinHeapNode(node); // Create new node for min heap with newly created Huffman tree node
            if(minHeap->head == NULL || freq[i] < minHeap->head->node->freq) { // If min heap is empty or frequency of character is less than frequency of first node in min heap
                minHeapNode->next = minHeap->head; // Insert new node at beginning of linked list
                minHeap->head = minHeapNode;
            } else {
                struct MinHeapNode *temp = minHeap->head;
                while(temp->next && temp->next->node->freq <= freq[i]) { // Traverse linked list until a node with greater frequency is found
                    temp = temp->next;
                }
                minHeapNode->next = temp->next; // Insert new node after node with lesser frequency
                temp->next = minHeapNode;
            }
        }
    }
    buildMinHeap(minHeap); // Build Huffman tree from min heap
    int *arr = (int *)malloc(SIZE * sizeof(int)); // Array to store codes for each character
    int **codes = (int **)malloc(SIZE * sizeof(int *)); // 2D array to store codes for each character
    for(i = 0; i < SIZE; i++) {
        codes[i] = (int *)malloc(SIZE * sizeof(int));
    }
    assignCodes(minHeap->head->node, arr, 0, codes); // Assign codes to characters in Huffman tree recursively
    printf("Huffman Codes:\n");
    for(i = 0; i < SIZE; i++) {
        if(codes[i][0]) { // Print code for each character
            printf("%c : %s\n", (char)i, codes[i]);
        }
    }
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin); // Read input string from user
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character
    printf("Input String: %s\n", str);
    huffman(str, strlen(str)); // Call Huffman coding function with input string and its length
    return 0;
}