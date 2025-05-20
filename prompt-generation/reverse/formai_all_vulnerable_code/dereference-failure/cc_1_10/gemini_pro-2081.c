//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
  char *name;
  int day;
  int month;
  int year;
  int hour;
  int minute;
  struct Appointment *next;
} Appointment;

Appointment *head = NULL;

// Function to create a new appointment
Appointment *create_appointment(char *name, int day, int month, int year, int hour, int minute) {
  Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));
  new_appointment->name = strdup(name);
  new_appointment->day = day;
  new_appointment->month = month;
  new_appointment->year = year;
  new_appointment->hour = hour;
  new_appointment->minute = minute;
  new_appointment->next = NULL;
  return new_appointment;
}

// Function to add a new appointment to the list
void add_appointment(Appointment *new_appointment) {
  if (head == NULL) {
    head = new_appointment;
  } else {
    Appointment *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_appointment;
  }
}

// Function to print the list of appointments
void print_appointments() {
  Appointment *current = head;
  while (current != NULL) {
    printf("%s %d/%d/%d %d:%d\n", current->name, current->day, current->month, current->year, current->hour, current->minute);
    current = current->next;
  }
}

// Function to delete an appointment from the list
void delete_appointment(char *name) {
  if (head == NULL) {
    return;
  } else if (strcmp(head->name, name) == 0) {
    head = head->next;
  } else {
    Appointment *current = head;
    while (current->next != NULL) {
      if (strcmp(current->next->name, name) == 0) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }
  }
}

// Function to find an appointment by name
Appointment *find_appointment(char *name) {
  if (head == NULL) {
    return NULL;
  } else {
    Appointment *current = head;
    while (current != NULL) {
      if (strcmp(current->name, name) == 0) {
        return current;
      } else {
        current = current->next;
      }
    }
  }
  return NULL;
}

// Main function
int main() {
  // Create some appointments
  Appointment *appointment1 = create_appointment("John Doe", 1, 1, 2023, 10, 0);
  Appointment *appointment2 = create_appointment("Jane Doe", 2, 1, 2023, 11, 0);
  Appointment *appointment3 = create_appointment("John Smith", 3, 1, 2023, 12, 0);

  // Add the appointments to the list
  add_appointment(appointment1);
  add_appointment(appointment2);
  add_appointment(appointment3);

  // Print the list of appointments
  print_appointments();

  // Delete an appointment
  delete_appointment("Jane Doe");

  // Print the list of appointments again
  printf("\n");
  print_appointments();

  // Find an appointment by name
  Appointment *found_appointment = find_appointment("John Smith");
  if (found_appointment != NULL) {
    printf("\nFound appointment: %s %d/%d/%d %d:%d\n", found_appointment->name, found_appointment->day, found_appointment->month, found_appointment->year, found_appointment->hour, found_appointment->minute);
  } else {
    printf("\nAppointment not found.\n");
  }

  return 0;
}