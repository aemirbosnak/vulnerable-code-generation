//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  char time[MAX_NAME_LENGTH];
  struct Appointment* next;
} Appointment;

void insertAppointment(Appointment* head, char* name, char* time) {
  Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
  strcpy(newApp->name, name);
  strcpy(newApp->time, time);
  newApp->next = NULL;

  if (head == NULL) {
    head = newApp;
  } else {
    head->next = newApp;
  }
  head = newApp;
}

void printAppointments(Appointment* head) {
  while (head) {
    printf("%s - %s\n", head->name, head->time);
    head = head->next;
  }
}

int main() {
  Appointment* head = NULL;

  char name[MAX_NAME_LENGTH];
  char time[MAX_NAME_LENGTH];

  // Insert some appointments
  insertAppointment(head, "John Doe", "10:00");
  insertAppointment(head, "Jane Doe", "12:00");
  insertAppointment(head, "Peter Pan", "14:00");

  // Print all appointments
  printAppointments(head);

  return 0;
}