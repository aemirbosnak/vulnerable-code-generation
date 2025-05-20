//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Heap;

Heap *createHeap(int size) {
    Heap *heap = malloc(sizeof(Heap));
    heap->data = malloc(size * sizeof(int));
    heap->size = size;
    return heap;
}

void heapify(Heap *heap, int i, int n) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if (l < n && heap->data[l] > heap->data[largest]) {
        largest = l;
    }

    if (r < n && heap->data[r] > heap->data[largest]) {
        largest = r;
    }

    if (largest!= i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;

        heapify(heap, largest, n);
    }
}

void buildHeap(Heap *heap) {
    int n = heap->size;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(heap, i, n);
    }
}

void heapSort(Heap *heap) {
    int n = heap->size;
    for (int i = n - 1; i >= 0; i--) {
        int temp = heap->data[0];
        heap->data[0] = heap->data[i];
        heap->data[i] = temp;

        heapify(heap, 0, i);
    }
}

void printHeap(Heap *heap) {
    int n = heap->size;
    for (int i = 0; i < n; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Heap *heap = createHeap(MAX_SIZE);
    int n = rand() % MAX_SIZE + 1;

    for (int i = 0; i < n; i++) {
        heap->data[i] = rand() % 100;
    }

    buildHeap(heap);
    heapSort(heap);
    printHeap(heap);

    return 0;
}