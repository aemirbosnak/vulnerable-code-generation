//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  Date date;
  char *description;
} Event;

Event *generate_event(int year, int month, int day, char *description) {
  Event *event = malloc(sizeof(Event));
  event->date.year = year;
  event->date.month = month;
  event->date.day = day;
  event->description = description;
  return event;
}

void print_event(Event *event) {
  printf("%d-%02d-%02d: %s\n", event->date.year, event->date.month, event->date.day, event->description);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a list of events
  Event *events[] = {
    generate_event(1985, 10, 26, "Born in a hospital"),
    generate_event(1995, 8, 15, "Started school"),
    generate_event(2005, 6, 12, "Graduated from high school"),
    generate_event(2010, 9, 1, "Started university"),
    generate_event(2015, 5, 15, "Graduated from university"),
    generate_event(2020, 3, 13, "Started working"),
    generate_event(2025, 7, 4, "Got married"),
    generate_event(2030, 12, 25, "Had a child"),
    generate_event(2035, 6, 17, "Retired"),
    generate_event(2040, 10, 2, "Died"),
  };

  // Shuffle the list of events
  for (int i = 0; i < 10; i++) {
    int j = rand() % 10;
    Event *temp = events[i];
    events[i] = events[j];
    events[j] = temp;
  }

  // Print the list of events
  for (int i = 0; i < 10; i++) {
    print_event(events[i]);
  }

  return 0;
}