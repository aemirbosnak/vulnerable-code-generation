//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
// C program for simulating airport baggage handling system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct baggage {
  char *destination;
  int weight;
  int priority;
};

struct node {
  struct baggage *bag;
  struct node *next;
};

struct queue {
  struct node *front;
  struct node *rear;
};

struct queue *createQueue() {
  struct queue *q = (struct queue*) malloc(sizeof(struct queue));
  q->front = q->rear = NULL;
  return q;
}

void enqueue(struct queue *q, struct baggage *bag) {
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->bag = bag;
  newNode->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = newNode;
    return;
  }
  q->rear->next = newNode;
  q->rear = newNode;
}

struct baggage *dequeue(struct queue *q) {
  if (q->front == NULL) return NULL;
  struct node *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL) q->rear = NULL;
  struct baggage *bag = temp->bag;
  free(temp);
  return bag;
}

void printBag(struct baggage *bag) {
  printf("Destination: %s, Weight: %d, Priority: %d\n", bag->destination, bag->weight, bag->priority);
}

int main() {
  srand(time(NULL));
  struct queue *domesticQueue = createQueue();
  struct queue *internationalQueue = createQueue();

  // Generate 10 random bags for domestic queue
  for (int i=0; i<10; i++) {
    struct baggage *bag = (struct baggage*) malloc(sizeof(struct baggage));
    char *destination = (char*) malloc(sizeof(char) * 3);
    strcpy(destination, "D");
    bag->destination = destination;
    bag->weight = rand() % 50 + 1;
    bag->priority = rand() % 3 + 1;
    enqueue(domesticQueue, bag);
  }

  // Generate 10 random bags for international queue
  for (int i=0; i<10; i++) {
    struct baggage *bag = (struct baggage*) malloc(sizeof(struct baggage));
    char *destination = (char*) malloc(sizeof(char) * 3);
    strcpy(destination, "I");
    bag->destination = destination;
    bag->weight = rand() % 50 + 1;
    bag->priority = rand() % 3 + 1;
    enqueue(internationalQueue, bag);
  }

  // Print the contents of both queues
  printf("Contents of domestic queue:\n");
  struct node *temp = domesticQueue->front;
  while(temp != NULL) {
    printBag(temp->bag);
    temp = temp->next;
  }

  printf("Contents of international queue:\n");
  temp = internationalQueue->front;
  while(temp != NULL) {
    printBag(temp->bag);
    temp = temp->next;
  }

  // Process bags in domestic queue
  while(domesticQueue->front != NULL) {
    struct baggage *bag = dequeue(domesticQueue);
    printf("Processing bag for domestic flight to %s with weight %d and priority %d\n", bag->destination, bag->weight, bag->priority);
    free(bag);
  }

  // Process bags in international queue
  while(internationalQueue->front != NULL) {
    struct baggage *bag = dequeue(internationalQueue);
    printf("Processing bag for international flight to %s with weight %d and priority %d\n", bag->destination, bag->weight, bag->priority);
    free(bag);
  }
  return 0;
}