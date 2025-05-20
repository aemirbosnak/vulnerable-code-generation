//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct node {
    int freq;
    char c;
    struct node* left, *right;
} Node;

typedef struct heap {
    int size;
    Node** arr;
} Heap;

Node* createNode(char c, int freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->c = c;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->arr = (Node**)malloc(capacity * sizeof(Node*));
    return heap;
}

void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Heap* heap, int idx) {
    int leftIndex = (idx * 2) + 1;
    int rightIndex = (idx * 2) + 2;
    int smallest = idx;

    if (leftIndex < heap->size && heap->arr[leftIndex]->freq < heap->arr[smallest]->freq) {
        smallest = leftIndex;
    }
    if (rightIndex < heap->size && heap->arr[rightIndex]->freq < heap->arr[smallest]->freq) {
        smallest = rightIndex;
    }
    if (smallest != idx) {
        swapNode(&heap->arr[smallest], &heap->arr[idx]);
        minHeapify(heap, smallest);
    }
}

Node* getMinNode(Heap* heap) {
    Node* min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return min;
}

void insertNode(Heap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->arr[(i - 1) / 2]->freq) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = node;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(Node* node) {
    return !(node->left) && !(node->right);
}

void encode(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        encode(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        encode(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->c);
        printArr(arr, top);
    }
}

void huffmanCoding(char data[], int freq[], int size) {
    Heap* heap = createHeap(size);
    for (int i = 0; i < size; i++) {
        Node* temp = createNode(data[i], freq[i]);
        insertNode(heap, temp);
    }

    while (heap->size != 1) {
        Node* left = getMinNode(heap);
        Node* right = getMinNode(heap);

        Node* temp = createNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        insertNode(heap, temp);
    }
    int arr[SIZE], top = 0;
    encode(heap->arr[0], arr, top);

}

int main() {
    char data[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[SIZE] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffmanCoding(data, freq, size);

    return 0;
}