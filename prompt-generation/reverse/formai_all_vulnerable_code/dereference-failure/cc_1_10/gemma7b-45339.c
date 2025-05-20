//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10

typedef struct TimeTravelEvent {
  char name[50];
  time_t timestamp;
  struct TimeTravelEvent* next;
} TimeTravelEvent;

TimeTravelEvent* head = NULL;

void addEvent(char* name, time_t timestamp) {
  TimeTravelEvent* newEvent = malloc(sizeof(TimeTravelEvent));
  strcpy(newEvent->name, name);
  newEvent->timestamp = timestamp;
  newEvent->next = NULL;

  if (head == NULL) {
    head = newEvent;
  } else {
    TimeTravelEvent* currentEvent = head;
    while (currentEvent->next) {
      currentEvent = currentEvent->next;
    }
    currentEvent->next = newEvent;
  }
}

void travelTo(time_t timestamp) {
  TimeTravelEvent* currentEvent = head;
  while (currentEvent) {
    if (currentEvent->timestamp == timestamp) {
      printf("%s occurred at %s", currentEvent->name, currentEvent->timestamp);
      break;
    } else if (currentEvent->timestamp > timestamp) {
      break;
    }
    currentEvent = currentEvent->next;
  }

  if (currentEvent == NULL) {
    printf("No event occurred at that timestamp");
  }
}

int main() {
  addEvent("Birthday Party", 1612224000);
  addEvent("Wedding Reception", 1612252000);
  addEvent("Family Picnic", 1612260000);

  travelTo(1612224000);
  travelTo(1612252000);
  travelTo(1612260000);

  return 0;
}