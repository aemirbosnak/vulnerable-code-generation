//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the appointment struct
typedef struct appointment {
  char *name;
  char *phone_number;
  char *email;
  char *date;
  char *time;
} appointment;

// Define the appointment scheduler struct
typedef struct appointment_scheduler {
  appointment *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_scheduler;

// Create a new appointment
appointment *new_appointment(char *name, char *phone_number, char *email, char *date, char *time) {
  appointment *appt = malloc(sizeof(appointment));
  appt->name = strdup(name);
  appt->phone_number = strdup(phone_number);
  appt->email = strdup(email);
  appt->date = strdup(date);
  appt->time = strdup(time);
  return appt;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *appt) {
  scheduler->appointments[scheduler->num_appointments++] = appt;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("Appointment %d:\n", i + 1);
    printf("  Name: %s\n", scheduler->appointments[i]->name);
    printf("  Phone number: %s\n", scheduler->appointments[i]->phone_number);
    printf("  Email: %s\n", scheduler->appointments[i]->email);
    printf("  Date: %s\n", scheduler->appointments[i]->date);
    printf("  Time: %s\n", scheduler->appointments[i]->time);
  }
}

// Free the memory allocated for an appointment
void free_appointment(appointment *appt) {
  free(appt->name);
  free(appt->phone_number);
  free(appt->email);
  free(appt->date);
  free(appt->time);
  free(appt);
}

// Free the memory allocated for the appointment scheduler
void free_appointment_scheduler(appointment_scheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free_appointment(scheduler->appointments[i]);
  }
  free(scheduler);
}

// Main function
int main() {
  // Create a new appointment scheduler
  appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
  scheduler->num_appointments = 0;

  // Add some appointments to the scheduler
  add_appointment(scheduler, new_appointment("John Doe", "123-456-7890", "john.doe@example.com", "2023-03-08", "10:00 AM"));
  add_appointment(scheduler, new_appointment("Jane Doe", "123-456-7891", "jane.doe@example.com", "2023-03-09", "11:00 AM"));
  add_appointment(scheduler, new_appointment("John Smith", "123-456-7892", "john.smith@example.com", "2023-03-10", "12:00 PM"));

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Free the memory allocated for the appointment scheduler
  free_appointment_scheduler(scheduler);

  return 0;
}