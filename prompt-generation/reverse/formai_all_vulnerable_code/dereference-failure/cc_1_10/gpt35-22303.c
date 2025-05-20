//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE 100
#define MIN_WEIGHT 1
#define MAX_WEIGHT 50

typedef struct BaggageTag {
    int id;
    int weight;
} BaggageTag;

typedef struct Node {
    BaggageTag* baggage;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

BaggageTag* createBaggageTag() {
    BaggageTag* baggage = (BaggageTag*) malloc(sizeof(BaggageTag));
    baggage->id = rand() % 1000;
    baggage->weight = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT;
    return baggage;
}

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q) {
    BaggageTag* baggage = createBaggageTag();
    Node* node = (Node*) malloc(sizeof(Node));
    node->baggage = baggage;
    node->next = NULL;
    if (q->size == 0) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

void dequeue(Queue* q) {
    if (q->size == 0) {
        printf("No baggage to dequeue\n");
        return;
    }
    Node* node = q->front;
    q->front = q->front->next;
    if (q->size == 1) {
        q->rear = NULL;
    }
    printf("Dequeued baggage tag: %d, Weight: %d\n", node->baggage->id, node->baggage->weight);
    free(node->baggage);
    free(node);
    q->size--;
}

void display(Queue* q) {
    if (q->size == 0) {
        printf("No baggage to display\n");
        return;
    }
    Node* node = q->front;
    while (node != NULL) {
        printf("Baggage tag: %d, Weight: %d\n", node->baggage->id, node->baggage->weight);
        node = node->next;
    }
}

int main() {
    srand(time(0));
    Queue* q = createQueue();
    int choice;
    do {
        printf("\n--Airport Baggage Handling Simulation--\n");
        printf("1. Enqueue baggage\n");
        printf("2. Dequeue baggage\n");
        printf("3. Display all baggage\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}