//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
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
} appointment_t;

appointment_t *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("Error: Too many appointments!\n");
    return;
  }

  appointments[num_appointments] = malloc(sizeof(appointment_t));
  appointments[num_appointments]->name = strdup(name);
  appointments[num_appointments]->description = strdup(description);
  appointments[num_appointments]->day = day;
  appointments[num_appointments]->month = month;
  appointments[num_appointments]->year = year;
  appointments[num_appointments]->hour = hour;
  appointments[num_appointments]->minute = minute;
  num_appointments++;
}

void print_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    printf("%s: %s (%d/%d/%d %d:%d)\n",
           appointments[i]->name,
           appointments[i]->description,
           appointments[i]->day,
           appointments[i]->month,
           appointments[i]->year,
           appointments[i]->hour,
           appointments[i]->minute);
  }
}

void free_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    free(appointments[i]->name);
    free(appointments[i]->description);
    free(appointments[i]);
  }
}

int main() {
  // Add some sample appointments
  add_appointment("John Smith", "Meeting with the boss", 15, 3, 2023, 10, 0);
  add_appointment("Jane Doe", "Doctor's appointment", 22, 3, 2023, 14, 30);
  add_appointment("Bill Jones", "Vacation", 1, 4, 2023, 0, 0);

  // Print the appointments
  print_appointments();

  // Free the appointments
  free_appointments();

  return 0;
}