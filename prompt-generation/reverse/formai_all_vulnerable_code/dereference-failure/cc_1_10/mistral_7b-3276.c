//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100

// Bag structure
typedef struct {
    int id;
    char* contents;
    struct Bag* next;
} Bag;

// Queue structure
typedef struct {
    int size;
    int capacity;
    Bag** data;
} Queue;

// Initialize queue
Queue* queue_init() {
    Queue* q = (Queue*)calloc(1, sizeof(Queue));
    q->capacity = MAX_BAGS;
    q->size = 0;
    q->data = (Bag**)calloc(q->capacity, sizeof(Bag*));
    return q;
}

// Enqueue bag onto conveyor belt
void queue_enqueue(Queue* q, Bag* bag) {
    q->data[q->size++] = bag;
}

// Dequeue bag from conveyor belt
Bag* queue_dequeue(Queue* q) {
    if (q->size == 0) return NULL;
    Bag* bag = q->data[0];
    memmove(q->data, q->data + 1, sizeof(Bag*) * (--q->size));
    return bag;
}

// Create bag with given id and random contents
Bag* create_bag(int id) {
    Bag* bag = (Bag*)calloc(1, sizeof(Bag));
    bag->id = id;
    bag->contents = (char*)calloc(RAND_MAX + 1, sizeof(char));
    for (int i = 0; i < RAND_MAX; ++i) {
        bag->contents[i] = rand() > RAND_MAX / 2 ? 'B' : 'I';
    }
    bag->next = NULL;
    return bag;
}

// Simulate airport baggage handling system
void simulate(int num_bags) {
    Queue* conveyor_belt = queue_init();
    Bag** bags = (Bag**)calloc(num_bags, sizeof(Bag*));

    srand(time(NULL));

    for (int i = 0; i < num_bags; ++i) {
        bags[i] = create_bag(i);
        printf("Created bag %d with contents: %s\n", bags[i]->id, bags[i]->contents);
        queue_enqueue(conveyor_belt, bags[i]);
    }

    printf("\nProcessing bags on conveyor belt:\n");

    while (conveyor_belt->size > 0) {
        Bag* bag = queue_dequeue(conveyor_belt);
        printf("Processed bag %d with contents: %s\n", bag->id, bag->contents);
        free(bag->contents);
        free(bag);
    }

    free(bags);
    free(conveyor_belt->data);
    free(conveyor_belt);
}

int main() {
    int num_bags = 10;
    simulate(num_bags);
    return 0;
}