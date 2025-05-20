//Gemma-7B DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertionSort(Node* head) {
    Node* current = head;
    Node* sorted = NULL;

    while (current) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = current->data;
        newNode->next = NULL;

        if (sorted) {
            Node* traverse = sorted;
            while (traverse->next) {
                if (newNode->data < traverse->next->data) {
                    break;
                }
                traverse = traverse->next;
            }

            newNode->next = traverse->next;
            traverse->next = newNode;
        } else {
            sorted = newNode;
        }
        current = current->next;
    }

    head = sorted;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 4;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 8;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 6;
    head->next->next->next->next = NULL;

    insertionSort(head);

    Node* traverse = head;
    while (traverse) {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }

    return 0;
}