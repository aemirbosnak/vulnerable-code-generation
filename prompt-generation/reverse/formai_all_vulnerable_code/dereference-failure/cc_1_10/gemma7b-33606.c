//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  struct Appointment* next;
} Appointment;

void createAppointment(Appointment* head) {
  head = (Appointment*)malloc(sizeof(Appointment));
  head->name[0] = '\0';
  head->date[0] = '\0';
  head->time[0] = '\0';
  head->next = NULL;
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
  Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
  strcpy(newApp->name, name);
  strcpy(newApp->date, date);
  strcpy(newApp->time, time);
  newApp->next = NULL;

  if (head == NULL) {
    head = newApp;
  } else {
    head->next = newApp;
  }
}

void listAppointments(Appointment* head) {
  Appointment* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Date: %s\n", current->date);
    printf("Time: %s\n", current->time);
    printf("\n");
    current = current->next;
  }
}

int main() {
  Appointment* head = NULL;
  createAppointment(head);

  addAppointment(head, "John Doe", "2023-04-01", "10:00 AM");
  addAppointment(head, "Jane Doe", "2023-04-02", "1:00 PM");
  addAppointment(head, "Peter Pan", "2023-04-03", "4:00 PM");

  listAppointments(head);

  return 0;
}