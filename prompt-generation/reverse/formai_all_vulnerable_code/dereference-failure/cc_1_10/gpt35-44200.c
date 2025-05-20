//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct huffman_node {
    char data;
    unsigned freq;
    struct huffman_node *left, *right;
};

// Huffman tree structure
struct huffman_tree {
  unsigned size;
  unsigned capacity;
  struct huffman_node **array;
};

// create a new huffman node
struct huffman_node* new_huffman_node(char data, unsigned freq) {
    struct huffman_node* node = (struct huffman_node*) malloc(sizeof (struct huffman_node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// create a minimum heap node
struct huffman_node* create_min_heap_node(char data, unsigned freq) {
    struct huffman_node* node = new_huffman_node(data, freq);
    return node;
}

// create a minimum heap
struct huffman_tree* create_min_heap(unsigned capacity) {
    struct huffman_tree* min_heap = (struct huffman_tree*) malloc(sizeof (struct huffman_tree));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct huffman_node**) malloc(min_heap->capacity * sizeof (struct huffman_node*));
    return min_heap;
}

// swap two nodes
void swap_huffman_nodes(struct huffman_node** node1, struct huffman_node** node2) {
    struct huffman_node* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// min heapify
void min_heapify(struct huffman_tree* min_heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq)
        smallest = left;

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap_huffman_nodes(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

// check if size is 1
int is_size_one(struct huffman_tree* min_heap) {
    return (min_heap->size == 1);
}

// extract min node from heap
struct huffman_node* extract_min(struct huffman_tree* min_heap) {
    struct huffman_node* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

// insert node into min heap
void insert_node(struct huffman_tree* min_heap, struct huffman_node* node) {
    ++min_heap->size;
    int index = min_heap->size - 1;

    while (index && node->freq < min_heap->array[(index - 1) / 2]->freq) {
        min_heap->array[index] = min_heap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    min_heap->array[index] = node;
}

// build min heap
void build_min_heap(struct huffman_tree* min_heap) {
    int n = min_heap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }
}

// check if node is a leaf
int is_leaf(struct huffman_node* node) {
    return !(node->left) && !(node->right);
}

// create a min heap of capacity equal to size and insert all character nodes
struct huffman_tree* build_huffman_tree(char data[], int freq[], int size) {
    struct huffman_tree* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        insert_node(min_heap, create_min_heap_node(data[i], freq[i]));
    }

    build_min_heap(min_heap);

    while (!is_size_one(min_heap)) {
        struct huffman_node* left = extract_min(min_heap);
        struct huffman_node* right = extract_min(min_heap);
        struct huffman_node* parent = new_huffman_node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insert_node(min_heap, parent);
    }

    return min_heap;
}

// print huffman codes for all the characters
void print_codes(struct huffman_node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// encode data to huffman codes
void huffman_encoding(struct huffman_tree* tree, const char* data) {
    int n = strlen(data);
    int arr[MAX_TREE_HT], top = 0;

    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0; j < tree->size; ++j) {
            if (tree->array[j]->data == data[i]) {
                printf("%d", arr[j]);
                break;
            }
        }
    }
}

// main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof (data) / sizeof (data[0]);
    struct huffman_tree* tree = build_huffman_tree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    print_codes(tree->array[0], arr, top);

    const char* message = "abcdef";
    printf("Encoded message: ");
    huffman_encoding(tree, message);

    return 0;
}