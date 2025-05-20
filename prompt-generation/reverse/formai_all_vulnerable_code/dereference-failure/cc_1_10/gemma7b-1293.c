//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  time_t timestamp;
  struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void schedule_appointment(char* name, time_t timestamp) {
  Appointment* new_appointment = malloc(sizeof(Appointment));
  strcpy(new_appointment->name, name);
  new_appointment->timestamp = timestamp;
  new_appointment->next = NULL;

  if (head == NULL) {
    head = new_appointment;
  } else {
    head->next = new_appointment;
  }
}

time_t get_available_time() {
  time_t now = time(NULL);
  time_t next_available_time = now + 60;

  while (head && head->timestamp < next_available_time) {
    next_available_time += 60;
  }

  return next_available_time;
}

void print_appointments() {
  Appointment* current_appointment = head;

  while (current_appointment) {
    printf("Name: %s, Timestamp: %ld\n", current_appointment->name, current_appointment->timestamp);
    current_appointment = current_appointment->next;
  }
}

int main() {
  schedule_appointment("John Doe", time(NULL) + 30);
  schedule_appointment("Jane Doe", time(NULL) + 60);
  schedule_appointment("Bill Smith", time(NULL) + 90);

  print_appointments();

  time_t next_available_time = get_available_time();

  printf("Next available time: %ld\n", next_available_time);

  return 0;
}