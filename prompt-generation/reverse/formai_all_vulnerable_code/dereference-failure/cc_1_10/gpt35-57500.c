//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_WEIGHT 100

typedef struct Bag {
    int id; 
    int weight;
} Bag;

typedef struct Node {
    Bag *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

Bag* create_bag(int id, int weight) {
    Bag *new_bag = (Bag*) malloc(sizeof(Bag));
    new_bag -> id = id;
    new_bag -> weight = weight;
    return new_bag;
}

Queue* create_queue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue -> head = NULL;
    queue -> tail = NULL;
    return queue;
}

void enqueue(Queue *queue, Bag *bag) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = bag;
    new_node -> next = NULL;
    if(queue -> head == NULL && queue -> tail == NULL) {
        queue -> head = new_node;
        queue -> tail = new_node;
        return;
    }
    queue -> tail -> next = new_node;
    queue -> tail = new_node;
}

Bag* dequeue(Queue *queue) {
    if(queue -> head == NULL) {
        return NULL;
    }
    Node *temp = queue -> head;
    Bag *data = temp -> data;
    queue -> head = temp -> next;
    free(temp);
    if(queue -> head == NULL) {
        queue -> tail = NULL;
    }
    return data;
}

int main() {
    srand(time(NULL));
    Queue *queue = create_queue();
    int total_bags = 0;
    while(total_bags < MAX_BAGS) {
        int weight = rand() % MAX_WEIGHT + 1;
        Bag *new_bag = create_bag(total_bags, weight);
        enqueue(queue, new_bag);
        printf("New bag arrived with id %d and weight %d\n", new_bag -> id, new_bag -> weight);
        total_bags++;
    }
    printf("Total Bags queued : %d\n", total_bags);
    int total_weight = 0;
    while(queue -> head != NULL) {
        Bag *bag = dequeue(queue);
        printf("Processing bag with id %d and weight %d\n", bag -> id, bag -> weight);
        total_weight += bag -> weight;
        free(bag);
    }
    printf("Total baggage weight processed : %d\n", total_weight);
    return 0;
}