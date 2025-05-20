//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_TREE_HT 50

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A Min Heap:  Collection of Min Heap (or Hufmn Tree) nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Utility function to allocate a new Min Heap Node
struct MinHeapNode* new_node(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Utility function to create a min heap of given capacity
struct MinHeap* create_min_heap(unsigned capacity) {
    struct MinHeap* min_heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct MinHeapNode**)malloc(min_heap->capacity * sizeof(struct MinHeapNode*));
    return min_heap;
}

// Utility function to swap two min heap nodes
void swap_min_heap_node(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the min heap
void min_heapify(struct MinHeap* min_heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swap_min_heap_node(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

// Function to check if size of heap is 1
bool is_size_one(struct MinHeap* min_heap) {
    return (min_heap->size == 1);
}

// Function to extract minimum node from heap
struct MinHeapNode* extract_min(struct MinHeap* min_heap) {
    struct MinHeapNode* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size; 
    min_heapify(min_heap, 0);
    return temp;
}

// Function to insert a new node to min heap
void insert_min_heap(struct MinHeap* min_heap, struct MinHeapNode* min_heap_node) {
    ++min_heap->size;
    int i = min_heap->size - 1;
    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = min_heap_node;
}

// Function to build min heap
void build_min_heap(struct MinHeap* min_heap) {
    int n = min_heap->size - 1; 
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }
}

// Function to print Huffman codes from the root of Huffman Tree.
void print_codes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        int i;
        for (i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to construct Huffman Tree
struct MinHeapNode* construct_huffman_tree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* min_heap = create_min_heap(size);
    int i;
    for (i = 0; i < size; ++i) {
        insert_min_heap(min_heap, new_node(data[i], freq[i]));
    }
    build_min_heap(min_heap);
    while (!is_size_one(min_heap)) {
        left = extract_min(min_heap);
        right = extract_min(min_heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(min_heap, top);
    }
    return extract_min(min_heap);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    struct MinHeapNode* root = construct_huffman_tree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    print_codes(root, arr, top);
    return 0;
}