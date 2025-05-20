//Gemma-7B DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sortByData(Node* head) {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        for (Node* current = head; current->next; current = current->next) {
            Node* next = current->next;
            if (current->data > next->data) {
                swap(current, next);
            }
        }
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 5;

    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 2;

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 8;

    Node* fourth = (Node*)malloc(sizeof(Node));
    fourth->data = 3;

    head->next = second;
    second->next = third;
    third->next = fourth;

    sortByData(head);

    printf("Sorted list:");
    for (Node* current = head; current; current = current->next) {
        printf(" %d", current->data);
    }

    return 0;
}