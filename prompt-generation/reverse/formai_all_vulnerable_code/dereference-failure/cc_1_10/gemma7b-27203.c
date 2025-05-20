//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  struct Appointment* next;
} Appointment;

void insertAppointment(Appointment* head, char* name, char* date, char* time) {
  Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
  strcpy(newAppointment->name, name);
  strcpy(newAppointment->date, date);
  strcpy(newAppointment->time, time);
  newAppointment->next = NULL;

  if (head == NULL) {
    head = newAppointment;
  } else {
    newAppointment->next = head;
    head = newAppointment;
  }
}

void printAppointments(Appointment* head) {
  while (head) {
    printf("%s, %s, %s\n", head->name, head->date, head->time);
    head = head->next;
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Appointment* head = NULL;

  // Insert some appointments
  insertAppointment(head, "John Doe", "2023-04-01", "10:00");
  insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
  insertAppointment(head, "Mike Smith", "2023-04-03", "14:00");

  // Print all appointments
  printAppointments(head);

  return 0;
}