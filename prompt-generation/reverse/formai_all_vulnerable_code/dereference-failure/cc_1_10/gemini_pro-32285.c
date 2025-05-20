//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
  char *name;
  time_t start_time;
  time_t end_time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
  appointment_t *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t *create_appointment_scheduler() {
  appointment_scheduler_t *scheduler = malloc(sizeof(appointment_scheduler_t));
  scheduler->num_appointments = 0;
  return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(appointment_scheduler_t *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]);
  }
  free(scheduler);
}

// Add an appointment to the scheduler
int add_appointment(appointment_scheduler_t *scheduler, char *name, time_t start_time, time_t end_time) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    return -1;  // Error: Too many appointments
  }

  // Create a new appointment
  appointment_t *appointment = malloc(sizeof(appointment_t));
  appointment->name = strdup(name);
  appointment->start_time = start_time;
  appointment->end_time = end_time;

  // Add the appointment to the scheduler
  scheduler->appointments[scheduler->num_appointments++] = appointment;

  return 0;  // Success
}

// Remove an appointment from the scheduler
int remove_appointment(appointment_scheduler_t *scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    return -1;  // Error: Invalid index
  }

  // Remove the appointment from the scheduler
  free(scheduler->appointments[index]->name);
  free(scheduler->appointments[index]);
  scheduler->num_appointments--;

  // Shift the remaining appointments down
  for (int i = index; i < scheduler->num_appointments; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }

  return 0;  // Success
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s - %s\n", scheduler->appointments[i]->name, ctime(&scheduler->appointments[i]->start_time), ctime(&scheduler->appointments[i]->end_time));
  }
}

// Get the next available time slot in the scheduler
time_t get_next_available_time_slot(appointment_scheduler_t *scheduler) {
  time_t next_available_time_slot = time(NULL);

  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (next_available_time_slot < scheduler->appointments[i]->start_time) {
      next_available_time_slot = scheduler->appointments[i]->start_time;
    }
  }

  return next_available_time_slot;
}

// Main function
int main() {
  // Create an appointment scheduler
  appointment_scheduler_t *scheduler = create_appointment_scheduler();

  // Add some appointments to the scheduler
  add_appointment(scheduler, "John Doe", time(NULL), time(NULL) + 3600);
  add_appointment(scheduler, "Jane Doe", time(NULL) + 3600, time(NULL) + 7200);

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Get the next available time slot in the scheduler
  time_t next_available_time_slot = get_next_available_time_slot(scheduler);

  // Print the next available time slot
  printf("Next available time slot: %s", ctime(&next_available_time_slot));

  // Destroy the appointment scheduler
  destroy_appointment_scheduler(scheduler);

  return 0;
}