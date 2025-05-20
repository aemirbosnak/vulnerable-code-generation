//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  char date[10];
  char time[10];
  struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
  *head = malloc(sizeof(Appointment));
  (*head)->next = NULL;
  (*head)->name[0] = '\0';
  (*head)->date[0] = '\0';
  (*head)->time[0] = '\0';
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
  Appointment* newAppt = malloc(sizeof(Appointment));
  newAppt->next = NULL;
  strcpy(newAppt->name, name);
  strcpy(newAppt->date, date);
  strcpy(newAppt->time, time);

  if (head) {
    head->next = newAppt;
  } else {
    head = newAppt;
  }
  head = newAppt;
}

void displayAppointments(Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Appointment* head = NULL;

  createAppointment(&head);
  addAppointment(head, "John Doe", "2023-04-01", "10:00");
  addAppointment(head, "Jane Doe", "2023-04-02", "12:00");
  addAppointment(head, "Peter Pan", "2023-04-03", "08:00");

  displayAppointments(head);

  return 0;
}