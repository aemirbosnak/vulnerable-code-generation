//FormAI DATASET v1.0 Category: Queue ; Style: content
#include <stdio.h>
#include <stdlib.h>

/*
 * Queue Data Structure using C language
 */

// Declare a structure for queue node
struct queueNode {
    int data;               // Data in queue
    struct queueNode* next; // Pointer to next node
};

// Declare a structure for queue
struct queue {
    struct queueNode *front, *rear; // Front and Rear pointers
};

// Create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    return (q->front == NULL);
}

// Add a node to the queue
void enqueue(struct queue* q, int data) {
    // Create a new node
    struct queueNode* new_node = (struct queueNode*) malloc(sizeof(struct queueNode));
    new_node->data = data;
    new_node->next = NULL;

    // Add the new node to the rear of the queue
    if(q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// Remove a node from the queue
int dequeue(struct queue* q) {
    // Check if queue is empty
    if(isEmpty(q)) {
        return -1;      // Return -1 for empty queue
    }

    // Store the data from the front node
    int data = q->front->data;

    // Remove the front node and update the front pointer
    struct queueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);

    // If the front is null, the queue is now empty
    if(q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Display the contents of the queue
void displayQueue(struct queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    struct queueNode* temp = q->front;

    // Traverse the queue and print each node
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// main function for the c Queue example program
int main() {
    struct queue* q = createQueue();
    int option, data;
    do {
        // Display the menu options
        printf("\n\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("\nEnter your option: ");
        scanf("%d", &option);

        // Perform the selected operation
        switch(option) {
            case 1:
                printf("\nEnter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                printf("Enqueued %d\n", data);
                break;
            case 2:
                data = dequeue(q);
                if(data == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued %d\n", data);
                }
                break;
            case 3:
                printf("Queue Contents: ");
                displayQueue(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option\n");
        }
    } while(option != 4);

    return 0;
}