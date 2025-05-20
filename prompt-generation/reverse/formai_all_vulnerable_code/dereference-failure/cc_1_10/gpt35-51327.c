//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// data structure for each node of the Huffman tree
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// data structure for a Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// data structure to map characters and their codes
struct Map {
    char character;
    char *code;
};

// function to create a new node for the Min Heap
struct MinHeapNode* create_node(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// function to create the Min Heap
struct MinHeap* create_min_heap(unsigned capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(heap->capacity * sizeof(struct MinHeapNode*));
    return heap;
}

// function to swap two Min Heap nodes
void swap_nodes(struct MinHeapNode** left_node, struct MinHeapNode** right_node) {
    struct MinHeapNode* temp = *left_node;
    *left_node = *right_node;
    *right_node = temp;
}

// function to build the Min Heap
void min_heapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int left_index = (2 * index) + 1;
    int right_index = (2 * index) + 2;

    if (left_index < heap->size && heap->array[left_index]->freq < heap->array[smallest]->freq) {
        smallest = left_index;
    }
  
    if (right_index < heap->size && heap->array[right_index]->freq < heap->array[smallest]->freq) {
        smallest = right_index;
    }

    if (smallest != index) {
        swap_nodes(&heap->array[smallest], &heap->array[index]);
        min_heapify(heap, smallest);
    }
}

// function to check if the Min Heap is of size 1
bool check_min_heap_size_one(struct MinHeap* heap) {
    return (heap->size == 1);
}

// function to extract the min element from the Min Heap
struct MinHeapNode* extract_min(struct MinHeap* heap) {
    struct MinHeapNode* min_node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return min_node;
}

// function to insert a new node into the Min Heap 
void insert_min_heap(struct MinHeap* heap, struct MinHeapNode* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1)/2]->freq) {
        heap->array[i] = heap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    heap->array[i] = node;
}

// function to build the Min Heap and return the root node
struct MinHeapNode* build_min_heap(char data[], int freq[], int size) {
    struct MinHeap* heap = create_min_heap(size);
    for (int i=0; i<size; ++i) {
        heap->array[i] = create_node(data[i], freq[i]);
    }
    heap->size = size;
    for (int i = (heap->size - 1)/2; i >= 0; --i) {
        min_heapify(heap, i);
    }
    while (!check_min_heap_size_one(heap)) {
        struct MinHeapNode *left_node = extract_min(heap);
        struct MinHeapNode *right_node = extract_min(heap);
        struct MinHeapNode *new_node = create_node('$', left_node->freq + right_node->freq);
        new_node->left = left_node;
        new_node->right = right_node;
        insert_min_heap(heap, new_node);
    }
    return extract_min(heap);
}

// function to print the codes
void print_codes(struct MinHeapNode* root, int arr[], int top, struct Map *map) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1, map);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1, map);
    }
    if (!root->left && !root->right) {
        map[root->data].character = root->data;
        map[root->data].code = (char*)malloc(sizeof(char) * (top + 1));
        for (int i = 0; i < top; ++i) {
            map[root->data].code[i] = arr[i] + '0';
        }
        map[root->data].code[top] = '\0';
    }
}

// function to free the nodes of the tree
void free_tree(struct MinHeapNode *node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

// function to print the codes for each character
void print_map(struct Map *map, int size) {
    printf("Character  Code\n");
    for (int i = 0; i < size; ++i) {
        if (map[i].character) {
            printf("%c         %s\n", map[i].character, map[i].code);
        }
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);

    struct Map map[128] = {0}; // array to store codes for each character
    struct MinHeapNode* root = build_min_heap(data, freq, size);
  
    int arr[MAX_TREE_HT], top = 0;
    print_codes(root, arr, top, map);
    print_map(map, 128);

    free_tree(root);

    return 0;
}