//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void visualize_list(Node* head)
{
    printf("Visualizing the linked list:\n");

    Node* current = head;
    while (current)
    {
        printf("Data: %d, Next: %p\n", current->data, current->next);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Node* head = NULL;

    // Create a few nodes
    Node* node1 = malloc(sizeof(Node));
    node1->data = 10;
    node1->next = NULL;

    Node* node2 = malloc(sizeof(Node));
    node2->data = 20;
    node2->next = NULL;

    Node* node3 = malloc(sizeof(Node));
    node3->data = 30;
    node3->next = NULL;

    // Link the nodes together
    head = node1;
    node1->next = node2;
    node2->next = node3;

    visualize_list(head);

    return 0;
}