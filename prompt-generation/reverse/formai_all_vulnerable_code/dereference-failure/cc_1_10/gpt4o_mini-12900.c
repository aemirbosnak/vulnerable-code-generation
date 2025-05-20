//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Definition of the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    struct Node* temp = createNode(value);
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        printf("Yay! %d has been added to the queue!\n", value);
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
    printf("Hooray! %d has been added to the queue!\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Oops! The queue is empty, nothing to dequeue.\n");
        return -1; // Indicating the queue is empty
    }

    struct Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Yay! %d has been removed from the queue!\n", value);
    return value;
}

// Function to display the queue elements
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty! No elements to display.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Menu for user interaction
void menu() {
    printf("Welcome to the happy Queue program! Choose an option:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, value;

    do {
        menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Thank you for using the happy Queue program! Bye-bye!\n");
                break;
            default:
                printf("Oops! That's an invalid choice. Please try again!\n");
        }
    } while (choice != 4);

    // Clean up memory
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
    
    return 0;
}