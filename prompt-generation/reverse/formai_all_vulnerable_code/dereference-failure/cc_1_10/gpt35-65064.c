//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    int freq;
    struct node *left, *right;
};

struct heap {
    int size;
    int capacity;
    struct node **nodes;
};

// create a new node
struct node* new_node(char data, int freq) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// create a new heap
struct heap* new_heap(int capacity) {
    struct heap* heap = (struct heap*)malloc(sizeof(struct heap));
    heap->nodes = (struct node**)malloc(capacity * sizeof(struct node*));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// swap nodes
void swap_nodes(struct node** n1, struct node** n2) {
    struct node* temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// heapify top-down
void heapify_down(struct heap* heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        swap_nodes(&heap->nodes[i], &heap->nodes[smallest]);
        heapify_down(heap, smallest);
    }
}

// heapify bottom-up
void heapify_up(struct heap* heap, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && heap->nodes[i]->freq < heap->nodes[parent]->freq) {
        swap_nodes(&heap->nodes[i], &heap->nodes[parent]);
        heapify_up(heap, parent);
    }
}

// add node to heap
void add_node(struct heap* heap, struct node* node) {
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size] = node;
        heap->size++;
        heapify_up(heap, heap->size - 1);
    }
}

// extract minimum node from heap
struct node* extract_min(struct heap* heap) {
    if (heap->size > 0) {
        struct node* node = heap->nodes[0];
        heap->size--;
        heap->nodes[0] = heap->nodes[heap->size];
        heapify_down(heap, 0);
        return node;
    }
    return NULL;
}

// build huffman tree
struct node* build_huffman_tree(struct heap* heap) {
    while (heap->size > 1) {
        struct node* node1 = extract_min(heap);
        struct node* node2 = extract_min(heap);
        struct node* parent = new_node('\0', node1->freq + node2->freq);
        parent->left = node1;
        parent->right = node2;
        add_node(heap, parent);
    }
    return extract_min(heap);
}

// print huffman codes
void print_codes(struct node* node, int arr[], int top) {
    if (node->left) {
        arr[top] = 0;
        print_codes(node->left, arr, top + 1);
    }
    if (node->right) {
        arr[top] = 1;
        print_codes(node->right, arr, top + 1);
    }
    if (!node->left && !node->right) {
        printf("%c: ", node->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    struct heap* heap = new_heap(size);
    for (int i = 0; i < size; i++) {
        add_node(heap, new_node(data[i], freq[i]));
    }
    struct node* root = build_huffman_tree(heap);
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    print_codes(root, arr, top);
    return 0;
}