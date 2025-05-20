//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_DEPTH 100
#define MAX_CHAR 256

// A node in the Huffman tree
struct HuffmanNode {
    char character;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// A priority queue to store nodes of the Huffman Tree
struct HuffmanQueue {
    int size;
    struct HuffmanNode** array;
};

// Create a new Huffman Node
struct HuffmanNode* newNode(char character, unsigned frequency) {
    struct HuffmanNode* temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}

// A function to create a priority queue of given capacity
struct HuffmanQueue* createQueue(int capacity) {
    struct HuffmanQueue* queue = (struct HuffmanQueue*)malloc(sizeof(struct HuffmanQueue));
    queue->size = 0;
    queue->array = (struct HuffmanNode**)malloc(capacity * sizeof(struct HuffmanNode*));
    return queue;
}

// Function to swap two nodes of the priority queue
void swap(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Minimum Heapify
void minHeapify(struct HuffmanQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->frequency < queue->array[smallest]->frequency)
        smallest = left;
    if (right < queue->size && queue->array[right]->frequency < queue->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swap(&queue->array[smallest], &queue->array[index]);
        minHeapify(queue, smallest);
    }
}

// Function to insert a new node into the priority queue
void insertQueue(struct HuffmanQueue* queue, struct HuffmanNode* node) {
    queue->array[queue->size] = node;
    int index = queue->size;
    queue->size++;

    while (index != 0 && queue->array[(index - 1) / 2]->frequency > queue->array[index]->frequency) {
        swap(&queue->array[index], &queue->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract the minimum node from the priority queue
struct HuffmanNode* extractMin(struct HuffmanQueue* queue) {
    if (queue->size <= 0)
        return NULL;
    if (queue->size == 1) {
        queue->size--;
        return queue->array[0];
    }

    struct HuffmanNode* root = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    queue->size--;
    minHeapify(queue, 0);

    return root;
}

// Function to build the Huffman Tree
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct HuffmanQueue* queue = createQueue(size);

    for (int i = 0; i < size; i++)
        insertQueue(queue, newNode(data[i], freq[i]));

    while (queue->size != 1) {
        left = extractMin(queue);
        right = extractMin(queue);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertQueue(queue, top);
    }
    return extractMin(queue);
}

// Function to print Huffman codes recursively
void printCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to decode the encoded data
void decode(struct HuffmanNode* root, const char* str) {
    struct HuffmanNode* current = root;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            printf("%c", current->character);
            current = root;
        }
    }
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_DEPTH], top = 0;

    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    char* encoded = "11001001111100101110";  
    printf("\nDecoded string: ");
    decode(root, encoded);
    printf("\n");

    return 0;
}