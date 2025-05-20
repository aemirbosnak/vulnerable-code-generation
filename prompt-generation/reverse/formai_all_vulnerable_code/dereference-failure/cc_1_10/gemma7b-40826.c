//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void greedy(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int currentData = current->data;
        int previousData = previous ? previous->data : -1;

        if (currentData > previousData) {
            previous = current;
        }
    }

    printf("The greedy algorithm has selected node with data: %d\n", previous->data);
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    greedy(head);

    return 0;
}