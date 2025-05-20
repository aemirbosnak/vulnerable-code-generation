//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP_SIZE 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertMinHeap(Node** head, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* lastNode = *head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void traverseHeap(Node* head)
{
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    insertMinHeap(&head, 10);
    insertMinHeap(&head, 20);
    insertMinHeap(&head, 30);
    insertMinHeap(&head, 40);
    insertMinHeap(&head, 50);

    traverseHeap(head);

    return 0;
}