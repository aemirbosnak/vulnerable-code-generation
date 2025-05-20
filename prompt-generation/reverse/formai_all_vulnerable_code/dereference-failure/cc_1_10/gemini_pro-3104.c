//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int freq;
    char data;
    struct node *left, *right;
};

struct min_heap {
    unsigned int size;
    unsigned int capacity;
    struct node **array;
};

struct min_heap* create_min_heap(unsigned int capacity)
{
    struct min_heap* min_heap = (struct min_heap*)malloc(sizeof(struct min_heap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct node**)malloc(min_heap->capacity * sizeof(struct node*));
    return min_heap;
}

void swap_nodes(struct node** a, struct node** b)
{
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct min_heap* min_heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq)
        smallest = left;

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap_nodes(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

int is_size_one(struct min_heap* min_heap)
{
    return (min_heap->size == 1);
}

struct node* extract_min(struct min_heap* min_heap)
{
    struct node* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

void insert_node(struct min_heap* min_heap, struct node* node)
{
    ++min_heap->size;
    int i = min_heap->size - 1;

    while (i && node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    min_heap->array[i] = node;
}

struct min_heap* build_min_heap(char data[], int freq[], int size)
{
    struct min_heap* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        min_heap->array[i] = (struct node*)malloc(sizeof(struct node));
        min_heap->array[i]->data = data[i];
        min_heap->array[i]->freq = freq[i];
        min_heap->array[i]->left = min_heap->array[i]->right = NULL;
    }

    min_heap->size = size;
    for (int i = (min_heap->size - 2) / 2; i >= 0; --i)
        min_heapify(min_heap, i);

    return min_heap;
}

struct node* build_huffman_tree(char data[], int freq[], int size)
{
    struct min_heap* min_heap = build_min_heap(data, freq, size);

    while (!is_size_one(min_heap)) {
        struct node *left = extract_min(min_heap);
        struct node *right = extract_min(min_heap);

        struct node *top = (struct node*)malloc(sizeof(struct node));
        top->freq = left->freq + right->freq;
        top->data = '\0';
        top->left = left;
        top->right = right;

        insert_node(min_heap, top);
    }

    return extract_min(min_heap);
}

void print_codes(struct node* root, char code[], int top)
{
    if (root->left) {
        code[top] = '0';
        print_codes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        print_codes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, code);
    }
}

void huffman_coding(char data[], int freq[], int size)
{
    struct node* root = build_huffman_tree(data, freq, size);
    char code[size];
    code[size - 1] = '\0';
    print_codes(root, code, 0);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    huffman_coding(data, freq, size);

    return 0;
}