//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
  char *title;
  char *description;
  time_t start_time;
  time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
  Appointment *appointments;
  int num_appointments;
  int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler(int max_appointments) {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = malloc(sizeof(Appointment) * max_appointments);
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i].title);
    free(scheduler->appointments[i].description);
  }
  free(scheduler->appointments);
  free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment appointment) {
  if (scheduler->num_appointments == scheduler->max_appointments) {
    printf("Error: Appointment scheduler is full.\n");
    return;
  }
  scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    printf("Error: Invalid appointment index.\n");
    return;
  }
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("Appointment %d:\n", i + 1);
    printf("  Title: %s\n", scheduler->appointments[i].title);
    printf("  Description: %s\n", scheduler->appointments[i].description);
    printf("  Start time: %s", ctime(&scheduler->appointments[i].start_time));
    printf("  End time: %s", ctime(&scheduler->appointments[i].end_time));
  }
}

// Main function
int main() {
  // Create an appointment scheduler
  AppointmentScheduler *scheduler = create_appointment_scheduler(10);

  // Add some appointments to the scheduler
  Appointment appointment1 = {
    .title = "Meeting with the team",
    .description = "Discuss the project plans.",
    .start_time = time(NULL) + 3600,
    .end_time = time(NULL) + 7200
  };
  add_appointment(scheduler, appointment1);

  Appointment appointment2 = {
    .title = "Doctor's appointment",
    .description = "Get a checkup.",
    .start_time = time(NULL) + 86400,
    .end_time = time(NULL) + 90000
  };
  add_appointment(scheduler, appointment2);

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Remove an appointment from the scheduler
  remove_appointment(scheduler, 1);

  // Print the appointments in the scheduler again
  print_appointments(scheduler);

  // Destroy the appointment scheduler
  destroy_appointment_scheduler(scheduler);

  return 0;
}