//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
// Appointment Scheduler in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
typedef struct Appointment {
  char *name;          // Name of the person
  char *description;    // Description of the appointment
  int start_time;      // Start time in HHMM format (e.g., 1330 for 1:30 PM)
  int end_time;        // End time in HHMM format (e.g., 1500 for 3:00 PM)
  struct Appointment *next;  // Pointer to the next appointment in the linked list
} Appointment;

// Function to create a new appointment
Appointment *create_appointment(char *name, char *description, int start_time, int end_time) {
  Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));
  new_appointment->name = (char *)malloc(strlen(name) + 1);
  strcpy(new_appointment->name, name);
  new_appointment->description = (char *)malloc(strlen(description) + 1);
  strcpy(new_appointment->description, description);
  new_appointment->start_time = start_time;
  new_appointment->end_time = end_time;
  new_appointment->next = NULL;
  return new_appointment;
}

// Function to add an appointment to the linked list
void add_appointment(Appointment **head, Appointment *new_appointment) {
  if (*head == NULL) {
    *head = new_appointment;
  } else {
    Appointment *current_appointment = *head;
    while (current_appointment->next != NULL) {
      current_appointment = current_appointment->next;
    }
    current_appointment->next = new_appointment;
  }
}

// Function to print the appointments in the linked list
void print_appointments(Appointment *head) {
  Appointment *current_appointment = head;
  while (current_appointment != NULL) {
    printf("Name: %s\n", current_appointment->name);
    printf("Description: %s\n", current_appointment->description);
    printf("Start Time: %d\n", current_appointment->start_time);
    printf("End Time: %d\n\n", current_appointment->end_time);
    current_appointment = current_appointment->next;
  }
}

// Function to free the memory allocated for the appointments
void free_appointments(Appointment *head) {
  Appointment *current_appointment = head;
  while (current_appointment != NULL) {
    Appointment *next_appointment = current_appointment->next;
    free(current_appointment->name);
    free(current_appointment->description);
    free(current_appointment);
    current_appointment = next_appointment;
  }
}

// Main function
int main() {
  // Create a linked list of appointments
  Appointment *head = NULL;
  add_appointment(&head, create_appointment("John Doe", "Meeting with client", 1330, 1500));
  add_appointment(&head, create_appointment("Jane Smith", "Phone call with vendor", 1600, 1700));
  add_appointment(&head, create_appointment("Bill Jones", "Presentation to team", 1000, 1200));

  // Print the appointments
  printf("Appointments:\n");
  print_appointments(head);

  // Free the memory allocated for the appointments
  free_appointments(head);

  return 0;
}