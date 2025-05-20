//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRIVAL_RATE 10  // Arrivals per minute
#define DEPARTURE_RATE 8  // Departures per minute
#define BAGGAGE_LIMIT 100  // Maximum number of bags in the system

// Baggage type enum
enum baggage_type {
  SUITCASE,
  BACKPACK,
  BRIEFCASE,
  OTHER
};

// Baggage struct
typedef struct baggage {
  enum baggage_type type;
  int weight;  // In kilograms
  int destination;  // Airport code
} baggage_t;

// Queue struct
typedef struct queue {
  baggage_t *data;
  int head;
  int tail;
  int size;
} queue_t;

// Initialize a queue
void queue_init(queue_t *queue) {
  queue->data = malloc(sizeof(baggage_t) * BAGGAGE_LIMIT);
  queue->head = 0;
  queue->tail = 0;
  queue->size = 0;
}

// Enqueue a baggage item
void queue_enqueue(queue_t *queue, baggage_t item) {
  if (queue->size == BAGGAGE_LIMIT) {
    printf("Error: Queue is full.\n");
    return;
  }

  queue->data[queue->tail] = item;
  queue->tail = (queue->tail + 1) % BAGGAGE_LIMIT;
  queue->size++;
}

// Dequeue a baggage item
baggage_t queue_dequeue(queue_t *queue) {
  if (queue->size == 0) {
    printf("Error: Queue is empty.\n");
    return (baggage_t){0};
  }

  baggage_t item = queue->data[queue->head];
  queue->head = (queue->head + 1) % BAGGAGE_LIMIT;
  queue->size--;

  return item;
}

// Print the queue
void queue_print(queue_t *queue) {
  for (int i = queue->head; i != queue->tail; i = (i + 1) % BAGGAGE_LIMIT) {
    printf("%d ", queue->data[i].weight);
  }

  printf("\n");
}

// Generate a random baggage item
baggage_t generate_baggage() {
  baggage_t baggage;

  // Generate a random type
  baggage.type = rand() % OTHER;

  // Generate a random weight
  baggage.weight = rand() % 20 + 1;

  // Generate a random destination
  baggage.destination = rand() % 1000 + 1;

  return baggage;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the arrival and departure queues
  queue_t arrival_queue;
  queue_init(&arrival_queue);
  queue_t departure_queue;
  queue_init(&departure_queue);

  // Simulation loop
  for (int i = 0; i < 1000; i++) {
    // Generate new arrivals
    for (int j = 0; j < ARRIVAL_RATE; j++) {
      baggage_t baggage = generate_baggage();
      queue_enqueue(&arrival_queue, baggage);
    }

    // Generate new departures
    for (int j = 0; j < DEPARTURE_RATE; j++) {
      baggage_t baggage = generate_baggage();
      queue_enqueue(&departure_queue, baggage);
    }

    // Process arrivals
    while (arrival_queue.size > 0) {
      baggage_t baggage = queue_dequeue(&arrival_queue);

      // Send the baggage to its destination
      printf("Baggage arrived: ");
      queue_print(&arrival_queue);
      printf("Baggage sent to: %d\n", baggage.destination);
    }

    // Process departures
    while (departure_queue.size > 0) {
      baggage_t baggage = queue_dequeue(&departure_queue);

      // Send the baggage to its destination
      printf("Baggage departed: ");
      queue_print(&departure_queue);
      printf("Baggage sent to: %d\n", baggage.destination);
    }

    // Print the current state of the system
    printf("Current state of the system:\n");
    printf("Arrival queue: ");
    queue_print(&arrival_queue);
    printf("Departure queue: ");
    queue_print(&departure_queue);
  }

  return 0;
}