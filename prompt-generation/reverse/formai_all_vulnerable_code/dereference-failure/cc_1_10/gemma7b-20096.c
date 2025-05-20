//Gemma-7B DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Heap {
    struct Node** arr;
    int size;
    int capacity;
};

void insert(struct Heap* h, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (h->size == h->capacity) {
        h->arr = (struct Node**)realloc(h->arr, h->capacity * 2);
        h->capacity *= 2;
    }

    newNode->next = h->arr[h->size];
    h->arr[h->size++] = newNode;
}

void sort(struct Heap* h) {
    for (int i = h->size - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0 && h->arr[j]->data > h->arr[i]->data; j--) {
            struct Node* tmp = h->arr[j];
            h->arr[j] = h->arr[i];
            h->arr[i] = tmp;
        }
    }
}

int main() {
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
    h->arr = NULL;
    h->size = 0;
    h->capacity = 10;

    insert(h, 'a');
    insert(h, 'c');
    insert(h, 'e');
    insert(h, 'g');
    insert(h, 'i');

    sort(h);

    for (struct Node* node = h->arr; node; node = node->next) {
        printf("%c ", node->data);
    }

    printf("\n");

    return 0;
}