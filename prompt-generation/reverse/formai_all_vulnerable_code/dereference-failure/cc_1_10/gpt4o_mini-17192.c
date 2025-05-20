//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight in the queue
typedef struct Knight {
    int id;
    struct Knight* next;
} Knight;

// Structure to represent the queue of knights
typedef struct Queue {
    Knight* front;
    Knight* rear;
} Queue;

// Function to create a new knight
Knight* createKnight(int id) {
    Knight* newKnight = (Knight*) malloc(sizeof(Knight));
    newKnight->id = id;
    newKnight->next = NULL;
    return newKnight;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add a knight to the end of the queue
void enqueue(Queue* q, int id) {
    Knight* newKnight = createKnight(id);
    if (isEmpty(q)) {
        q->front = newKnight;
        q->rear = newKnight;
    } else {
        q->rear->next = newKnight;
        q->rear = newKnight;
    }
    printf("Knight %d has joined the queue!\n", id);
}

// Function to remove a knight from the front of the queue
Knight* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Alas! The queue is empty, no knights to dequeue!\n");
        return NULL;
    }
    Knight* tmp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("Knight %d has embarked on their noble quest!\n", tmp->id);
    return tmp;
}

// Function to display the queue of knights
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty, no brave souls await!\n");
        return;
    }
    Knight* curr = q->front;
    printf("Knights in the queue: ");
    while (curr != NULL) {
        printf("%d ", curr->id);
        curr = curr->next;
    }
    printf("\n");
}

// Main function to demonstrate the C Queue implementation
int main() {
    Queue* knightQueue = createQueue();
    
    int choice, knightId;
    
    while (1) {
        printf("\n--- Knight's Queue Management ---\n");
        printf("1. Enlist a knight\n");
        printf("2. Release a knight\n");
        printf("3. Show knights in queue\n");
        printf("4. Exit\n");
        printf("-----------------------------------\n");
        printf("Choose thy option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the knight's noble ID: ");
                scanf("%d", &knightId);
                enqueue(knightQueue, knightId);
                break;
            case 2:
                {
                    Knight* releasedKnight = dequeue(knightQueue);
                    if (releasedKnight != NULL) {
                        free(releasedKnight);
                    }
                }
                break;
            case 3:
                displayQueue(knightQueue);
                break;
            case 4:
                printf("Farewell, good sirs and madams. The quest has ended.\n");
                free(knightQueue);
                exit(0);
            default:
                printf("Thou hast chosen an invalid option. Please choose again!\n");
        }
    }
    
    return 0;
}