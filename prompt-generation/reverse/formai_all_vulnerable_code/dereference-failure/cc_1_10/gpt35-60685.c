//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESS_TIME 5     // maximum time a luggage takes for processing
#define MAX_BAGS_PER_ARRIVAL 5 // maximum bags that can arrive at once
#define MAX_QUEUE_SIZE 10      // maximum size of the queue for each conveyor belt

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isQueueEmpty(Queue* q) {
    if (q->front == NULL) {
        return true;
    }
    return false;
}

void enqueue(Queue* q, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

int main() {
    srand(time(0)); // for randomization

    // initialize the queues
    Queue* conveyer_belt1 = createQueue();
    Queue* conveyer_belt2 = createQueue();
    Queue* processing_belt1 = createQueue();
    Queue* processing_belt2 = createQueue();

    // initialize variables
    int clock_time = 0;
    int bags_arrived = 0;
    int bags_processed = 0;

    while (true) {
        // check if any bags have arrived
        int bags_to_add = rand() % (MAX_BAGS_PER_ARRIVAL + 1);
        for (int i = 0; i < bags_to_add; i++) {
            enqueue(conveyer_belt1, bags_arrived);
            bags_arrived++;
        }

        // move bags from conveyer belt 1 to conveyer belt 2
        while (!isQueueEmpty(conveyer_belt1)) {
            int bag = dequeue(conveyer_belt1);
            if (conveyer_belt2->size < MAX_QUEUE_SIZE) {
                enqueue(conveyer_belt2, bag);
            }
            else {
                printf("Error: Conveyer belt 2 is full\n");
            }
        }

        // move bags from conveyer belt 2 to processing belts
        while (!isQueueEmpty(conveyer_belt2)) {
            int bag = dequeue(conveyer_belt2);
            int processing_belt = rand() % 2 + 1; // choose random processing belt
            if (processing_belt == 1) {
                if (processing_belt1->size < MAX_QUEUE_SIZE) {
                    printf("Bag %d is being processed on processing belt 1\n", bag);
                    enqueue(processing_belt1, bag);
                }
                else {
                    printf("Error: Processing belt 1 is full, bag %d is lost\n", bag);
                }
            }
            else {
                if (processing_belt2->size < MAX_QUEUE_SIZE) {
                    printf("Bag %d is being processed on processing belt 2\n", bag);
                    enqueue(processing_belt2, bag);
                }
                else {
                    printf("Error: Processing belt 2 is full, bag %d is lost\n", bag);
                }
            }
        }

        // process bags on processing belt 1
        if (!isQueueEmpty(processing_belt1)) {
            int processing_time = rand() % (MAX_PROCESS_TIME + 1);
            int bag = dequeue(processing_belt1);
            printf("Bag %d is being processed on processing belt 1 for %d seconds\n", bag, processing_time);
            if (processing_time == MAX_PROCESS_TIME) {
                printf("Bag %d is successfully processed on processing belt 1\n", bag);
                bags_processed++;
            }
            else {
                enqueue(processing_belt1, bag);
            }
        }

        // process bags on processing belt 2
        if (!isQueueEmpty(processing_belt2)) {
            int processing_time = rand() % (MAX_PROCESS_TIME + 1);
            int bag = dequeue(processing_belt2);
            printf("Bag %d is being processed on processing belt 2 for %d seconds\n", bag, processing_time);
            if (processing_time == MAX_PROCESS_TIME) {
                printf("Bag %d is successfully processed on processing belt 2\n", bag);
                bags_processed++;
            }
            else {
                enqueue(processing_belt2, bag);
            }
        }

        // check if all bags have been processed
        if (bags_processed == bags_arrived) {
            break;
        }

        clock_time++; // increment clock time
    }

    printf("\nAll bags have been processed in %d seconds\n", clock_time);

    return 0;
}