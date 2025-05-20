//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet Queue
struct Queue {
    int Romeo, Juliet;
    struct Queue *next;
};

// Create a new queue node
struct Queue *create_node(int Romeo, int Juliet) {
    struct Queue *new_node = (struct Queue *)malloc(sizeof(struct Queue));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->Romeo = Romeo;
    new_node->Juliet = Juliet;
    new_node->next = NULL;
    return new_node;
}

// Insert an element into the queue
void enqueue(struct Queue **head, struct Queue **tail, int Romeo, int Juliet) {
    struct Queue *new_node = create_node(Romeo, Juliet);
    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

// Remove an element from the queue
struct Queue *dequeue(struct Queue **head) {
    if (*head == NULL) {
        printf("Error: queue is empty\n");
        return NULL;
    }
    struct Queue *temp = *head;
    *head = (*head)->next;
    free(temp);
    return temp;
}

// Print the queue
void print_queue(struct Queue *head) {
    while (head != NULL) {
        printf("(%d, %d) ", head->Romeo, head->Juliet);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Queue *head = NULL, *tail = NULL;

    // Romeo and Juliet's first meeting
    enqueue(&head, &tail, 1, 1);

    // Their secret rendezvous
    enqueue(&head, &tail, 2, 2);
    enqueue(&head, &tail, 3, 3);

    // Their tragic separation
    dequeue(&head);
    dequeue(&head);

    // Their final reunion
    enqueue(&head, &tail, 4, 4);

    // Print the queue of their love story
    print_queue(head);

    return 0;
}