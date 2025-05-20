//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct baggage {
    int id; // ID of the baggage
    int weight; // Weight of the baggage in kilograms
    int dest_gate; // Destination gate for the baggage
};

struct node {
    struct baggage data;
    struct node* next;
};

void enqueue(struct node** head, struct node** tail, struct baggage data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void dequeue(struct node** head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;

    printf("Baggage with ID %d and weight %d kg has been released to gate %d\n", temp->data.id, temp->data.weight, temp->data.dest_gate);

    free(temp);
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;

    srand(time(0));

    printf("Starting airport baggage handling simulation...\n\n");
    
    printf("Generating 10 random baggages for simulation...\n\n");
    for (int i = 1; i <= 10; i++) {
        struct baggage b;
        b.id = i;
        b.weight = rand() % 50 + 1;
        b.dest_gate = rand() % 10 + 1;

        enqueue(&head, &tail, b);
    }

    printf("Enqueueing completed.\n\n");

    while (head != NULL) {
        dequeue(&head);
    }

    printf("\nBaggage handling simulation completed.\n");

    return 0;
}