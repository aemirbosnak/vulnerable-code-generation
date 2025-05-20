//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TREE_HT 100

// a Huffman Tree node
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// A Min Heap Node
struct MinHeapNode {
    struct Node *node;
    unsigned freq;
};

// A Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Create a new Node
struct Node *new_node(char data, unsigned freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new Min Heap Node
struct MinHeapNode *new_min_heap_node(struct Node *node, unsigned freq) {
    struct MinHeapNode *min_heap_node = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    min_heap_node->node = node;
    min_heap_node->freq = freq;
    return min_heap_node;
}

// Create a Min Heap
struct MinHeap *create_min_heap(unsigned capacity) {
    struct MinHeap *min_heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct MinHeapNode **)malloc(min_heap->capacity * sizeof(struct MinHeapNode *));
    return min_heap;
}

// Swap two Min Heap Nodes
void swap_min_heap_node(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Heapify Min Heap
void min_heapify(struct MinHeap *min_heap, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if (l < min_heap->size && min_heap->array[l]->freq < min_heap->array[smallest]->freq)
        smallest = l;
    if (r < min_heap->size && min_heap->array[r]->freq < min_heap->array[smallest]->freq)
        smallest = r;
    if (smallest != idx) {
        swap_min_heap_node(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

// Check if the given Min Heap has only one node
int is_size_one(struct MinHeap *min_heap) {
    return (min_heap->size == 1);
}

// Extract minimum node from Min Heap
struct MinHeapNode *extract_min(struct MinHeap *min_heap) {
    struct MinHeapNode *temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

// Insert a node into Min Heap
void insert_min_heap(struct MinHeap *min_heap, struct MinHeapNode *min_heap_node) {
    ++min_heap->size;
    int i = min_heap->size - 1;
    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = min_heap_node;
}

// Builds Huffman Tree
struct Node *build_huffman_tree(char data[], unsigned freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap *min_heap = create_min_heap(size);
    for (int i = 0; i < size; ++i)
        insert_min_heap(min_heap, new_min_heap_node(new_node(data[i], freq[i]), freq[i]));
    while (!is_size_one(min_heap)) {
        left = extract_min(min_heap)->node;
        right = extract_min(min_heap)->node;
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(min_heap, new_min_heap_node(top, top->freq));
    }
    return extract_min(min_heap)->node;
}

// Print Huffman Codes
void print_huffman_codes(struct Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman Coding Function
void huffman_code(char data[], unsigned freq[], int size) {
    struct Node *root = build_huffman_tree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    print_huffman_codes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_code(data, freq, size);
    return 0;
}