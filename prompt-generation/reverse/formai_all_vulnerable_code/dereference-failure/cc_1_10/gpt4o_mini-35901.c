//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Let's declare our very own queue of type integer, which we will lovingly call "Queue of Wonders"
typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} QueueOfWonders;

// Declare the Queue
QueueOfWonders* createQueue() {
    QueueOfWonders* q = (QueueOfWonders*)malloc(sizeof(QueueOfWonders));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full (yep, it’s a full house in there!)
int isFull(QueueOfWonders* q) {
    return (q->rear == QUEUE_SIZE - 1);
}

// Check if the queue is empty (better call a doctor!)
int isEmpty(QueueOfWonders* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue: Add a new "wonder" to the queue
void enqueue(QueueOfWonders* q, int value) {
    if (isFull(q)) {
        printf("Oh no! The Queue of Wonders is full! Can't add %d!\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First item, we set the front
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d. The Queue of Wonders now holds %d wonder(s)!\n", value, q->rear - q->front + 1);
}

// Dequeue: Remove a "wonder" from the queue
int dequeue(QueueOfWonders* q) {
    if (isEmpty(q)) {
        printf("Oops! There's nothing in the Queue of Wonders to dequeue!\n");
        return -1; // Indicating that the queue is empty
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        printf("The Queue of Wonders is now empty! What a sad day...\n");
        q->front = -1; // Reset the queue
        q->rear = -1;
    }
    printf("Dequeued: %d. What's next in the Queue of Wonders?\n", item);
    return item;
}

// Peek: Check the front of the queue
int peek(QueueOfWonders* q) {
    if (isEmpty(q)) {
        printf("Oh dear! The Queue of Wonders is empty! Nothing to peek at!\n");
        return -1; // Indicating that the queue is empty
    }
    return q->items[q->front];
}

// Display the items in the queue
void displayQueue(QueueOfWonders* q) {
    if (isEmpty(q)) {
        printf("The Queue of Wonders is empty! Where did all the wonders go?\n");
        return;
    }
    printf("Queue of Wonders: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    QueueOfWonders* myQueue = createQueue();
    int choice, value;

    printf("Welcome to the Queue of Wonders! Choose your adventure:\n");
    
    do {
        printf("\n1. Enqueue a wonder\n2. Dequeue a wonder\n3. Peek at the front wonder\n4. Display the queue\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(myQueue, value);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                value = peek(myQueue);
                if (value != -1) {
                    printf("The front wonder is: %d\n", value);
                }
                break;
            case 4:
                displayQueue(myQueue);
                break;
            case 5:
                printf("Exiting the Queue of Wonders... Come back soon!\n");
                break;
            default:
                printf("That's not a valid choice! You must be lost!\n");
        }
    } while (choice != 5);

    free(myQueue);
    return 0;
}