//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
  char name[50];
  char description[100];
  int start_time;  // in hours
  int end_time;    // in hours
};

struct appointment_scheduler {
  struct appointment appointments[MAX_APPOINTMENTS];
  int num_appointments;
};

struct appointment_scheduler* create_scheduler() {
  struct appointment_scheduler* scheduler = malloc(sizeof(struct appointment_scheduler));
  scheduler->num_appointments = 0;
  return scheduler;
}

void destroy_scheduler(struct appointment_scheduler* scheduler) {
  free(scheduler);
}

void add_appointment(struct appointment_scheduler* scheduler, struct appointment* appointment) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    printf("Error: Appointment scheduler is full.\n");
    return;
  }

  scheduler->appointments[scheduler->num_appointments] = *appointment;
  scheduler->num_appointments++;
}

void print_appointment(struct appointment* appointment) {
  printf("Name: %s\n", appointment->name);
  printf("Description: %s\n", appointment->description);
  printf("Start time: %d:00\n", appointment->start_time);
  printf("End time: %d:00\n", appointment->end_time);
  printf("\n");
}

void print_scheduler(struct appointment_scheduler* scheduler) {
  printf("Appointments:\n");
  for (int i = 0; i < scheduler->num_appointments; i++) {
    print_appointment(&scheduler->appointments[i]);
  }
}

int main() {
  struct appointment_scheduler* scheduler = create_scheduler();

  struct appointment appointment1 = {
    .name = "John Doe",
    .description = "Meeting about project X",
    .start_time = 10,
    .end_time = 11
  };

  struct appointment appointment2 = {
    .name = "Jane Smith",
    .description = "Interview for position Y",
    .start_time = 13,
    .end_time = 14
  };

  add_appointment(scheduler, &appointment1);
  add_appointment(scheduler, &appointment2);

  print_scheduler(scheduler);

  destroy_scheduler(scheduler);

  return 0;
}