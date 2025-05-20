//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[50];
  char description[100];
  time_t timestamp;
  struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void schedule_appointment(char* name, char* description, time_t timestamp) {
  Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));
  strcpy(new_appointment->name, name);
  strcpy(new_appointment->description, description);
  new_appointment->timestamp = timestamp;
  new_appointment->next = NULL;

  if (head == NULL) {
    head = new_appointment;
  } else {
    head->next = new_appointment;
  }
}

void print_appointments() {
  Appointment* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Description: %s\n", current->description);
    printf("Timestamp: %ld\n", current->timestamp);
    printf("\n");
    current = current->next;
  }
}

int main() {
  time_t timestamp = time(NULL);
  schedule_appointment("John Doe", "Meeting with CEO", timestamp);
  schedule_appointment("Jane Doe", "Lunch with friends", timestamp + 3600);
  schedule_appointment("Peter Pan", "Flying to Neverland", timestamp + 2 * 3600);

  print_appointments();

  return 0;
}