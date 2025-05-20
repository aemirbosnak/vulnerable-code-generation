//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

struct node *new_node(char ch, int freq) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void swap_nodes(struct node **one, struct node **two) {
    struct node *temp = *one;
    *one = *two;
    *two = temp;
}

void heapify(struct node **heap, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left]->freq > heap[largest]->freq)
        largest = left;
    
    if (right < size && heap[right]->freq > heap[largest]->freq)
        largest = right;
    
    if (largest != i) {
        swap_nodes(&heap[i], &heap[largest]);
        heapify(heap, size, largest);
    }
}

struct node *build_heap(char *data, int *freq, int size) {
    struct node **heap = (struct node **)malloc(size * sizeof(struct node *));
    for (int i = 0; i < size; i++) {
        heap[i] = new_node(data[i], freq[i]);
    }

    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(heap, size, i);

    while (size > 1) {
        struct node *left = heap[0];
        swap_nodes(&heap[0], &heap[size - 1]);
        size--;
        heapify(heap, size, 0);

        struct node *right = heap[0];
        swap_nodes(&heap[0], &heap[size - 1]);
        size--;
        heapify(heap, size, 0);

        struct node *parent = new_node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        heap[size] = parent;
        size++;
        heapify(heap, size, size - 1);
    }

    struct node *root = heap[0];
    free(heap);
    return root;
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void encode_helper(struct node *root, int *arr, int top) {
    if (root->left) {
        arr[top] = 0;
        encode_helper(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        encode_helper(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        print_arr(arr, top);
    }
}

void encode(char *data, int *freq, int size) {
    struct node *root = build_heap(data, freq, size);
    int arr[100], top = 0;
    encode_helper(root, arr, top);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    encode(data, freq, size);

    return 0;
}