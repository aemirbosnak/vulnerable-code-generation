//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the airport layout
#define NUM_CHECKIN_COUNTERS 10
#define NUM_SECURITY_LINES 5
#define NUM_BAGGAGE_CLAIM_AREAS 5

// Define the types of events that can occur
#define EVENT_ARRIVAL 0
#define EVENT_CHECKIN 1
#define EVENT_SECURITY 2
#define EVENT_BAGGAGE_CLAIM 3
#define EVENT_DEPARTURE 4

// Define the structure of an event
typedef struct event {
  int type;
  int time;
  int passenger_id;
  int baggage_id;
} event;

// Define the structure of a passenger
typedef struct passenger {
  int id;
  int arrival_time;
  int checkin_time;
  int security_time;
  int baggage_claim_time;
  int departure_time;
} passenger;

// Define the structure of a baggage item
typedef struct baggage {
  int id;
  int passenger_id;
  int checkin_time;
  int security_time;
  int baggage_claim_time;
} baggage;

// Define the global variables
int num_passengers = 0;
int num_baggage_items = 0;
int current_time = 0;
event *event_queue = NULL;
passenger *passengers = NULL;
baggage *baggage_items = NULL;

// Initialize the simulation
void initialize() {
  // Create the event queue
  event_queue = malloc(sizeof(event) * 100);

  // Create the passengers
  passengers = malloc(sizeof(passenger) * 100);

  // Create the baggage items
  baggage_items = malloc(sizeof(baggage) * 100);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the passengers
  for (int i = 0; i < num_passengers; i++) {
    passengers[i].id = i;
    passengers[i].arrival_time = rand() % 100;
  }

  // Generate the baggage items
  for (int i = 0; i < num_baggage_items; i++) {
    baggage_items[i].id = i;
    baggage_items[i].passenger_id = rand() % num_passengers;
    baggage_items[i].checkin_time = rand() % 100;
    baggage_items[i].security_time = rand() % 100;
    baggage_items[i].baggage_claim_time = rand() % 100;
  }

  // Schedule the arrival events
  for (int i = 0; i < num_passengers; i++) {
    event_queue[i].type = EVENT_ARRIVAL;
    event_queue[i].time = passengers[i].arrival_time;
    event_queue[i].passenger_id = i;
  }
}

// Update the simulation
void update() {
  // Get the next event from the event queue
  event next_event = event_queue[0];
  for (int i = 1; i < num_passengers; i++) {
    if (event_queue[i].time < next_event.time) {
      next_event = event_queue[i];
    }
  }

  // Update the current time
  current_time = next_event.time;

  // Process the event
  switch (next_event.type) {
    case EVENT_ARRIVAL:
      // The passenger has arrived at the airport
      passengers[next_event.passenger_id].arrival_time = current_time;

      // Schedule the checkin event
      event_queue[num_passengers].type = EVENT_CHECKIN;
      event_queue[num_passengers].time = current_time + rand() % 100;
      event_queue[num_passengers].passenger_id = next_event.passenger_id;
      num_passengers++;
      break;

    case EVENT_CHECKIN:
      // The passenger has checked in
      passengers[next_event.passenger_id].checkin_time = current_time;

      // Schedule the security event
      event_queue[num_passengers].type = EVENT_SECURITY;
      event_queue[num_passengers].time = current_time + rand() % 100;
      event_queue[num_passengers].passenger_id = next_event.passenger_id;
      num_passengers++;
      break;

    case EVENT_SECURITY:
      // The passenger has passed through security
      passengers[next_event.passenger_id].security_time = current_time;

      // Schedule the baggage claim event
      event_queue[num_passengers].type = EVENT_BAGGAGE_CLAIM;
      event_queue[num_passengers].time = current_time + rand() % 100;
      event_queue[num_passengers].passenger_id = next_event.passenger_id;
      num_passengers++;
      break;

    case EVENT_BAGGAGE_CLAIM:
      // The passenger has claimed their baggage
      passengers[next_event.passenger_id].baggage_claim_time = current_time;

      // Schedule the departure event
      event_queue[num_passengers].type = EVENT_DEPARTURE;
      event_queue[num_passengers].time = current_time + rand() % 100;
      event_queue[num_passengers].passenger_id = next_event.passenger_id;
      num_passengers++;
      break;

    case EVENT_DEPARTURE:
      // The passenger has departed from the airport
      passengers[next_event.passenger_id].departure_time = current_time;

      // Remove the passenger from the event queue
      for (int i = 0; i < num_passengers; i++) {
        if (event_queue[i].passenger_id == next_event.passenger_id) {
          event_queue[i] = event_queue[num_passengers - 1];
          num_passengers--;
          break;
        }
      }
      break;
  }
}

// Run the simulation
void run() {
  initialize();

  while (num_passengers > 0) {
    update();
  }
}

// Print the results of the simulation
void print_results() {
  // Print the average time spent in each stage of the journey
  printf("Average time spent in each stage of the journey:\n");
  printf("  Arrival: %.2f minutes\n", (float)current_time / num_passengers);
  printf("  Checkin: %.2f minutes\n", (float)current_time / num_passengers);
  printf("  Security: %.2f minutes\n", (float)current_time / num_passengers);
  printf("  Baggage claim: %.2f minutes\n", (float)current_time / num_passengers);
  printf("  Departure: %.2f minutes\n", (float)current_time / num_passengers);

  // Print the total time spent in the airport
  printf("Total time spent in the airport: %.2f minutes\n", (float)current_time);
}

int main() {
  run();
  print_results();

  return 0;
}