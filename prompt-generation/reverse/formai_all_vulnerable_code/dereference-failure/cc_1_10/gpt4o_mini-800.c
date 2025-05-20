//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node **array;
} MinHeap;

// Function to create a new node
Node* newNode(char character, unsigned frequency) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min heap
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

// Function to swap two nodes
void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to min heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the size is one
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum node from the heap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node into the min heap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char* characters, int* frequencies, int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, newNode(characters[i], frequencies[i]));
    }

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print the codes
void printCodes(Node* root, int arr[], int top, FILE* output) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, output);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, output);
    }

    if (!(root->left) && !(root->right)) {
        fprintf(output, "%c: ", root->character);
        for (int i = 0; i < top; ++i)
            fprintf(output, "%d", arr[i]);
        fprintf(output, "\n");
    }
}

// Function to decode the encoded string
void decode(Node* root, char* encodedString) {
    Node* current = root;
    for (int i = 0; i < strlen(encodedString); ++i) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!(current->left) && !(current->right)) {
            printf("%c", current->character);
            current = root;
        }
    }
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);

    Node* root = buildHuffmanTree(characters, frequencies, size);

    printf("Huffman Codes:\n");
    int arr[100], top = 0;
    FILE* output = stdout; // Just for writing to console
    printCodes(root, arr, top, output);

    // Example encoded string
    char encodedString[] = "110101101110111";
    printf("Decoded string:\n");
    decode(root, encodedString);
    printf("\n");

    return 0;
}