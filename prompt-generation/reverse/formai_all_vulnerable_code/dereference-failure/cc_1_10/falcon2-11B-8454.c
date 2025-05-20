//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add an element to the queue
void enqueue(struct node** head_ref, int new_data) {
    struct node* new_node = create_node(new_data);
    struct node* current = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Function to remove an element from the queue
int dequeue(struct node** head_ref) {
    if (*head_ref == NULL) {
        return -1;
    }

    int data = (*head_ref)->data;
    struct node* temp = *head_ref;

    *head_ref = (*head_ref)->next;
    free(temp);

    return data;
}

// Function to display the elements in the queue
void display_queue(struct node* head) {
    struct node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;

    enqueue(&head, 5);
    enqueue(&head, 10);
    enqueue(&head, 15);

    printf("Elements in the queue: ");
    display_queue(head);

    printf("\nDequeued element: %d\n", dequeue(&head));

    return 0;
}