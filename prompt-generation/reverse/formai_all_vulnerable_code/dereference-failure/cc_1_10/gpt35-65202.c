//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct baggage_struct {
    int id; // unique id of the baggage
    int flight_number; // flight number of the baggage
    char airport_code[4]; // airport code of the baggage
    int weight; // weight of the baggage in pounds
    int destination_gate; // gate number of the baggage's destination
} baggage;

typedef struct node_struct {
    baggage data;
    struct node_struct* next;
} node;

node* front;
node* rear;

/* function to add a new baggage */
void enqueue(baggage b) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = b;
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

/* function to remove the next baggage in line */
void dequeue() {
    if (front == NULL) {
        printf("No baggage to dequeue.\n");
        return;
    }

    node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

/* function to print all the baggage in the queue */
void print_queue() {
    if (front == NULL) {
        printf("No baggage in queue.\n");
        return;
    }

    node* current = front;

    while (current != NULL) {
        printf("Baggage ID: %d, Flight Number: %d, Airport Code: %s, Weight: %d, Destination Gate: %d\n",
            current->data.id,
            current->data.flight_number,
            current->data.airport_code,
            current->data.weight,
            current->data.destination_gate);

        current = current->next;
    }
}

int main() {
    // seed randomizer
    srand(time(NULL));

    // initialize queue
    front = NULL;
    rear = NULL;

    // generate 10 new baggage and add them to the queue
    for (int i = 1; i <= 10; i++) {
        baggage b;
        b.id = i;
        b.flight_number = rand() % 1000 + 1;
        b.airport_code[0] = rand() % 26 + 'A';
        b.airport_code[1] = rand() % 26 + 'A';
        b.airport_code[2] = rand() % 26 + 'A';
        b.airport_code[3] = '\0';
        b.weight = rand() % 100 + 1;
        b.destination_gate = rand() % 50 + 1;

        enqueue(b);
    }

    // print out initial queue
    printf("Initial baggage queue:\n");
    print_queue();

    // dequeue 3 baggage and print out updated queue
    printf("\nRemoving first 3 baggage from queue...\n");
    dequeue();
    dequeue();
    dequeue();

    printf("\nUpdated baggage queue:\n");
    print_queue();

    return 0;
}