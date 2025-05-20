//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
  char name[50];
  char description[100];
  time_t start_time;
  time_t end_time;
} appointment_t;

// Define the structure of an appointment scheduler
typedef struct appointment_scheduler {
  appointment_t appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t* appointment_scheduler_new() {
  appointment_scheduler_t* scheduler = malloc(sizeof(appointment_scheduler_t));
  scheduler->num_appointments = 0;
  return scheduler;
}

// Free an appointment scheduler
void appointment_scheduler_free(appointment_scheduler_t* scheduler) {
  free(scheduler);
}

// Add an appointment to the scheduler
int appointment_scheduler_add(appointment_scheduler_t* scheduler, appointment_t* appointment) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    return -1;
  }
  scheduler->appointments[scheduler->num_appointments++] = *appointment;
  return 0;
}

// Remove an appointment from the scheduler
int appointment_scheduler_remove(appointment_scheduler_t* scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    return -1;
  }
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
  return 0;
}

// Get an appointment from the scheduler
appointment_t* appointment_scheduler_get(appointment_scheduler_t* scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    return NULL;
  }
  return &scheduler->appointments[index];
}

// Print the appointments in the scheduler
void appointment_scheduler_print(appointment_scheduler_t* scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    appointment_t* appointment = &scheduler->appointments[i];
    printf("%s: %s\n", appointment->name, appointment->description);
  }
}

// Main function
int main() {
  // Create a new appointment scheduler
  appointment_scheduler_t* scheduler = appointment_scheduler_new();

  // Add some appointments to the scheduler
  appointment_t appointment1 = {
    .name = "Appointment 1",
    .description = "This is the first appointment.",
    .start_time = time(NULL) + 3600, // 1 hour from now
    .end_time = time(NULL) + 7200, // 2 hours from now
  };
  appointment_scheduler_add(scheduler, &appointment1);

  appointment_t appointment2 = {
    .name = "Appointment 2",
    .description = "This is the second appointment.",
    .start_time = time(NULL) + 86400, // 1 day from now
    .end_time = time(NULL) + 90000, // 1 day and 1 hour from now
  };
  appointment_scheduler_add(scheduler, &appointment2);

  // Print the appointments in the scheduler
  printf("Appointments:\n");
  appointment_scheduler_print(scheduler);

  // Free the appointment scheduler
  appointment_scheduler_free(scheduler);

  return 0;
}