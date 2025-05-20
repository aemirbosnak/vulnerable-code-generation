//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the Huffman Tree structure
struct huffman_tree_node {
    int freq;
    char data;
    struct huffman_tree_node *left, *right;
};

// Define the Heap structure for Priority Queue
struct heap_node {
    int size;
    int capacity;
    struct huffman_tree_node** array;
};

// Create a new node with given character and frequency
struct huffman_tree_node* create_node(char data, int freq) {
    struct huffman_tree_node* node =
        (struct huffman_tree_node*)malloc(sizeof(struct huffman_tree_node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new heap of given capacity
struct heap_node* create_heap(int capacity) {
    struct heap_node* heap =
        (struct heap_node*)malloc(sizeof(struct heap_node));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array =
        (struct huffman_tree_node**)malloc(heap->capacity * sizeof(struct huffman_tree_node*));
    return heap;
}

// Swap two nodes
void swap(struct huffman_tree_node** a, struct huffman_tree_node** b) {
    struct huffman_tree_node* t = *a;
    *a = *b;
    *b = t;
}

// Standard MinHeapify function
void min_heapify(struct heap_node* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        min_heapify(heap, smallest);
    }
}

// Check if size of heap is 1
int is_size_one(struct heap_node* heap) {
    return (heap->size == 1);
}

// Extract minimum node from heap
struct huffman_tree_node* extract_min(struct heap_node* heap) {
    struct huffman_tree_node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);
    return temp;
}

// Insert node into heap
void insert_min_heap(struct heap_node* heap, struct huffman_tree_node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Build the Huffman Tree
struct huffman_tree_node* build_huffman_tree(char data[], int freq[], int size) {
    struct huffman_tree_node *left, *right, *top;
    struct heap_node* heap = create_heap(size);
    for (int i = 0; i < size; ++i)
        insert_min_heap(heap, create_node(data[i], freq[i]));  
    while (!is_size_one(heap)) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = create_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(heap, top);
    }
    return extract_min(heap);
}

// Function to store Huffman codes in an array
void store_huffman_codes(struct huffman_tree_node* root, int arr[], int top, int* count) {
    if (root->left) {
        arr[top] = 0;
        store_huffman_codes(root->left, arr, top + 1, count);
    }
    if (root->right) {
        arr[top] = 1;
        store_huffman_codes(root->right, arr, top + 1, count);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
            count++;
        }
        printf("\n");
    }
}

// Calculate the Huffman codes and print them
void print_huffman_codes(char data[], int freq[], int size) {
    struct huffman_tree_node* root = build_huffman_tree(data, freq, size);
    int arr[100], top = 0, count = 0;
    printf("The Huffman codes are:\n");
    store_huffman_codes(root, arr, top, &count);
}

// Driver program to test the Huffman algorithm
int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    print_huffman_codes(data, freq, size);
    return 0;
}