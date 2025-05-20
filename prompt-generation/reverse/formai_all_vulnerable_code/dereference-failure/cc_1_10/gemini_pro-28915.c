//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
  Appointment **appointments;
  int num_appointments;
  int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *appointment_scheduler_new(int max_appointments) {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = malloc(sizeof(Appointment *) * max_appointments);
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

// Free an appointment scheduler
void appointment_scheduler_free(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]);
  }
  free(scheduler->appointments);
  free(scheduler);
}

// Add an appointment to the scheduler
int appointment_scheduler_add(AppointmentScheduler *scheduler, Appointment *appointment) {
  if (scheduler->num_appointments >= scheduler->max_appointments) {
    return -1;
  }
  scheduler->appointments[scheduler->num_appointments++] = appointment;
  return 0;
}

// Remove an appointment from the scheduler
int appointment_scheduler_remove(AppointmentScheduler *scheduler, Appointment *appointment) {
  int index = -1;
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (scheduler->appointments[i] == appointment) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    return -1;
  }
  for (int i = index + 1; i < scheduler->num_appointments; i++) {
    scheduler->appointments[i - 1] = scheduler->appointments[i];
  }
  scheduler->num_appointments--;
  return 0;
}

// Find an appointment in the scheduler
Appointment *appointment_scheduler_find(AppointmentScheduler *scheduler, char *name) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (strcmp(scheduler->appointments[i]->name, name) == 0) {
      return scheduler->appointments[i];
    }
  }
  return NULL;
}

// Print the appointments in the scheduler
void appointment_scheduler_print(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s\n", scheduler->appointments[i]->name, scheduler->appointments[i]->description);
    printf("Start time: %s\n", ctime(&scheduler->appointments[i]->start_time));
    printf("End time: %s\n", ctime(&scheduler->appointments[i]->end_time));
    printf("\n");
  }
}

// Test the appointment scheduler
int main() {
  // Create a new appointment scheduler
  AppointmentScheduler *scheduler = appointment_scheduler_new(10);

  // Add some appointments to the scheduler
  Appointment *appointment1 = malloc(sizeof(Appointment));
  appointment1->name = "Meeting with John";
  appointment1->description = "Discuss the project";
  appointment1->start_time = time(NULL) + 3600;
  appointment1->end_time = time(NULL) + 7200;
  appointment_scheduler_add(scheduler, appointment1);

  Appointment *appointment2 = malloc(sizeof(Appointment));
  appointment2->name = "Lunch with Mary";
  appointment2->description = "Catch up and talk about the weekend";
  appointment2->start_time = time(NULL) + 10800;
  appointment2->end_time = time(NULL) + 14400;
  appointment_scheduler_add(scheduler, appointment2);

  // Find an appointment in the scheduler
  Appointment *appointment3 = appointment_scheduler_find(scheduler, "Meeting with John");

  // Print the appointments in the scheduler
  appointment_scheduler_print(scheduler);

  // Free the appointment scheduler
  appointment_scheduler_free(scheduler);

  return 0;
}