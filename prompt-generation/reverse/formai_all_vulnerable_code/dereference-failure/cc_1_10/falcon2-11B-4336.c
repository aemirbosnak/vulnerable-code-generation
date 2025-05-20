//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the elements of the queue
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the front of the queue
void enqueue(Node** front, int data)
{
    Node* newNode = createNode(data);
    newNode->next = *front;
    *front = newNode;
}

// Function to remove and return the element at the front of the queue
int dequeue(Node** front)
{
    if (*front == NULL)
    {
        return -1;
    }
    int data = (*front)->data;
    Node* temp = *front;
    *front = (*front)->next;
    free(temp);
    return data;
}

// Function to print all the elements of the queue
void printQueue(Node* front)
{
    Node* temp = front;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to check if the queue is empty
int isEmpty(Node* front)
{
    return (front == NULL);
}

int main()
{
    Node* front = NULL;

    // Enqueue elements into the queue
    enqueue(&front, 1);
    enqueue(&front, 2);
    enqueue(&front, 3);
    enqueue(&front, 4);
    enqueue(&front, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(front);

    // Dequeue elements from the queue
    printf("Dequeued: ");
    printf("%d\n", dequeue(&front));
    printf("%d\n", dequeue(&front));
    printf("%d\n", dequeue(&front));
    printf("%d\n", dequeue(&front));
    printf("%d\n", dequeue(&front));

    // Check if the queue is empty
    if (isEmpty(front))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }

    return 0;
}