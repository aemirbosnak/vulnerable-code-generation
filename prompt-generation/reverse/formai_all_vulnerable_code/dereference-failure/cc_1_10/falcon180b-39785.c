//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the queue
void enqueue(struct node** front_ref, struct node** rear_ref, int data) {
    struct node* new_node = newNode(data);

    if (*front_ref == NULL) {
        *front_ref = new_node;
        *rear_ref = new_node;
    }
    else {
        (*rear_ref)->next = new_node;
        *rear_ref = new_node;
    }
}

// Function to remove an element from the queue
int dequeue(struct node** front_ref, struct node** rear_ref) {
    char res;
    struct node* temp = *front_ref;
    int data = temp->data;

    if (*front_ref == *rear_ref) {
        *front_ref = NULL;
        *rear_ref = NULL;
    }
    else {
        *front_ref = (*front_ref)->next;
    }

    free(temp);

    return data;
}

// Function to display the elements in the queue
void display(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("Queue after adding elements: ");
    display(front);

    int removed_element = dequeue(&front, &rear);
    printf("\nRemoved element: %d", removed_element);

    printf("\nQueue after removing an element: ");
    display(front);

    return 0;
}