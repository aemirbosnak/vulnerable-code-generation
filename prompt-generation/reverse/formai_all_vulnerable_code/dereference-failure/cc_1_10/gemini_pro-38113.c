//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
  char *description;
  int start_time;
  int end_time;
} Appointment;

typedef struct Schedule {
  Appointment *appointments[100];
  int num_appointments;
} Schedule;

Schedule *create_schedule() {
  Schedule *schedule = malloc(sizeof(Schedule));
  schedule->num_appointments = 0;
  return schedule;
}

void add_appointment(Schedule *schedule, Appointment *appointment) {
  if (schedule->num_appointments < 100) {
    schedule->appointments[schedule->num_appointments++] = appointment;
  } else {
    printf("Error: Schedule is full.\n");
  }
}

void print_schedule(Schedule *schedule) {
  for (int i = 0; i < schedule->num_appointments; i++) {
    Appointment *appointment = schedule->appointments[i];
    printf("%s (%d-%d)\n", appointment->description, appointment->start_time,
           appointment->end_time);
  }
}

int main() {
  Schedule *schedule = create_schedule();

  Appointment *appointment1 = malloc(sizeof(Appointment));
  appointment1->description = "Meet with client";
  appointment1->start_time = 900;
  appointment1->end_time = 1000;

  Appointment *appointment2 = malloc(sizeof(Appointment));
  appointment2->description = "Work on project";
  appointment2->start_time = 1000;
  appointment2->end_time = 1200;

  Appointment *appointment3 = malloc(sizeof(Appointment));
  appointment3->description = "Lunch break";
  appointment3->start_time = 1200;
  appointment3->end_time = 1300;

  add_appointment(schedule, appointment1);
  add_appointment(schedule, appointment2);
  add_appointment(schedule, appointment3);

  print_schedule(schedule);

  return 0;
}