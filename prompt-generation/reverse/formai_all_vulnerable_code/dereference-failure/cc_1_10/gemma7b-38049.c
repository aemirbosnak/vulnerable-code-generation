//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

struct Appointment {
  char name[50];
  char date[50];
  char time[50];
  struct Appointment* next;
};

void displayAppointments(struct Appointment* head) {
  struct Appointment* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Date: %s\n", current->date);
    printf("Time: %s\n", current->time);
    printf("\n");
    current = current->next;
  }
}

struct Appointment* insertAppointment(struct Appointment* head, char* name, char* date, char* time) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  strcpy(newAppointment->name, name);
  strcpy(newAppointment->date, date);
  strcpy(newAppointment->time, time);
  newAppointment->next = NULL;

  if (head == NULL) {
    head = newAppointment;
  } else {
    struct Appointment* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newAppointment;
  }

  return head;
}

int main() {
  struct Appointment* head = NULL;

  insertAppointment(head, "John Doe", "2023-04-01", "10:00");
  insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
  insertAppointment(head, "Peter Pan", "2023-04-03", "14:00");

  displayAppointments(head);

  return 0;
}