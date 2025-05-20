//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int data;
    struct queue *next;
};

// Create a new queue
struct queue *create_queue() {
    return NULL;
}

// Add an element to the queue
void enqueue(struct queue **head, int data) {
    struct queue *new_element = malloc(sizeof(struct queue));
    new_element->data = data;
    new_element->next = NULL;
    if (*head == NULL) {
        *head = new_element;
    } else {
        enqueue(&(*head)->next, data);
    }
}

// Remove an element from the queue
int dequeue(struct queue **head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = (*head)->data;
        struct queue *new_head = (*head)->next;
        free(*head);
        *head = new_head;
        return data;
    }
}

// Print the queue
void print_queue(struct queue *head) {
    if (head == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("%d ", head->data);
        print_queue(head->next);
    }
}

// Free the queue
void free_queue(struct queue *head) {
    if (head == NULL) {
        return;
    } else {
        free_queue(head->next);
        free(head);
    }
}

// Main function
int main() {
    struct queue *head = create_queue();
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);
    print_queue(head);
    printf("\n");
    dequeue(&head);
    dequeue(&head);
    print_queue(head);
    printf("\n");
    free_queue(head);
    return 0;
}