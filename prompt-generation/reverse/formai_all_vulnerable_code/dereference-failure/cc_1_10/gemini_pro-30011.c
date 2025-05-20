//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
  char *description;
  int start_time;
  int end_time;
} appointment;

typedef struct calendar {
  appointment *appointments;
  int num_appointments;
} calendar;

calendar *create_calendar() {
  calendar *c = malloc(sizeof(calendar));
  c->appointments = NULL;
  c->num_appointments = 0;
  return c;
}

void destroy_calendar(calendar *c) {
  for (int i = 0; i < c->num_appointments; i++) {
    free(c->appointments[i].description);
  }
  free(c->appointments);
  free(c);
}

void add_appointment(calendar *c, char *description, int start_time, int end_time) {
  c->appointments = realloc(c->appointments, (c->num_appointments + 1) * sizeof(appointment));
  c->appointments[c->num_appointments].description = strdup(description);
  c->appointments[c->num_appointments].start_time = start_time;
  c->appointments[c->num_appointments].end_time = end_time;
  c->num_appointments++;
}

void print_calendar(calendar *c) {
  for (int i = 0; i < c->num_appointments; i++) {
    printf("%s (%d-%d)\n", c->appointments[i].description, c->appointments[i].start_time, c->appointments[i].end_time);
  }
}

int main() {
  calendar *c = create_calendar();
  add_appointment(c, "Meeting with Bob", 10, 11);
  add_appointment(c, "Lunch with Alice", 12, 13);
  add_appointment(c, "Interview with Charlie", 14, 15);
  print_calendar(c);
  destroy_calendar(c);
  return 0;
}