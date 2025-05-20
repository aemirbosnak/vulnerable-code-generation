//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
  char *name;
  char *description;
  int day;
  int month;
  int year;
  int hour;
  int minute;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_appointment(appointment *appt) {
  printf("%s: %s, %d/%d/%d, %d:%d\n", appt->name, appt->description, appt->day, appt->month, appt->year, appt->hour, appt->minute);
}

void print_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    print_appointment(&appointments[i]);
  }
}

void add_appointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
  if (num_appointments >= MAX_APPOINTMENTS) {
    printf("Error: too many appointments\n");
    return;
  }

  appointment *appt = &appointments[num_appointments++];
  appt->name = strdup(name);
  appt->description = strdup(description);
  appt->day = day;
  appt->month = month;
  appt->year = year;
  appt->hour = hour;
  appt->minute = minute;
}

int main() {
  add_appointment("John Doe", "Meeting", 1, 1, 2023, 10, 0);
  add_appointment("Jane Smith", "Lunch", 2, 1, 2023, 12, 0);
  add_appointment("Bob Jones", "Dinner", 3, 1, 2023, 18, 0);

  print_appointments();

  return 0;
}