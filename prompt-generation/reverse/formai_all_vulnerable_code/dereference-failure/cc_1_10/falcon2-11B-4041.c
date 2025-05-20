//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct node {
    int data;
    struct node *next;
};

// Function to initialize the queue
void init_queue(struct node **front, struct node **rear) {
    *front = *rear = NULL;
}

// Function to add an element to the queue
void enqueue(struct node **front, struct node **rear, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*front == NULL) {
        *front = *rear = new_node;
    } else {
        new_node->next = *front;
        *front = new_node;
    }
}

// Function to remove an element from the queue
int dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = (*front)->data;
    struct node *temp = *front;
    *front = (*front)->next;
    free(temp);

    if (*front == NULL) {
        *rear = NULL;
    }

    return data;
}

// Function to display the elements of the queue
void display_queue(struct node *front) {
    struct node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *front, *rear;
    init_queue(&front, &rear);

    // Enqueue elements
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);

    // Display the elements
    display_queue(front);

    // Dequeue elements
    printf("Dequeued elements: ");
    while (dequeue(&front, &rear)!= -1) {
        printf("%d ", dequeue(&front, &rear));
    }

    return 0;
}