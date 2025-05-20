//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the rear of the queue
void enqueue(struct Node** front_ref, struct Node** rear_ref, int data) {
    struct Node* node = newNode(data);

    if(*front_ref == NULL) {
        *front_ref = node;
        *rear_ref = node;
    }
    else {
        (*rear_ref)->next = node;
        *rear_ref = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Node** front_ref, struct Node** rear_ref) {
    char res;
    struct Node* node = *front_ref;
    int data = node->data;

    if(*front_ref!= NULL) {
        *front_ref = node->next;

        if(*front_ref == NULL)
            *rear_ref = NULL;

        free(node);
    }
    else {
        printf("Queue Underflow\n");
        res = 0;
    }

    return res;
}

// Function to display the elements in the queue
void display(struct Node* node) {
    while(node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("Elements in the queue are: ");
    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);

    printf("\nElements in the queue after dequeueing twice are: ");
    display(front);

    return 0;
}