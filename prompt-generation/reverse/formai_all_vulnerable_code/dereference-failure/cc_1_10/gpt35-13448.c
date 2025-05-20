//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct min_heap 
{
    size_t size;
    size_t capacity;
    node** arr;
} min_heap;

node* create_node(char ch, int freq) 
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

min_heap* create_heap(size_t capacity) 
{
    min_heap* heap = (min_heap*)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (node**)malloc(sizeof(node*) * capacity);
    return heap;
}

void swap_node(node **a, node **b) 
{
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(min_heap *heap, size_t index) 
{
    size_t left = 2 * index + 1, right = 2 * index + 2, smallest = index;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq) 
        smallest = left;
    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq) 
        smallest = right;
    if (smallest != index) 
    {
        swap_node(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

node* extract_min(min_heap *heap) 
{
    node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}

void insert_node(min_heap *heap, node *node) 
{
    ++heap->size;
    size_t i = heap->size - 1;
    while (i && node->freq < heap->arr[(i - 1) / 2]->freq) 
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = node;
}

node* build_huffman_tree(char string[], int freq[], size_t size) 
{
    min_heap *heap = create_heap(size);
    for (size_t i = 0; i < size; ++i) 
        insert_node(heap, create_node(string[i], freq[i]));
    while (heap->size != 1) 
    {
        node *left = extract_min(heap);
        node *right = extract_min(heap);
        node *new_node = create_node('$', left->freq + right->freq);
        new_node->left = left;
        new_node->right = right;
        insert_node(heap, new_node);
    }
    return extract_min(heap);
}

void print_codes(node *root, int codes[], int top) 
{
    if (root->left) 
    {
        codes[top] = 0;
        print_codes(root->left, codes, top+1);
    }
    if (root->right) 
    {
        codes[top] = 1;
        print_codes(root->right, codes, top+1);
    }
    if(!root->left && !root->right) 
    {
        printf("%c: ", root->ch);
        for(size_t i=0; i<top; ++i) printf("%d", codes[i]);
        printf("\n");
    }
}

void huffman_codes(char string[], int freq[], size_t size) 
{
    node *root = build_huffman_tree(string, freq, size);
    int codes[size];
    int top=0;
    print_codes(root, codes, top);
}

int main() 
{
    char string[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
    size_t size = sizeof(string)/sizeof(string[0]);
    huffman_codes(string, freq, size);
    return 0;
}