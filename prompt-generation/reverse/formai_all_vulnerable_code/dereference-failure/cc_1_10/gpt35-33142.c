//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 256
#define MAX_CODE_LENGTH 100

typedef struct _Node
{
    int value;
    int freq;
    struct _Node* left;
    struct _Node* right;
} Node;

typedef struct _Heap
{
    int size;
    Node* data[MAX_NODE_COUNT];
} Heap;

int get_parent_index(int i)
{
    return (i - 1) / 2;
}

int get_left_child_index(int i)
{
    return (i * 2) + 1;
}

int get_right_child_index(int i)
{
    return (i * 2) + 2;
}

void heapify_up(Heap* heap, int child_index)
{
    if (child_index <= 0)
    {
        return;
    }

    int parent_index = get_parent_index(child_index);

    if (heap->data[parent_index]->freq > heap->data[child_index]->freq)
    {
        Node* tmp = heap->data[parent_index];
        heap->data[parent_index] = heap->data[child_index];
        heap->data[child_index] = tmp;
        heapify_up(heap, parent_index);
    }
}

void heapify_down(Heap* heap, int parent_index)
{
    int left_index = get_left_child_index(parent_index);
    int right_index = get_right_child_index(parent_index);

    int smallest_index = parent_index;

    if (left_index < heap->size && heap->data[left_index]->freq < heap->data[smallest_index]->freq)
    {
        smallest_index = left_index;
    }

    if (right_index < heap->size && heap->data[right_index]->freq < heap->data[smallest_index]->freq)
    {
        smallest_index = right_index;
    }

    if (smallest_index != parent_index)
    {
        Node* tmp = heap->data[parent_index];
        heap->data[parent_index] = heap->data[smallest_index];
        heap->data[smallest_index] = tmp;
        heapify_down(heap, smallest_index);
    }
}

Node* create_node(int value, int freq)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Heap* heap, Node* node)
{
    if (heap->size >= MAX_NODE_COUNT)
    {
        printf("Heap is full\n");
        return;
    }

    heap->data[heap->size] = node;
    heap->size++;

    heapify_up(heap, heap->size - 1);
}

Node* delete_min(Heap* heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty\n");
        return NULL;
    }

    Node* min_node = heap->data[0];
    heap->size--;

    heap->data[0] = heap->data[heap->size];
    heapify_down(heap, 0);

    return min_node;
}

void print_codes(Node* root, int code[], int top)
{
    if (root->left)
    {
        code[top] = 0;
        print_codes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = 1;
        print_codes(root->right, code, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("Value %c: ", root->value);
        for (int i = 0; i < top; i++)
        {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(int freq[], int size)
{
    Node* top_node;
    Node* left_node;
    Node* right_node;

    Heap min_heap;
    min_heap.size = 0;

    for (int i = 0; i < size; i++)
    {
        if (freq[i] > 0)
        {
            insert(&min_heap, create_node((char)i, freq[i]));
        }
    }

    while (min_heap.size > 1)
    {
        left_node = delete_min(&min_heap);
        right_node = delete_min(&min_heap);

        top_node = create_node('$', left_node->freq + right_node->freq);
        top_node->left = left_node;
        top_node->right = right_node;

        insert(&min_heap, top_node);
    }

    int code[MAX_CODE_LENGTH];
    print_codes(delete_min(&min_heap), code, 0);
}

int main()
{
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(freq) / sizeof(freq[0]);
    huffman_encoding(freq, size);
    return 0;
}