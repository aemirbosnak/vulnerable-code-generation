//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct node {
    char c;
    int freq;
    struct node *left, *right;
};

struct node *new_node(char c, int freq) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->c = c;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void swap(struct node **a, struct node **b) {
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct node **heap, int i, int size) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l]->freq < heap[smallest]->freq)
        smallest = l;

    if (r < size && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        min_heapify(heap, smallest, size);
    }
}

int is_leaf(struct node *root) {
    return !(root->left) && !(root->right);
}

void print_codes(struct node *root, int arr[], int top) { 
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root)) {
        printf("%c: ", root->c);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffman_encoding(char data[], int freq[], int size) {
    struct node **heap = (struct node**) malloc(sizeof(struct node*) * size);
    for (int i = 0; i < size; i++)
        heap[i] = new_node(data[i], freq[i]);

    int heap_size = size;
    while (heap_size > 1) {
        struct node *left = heap[0];
        swap(&heap[0], &heap[heap_size - 1]);
        heap_size--;
        min_heapify(heap, 0, heap_size);

        struct node *right = heap[0];
        swap(&heap[0], &heap[heap_size - 1]);
        heap_size--;
        min_heapify(heap, 0, heap_size);

        struct node *temp = new_node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        heap[heap_size] = temp;
        heap_size++;
        min_heapify(heap, heap_size - 1, heap_size);
    }

    int arr[size];
    printf("Huffman Codes:\n"); 
    print_codes(heap[0], arr, 0);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    huffman_encoding(data, freq, size);

    return 0;
}