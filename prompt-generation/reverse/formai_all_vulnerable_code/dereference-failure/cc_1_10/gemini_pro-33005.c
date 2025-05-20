//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of time travelers
#define MAX_TRAVELERS 10

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the structure of a time traveler
typedef struct {
  int id;
  char name[32];
  time_t birthdate;
  time_t deathdate;
} time_traveler;

// Define the structure of a time travel event
typedef struct {
  int id;
  time_t timestamp;
  int traveler_id;
  char description[256];
} time_travel_event;

// Define the global array of time travelers
time_traveler travelers[MAX_TRAVELERS];

// Define the global array of time travel events
time_travel_event events[MAX_EVENTS];

// Define the global variable to track the current time
time_t current_time;

// Function to create a new time traveler
time_traveler* create_time_traveler(int id, char* name, time_t birthdate, time_t deathdate) {
  // Allocate memory for the new time traveler
  time_traveler* traveler = malloc(sizeof(time_traveler));

  // Set the properties of the new time traveler
  traveler->id = id;
  strcpy(traveler->name, name);
  traveler->birthdate = birthdate;
  traveler->deathdate = deathdate;

  // Return the new time traveler
  return traveler;
}

// Function to create a new time travel event
time_travel_event* create_time_travel_event(int id, time_t timestamp, int traveler_id, char* description) {
  // Allocate memory for the new time travel event
  time_travel_event* event = malloc(sizeof(time_travel_event));

  // Set the properties of the new time travel event
  event->id = id;
  event->timestamp = timestamp;
  event->traveler_id = traveler_id;
  strcpy(event->description, description);

  // Return the new time travel event
  return event;
}

// Function to initialize the time travel simulator
void initialize_time_travel_simulator() {
  // Create the time travelers
  travelers[0] = *create_time_traveler(1, "John Doe", time(NULL) - 30 * 365 * 24 * 60 * 60, time(NULL) - 10 * 365 * 24 * 60 * 60);
  travelers[1] = *create_time_traveler(2, "Jane Doe", time(NULL) - 25 * 365 * 24 * 60 * 60, time(NULL) - 5 * 365 * 24 * 60 * 60);
  travelers[2] = *create_time_traveler(3, "John Smith", time(NULL) - 20 * 365 * 24 * 60 * 60, time(NULL));

  // Create the time travel events
  events[0] = *create_time_travel_event(1, time(NULL) - 15 * 365 * 24 * 60 * 60, 1, "John Doe traveled back to 1985");
  events[1] = *create_time_travel_event(2, time(NULL) - 10 * 365 * 24 * 60 * 60, 2, "Jane Doe traveled forward to 2025");
  events[2] = *create_time_travel_event(3, time(NULL) - 5 * 365 * 24 * 60 * 60, 3, "John Smith traveled back to 2000");

  // Set the current time
  current_time = time(NULL);
}

// Function to simulate a time travel event
void simulate_time_travel_event(int event_id) {
  // Get the event
  time_travel_event* event = &events[event_id];

  // Get the traveler
  time_traveler* traveler = &travelers[event->traveler_id - 1];

  // Update the current time
  current_time = event->timestamp;

  // Print the event description
  printf("%s traveled to %s\n", traveler->name, ctime(&event->timestamp));
}

// Function to print the current time
void print_current_time() {
  printf("Current time: %s\n", ctime(&current_time));
}

// Function to print the list of time travelers
void print_time_travelers() {
  printf("Time travelers:\n");
  for (int i = 0; i < MAX_TRAVELERS; i++) {
    time_traveler traveler = travelers[i];
    if (traveler.id != 0) {
      printf("%d: %s (%s - %s)\n", traveler.id, traveler.name, ctime(&traveler.birthdate), ctime(&traveler.deathdate));
    }
  }
}

// Function to print the list of time travel events
void print_time_travel_events() {
  printf("Time travel events:\n");
  for (int i = 0; i < MAX_EVENTS; i++) {
    time_travel_event event = events[i];
    if (event.id != 0) {
      printf("%d: %s (%s) - %s\n", event.id, event.description, ctime(&event.timestamp), travelers[event.traveler_id - 1].name);
    }
  }
}

// Main function
int main() {
  // Initialize the time travel simulator
  initialize_time_travel_simulator();

  // Print the initial state of the time travel simulator
  print_current_time();
  print_time_travelers();
  print_time_travel_events();

  // Simulate a time travel event
  simulate_time_travel_event(0);

  // Print the final state of the time travel simulator
  print_current_time();
  print_time_travelers();
  print_time_travel_events();

  return 0;
}