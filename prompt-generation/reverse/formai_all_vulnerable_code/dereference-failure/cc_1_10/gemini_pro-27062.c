//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Appointment {
  char *name;
  char *description;
  int day;
  int month;
  int year;
  int hour;
  int minute;
} Appointment;

Appointment *create_appointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
  Appointment *appointment = malloc(sizeof(Appointment));
  appointment->name = strdup(name);
  appointment->description = strdup(description);
  appointment->day = day;
  appointment->month = month;
  appointment->year = year;
  appointment->hour = hour;
  appointment->minute = minute;
  return appointment;
}

void print_appointment(Appointment *appointment) {
  printf("Appointment: %s\n", appointment->name);
  printf("Description: %s\n", appointment->description);
  printf("Date: %d/%d/%d\n", appointment->day, appointment->month, appointment->year);
  printf("Time: %d:%d\n", appointment->hour, appointment->minute);
  printf("\n");
}

int main() {
  Appointment *appointments[] = {
    create_appointment("Squire's Tournament", "Heralds will announce the commencement of the tournament at the castle gates.", 10, 6, 1453, 9, 0),
    create_appointment("Lady's Soiree", "The Lady of the Manor invites you to a grand soiree at her estate.", 15, 7, 1453, 19, 0),
    create_appointment("King's Feast", "The King and Queen will be hosting a feast in the Great Hall.", 20, 8, 1453, 18, 0),
    create_appointment("Bard's Concert", "A renowned bard will be performing in the village square.", 25, 9, 1453, 14, 0),
    create_appointment("Jester's Show", "A jester will be performing at the market.", 1, 10, 1453, 10, 0),
  };

  int num_appointments = sizeof(appointments) / sizeof(appointments[0]);

  for (int i = 0; i < num_appointments; i++) {
    print_appointment(appointments[i]);
  }

  return 0;
}