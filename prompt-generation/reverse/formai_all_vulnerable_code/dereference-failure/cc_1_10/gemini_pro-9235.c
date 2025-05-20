//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Passenger's baggage details
typedef struct Baggage {
    int id;         // Unique ID
    char type;       // Type (eg. 'C' for checked-in, 'H' for hand baggage)
    int weight;     // Weight in kilograms
    int flight_no;  // Flight number
    int priority;   // Priority level (1-5)
} Baggage;

// Queue for baggage handling
typedef struct Queue {
    Baggage *items[100];  // Array to store baggage
    int front, rear;      // Indices of front and rear of queue
} Queue;

// Initialize the queue
void init_queue(Queue *q) {
    q->front = q->rear = -1;
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->front == -1;
}

// Enqueue a baggage
void enqueue(Queue *q, Baggage *bag) {
    if (q->rear == 99) {  // Queue is full
        printf("Sorry, but the baggage handling system is currently at capacity. Please try again later.\n");
        return;
    }
    if (q->front == -1) {  // Queue is empty
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = bag;
}

// Dequeue a baggage
Baggage *dequeue(Queue *q) {
    if (is_empty(q)) {  // Queue is empty
        printf("There are no bags to handle at the moment. Please wait until a flight arrives.\n");
        return NULL;
    }
    Baggage *bag = q->items[q->front];
    if (q->front == q->rear) {  // Queue contains only one baggage
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return bag;
}

// Print the queue
void print_queue(Queue *q) {
    if (is_empty(q)) {  // Queue is empty
        printf("There are no bags in the queue currently.\n");
    } else {
        printf("Baggage Handling Queue:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("Baggage ID: %d, Type: %c, Weight: %d kg, Flight No: %d, Priority: %d\n",
                   q->items[i]->id, q->items[i]->type, q->items[i]->weight, q->items[i]->flight_no, q->items[i]->priority);
        }
    }
}

// Handle baggage loading
void load_baggage(Queue *q, int flight_no) {
    printf("Now loading baggage for Flight %d:\n", flight_no);
    while (!is_empty(q)) {
        Baggage *bag = dequeue(q);
        if (bag->flight_no == flight_no) {
            printf("Loading baggage ID: %d, Type: %c, Weight: %d kg\n", bag->id, bag->type, bag->weight);
        } else {
            enqueue(q, bag);  // Put the baggage back in the queue if it's not for this flight
        }
    }
    printf("All baggage for Flight %d has been loaded.\n\n", flight_no);
}

// Generate random baggage
Baggage *generate_random_baggage() {
    Baggage *bag = malloc(sizeof(Baggage));
    bag->id = rand() % 1000 + 1;  // Random ID between 1 and 1000
    bag->type = rand() % 2 == 0 ? 'C' : 'H';  // Random type (checked-in or hand baggage)
    bag->weight = rand() % 30 + 1;  // Random weight between 1 and 30 kg
    bag->flight_no = rand() % 10 + 1;  // Random flight number between 1 and 10
    bag->priority = rand() % 5 + 1;  // Random priority level between 1 and 5
    return bag;
}

// Main function
int main() {
    srand(time(NULL));  // Initialize random seed
    Queue baggage_queue;
    init_queue(&baggage_queue);

    // Generate some random baggage
    for (int i = 0; i < 20; i++) {
        Baggage *bag = generate_random_baggage();
        enqueue(&baggage_queue, bag);
    }

    // Print the initial queue
    printf("Initial Baggage Handling Queue:\n");
    print_queue(&baggage_queue);

    // Load baggage for flight 3
    load_baggage(&baggage_queue, 3);

    // Print the queue after loading
    printf("Baggage Handling Queue after loading for Flight 3:\n");
    print_queue(&baggage_queue);

    // Load baggage for flight 7
    load_baggage(&baggage_queue, 7);

    // Print the queue after loading
    printf("Baggage Handling Queue after loading for Flight 7:\n");
    print_queue(&baggage_queue);

    return 0;
}