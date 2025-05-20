//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
  char *name;
  char *description;
  int day;
  int month;
  int year;
  int hour;
  int minute;
} appointment;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
  appointment *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler *create_appointment_scheduler() {
  appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
  scheduler->num_appointments = 0;
  return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *appointment) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    printf("Error: Appointment scheduler is full.\n");
    return;
  }
  scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler *scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    printf("Error: Invalid appointment index.\n");
    return;
  }
  free(scheduler->appointments[index]);
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    appointment *appointment = scheduler->appointments[i];
    printf("Appointment %d:\n", i + 1);
    printf("  Name: %s\n", appointment->name);
    printf("  Description: %s\n", appointment->description);
    printf("  Date: %d/%d/%d\n", appointment->day, appointment->month, appointment->year);
    printf("  Time: %d:%d\n", appointment->hour, appointment->minute);
  }
}

// Free the memory allocated for the appointment scheduler
void free_appointment_scheduler(appointment_scheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]);
  }
  free(scheduler);
}

// Main function
int main() {
  // Create a new appointment scheduler
  appointment_scheduler *scheduler = create_appointment_scheduler();

  // Add some appointments to the scheduler
  appointment *appointment1 = malloc(sizeof(appointment));
  appointment1->name = "Doctor's appointment";
  appointment1->description = "Annual checkup";
  appointment1->day = 15;
  appointment1->month = 3;
  appointment1->year = 2023;
  appointment1->hour = 10;
  appointment1->minute = 30;
  add_appointment(scheduler, appointment1);

  appointment *appointment2 = malloc(sizeof(appointment));
  appointment2->name = "Job interview";
  appointment2->description = "Interview for a software engineer position";
  appointment2->day = 22;
  appointment2->month = 3;
  appointment2->year = 2023;
  appointment2->hour = 14;
  appointment2->minute = 0;
  add_appointment(scheduler, appointment2);

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Remove an appointment from the scheduler
  remove_appointment(scheduler, 1);

  // Print the appointments in the scheduler again
  print_appointments(scheduler);

  // Free the memory allocated for the appointment scheduler
  free_appointment_scheduler(scheduler);

  return 0;
}