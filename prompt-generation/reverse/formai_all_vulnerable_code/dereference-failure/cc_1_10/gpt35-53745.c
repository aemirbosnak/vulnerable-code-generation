//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Sherlock Holmes
//The case of the Huffman Code Implementation
//by Detective Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure for Huffman Tree
struct node {
    char val;
    unsigned freq;
    struct node* left;
    struct node* right;
};

//Priority queue structure
struct priorityQueue {
    int size;
    struct node** array;
};

//Create a new node
struct node* createNode(char val, unsigned freq) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Create a priority queue
struct priorityQueue* createQueue(int size) {
    struct priorityQueue* queue = (struct priorityQueue*)malloc(sizeof(struct priorityQueue));
    queue->size = 0;
    queue->array = (struct node**)malloc(size * sizeof(struct node*));
    return queue;
}

//Swap two nodes
void swap(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;
}

//Min heapify function
void heapify(struct priorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq) {
        smallest = left;
    }
    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&queue->array[smallest], &queue->array[index]);
        heapify(queue, smallest);
    }
}

//Check if the node is a leaf node
int isLeaf(struct node* node) {
    return !(node->left) && !(node->right);
}

//Print the Huffman codes
void printCodes(struct node* root, int* array, int top) {
    if (root->left) {
        array[top] = 0;
        printCodes(root->left, array, top + 1);
    }
    if (root->right) {
        array[top] = 1;
        printCodes(root->right, array, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c ", root->val);
        for (int i = 0; i < top; i++) {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}

//Build Huffman tree
struct node* buildHuffmanTree(char val[], unsigned freq[], int size) {
    struct node *left, *right, *top;
    struct priorityQueue* queue = createQueue(size);
    for (int i = 0; i < size; i++) {
        queue->array[i] = createNode(val[i], freq[i]);
    }
    queue->size = size;
    while (queue->size > 1) {
        left = queue->array[0];
        right = queue->array[1];
        queue->array[0] = createNode('$', left->freq + right->freq);
        queue->array[0]->left = left;
        queue->array[0]->right = right;
        queue->size--;
        for (int i = 1; i < queue->size; i++) {
            queue->array[i] = queue->array[i + 1];
        }
        heapify(queue, 0);
    }
    top = queue->array[0];
    free(queue->array);
    free(queue);
    return top;
}

//Main function
int main() {
    char val[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(val) / sizeof(val[0]);
    struct node* root = buildHuffmanTree(val, freq, size);
    int array[100], top = 0;
    printf("Huffman Codes are:\n");
    printCodes(root, array, top);
    return 0;
}