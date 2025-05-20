//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum number of appointments. */
#define MAX_APPOINTMENTS 100

/* Define the structure of an appointment. */
typedef struct {
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} Appointment;

/* Define the structure of the appointment scheduler. */
typedef struct {
  Appointment *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} AppointmentScheduler;

/* Create a new appointment scheduler. */
AppointmentScheduler *create_appointment_scheduler() {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->num_appointments = 0;
  return scheduler;
}

/* Destroy an appointment scheduler. */
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]);
  }
  free(scheduler);
}

/* Add an appointment to the scheduler. */
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    fprintf(stderr, "Error: Too many appointments.\n");
    return;
  }

  scheduler->appointments[scheduler->num_appointments++] = appointment;
}

/* Print the appointments in the scheduler. */
void print_appointments(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s (%s - %s)\n",
           scheduler->appointments[i]->name,
           scheduler->appointments[i]->description,
           ctime(&scheduler->appointments[i]->start_time),
           ctime(&scheduler->appointments[i]->end_time));
  }
}

/* Main function. */
int main() {
  /* Create an appointment scheduler. */
  AppointmentScheduler *scheduler = create_appointment_scheduler();

  /* Add some appointments to the scheduler. */
  Appointment *appointment1 = malloc(sizeof(Appointment));
  appointment1->name = strdup("Meeting with the boss");
  appointment1->description = strdup("Discuss the project plan.");
  appointment1->start_time = time(NULL) + 3600;  // 1 hour from now
  appointment1->end_time = time(NULL) + 7200;    // 2 hours from now
  add_appointment(scheduler, appointment1);

  Appointment *appointment2 = malloc(sizeof(Appointment));
  appointment2->name = strdup("Doctor's appointment");
  appointment2->description = strdup("Get a checkup.");
  appointment2->start_time = time(NULL) + 86400;  // 1 day from now
  appointment2->end_time = time(NULL) + 97200;    // 1 day and 3 hours from now
  add_appointment(scheduler, appointment2);

  /* Print the appointments in the scheduler. */
  print_appointments(scheduler);

  /* Destroy the appointment scheduler. */
  destroy_appointment_scheduler(scheduler);

  return 0;
}