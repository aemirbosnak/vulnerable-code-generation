//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct baggage_node {
    char *name;
    struct baggage_node *next;
} baggage_node;

void insert_into_queue(baggage_node **head, char *name) {
    baggage_node *new_node = (baggage_node *)malloc(sizeof(baggage_node));
    new_node->name = name;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void remove_from_queue(baggage_node **head, char *name) {
    baggage_node *prev = NULL;
    baggage_node *curr = *head;

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (prev) {
        prev->next = curr->next;
        free(curr);
    } else {
        *head = NULL;
        free(curr);
    }
}

int main() {
    baggage_node *head = NULL;

    insert_into_queue(&head, "John Doe");
    insert_into_queue(&head, "Jane Doe");
    insert_into_queue(&head, "Peter Pan");

    remove_from_queue(&head, "Jane Doe");

    for (baggage_node *curr = head; curr; curr = curr->next) {
        printf("%s ", curr->name);
    }

    return 0;
}