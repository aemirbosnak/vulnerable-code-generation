//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* node structure definition */
struct node {
    int data;
    struct node* next;
};

/* function to create a new node with the given data */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* function to check if the queue is empty */
int isEmpty(struct node* front, struct node* rear) {
    if (front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

/* function to add an element to the rear of the queue */
void enqueue(struct node** front, struct node** rear, int data) {
    struct node* node = newNode(data);

    if (isEmpty(*front, *rear)) {
        *front = node;
        *rear = node;
    } else {
        (*rear)->next = node;
        *rear = node;
    }
}

/* function to remove an element from the front of the queue */
int dequeue(struct node** front, struct node** rear) {
    struct node* node = *front;
    int data = node->data;

    if (isEmpty(node, *rear))
        return -1;

    *front = node->next;

    free(node);

    return data;
}

/* function to display the elements in the queue */
void display(struct node* front) {
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        while (front!= NULL) {
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);

    display(front);

    int removed = dequeue(&front, &rear);
    printf("Removed element: %d\n", removed);

    display(front);

    return 0;
}