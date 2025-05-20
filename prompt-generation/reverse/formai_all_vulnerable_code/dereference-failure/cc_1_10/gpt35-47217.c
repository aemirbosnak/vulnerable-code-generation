//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node
struct node {
    char letter;
    int freq;
    struct node* left;
    struct node* right;
};

// Min Heap node
struct min_heap_node {
    struct node* data;
    struct min_heap_node* next;
};

// Min Heap
struct min_heap {
    struct min_heap_node* head;
    int size;
};

// Create a new Huffman tree node
struct node* new_node(char letter, int freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->letter = letter;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Create a new Min Heap node
struct min_heap_node* new_min_heap_node(struct node* data) {
    struct min_heap_node* temp = (struct min_heap_node*)malloc(sizeof(struct min_heap_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create a new Min Heap
struct min_heap* create_min_heap() {
    struct min_heap* heap = (struct min_heap*)malloc(sizeof(struct min_heap));
    heap->head = NULL;
    heap->size = 0;
    return heap;
}

// Swap two Min Heap nodes
void swap_min_heap_nodes(struct min_heap_node* a, struct min_heap_node* b) {
    struct node* temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Heapify the Min Heap
void min_heapify(struct min_heap* heap) {
    struct min_heap_node* current = heap->head;
    while (current->next != NULL) {
        if (current->data->freq > current->next->data->freq) {
            swap_min_heap_nodes(current, current->next);
            current = heap->head;
        } else {
            current = current->next;
        }
    }
}

// Insert a node into the Min Heap
void insert_min_heap(struct min_heap* heap, struct node* data) {
    struct min_heap_node* temp = new_min_heap_node(data);
    if (heap->head == NULL) {
        heap->head = temp;
    } else {
        struct min_heap_node* current = heap->head;
        if (current->data->freq > data->freq) {
            temp->next = current;
            heap->head = temp;
        } else {
            while (current->next != NULL && current->next->data-> freq < data->freq) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }
    heap->size++;
}

// Remove the node with the smallest frequency from the Min Heap
struct node* remove_min_heap(struct min_heap* heap) {
    struct node* data = heap->head->data;
    heap->head = heap->head->next;
    heap->size--;
    return data;
}

// Build the Huffman tree
struct node* build_huffman_tree(char data[], int freq[], int size) {
    struct node *left, *right, *top;
    struct min_heap* heap = create_min_heap();    
    for (int i = 0; i < size; ++i) {
        insert_min_heap(heap, new_node(data[i], freq[i]));
    }
    
    while (heap->size > 1) {
        left = remove_min_heap(heap);
        right = remove_min_heap(heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(heap, top);
    }
    return remove_min_heap(heap);
}

// Print the Huffman codes
void print_huffman_codes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }
 
    if (!root->left && !root->right) {
        printf("%c : ", root->letter);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
 
// Huffman codes driver function
void huffman_codes(char data[], int freq[], int size) {
   struct node* root = build_huffman_tree(data, freq, size);
   int arr[size], top = 0;
   
   print_huffman_codes(root, arr, top);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    huffman_codes(data, freq, size);
    return 0;
}