//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} node;

typedef struct heap {
    int size;
    int capacity;
    struct node **array;
} heap;

typedef struct code {
    char symbol;
    char *code;
} code;

node *create_node(char data, int freq, node *left, node *right) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node -> data = data;
    new_node -> freq = freq;
    new_node -> left = left;
    new_node -> right = right;
    return new_node;
}

heap *create_heap(int capacity) {
    heap *new_heap = (heap *) malloc(sizeof(heap));
    new_heap -> size = 0;
    new_heap -> capacity = capacity;
    new_heap -> array = (node **) malloc(sizeof(node *) * capacity);
    return new_heap;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(heap *min_heap, int index) {
    int smallest = index;
    int left_child = (index * 2) + 1;
    int right_child = (index * 2) + 2;
    if(left_child < min_heap -> size && min_heap -> array[left_child] -> freq < min_heap -> array[smallest] -> freq)
        smallest = left_child;
    if(right_child < min_heap -> size && min_heap -> array[right_child] -> freq < min_heap -> array[smallest] -> freq)
        smallest = right_child;
    if(smallest != index) {
        swap_nodes(&min_heap -> array[smallest], &min_heap -> array[index]);
        min_heapify(min_heap, smallest);
    }
}

node *extract_min(heap *min_heap) {
    node *min_node = min_heap -> array[0];
    min_heap -> array[0] = min_heap -> array[min_heap -> size - 1];
    --min_heap -> size;
    min_heapify(min_heap, 0);
    return min_node;
}

void insert_heap(heap *min_heap, node *new_node) {
    ++min_heap -> size;
    int i = min_heap -> size - 1;
    while(i && new_node -> freq < min_heap -> array[(i - 1) / 2] -> freq) {
        min_heap -> array[i] = min_heap -> array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap -> array[i] = new_node;
}

void build_min_heap(heap *min_heap) {
    int n = min_heap -> size;
    for(int i = (n - 1) / 2; i >= 0; --i)
        min_heapify(min_heap, i);
}

heap *create_priority_queue(char *data, int *freq, int size) {
    heap *min_heap = create_heap(size);
    for(int i = 0; i < size; ++i)
        insert_heap(min_heap, create_node(data[i], freq[i], NULL, NULL));
    build_min_heap(min_heap);
    return min_heap;
}

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

void print_codes(node *root, int *arr, int top, code *codes) {
    if(root -> left) {
        arr[top] = 0;
        print_codes(root -> left, arr, top + 1, codes);
    }
    if(root -> right) {
        arr[top] = 1;
        print_codes(root -> right, arr, top + 1, codes);
    }
    if(!(root -> left || root -> right)) {
        code new_code = {root -> data, (char *) malloc(sizeof(char) * top)};
        for(int i = 0; i < top; ++i)
            new_code.code[i] = arr[i] + '0';
        codes[root -> data] = new_code;
    }
}

void huffman_encoding(char *data, int *freq, int size) {
    heap *min_heap = create_priority_queue(data, freq, size);
    while(min_heap -> size != 1) {
        node *left = extract_min(min_heap);
        node *right = extract_min(min_heap);
        node *new_node = create_node('\0', left -> freq + right -> freq, left, right);
        insert_heap(min_heap, new_node);
    }
    node *root = extract_min(min_heap);
    int arr[MAX_TREE_HT], top = 0;
    code codes[256];
    print_codes(root, arr, top, codes);
    for(int i = 0; i < size; ++i) {
        printf("%s", codes[data[i]].code);
    }
}

int main() {
    char data[] = "huffmanencodingexample";
    int freq[] = {2, 2, 3, 3, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_encoding(data, freq, size);
    return 0;
}