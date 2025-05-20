//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  char time[MAX_NAME_LENGTH];
  struct Appointment* next;
} Appointment;

Appointment* insertAppointment(Appointment* head, char* name, char* time) {
  Appointment* newAppointment = malloc(sizeof(struct Appointment));
  strcpy(newAppointment->name, name);
  strcpy(newAppointment->time, time);
  newAppointment->next = NULL;

  if (head == NULL) {
    return newAppointment;
  }

  head->next = newAppointment;
  return head;
}

int validateAppointment(Appointment* head, char* name, char* time) {
  for (Appointment* currentAppointment = head; currentAppointment; currentAppointment = currentAppointment->next) {
    if (strcmp(currentAppointment->name, name) == 0 && strcmp(currentAppointment->time, time) == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  Appointment* head = NULL;

  char* name = "John Doe";
  char* time = "10:00 AM";

  insertAppointment(head, name, time);

  if (validateAppointment(head, name, time) == 0) {
    printf("Error: Appointment already exists.\n");
  } else {
    printf("Appointment inserted successfully.\n");
  }

  return 0;
}