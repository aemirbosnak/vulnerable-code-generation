//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 500
#define MAX_WEIGHT 50

typedef struct Baggage {
    int id;
    int weight;
    int conveyor;
} Baggage;

typedef struct Node {
    Baggage* baggage;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void initialize_queue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int is_queue_empty(Queue* queue) {
    if (queue->head == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(Queue* queue, Baggage* baggage) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->baggage = baggage;
    new_node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
        return;
    }

    queue->tail->next = new_node;
    queue->tail = new_node;
}

Baggage* dequeue(Queue* queue) {
    if (is_queue_empty(queue)) {
        return NULL;
    }

    Node* dequeued = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    Baggage* baggage = dequeued->baggage;
    free(dequeued);
    return baggage;
}

int main() {
    srand(time(NULL));

    Queue conveyor_belts[3];
    for (int i = 0; i < 3; i++) {
        initialize_queue(&conveyor_belts[i]);
    }

    Baggage baggage_list[MAX_BAGS];

    for (int i = 0; i < MAX_BAGS; i++) {
        baggage_list[i].id = i;
        baggage_list[i].weight = rand() % MAX_WEIGHT + 1;
        baggage_list[i].conveyor = rand() % 3;
        enqueue(&conveyor_belts[baggage_list[i].conveyor], &baggage_list[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("Bags on Conveyor Belt %d:\n", i);
        while (!is_queue_empty(&conveyor_belts[i])) {
            Baggage* baggage = dequeue(&conveyor_belts[i]);
            printf("Bag ID: %d\tWeight: %d\n", baggage->id, baggage->weight);
        }
    }

    return 0;
}