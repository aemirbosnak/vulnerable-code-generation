//FormAI DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

typedef struct {
    int heap[MAX_SIZE];
    int size;
} Heap;

void initializeLinkedList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

bool isEmpty(LinkedList* list) {
    return list->size == 0;
}

void printLinkedList(LinkedList* list) {
    if (isEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void deleteAtBeginning(LinkedList* list) {
    Node* nodeToDelete = list->head;
    list->head = nodeToDelete->next;
    free(nodeToDelete);
    list->size--;
}

void initializeHeap(Heap* heap) {
    heap->size = 0;
}

bool isHeapEmpty(Heap* heap) {
    return heap->size == 0;
}

void printHeap(Heap* heap) {
    if (isHeapEmpty(heap)) {
        printf("The heap is empty.\n");
        return;
    }
    for(int i = 0; i < heap->size; i++) {
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}

void insertInHeap(Heap* heap, int data) {
    heap->heap[heap->size] = data;
    heap->size++;
    int childIndex = heap->size - 1;
    int parentIndex = (childIndex - 1) / 2;
    while (childIndex > 0 && heap->heap[childIndex] > heap->heap[parentIndex]) {
        int temp = heap->heap[childIndex];
        heap->heap[childIndex] = heap->heap[parentIndex];
        heap->heap[parentIndex] = temp;
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

void deleteFromHeap(Heap* heap) {
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    int parentIndex = 0;
    while (true) {
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        if (leftChildIndex >= heap->size) {
            break;
        }
        int largerChildIndex = leftChildIndex;
        if (rightChildIndex < heap->size && heap->heap[rightChildIndex] > heap->heap[leftChildIndex]) {
            largerChildIndex = rightChildIndex;
        }
        if (heap->heap[parentIndex] < heap->heap[largerChildIndex]) {
            int temp = heap->heap[parentIndex];
            heap->heap[parentIndex] = heap->heap[largerChildIndex];
            heap->heap[largerChildIndex] = temp;
            parentIndex = largerChildIndex;
        } else {
            break;
        }
    }
}

int main() {
   LinkedList list;
   initializeLinkedList(&list);
   insertAtBeginning(&list, 10);
   insertAtBeginning(&list, 20);
   insertAtBeginning(&list, 30);
   printLinkedList(&list);
   deleteAtBeginning(&list);
   printLinkedList(&list);

   Heap heap;
   initializeHeap(&heap);
   insertInHeap(&heap, 40);
   insertInHeap(&heap, 30);
   insertInHeap(&heap, 50);
   printHeap(&heap);
   deleteFromHeap(&heap);
   printHeap(&heap);

   return 0;
}