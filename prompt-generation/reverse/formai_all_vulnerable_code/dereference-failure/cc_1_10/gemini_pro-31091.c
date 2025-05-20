//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Appointment struct
typedef struct appointment {
  char *name;
  char *reason;
  int year;
  int month;
  int day;
  int hour;
  int minute;
} appointment;

// Appointment list struct
typedef struct appointment_list {
  appointment *appoint;
  struct appointment_list *next;
} appointment_list;

// Create a new appointment
appointment *create_appointment(char *name, char *reason, int year, int month, int day, int hour, int minute) {
  appointment *new_appoint = malloc(sizeof(appointment));
  new_appoint->name = name;
  new_appoint->reason = reason;
  new_appoint->year = year;
  new_appoint->month = month;
  new_appoint->day = day;
  new_appoint->hour = hour;
  new_appoint->minute = minute;
  return new_appoint;
}

// Add an appointment to the list
void add_appointment(appointment_list **head, appointment *new_appoint) {
  appointment_list *new_node = malloc(sizeof(appointment_list));
  new_node->appoint = new_appoint;
  new_node->next = *head;
  *head = new_node;
}

// Print the appointment list
void print_appointments(appointment_list *head) {
  while (head != NULL) {
    printf("%s: %s\n", head->appoint->name, head->appoint->reason);
    head = head->next;
  }
}

// Free the appointment list
void free_appointments(appointment_list *head) {
  while (head != NULL) {
    appointment_list *next = head->next;
    free(head->appoint);
    free(head);
    head = next;
  }
}

// Main function
int main() {
  // Create a new appointment list
  appointment_list *head = NULL;

  // Add some appointments to the list
  add_appointment(&head, create_appointment("John Smith", "Doctor's appointment", 2023, 3, 15, 10, 30));
  add_appointment(&head, create_appointment("Jane Doe", "Dentist appointment", 2023, 4, 1, 14, 0));
  add_appointment(&head, create_appointment("Bill Jones", "Haircut", 2023, 5, 10, 12, 0));

  // Print the appointment list
  printf("Appointments:\n");
  print_appointments(head);

  // Free the appointment list
  free_appointments(head);

  return 0;
}