//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

//struct to hold characters and their frequency
struct char_freq {
    char character;
    int freq;
};

//node in the huffman tree
struct node {
    char character;
    int freq;
    struct node *left, *right;
};

//heap node
struct heap_node {
    char character;
    int freq;
    struct node *p;
};

//heap to store heap nodes
struct heap {
    int size;
    int capacity;
    struct heap_node *array;
};

//function to create a new node
struct node* new_node(char character, int freq) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node -> character = character;
    node -> freq = freq;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

//function to create a heap node
struct heap_node* new_heap_node(char character, int freq, struct node* p) {
    struct heap_node* node = (struct heap_node*) malloc(sizeof(struct heap_node));
    node -> character = character;
    node -> freq = freq;
    node -> p = p;
    return node;
}

//function to create a heap
struct heap* create_heap(int capacity) {
    struct heap* heap = (struct heap*) malloc(sizeof(struct heap));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> array = (struct heap_node*) malloc(heap -> capacity * sizeof(struct heap_node));
    return heap;
}

//function to perform heapify operation
void heapify(struct heap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap -> size && heap -> array[left].freq < heap -> array[smallest].freq) {
        smallest = left;
    }
    if (right < heap -> size && heap -> array[right].freq < heap -> array[smallest].freq) {
        smallest = right;
    }
    if (smallest != idx) {
        struct heap_node temp = heap -> array[idx];
        heap -> array[idx] = heap -> array[smallest];
        heap -> array[smallest] = temp;
        heapify(heap, smallest);
    }
}

//function to check if the heap has only one node
int is_size_one(struct heap* heap) {
    return (heap -> size == 1);
}

//function to get the minimum node from the heap
struct heap_node get_min(struct heap* heap) {
    struct heap_node temp = heap -> array[0];
    heap -> array[0] = heap -> array[heap -> size - 1];
    heap -> size--;
    heapify(heap, 0);
    return temp;
}

//function to insert a node into the heap
void insert(struct heap* heap, struct heap_node node) {
    if (heap -> size == heap -> capacity) {
        return;
    }
    heap -> size++;
    int i = heap -> size - 1;
    while (i && node.freq < heap -> array[(i - 1) / 2].freq) {
        heap -> array[i] = heap -> array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap -> array[i] = node;
}

//function to build the huffman tree
struct node* build_huffman_tree(struct char_freq freq_table[], int n) {
    struct heap* heap = create_heap(n);
    for (int i = 0; i < n; i++) {
        struct node* node = new_node(freq_table[i].character, freq_table[i].freq);
        struct heap_node heap_node = {
            freq_table[i].character,
            freq_table[i].freq,
            node
        };
        insert(heap, heap_node);
    }
    while (!is_size_one(heap)) {
        struct heap_node left = get_min(heap);
        struct heap_node right = get_min(heap);
        struct node* node = new_node('#', left.freq + right.freq);
        node -> left = left.p;
        node -> right = right.p;
        struct heap_node heap_node = {
            '#', left.freq + right.freq, node
        };
        insert(heap, heap_node);
    }
    return get_min(heap).p;
}

//function to print the huffman codes for all the characters in the huffman tree
void print_codes(struct node* root, int arr[], int top) {
    if (root -> left) {
        arr[top] = 0;
        print_codes(root -> left, arr, top + 1);
    }
    if (root -> right) {
        arr[top] = 1;
        print_codes(root -> right, arr, top + 1);
    }
    if (!(root -> left) && !(root -> right)) {
        printf("%c: ", root -> character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

//function to perform huffman coding
void huffman_coding(struct char_freq freq_table[], int n) {
    struct node* root = build_huffman_tree(freq_table, n);
    int arr[MAX_TREE_HT], top = 0;
    print_codes(root, arr, top);
}

//driver program
int main() {
    struct char_freq freq_table[] = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };
    int n = sizeof(freq_table) / sizeof(freq_table[0]);
    huffman_coding(freq_table, n);
    return 0;
}