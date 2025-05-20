//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
    int size;
} linked_list;

typedef struct {
    int array[MAX_SIZE];
    int top;
} stack;

typedef struct {
    int heap[MAX_SIZE];
    int size;
} binary_heap;

void insert(linked_list *list, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

void push(stack *s, int data) {
    s->array[++s->top] = data;
}

int pop(stack *s) {
    if (s->top == -1) {
        printf("Error: Stack is empty.");
        return -1;
    } else {
        return s->array[s->top--];
    }
}

void insert_heap(binary_heap *heap, int data) {
    if (heap->size == MAX_SIZE) {
        printf("Error: Heap overflow");
        return;
    }
    int i = ++heap->size;
    while (i != 1 && data > heap->heap[i/2]) {
        heap->heap[i] = heap->heap[i/2];
        i = i/2;
    }
    heap->heap[i] = data;
}

void heapify(binary_heap *heap, int i) {
    int largest;
    int l = 2 * i;
    int r = 2 * i + 1;
    
    if (l <= heap->size && heap->heap[l] > heap->heap[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= heap->size && heap->heap[r] > heap->heap[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = heap->heap[i];
        heap->heap[i] = heap->heap[largest];
        heap->heap[largest] = temp;
        heapify(heap, largest);
    }
}

int main() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->size = 0;

    insert(list, 5);
    insert(list, 9);
    insert(list, 2);
    insert(list, 4);

    stack *s = malloc(sizeof(stack));
    s->top = -1;

    push(s, 3);
    push(s, 7);

    binary_heap *heap = malloc(sizeof(binary_heap));
    heap->size = 0;

    insert_heap(heap, 8);
    insert_heap(heap, 6);
    insert_heap(heap, 10);

    heapify(heap, 1);
    
    return 0;
}