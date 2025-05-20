//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    int size;
    int *array;
} Node;

void init(Node* node, int size) {
    node->data = 0;
    node->size = size;
    node->array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        node->array[i] = 0;
    }
}

void insert(Node* node, int data) {
    if (node->data >= MAX_SIZE) {
        printf("Error: Array is full\n");
        return;
    }
    node->array[node->data++] = data;
}

void print(Node* node) {
    printf("Data: ");
    for (int i = 0; i < node->data; i++) {
        printf("%d ", node->array[i]);
    }
    printf("\n");
}

void main() {
    Node array;
    init(&array, MAX_SIZE);

    insert(&array, 10);
    print(&array);

    insert(&array, 20);
    print(&array);

    insert(&array, 30);
    print(&array);

    insert(&array, 40);
    print(&array);

    insert(&array, 50);
    print(&array);
}