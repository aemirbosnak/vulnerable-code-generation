//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the end of the queue
void enqueue(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        Node* temp = *head_ref;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete an element from the front of the queue
void dequeue(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
}

// Function to display the elements of the queue
void display(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the queue
    enqueue(&head, 5);
    enqueue(&head, 10);
    enqueue(&head, 15);
    enqueue(&head, 20);

    // Display the elements of the queue
    printf("Queue: ");
    display(head);

    // Delete an element from the front of the queue
    dequeue(&head);

    // Display the elements of the queue after deletion
    printf("\nQueue after deletion: ");
    display(head);

    return 0;
}