//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node* left;
    struct node* right;
};

struct node* newNode(char character, int frequency) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

void swap(struct node** a, struct node** b) {
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct node** heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
 
    if (left < size && heap[left]->frequency < heap[smallest]->frequency)
        smallest = left;
        
    if (right < size && heap[right]->frequency < heap[smallest]->frequency)
        smallest = right;
 
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

int isLeaf(struct node* node) {
    return !node->left && !node->right;
}

struct node* buildHuffmanTree(char* characters, int* frequencies, int size) {
    int i;
    struct node *left, *right, *top;
    int heap_size = size;
 
    struct node** heap = (struct node**) malloc(size * sizeof(struct node*));
 
    for(i = 0; i < size; ++i)
        heap[i] = newNode(characters[i], frequencies[i]);
 
    while (heap_size > 1) {
        minHeapify(heap, heap_size, 0);
        
        left = heap[0];
        swap(&heap[0], &heap[heap_size-1]);
        --heap_size;
        minHeapify(heap, heap_size, 0);
        
        right = heap[0];
        swap(&heap[0], &heap[heap_size-1]);
        --heap_size;
        
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
 
        heap[heap_size] = top;
        ++heap_size;
    }
 
    return heap[0];
}

void printEncodedData(struct node* root, char data, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printEncodedData(root->left, data, arr, top + 1);
    }
 
    if (root->right) {
        arr[top] = 1;
        printEncodedData(root->right, data, arr, top + 1);
    }
 
    if (isLeaf(root) && root->character == data) {
        int i;
        printf("%c : ", data);
        for (i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
 
void HuffmanCodes(char* characters, int* frequencies, int size) {
    struct node* root = buildHuffmanTree(characters, frequencies, size);
 
    int arr[size];
    int top = 0;
 
    int i;
    for (i = 0; i < size; ++i) {
        printEncodedData(root, characters[i], arr, top);
    }
}
 
int main() {
    char characters[] = {'r', 'e', 't', 'r', 'o'};
    int frequencies[] = {7, 3, 1, 4, 2};
    int size = sizeof(characters)/sizeof(characters[0]);
 
    printf("Huffman codes for given characters are:\n");
    HuffmanCodes(characters, frequencies, size);
 
    return 0;
}