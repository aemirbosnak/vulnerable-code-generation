//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the Queue
void printQueue(struct Node* front) {
    struct Node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the Queue is empty
int isQueueEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to insert an element at the rear of the Queue
void enqueue(struct Node** front, int data) {
    struct Node* newNode = createNode(data);
    if (*front == NULL) {
        *front = newNode;
    } else {
        struct Node* temp = *front;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete an element from the front of the Queue
void dequeue(struct Node** front) {
    if (isQueueEmpty(*front)) {
        printf("Queue is empty\n");
        return;
    }
    *front = (*front)->next;
    free(front);
}

// Function to delete an element from the Queue
void deleteElement(struct Node** front, int data) {
    if (isQueueEmpty(*front)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = *front;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found in the Queue\n");
        return;
    }
    if (temp == *front) {
        *front = temp->next;
    } else {
        struct Node* prev = *front;
        while (prev->next!= temp) {
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* front = NULL;
    enqueue(&front, 5);
    enqueue(&front, 10);
    enqueue(&front, 15);
    printQueue(front);
    printf("Deleting 10\n");
    deleteElement(&front, 10);
    printQueue(front);
    printf("Deleting 15\n");
    deleteElement(&front, 15);
    printQueue(front);
    printf("Deleting 5\n");
    dequeue(&front);
    printQueue(front);
    return 0;
}