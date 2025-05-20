//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Node* createQueue() {
    struct Node* head = NULL;
    return head;
}

// Function to insert a new element at the end of the queue
void enqueue(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove and return the element from the front of the queue
int dequeue(struct Node** headRef) {
    if (*headRef == NULL) {
        return -1;
    }
    int data = (*headRef)->data;
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    return data;
}

// Function to check if the queue is empty
bool isEmpty(struct Node* head) {
    return (head == NULL);
}

// Function to print the elements of the queue
void printQueue(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to get the size of the queue
int getSize(struct Node* head) {
    int size = 0;
    struct Node* temp = head;
    while (temp!= NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

int main() {
    struct Node* head = createQueue();
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    printf("Queue elements: ");
    printQueue(head);
    printf("Size of the queue: %d\n", getSize(head));
    dequeue(&head);
    printf("Queue elements after deletion: ");
    printQueue(head);
    return 0;
}