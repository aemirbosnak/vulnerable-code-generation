//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// node for huffman tree
typedef struct Node
{
    char data;
    unsigned frequency;
    struct Node *left, *right;
} Node;

// priority queue node
typedef struct MinHeapNode
{
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode;

MinHeapNode* create_min_heap_node(char data, unsigned frequency)
{
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

void swap_min_heap_nodes(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeapNode** min_heap, int idx, int heap_size)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < heap_size && min_heap[left]->frequency < min_heap[smallest]->frequency)
        smallest = left;
 
    if (right < heap_size && min_heap[right]->frequency < min_heap[smallest]->frequency)
        smallest = right;
 
    if (smallest != idx)
    {
        swap_min_heap_nodes(&min_heap[idx], &min_heap[smallest]);
        min_heapify(min_heap, smallest, heap_size);
    }
}

bool is_size_one(int size)
{
    return (size == 1);
}

MinHeapNode* extract_min(MinHeapNode** min_heap, int* heap_size)
{
    MinHeapNode* temp = min_heap[0];
    min_heap[0] = min_heap[(*heap_size) - 1];
    --(*heap_size);
    min_heapify(min_heap, 0, *heap_size);
    return temp;
}

void insert_min_heap(MinHeapNode** min_heap, MinHeapNode* node, int* heap_size)
{
    ++(*heap_size);
    int i = (*heap_size) - 1;
    while (i && node->frequency < min_heap[(i - 1) / 2]->frequency)
    {
        min_heap[i] = min_heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap[i] = node;
}

bool is_leaf(Node* root)
{
    return !(root->left) && !(root->right) ;
}

Node* build_huffman_tree(char* data, unsigned* freq, int size)
{
    int heap_size = 0;
    MinHeapNode** min_heap = (MinHeapNode**) malloc(size * sizeof(MinHeapNode*));
 
    for (int i = 0; i < size; ++i)
        min_heap[i] = create_min_heap_node(data[i], freq[i]);
 
    heap_size = size;
 
    while (!is_size_one(heap_size))
    {
        MinHeapNode* left = extract_min(min_heap, &heap_size);
        MinHeapNode* right = extract_min(min_heap, &heap_size);
 
        MinHeapNode* top = create_min_heap_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
 
        insert_min_heap(min_heap, top, &heap_size);
    }
 
    Node* root = (Node*) malloc(sizeof(Node));
    root->left = root->right = NULL;
 
    MinHeapNode* min_heap_node = extract_min(min_heap, &heap_size);

    root->data = min_heap_node->data;
    root->frequency = min_heap_node->frequency;

    free(min_heap_node);
    free(min_heap);
    return root;
}

void print_codes(Node* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root))
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffman_encode(char* data, unsigned* freq, int size)
{
    Node* root = build_huffman_tree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
 
    print_codes(root, arr, top);
}
 
int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    huffman_encode(data, freq, size);
    return 0;
}