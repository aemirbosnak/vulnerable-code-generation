//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define struct for Node in Huffman Tree
typedef struct Node {
    struct Node *left, *right;
    char c;
    int freq;
} Node;

// Function to create a new Node for Huffman Tree
Node* newNode(char c, int freq) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->c = c;
    node->freq = freq;
    return node;
}

// Function to swap two Nodes in an array
void swap(Node** arr, int i, int j) {
    Node* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to heapify an array of Nodes
void heapify(Node** arr, int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left]->freq > arr[largest]->freq) {
        largest = left;
    }

    if (right < size && arr[right]->freq > arr[largest]->freq) {
        largest = right;
    }

    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, size, largest);
    }
}

// Function to build a Huffman Tree from a frequency array
Node* buildHuffmanTree(char* arr, int* freq, int size) {
    Node** nodes = (Node**) malloc(sizeof(Node*) * size);

    for (int i = 0; i < size; i++) {
        nodes[i] = newNode(arr[i], freq[i]);
    }

    int heapSize = size;
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(nodes, heapSize, i);
    }

    while (heapSize > 1) {
        Node* left = nodes[0];
        swap(nodes, 0, heapSize - 1);
        heapSize--;
        heapify(nodes, heapSize, 0);

        Node* right = nodes[0];
        swap(nodes, 0, heapSize - 1);
        heapSize--;
        heapify(nodes, heapSize, 0);

        Node* parent = newNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[heapSize] = parent;
        heapSize++;
        heapify(nodes, heapSize, heapSize-1);
    }

    Node* root = nodes[0];
    free(nodes);
    return root;
}

// Function to print the codes for each character in a Huffman Tree
void printCodes(Node* node, int code[], int length) {
    if (node->left == NULL && node->right == NULL) {
        printf("%c: ", node->c);
        for (int i = 0; i < length; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    } else {
        code[length] = 0;
        printCodes(node->left, code, length+1);

        code[length] = 1;
        printCodes(node->right, code, length+1);
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);

    Node* root = buildHuffmanTree(arr, freq, size);

    int code[size];
    printCodes(root, code, 0);

    return 0;
}