//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Event {
  char *name;
  int year;
  struct Event *next;
} Event;

Event *addEvent(Event *events, char *name, int year);
void printEvents(Event *events);
void travelToYear(Event *events, int year);
void deleteAllEvents(Event *events);

int main() {
  srand(time(NULL));

  // Create initial events
  Event *events = NULL;
  events = addEvent(events, "Invention of the Wheel", 3500);
  events = addEvent(events, "Battle of Hastings", 1066);
  events = addEvent(events, "First Man on the Moon", 1969);
  events = addEvent(events, "Y2K Bug", 2000);
  events = addEvent(events, "COVID-19 Pandemic", 2020);

  // Print all events
  printEvents(events);

  // Travel to a random year between 1000 BC and 3000 AD and print events
  int year = rand() % 6001 - 3000;
  printf("\n\nTraveling to year %d...\n", year);
  travelToYear(events, year);

  // Delete all events
  deleteAllEvents(events);

  return 0;
}

Event *addEvent(Event *events, char *name, int year) {
  Event *event = malloc(sizeof(Event));
  event->name = name;
  event->year = year;
  event->next = events;
  return event;
}

void printEvents(Event *events) {
  printf("All Events:\n");
  while (events != NULL) {
    printf("- %s (%d)\n", events->name, events->year);
    events = events->next;
  }
  printf("\n");
}

void travelToYear(Event *events, int year) {
  printf("Events in year %d:\n", year);
  while (events != NULL) {
    if (events->year == year) {
      printf("- %s\n", events->name);
    }
    events = events->next;
  }
}

void deleteAllEvents(Event *events) {
  Event *temp;
  while (events != NULL) {
    temp = events;
    events = events->next;
    free(temp);
  }
}