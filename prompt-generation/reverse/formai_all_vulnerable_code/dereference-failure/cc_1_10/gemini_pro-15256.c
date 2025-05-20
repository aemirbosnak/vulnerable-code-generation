//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
  char name[50];
  char description[100];
  int start_time;
  int end_time;
} appointment_t;

// Define the structure of the appointment scheduler
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

// Free the memory allocated for the appointment scheduler
void appointment_scheduler_free(appointment_scheduler_t* scheduler) {
  free(scheduler);
}

// Add an appointment to the scheduler
void appointment_scheduler_add(appointment_scheduler_t* scheduler, appointment_t appointment) {
  scheduler->appointments[scheduler->num_appointments] = appointment;
  scheduler->num_appointments++;
}

// Print the appointments in the scheduler
void appointment_scheduler_print(appointment_scheduler_t* scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s, %d-%d\n", scheduler->appointments[i].name, scheduler->appointments[i].description, scheduler->appointments[i].start_time, scheduler->appointments[i].end_time);
  }
}

// Main function
int main() {
  // Create a new appointment scheduler
  appointment_scheduler_t* scheduler = appointment_scheduler_new();

  // Add some appointments to the scheduler
  appointment_t appointment1 = {"John Doe", "Meeting with the boss", 1000, 1100};
  appointment_scheduler_add(scheduler, appointment1);

  appointment_t appointment2 = {"Jane Doe", "Doctor's appointment", 1200, 1300};
  appointment_scheduler_add(scheduler, appointment2);

  appointment_t appointment3 = {"John Smith", "Lunch with friends", 1300, 1400};
  appointment_scheduler_add(scheduler, appointment3);

  // Print the appointments in the scheduler
  appointment_scheduler_print(scheduler);

  // Free the memory allocated for the appointment scheduler
  appointment_scheduler_free(scheduler);

  return 0;
}