//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Node
{
    char data;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap
{
    int size;
    int capacity;
    Node **array;
} MinHeap;

Node *new_node(char data, int frequency)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap *create_min_heap(int capacity)
{
    MinHeap *min_heap = (MinHeap *)malloc(sizeof(MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (Node **)malloc(capacity * sizeof(Node *));
    return min_heap;
}

void swap_nodes(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap *min_heap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < min_heap->size && min_heap->array[left]->frequency < min_heap->array[smallest]->frequency)
        smallest = left;
    if (right < min_heap->size && min_heap->array[right]->frequency < min_heap->array[smallest]->frequency)
        smallest = right;
    if (smallest != index)
    {
        swap_nodes(&min_heap->array[smallest], &min_heap->array[index]);
        min_heapify(min_heap, smallest);
    }
}

int is_size_one(MinHeap *min_heap)
{
    return (min_heap->size == 1);
}

Node *extract_minimum(MinHeap *min_heap)
{
    Node *node = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    min_heap->size--;
    min_heapify(min_heap, 0);
    return node;
}

void insert_min_heap(MinHeap *min_heap, Node *node)
{
    min_heap->size++;
    int i = min_heap->size - 1;
    while (i && node->frequency < min_heap->array[(i - 1) / 2]->frequency)
    {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = node;
}

void build_min_heap(MinHeap *min_heap)
{
    int n = min_heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--)
        min_heapify(min_heap, i);
}

void print_codes(Node *root, int *codes, int *top)
{
    if (root->left)
    {
        codes[*top] = 0;
        (*top)++;
        print_codes(root->left, codes, top);
        (*top)--;
    }
    if (root->right)
    {
        codes[*top] = 1;
        (*top)++;
        print_codes(root->right, codes, top);
        (*top)--;
    }
    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        int i;
        for (i = 0; i < *top; i++)
            printf("%d", codes[i]);
        printf("\n");
    }
}

void huffman_tree(char *data, int *frequency, int size)
{
    MinHeap *min_heap = create_min_heap(size);
    for (int i = 0; i < size; i++)
        min_heap->array[i] = new_node(data[i], frequency[i]);
    min_heap->size = size;
    build_min_heap(min_heap);

    while (!is_size_one(min_heap))
    {
        Node *left = extract_minimum(min_heap);
        Node *right = extract_minimum(min_heap);
        Node *node = new_node('*', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        insert_min_heap(min_heap, node);
    }

    Node *root = extract_minimum(min_heap);
    int codes[MAX_CHAR], top = 0;
    print_codes(root, codes, &top);
}

int main()
{
    char data[MAX_CHAR];
    int frequency[MAX_CHAR] = {0};
    printf("Enter a string: ");
    fgets(data, MAX_CHAR, stdin);
    int n = strlen(data);
    if (data[n - 1] == '\n')
        data[n - 1] = '\0';
    for (int i = 0; i < n; i++)
        frequency[data[i]]++;

    huffman_tree(data, frequency, MAX_CHAR);
    return 0;
}