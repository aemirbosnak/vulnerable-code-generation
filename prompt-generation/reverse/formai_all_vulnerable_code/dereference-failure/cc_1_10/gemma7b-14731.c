//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the appointment structure
typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  struct Appointment* next;
} Appointment;

// Define the appointment scheduler function
void schedule_appointment(Appointment* head) {
  // Get the appointment information from the user
  char name[50];
  char date[20];
  char time[20];

  // Allocate memory for the new appointment
  Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));

  // Fill the new appointment information
  strcpy(new_appointment->name, name);
  strcpy(new_appointment->date, date);
  strcpy(new_appointment->time, time);

  // Insert the new appointment into the linked list
  new_appointment->next = head;
  head = new_appointment;
}

// Define the list of appointments function
void list_appointments(Appointment* head) {
  // Traverse the linked list of appointments
  while (head) {
    // Print the appointment information
    printf("%s, %s, %s\n", head->name, head->date, head->time);
    head = head->next;
  }
}

int main() {
  // Create a new head of the linked list
  Appointment* head = NULL;

  // Schedule an appointment
  schedule_appointment(head);

  // List all appointments
  list_appointments(head);

  return 0;
}