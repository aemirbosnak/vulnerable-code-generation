//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

node_t* create_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void enqueue(node_t** head, int data) {
    node_t* new_node = create_node(data);
    node_t* current = *head;

    if (*head == NULL) {
        *head = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void dequeue(node_t** head) {
    node_t* first = *head;

    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        *head = NULL;
        free(first);
    } else {
        node_t* second = (*head)->next;
        (*head)->next = NULL;
        second->prev = NULL;
        *head = second;
    }
}

void print_queue(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t* head = NULL;

    enqueue(&head, 5);
    enqueue(&head, 10);
    enqueue(&head, 15);
    enqueue(&head, 20);

    print_queue(head);

    dequeue(&head);

    print_queue(head);

    return 0;
}