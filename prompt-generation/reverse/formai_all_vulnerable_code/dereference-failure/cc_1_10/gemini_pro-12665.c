//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
typedef struct appointment {
  char *name;
  char *date;
  char *time;
  char *location;
  struct appointment *next;
} appointment;

// Function to create a new appointment
appointment *create_appointment(char *name, char *date, char *time, char *location) {
  appointment *new_appointment = (appointment *)malloc(sizeof(appointment));
  new_appointment->name = strdup(name);
  new_appointment->date = strdup(date);
  new_appointment->time = strdup(time);
  new_appointment->location = strdup(location);
  new_appointment->next = NULL;
  return new_appointment;
}

// Function to add an appointment to the schedule
void add_appointment(appointment **schedule, appointment *new_appointment) {
  if (*schedule == NULL) {
    *schedule = new_appointment;
    return;
  }

  appointment *current = *schedule;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_appointment;
}

// Function to remove an appointment from the schedule
void remove_appointment(appointment **schedule, char *name) {
  if (*schedule == NULL) {
    return;
  }

  appointment *current = *schedule;
  appointment *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      if (previous == NULL) {
        *schedule = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }
}

// Function to print the schedule
void print_schedule(appointment *schedule) {
  if (schedule == NULL) {
    printf("Your schedule is empty.\n");
    return;
  }

  appointment *current = schedule;

  printf("Your upcoming appointments:\n");
  while (current != NULL) {
    printf("%s - %s - %s - %s\n", current->name, current->date, current->time, current->location);
    current = current->next;
  }
}

// Main function
int main() {
  appointment *schedule = NULL;

  // Create some appointments
  appointment *appointment1 = create_appointment("John Doe", "2023-03-08", "10:00 AM", "Office");
  appointment *appointment2 = create_appointment("Jane Smith", "2023-03-15", "2:00 PM", "Coffee Shop");
  appointment *appointment3 = create_appointment("Bill Jones", "2023-03-22", "4:00 PM", "Home");

  // Add the appointments to the schedule
  add_appointment(&schedule, appointment1);
  add_appointment(&schedule, appointment2);
  add_appointment(&schedule, appointment3);

  // Print the schedule
  print_schedule(schedule);

  // Remove an appointment from the schedule
  remove_appointment(&schedule, "Jane Smith");

  // Print the schedule again
  print_schedule(schedule);

  // Free the memory allocated for the appointments
  free(appointment1);
  free(appointment2);
  free(appointment3);

  return 0;
}