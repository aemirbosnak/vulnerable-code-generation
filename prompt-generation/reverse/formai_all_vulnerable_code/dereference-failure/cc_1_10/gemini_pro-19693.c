//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIMELINES 10
#define MAX_EVENTS 100
#define MAX_CHOICES 10

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  Date date;
  char *description;
  int *choices;
  int num_choices;
} Event;

typedef struct {
  Event *events;
  int num_events;
} Timeline;

Timeline timelines[MAX_TIMELINES];
int num_timelines = 0;

int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Create a new timeline.
  Timeline timeline;
  timelines[num_timelines++] = timeline;

  // Add some events to the timeline.
  Event event;
  event.date.year = 2020;
  event.date.month = 1;
  event.date.day = 1;
  event.description = "You are born.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2024;
  event.date.month = 9;
  event.date.day = 1;
  event.description = "You start school.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2030;
  event.date.month = 6;
  event.date.day = 1;
  event.description = "You graduate from high school.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2034;
  event.date.month = 9;
  event.date.day = 1;
  event.description = "You start college.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2038;
  event.date.month = 5;
  event.date.day = 1;
  event.description = "You graduate from college.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2042;
  event.date.month = 10;
  event.date.day = 1;
  event.description = "You get your first job.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2046;
  event.date.month = 4;
  event.date.day = 1;
  event.description = "You get married.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2050;
  event.date.month = 8;
  event.date.day = 1;
  event.description = "You have your first child.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2054;
  event.date.month = 12;
  event.date.day = 1;
  event.description = "You move to a new house.";
  timeline.events[timeline.num_events++] = event;

  event.date.year = 2058;
  event.date.month = 6;
  event.date.day = 1;
  event.description = "You get a promotion at work.";
  timeline.events[timeline.num_events++] = event;

  // Print the timeline.
  for (int i = 0; i < timeline.num_events; i++) {
    Event event = timeline.events[i];
    printf("%d-%d-%d: %s\n", event.date.year, event.date.month, event.date.day, event.description);
  }

  return 0;
}