//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    int size;
    int capacity;
    struct Node* head;
} Array;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initArray(Array* arr, int initialCapacity) {
    arr->size = 0;
    arr->capacity = initialCapacity;
    arr->head = NULL;
}

void add(Array* arr, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = arr->head;
    arr->head = newNode;
    arr->size++;

    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->head = realloc(arr->head, sizeof(Node) * arr->capacity);
    }
}

int get(Array* arr, int index) {
    Node* current = arr->head;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            printf("Index out of range\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }
    return current->data;
}

void removeAt(Array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of range\n");
        exit(EXIT_FAILURE);
    }

    Node* prev = NULL;
    Node* current = arr->head;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
    arr->size--;
}

void printArray(Array* arr) {
    Node* current = arr->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Array arr;
    initArray(&arr, 10);

    add(&arr, 1);
    add(&arr, 2);
    add(&arr, 3);
    add(&arr, 4);
    add(&arr, 5);

    printf("Current array:\n");
    printArray(&arr);

    printf("Get element at index 2: %d\n", get(&arr, 2));
    printf("Get element at index 5: %d\n", get(&arr, 5));

    removeAt(&arr, 2);
    printf("After removing element at index 2:\n");
    printArray(&arr);

    return 0;
}