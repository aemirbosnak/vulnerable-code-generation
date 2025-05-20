//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

// Define a node for the Huffman tree
typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

// Define a min-heap
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node *array[MAX_TREE_NODES];
} MinHeap;

// Function to create a new min-heap node
Node* newNode(char character, unsigned frequency) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min-heap
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Function to swap two nodes in the heap
void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

// Function to minheapify a subtree
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

// Function to check if the size of the heap is one
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from the heap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to the min-heap
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
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
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

// Function to generate Huffman codes
void generateHuffmanCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        generateHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        generateHuffmanCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to encode a string using given Huffman codes
void encodeString(Node* root, char* input) {
    char* encoded = (char *)malloc(strlen(input) * 8 + 1); // Assuming maximum bits
    encoded[0] = '\0';
    
    Node* current;
    for (int i = 0; input[i]; i++) {
        current = root;
        while (current->left || current->right) {
            if (current->left && strchr(input, current->left->character)) {
                strcat(encoded, "0");
                current = current->left;
            } else if (current->right && strchr(input, current->right->character)) {
                strcat(encoded, "1");
                current = current->right;
            }
        }
    }
    
    printf("Encoded String: %s\n", encoded);
    free(encoded);
}

int main() {
    char input[256];
    
    printf("Enter a string for Huffman Encoding: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    int frequency[MAX_TREE_NODES] = {0};
    char characters[MAX_TREE_NODES];
    int size = 0;

    // Calculate frequency of characters
    for (int i = 0; input[i]; i++) {
        if (frequency[(unsigned char)input[i]] == 0) {
            characters[size] = input[i];
            size++;
        }
        frequency[(unsigned char)input[i]]++;
    }

    // Build the Huffman Tree
    Node* root = buildHuffmanTree(characters, frequency, size);

    // Generate Huffman Codes
    int arr[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    generateHuffmanCodes(root, arr, top);
    
    // Encode the string
    encodeString(root, input);

    return 0;
}