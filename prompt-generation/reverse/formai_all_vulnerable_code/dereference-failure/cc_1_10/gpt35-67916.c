//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50

typedef struct {
    int flight_num;
    int bag_cnt;
    int* bag_weights;
} Flight;

typedef struct {
    int id;
    int weight;
} Baggage;

typedef struct Node {
    Baggage data;
    struct Node* next;
} Node;

typedef struct {
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

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enQueue(Queue* q, Baggage data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}

Baggage deQueue(Queue* q) {
    if (isEmpty(q)) {
        Baggage bag;
        bag.id = -1;
        bag.weight = -1;
        return bag;
    }
    Node* temp = q->front;
    Baggage data = temp->data;
    q->front = temp->next;
    q->size--;
    free(temp);
    return data;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data.weight);
        temp = temp->next;
    }
    printf("\n");
}

void simulateBags(Flight flight) {
    Queue* queue = createQueue();
    int total_weight = 0;
    printf("Flight %d has %d bags:\n", flight.flight_num, flight.bag_cnt);
    for (int i = 0; i < flight.bag_cnt; i++) {
        Baggage b;
        b.id = i+1;
        b.weight = flight.bag_weights[i];
        total_weight += b.weight;
        enQueue(queue, b);
    }
    printf("Total bag weight: %d kg\n", total_weight);
    printf("Bags being loaded onto the plane:\n");
    while (!isEmpty(queue)) {
        Baggage b = deQueue(queue);
        printf(" Bag %d - %d kg\n", b.id, b.weight);
    }
}

int main() {
    Flight f1, f2, f3;
    f1.flight_num = 101;
    f1.bag_cnt = 5;
    f1.bag_weights = (int*) malloc(f1.bag_cnt * sizeof(int));
    for (int i = 0; i < f1.bag_cnt; i++) {
        f1.bag_weights[i] = rand() % MAX_WEIGHT;
    }

    f2.flight_num = 102;
    f2.bag_cnt = 3;
    f2.bag_weights = (int*) malloc(f2.bag_cnt * sizeof(int));
    for (int i = 0; i < f2.bag_cnt; i++) {
        f2.bag_weights[i] = rand() % MAX_WEIGHT;
    }

    f3.flight_num = 103;
    f3.bag_cnt = 7;
    f3.bag_weights = (int*) malloc(f3.bag_cnt * sizeof(int));
    for (int i = 0; i < f3.bag_cnt; i++) {
        f3.bag_weights[i] = rand() % MAX_WEIGHT;
    }

    simulateBags(f1);
    simulateBags(f2);
    simulateBags(f3);

    free(f1.bag_weights);
    free(f2.bag_weights);
    free(f3.bag_weights);

    return 0;
}