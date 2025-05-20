//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

// Structure for queue elements
typedef struct QueueElement {
    char data[100];
    struct QueueElement* next;
} QueueElement;

// Structure for the queue
typedef struct Queue {
    QueueElement* front;
    QueueElement* rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Add an element to the queue
void enqueue(Queue* q, char* data) {
    QueueElement* newElement = (QueueElement*) malloc(sizeof(QueueElement));
    strcpy(newElement->data, data);
    newElement->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newElement;
    } else {
        q->rear->next = newElement;
        q->rear = newElement;
    }
}

// Remove an element from the queue
char* dequeue(Queue* q) {
    QueueElement* temp = q->front;
    char* data = temp->data;

    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

// Print the queue elements
void printQueue(Queue* q) {
    QueueElement* current = q->front;

    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");

    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Queue q;
    initQueue(&q);

    char input[100];

    printf("Sherlock's Queue:\n");

    while (1) {
        printf("Enter a clue or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        enqueue(&q, input);
    }

    printf("\nSherlock is thinking...\n");
    printf("Let me see what I have here:\n");

    printQueue(&q);

    while (!isEmpty(&q)) {
        char clue = dequeue(&q);

        // Process the clue here
        printf("Processed clue: %s\n", clue);
    }

    return 0;
}