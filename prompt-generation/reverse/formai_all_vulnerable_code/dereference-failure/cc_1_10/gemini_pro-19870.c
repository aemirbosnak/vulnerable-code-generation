//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Appointment {
  char *description;
  time_t start_time;
  time_t end_time;
};

struct AppointmentScheduler {
  struct Appointment **appointments;
  int num_appointments;
  int max_appointments;
};

struct AppointmentScheduler *create_appointment_scheduler(int max_appointments) {
  struct AppointmentScheduler *scheduler = malloc(sizeof(struct AppointmentScheduler));
  scheduler->appointments = malloc(sizeof(struct Appointment *) * max_appointments);
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

void destroy_appointment_scheduler(struct AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]);
  }
  free(scheduler->appointments);
  free(scheduler);
}

int add_appointment(struct AppointmentScheduler *scheduler, struct Appointment *appointment) {
  if (scheduler->num_appointments == scheduler->max_appointments) {
    return -1;
  }
  scheduler->appointments[scheduler->num_appointments++] = appointment;
  return 0;
}

void print_appointments(struct AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s to %s\n", scheduler->appointments[i]->description, ctime(&scheduler->appointments[i]->start_time), ctime(&scheduler->appointments[i]->end_time));
  }
}

int main() {
  struct AppointmentScheduler *scheduler = create_appointment_scheduler(10);

  struct Appointment *appointment1 = malloc(sizeof(struct Appointment));
  appointment1->description = "Dinner with my love";
  appointment1->start_time = time(NULL) + 60 * 60;
  appointment1->end_time = appointment1->start_time + 60 * 60 * 2;
  add_appointment(scheduler, appointment1);

  struct Appointment *appointment2 = malloc(sizeof(struct Appointment));
  appointment2->description = "Movie with my darling";
  appointment2->start_time = time(NULL) + 60 * 60 * 24;
  appointment2->end_time = appointment2->start_time + 60 * 60 * 2;
  add_appointment(scheduler, appointment2);

  print_appointments(scheduler);

  destroy_appointment_scheduler(scheduler);

  return 0;
}